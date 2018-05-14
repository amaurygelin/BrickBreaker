#ifndef BRIQUE3_H_INCLUDED
#define BRIQUE3_H_INCLUDED

#include "brique.h"

class brique3 : public brique
{
    protected :

    public :
        brique3(float,float);
        ~brique3();
        bool action(balle*,raquette*,listeballe*);
};

#endif // BRIQUE3_H_INCLUDED
