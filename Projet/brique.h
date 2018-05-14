#ifndef BRIQUE_H_INCLUDED
#define BRIQUE_H_INCLUDED

#include "rectangle.h"
#include "balle.h"
#include "raquette.h"

class listeballe;

class brique : public rectangle
{
    protected :
        int compteur;
        int score;
    public :
        brique(float,float,int);
        ~brique();
        virtual bool action(balle*,raquette*,listeballe*)=0;
        int getScore();
};

#endif // BRIQUE_H_INCLUDED
