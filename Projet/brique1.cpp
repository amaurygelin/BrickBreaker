#include <iostream>
#include <allegro.h>

#include "brique1.h"

using namespace std;

brique1::brique1(float px, float py):brique(px,py,makecol(255,100,100))
{
    compteur=1;
    score=10;
}

brique1::~brique1()
{
}

bool brique1::action(balle* b,raquette* r,listeballe* lb)
{
    compteur--;
    if(compteur==0)
        return true;
    else
        return false;
}
