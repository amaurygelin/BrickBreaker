#include <iostream>
#include <allegro.h>

#include "brique3.h"

using namespace std;

brique3::brique3(float px, float py):brique(px,py,makecol(100,100,252))
{
    compteur=3;
    score=30;
}

brique3::~brique3()
{
}

bool brique3::action(balle* b,raquette* r,listeballe* lb)
{
    compteur--;
    if(compteur==0)
        return true;
    else
        return false;
}
