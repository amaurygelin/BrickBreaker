#ifndef BRIQUEBONUS_H_INCLUDED
#define BRIQUEBONUS_H_INCLUDED

#include "brique.h"

class briquebonus : public brique
{
    protected :
        int bonus;
    public :
        briquebonus(float,float);
        ~briquebonus();
        bool action(balle*,raquette*,listeballe*);
};

#endif // BRIQUEBONUS_H_INCLUDED
