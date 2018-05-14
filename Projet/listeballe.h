#ifndef LISTEBALLE_H_INCLUDED
#define LISTEBALLE_H_INCLUDED

#include "murbrique.h"

class listeballe : public forme
{
    protected :
        list<balle*> l;
        list<balle*>::iterator it;
        int nbBalles;
    public :
        listeballe();
        ~listeballe();
        void affiche();
        bool selection(float,float){return false;}
        void deplace();
        void collision(murbrique*, raquette*);
        void ajoute_balle(float,float,float,float,int);
        void supprime_balle(balle*);
};

#endif // LISTEBALLE_H_INCLUDED
