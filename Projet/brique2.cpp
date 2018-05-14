#include <iostream>
#include <allegro.h>

#include "brique2.h"

using namespace std;

brique2::brique2(float px, float py):brique(px,py,makecol(100, 252, 100))
{
    compteur=2;
    score=20;
}

brique2::~brique2()
{
}

bool brique2::action(balle* b,raquette* r,listeballe* lb)
{
    compteur--;
    if(compteur==0)
        return true;
    else
        return false;
}
