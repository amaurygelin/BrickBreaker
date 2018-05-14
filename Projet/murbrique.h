#ifndef MURBRIQUE_H_INCLUDED
#define MURBRIQUE_H_INCLUDED

#include "forme.h"
#include "brique.h"
#include "balle.h"

class listeballe;

class murbrique : public forme
{
    protected :
        list<brique*> l;
        list<brique*>::iterator it;
        int nbBriques;
        int score;
    public :
        murbrique();
        ~murbrique();
        void affiche();
        void collision(balle*,raquette*,listeballe*);
        bool selection(float,float){return false;}
        int getScore();
        void suppression_brique(brique*);
};

#endif // MURBRIQUE_H_INCLUDED
