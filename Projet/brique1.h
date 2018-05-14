#ifndef BRIQUE1_H_INCLUDED
#define BRIQUE1_H_INCLUDED

#include "brique.h"

class brique1 : public brique
{
    protected :

    public :
        brique1(float,float);
        ~brique1();
        bool action(balle*,raquette*,listeballe*);
};


#endif // BRIQUE1_H_INCLUDED
