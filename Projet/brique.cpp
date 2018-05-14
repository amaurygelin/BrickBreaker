#include <iostream>
#include <string.h>
#include <list>
#include <allegro.h>

#include "brique.h"

using namespace std;

extern BITMAP *page;

brique::brique(float px,float py,int coul):rectangle(px,py,px+100,py+40,coul)
{
}

brique::~brique()
{
}

int brique::getScore()
{
    return score;
}
