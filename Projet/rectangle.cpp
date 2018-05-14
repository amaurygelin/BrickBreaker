#include <iostream>
#include <string.h>
#include <list>
#include <allegro.h>

#include "rectangle.h"

using namespace std;

extern BITMAP *page;

rectangle::rectangle(float x1,float y1,float x2,float y2,int coul) : p1(x1,y1),p2(x2,y2)
{
    couleur=coul;
}

rectangle::rectangle(point pp1,point pp2, int coul) : p1(pp1),p2(pp2)
{
    couleur=coul;
}

rectangle::~rectangle()
{
    //rien à mettre car la relation de composition est gérée de manière statique ici
}

void rectangle::affiche()
{
    rectfill(page,p1.getx(),p1.gety(),p2.getx(),p2.gety(),couleur);
}

bool rectangle::selection(float sx, float sy)
{
    if((sx>=p1.getx())&&(sx<=p2.getx())&&(sy>=p1.gety())&&(sy<=p2.gety()))
        return true;
    return false;
}

void rectangle::getp1p2(float* px1,float* py1,float* px2,float* py2)
{
    *px1 = p1.getx();
    *py1 = p1.gety();
    *px2 = p2.getx();
    *py2 = p2.gety();
}

