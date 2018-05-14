#include <iostream>
#include <allegro.h>
#include <list>

#include "briquebonus.h"
#include "listeballe.h"

using namespace std;

extern SAMPLE *taillePlus;
extern SAMPLE *vitessePlus;
extern SAMPLE *inversionRaquette;
extern SAMPLE *balleSup;

briquebonus::briquebonus(float px, float py):brique(px,py,makecol(255,215,0))
{
    compteur=1;
    score=10;
    bonus=rand()%4+1;
}

briquebonus::~briquebonus()
{
}

bool briquebonus::action(balle* b,raquette* r,listeballe* lb)
{
    compteur--;
    if(compteur==0)
    {
        if(bonus==1)
        {
            play_sample(taillePlus,255,128,800,false);
            b->set_rayon(b->get_rayon()+5);
        }
        else if(bonus==2)
        {
            play_sample(vitessePlus,255,128,800,false);
            b->set_vitesse(b->get_vitesse()+0.2);
            b->set_couleur(makecol(255,215,0));
            r->set_couleur(makecol(255,215,0));
            r->set_vitesse(r->get_vitesse()+0.2);
        }
        else if(bonus==3)
        {
            play_sample(inversionRaquette,255,128,800,false);
            if(r->get_inverse()==false)
            {
                r->set_inverse(true);
                r->set_couleur(makecol(100,100,100));
            }
            else
            {
                r->set_inverse(false);
                r->set_couleur(makecol(255,255,100));
            }
        }
        else if(bonus==4)
        {
            play_sample(balleSup,255,128,800,false);
            lb->ajoute_balle(315,435,10,0.4,makecol(255,255,255));
        }
        return true;
    }
    else
        return false;
}
