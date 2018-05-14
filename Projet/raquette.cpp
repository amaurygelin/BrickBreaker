#include <iostream>
#include <allegro.h>

#include "raquette.h"

using namespace std;

extern BITMAP *page;
extern SAMPLE *beep_raquette;


raquette::raquette(float px,float py, float l, float h, float v, int coul):rectangle(px,py,px+l,py+h,coul)
{
    vitesse = v;
    longueur = l;
    hauteur = h;
    inverse = false;
}

raquette::~raquette()
{
}

float raquette::get_vitesse()
{
    return vitesse;
}

float raquette::get_longueur()
{
    return longueur;
}

float raquette::get_hauteur()
{
    return hauteur;
}

int raquette::get_couleur()
{
    return couleur;
}

bool raquette::get_inverse()
{
    return inverse;
}

void raquette::set_vitesse(float v)
{
    vitesse = v;
}

void raquette::set_longueur(float l)
{
    longueur = l;
}

void raquette::set_hauteur(float h)
{
    hauteur = h;
}

void raquette::set_couleur(int c)
{
    couleur = c;
}

void raquette::set_inverse(bool i)
{
    inverse = i;
}

void raquette::affiche()
{
    rectfill(page,p1.getx(),p1.gety(),p2.getx(),p2.gety(),couleur);
}

void raquette::deplace()
{
    if(inverse==false)
    {
        if(key[KEY_RIGHT])
        {
            if(p2.getx()<SCREEN_W)
            {
                p1.deplace(vitesse,0);
                p2.deplace(vitesse,0);
            }
            else
            {
                p1.deplace(-3,0);
                p2.deplace(-3,0);
            }
        }
        if(key[KEY_LEFT])
        {
            if(p1.getx()>0)
            {
                p1.deplace(-vitesse,0);
                p2.deplace(-vitesse,0);
            }
            else
            {
                p1.deplace(3,0);
                p2.deplace(3,0);
            }
        }
    }
    else
    {
        if(key[KEY_LEFT])
        {
            if(p1.getx()>0 && p2.getx()<640)
            {
                p1.deplace(vitesse,0);
                p2.deplace(vitesse,0);
            }
            else if(p2.getx()>=640)
            {
                p1.deplace(-10,0);
                p2.deplace(-10,0);
            }
        }
        if(key[KEY_RIGHT])
        {
            if(p1.getx()>0 && p2.getx()<640)
            {
                p1.deplace(-vitesse,0);
                p2.deplace(-vitesse,0);
            }
            else if(p1.getx()<=0)
            {
                p1.deplace(10,0);
                p2.deplace(10,0);
            }
        }
    }
}

void raquette::collision(balle* b)
{
    float x_centre_balle;
    float y_centre_balle;
    b->get_p(&x_centre_balle,&y_centre_balle);
    float rayon_balle = b->get_rayon();
    float dx = b->get_pas_x();
    float dy = b->get_pas_y();
    if((*this).selectionDroite(x_centre_balle,y_centre_balle+rayon_balle))
    {
        play_sample(beep_raquette,255,128,800,false);
        if(dx>0)
            b->set_pas_y(-dy);
        else if(dx<0)
        {
            b->set_pas_y(-dy);
            b->set_pas_x(-dx);
        }
    }
    else if((*this).selectionGauche(x_centre_balle,y_centre_balle+rayon_balle))
    {
        play_sample(beep_raquette,255,128,800,false);
        if(dx>0)
        {
            b->set_pas_y(-dy);
            b->set_pas_x(-dx);
        }
        else if(dx<0)
            b->set_pas_y(-dy);
    }
}

bool raquette::selectionGauche(float sx, float sy)
{
    if((sx>=p1.getx())&&(sx<=(p2.getx()-longueur/2.0))&&(sy>=p1.gety())&&(sy<=p2.gety()))
        {
            return true;
        }
    return false;
}

bool raquette::selectionDroite(float sx, float sy)
{
    if((sx>=(p1.getx()+longueur/2.0))&&(sx<=p2.getx())&&(sy>=p1.gety())&&(sy<=p2.gety()))
        {
            return true;
        }
    return false;
}

