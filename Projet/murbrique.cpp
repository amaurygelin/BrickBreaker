#include <iostream>
#include <list>
#include <allegro.h>
#include <time.h>

#include "murbrique.h"
#include "brique1.h"
#include "brique2.h"
#include "brique3.h"
#include "briquebonus.h"

using namespace std;

extern SAMPLE *beep_brique;
extern bool WIN;

murbrique::murbrique()
{
    score=0;
    int r;
    nbBriques = 20;
    bloque();
    srand(time(NULL));
    for(int i=50;i<=490;i=i+110)
    {
        for(int j=30;j<=180;j=j+50)
        {
            r=rand()%10+1;
            if(r==1 || r==4 || r==7)
            {
                l.push_back(new brique1(i,j));
            }
            else if(r==2 || r==5 || r==8)
            {
                l.push_back(new brique2(i,j));
            }
            else if(r==3 || r==6 || r==9)
            {
                l.push_back(new brique3(i,j));
            }
            else if(r==10)
            {
                l.push_back(new briquebonus(i,j));
            }
        }
    }
    debloque();
}

murbrique::~murbrique()
{
    for(it=l.begin();it!=l.end();it++)
    {
        delete(*it);
    }
}

void murbrique::affiche()
{
    for(it=l.begin();it!=l.end();it++)
    {
        (*it)->affiche();
    }
}

void murbrique::suppression_brique(brique* b)
{
    l.remove(b);
    nbBriques--;
    score += b->getScore();
}

void murbrique::collision(balle* b,raquette* r,listeballe* lb)
{
    for(it=l.begin();it!=l.end();it++)
    {
        float x_centre_balle;
        float y_centre_balle;
        b->get_p(&x_centre_balle,&y_centre_balle);
        float rayon_balle = b->get_rayon();
        float dx = b->get_pas_x();
        float dy = b->get_pas_y();
        if((*it)->selection(x_centre_balle,y_centre_balle-rayon_balle) || (*it)->selection(x_centre_balle,y_centre_balle+rayon_balle))
        {
            play_sample(beep_brique,255,128,800,false);
            b->set_pas_y(-dy);
            if((*it)->action(b,r,lb))
            {
                suppression_brique(*it);
                return;
            }
        }
        if((*it)->selection(x_centre_balle+rayon_balle,y_centre_balle) || (*it)->selection(x_centre_balle-rayon_balle,y_centre_balle))
        {
            play_sample(beep_brique,255,128,800,false);
            b->set_pas_x(-dx);
            if((*it)->action(b,r,lb))
            {
                suppression_brique(*it);
                return;
            }
        }
    }
    if(nbBriques==0)
    {
        WIN = true;
    }
}

int murbrique::getScore()
{
    return score;
}

