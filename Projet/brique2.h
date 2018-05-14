#ifndef BRIQUE2_H_INCLUDED
#define BRIQUE2_H_INCLUDED

#include "brique.h"

class brique2 : public brique
{
    protected :

    public :
        brique2(float,float);
        ~brique2();
        bool action(balle*,raquette*,listeballe*);
};

#endif // BRIQUE2_H_INCLUDED
