#include <iostream>
#include <string.h>
#include <allegro.h>
#include <math.h>

#include "cercle.h"

using namespace std;

extern BITMAP *page;

cercle::cercle(float px,float py,float r,int coul) : p(px,py)
{
    rayon = r;
    couleur = coul;
}

cercle::~cercle()
{
    //rien à mettre car la relation de composition est gérée de manière statique ici
}

float cercle::get_rayon()
{
    return rayon;
}

int cercle::get_couleur()
{
    return couleur;
}

void cercle::set_rayon(float r)
{
    rayon = r;
}

void cercle::set_couleur(int c)
{
    couleur = c;
}

void cercle::affiche()
{
    circlefill(page,p.getx(),p.gety(),rayon,couleur);
}

bool cercle::selection(float sx, float sy)
{
    float d = sqrt(pow(sx-p.getx(),2)+pow(sy-p.gety(),2));
    if(d<=rayon)
        return true;
    return false;
}

void cercle::get_p(float* px,float* py)
{
    *px = p.getx();
    *py = p.gety();
}

