#include <iostream>
#include <list>
#include <allegro.h>
#include <time.h>

#include "listeballe.h"

using namespace std;

listeballe::listeballe()
{
    nbBalles=0;
    ajoute_balle(315,435,10,0.6,makecol(255,255,255));
}

listeballe::~listeballe()
{
    for(it=l.begin();it!=l.end();it++)
    {
        delete(*it);
    }
}

void listeballe::affiche()
{
    for(it=l.begin();it!=l.end();it++)
    {
        (*it)->affiche();
    }
}

void listeballe::deplace()
{
    for(it=l.begin();it!=l.end();it++)
    {
        (*it)->deplace();
    }
}

void listeballe::collision(murbrique* m, raquette* r)
{
    for(it=l.begin();it!=l.end();it++)
    {
        r->collision(*it);
        m->collision(*it,r,this);
    }
}

void listeballe::ajoute_balle(float x, float y, float r, float v, int coul)
{
    bloque();
    l.push_back(new balle(x,y,r,v,coul));
    debloque();
    nbBalles++;
}

void listeballe::supprime_balle(balle* b)
{
    l.remove(b);
    nbBalles--;
}

