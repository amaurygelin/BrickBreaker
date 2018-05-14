#include <iostream>
#include <allegro.h>
#include <time.h>

#include "balle.h"

using namespace std;

extern BITMAP *page;
extern MIDI *BackGround;
extern bool LOSE;

balle::balle(float px, float py, float r,float v,int coul) : cercle(px,py,r,coul)
{
    vitesse=v;
    pas_x=v;
    pas_y=-v;
}

balle::~balle()
{
}

float balle::get_vitesse()
{
    return vitesse;
}

void balle::set_vitesse(float v)
{
    vitesse = v;
    if(pas_x>0)
        pas_x = v;
    else if(pas_x<0)
        pas_x=-v;
    if(pas_y>0)
        pas_y = v;
    else if(pas_y<0)
        pas_y=-v;
}

void balle::deplace()
{
    p.deplace(pas_x,pas_y);
    if(p.getx()+rayon>=640)
    {
        set_pas_x(-pas_x);
    }
    else if(p.gety()-rayon<=0)
    {
        set_pas_y(-pas_y);
    }
    else if(p.getx()-rayon<=0)
    {
        set_pas_x(-pas_x);
    }
    else if(p.gety()+rayon>=530)
    {
        LOSE = true;
    }
}

void balle::set_pas_x(float dx)
{
    pas_x=dx;
}
void balle::set_pas_y(float dy)
{
    pas_y=dy;
}
float balle::get_pas_x()
{
    return pas_x;
}
float balle::get_pas_y()
{
    return pas_y;
}
