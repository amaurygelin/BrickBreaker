#include <iostream>
#include <string.h>
#include <list>
#include <allegro.h>

#include "menu.h"

using namespace std;

menu::menu(char*t[],int pnb)
{
    bloque();
    tab=new bouton*[nb=pnb];
    for(int i=0;i<nb;i++)
    {
        tab[i] = new bouton(i,2*i,i,2*i,makecol(100,180,0),t[i]); //*paramétrage à revoir
    }
    debloque();
}

menu::~menu()
{
    for(int i=0;i<nb;i++)
    {
        delete(tab[i]);
    }
    delete tab;
}

void menu::affiche()
{
    for(int i=0;i<nb;i++)
    {
        (*tab[i]).affiche();
    }
}

menu::menu(const menu& src)
{
    nb=src.nb;
    tab=new bouton*[nb];
    for(int i=0;i<nb;i++)
    {
        tab[i]=new bouton(*(src.tab[i]));
    }
}

menu& menu::operator=(const menu& src)
{
    if(this!=&src)
    {
        //destructeur
        for(int i=0;i<nb;i++)
        {
            delete(tab[i]);
        }
        delete tab;

        //constructeur par recopie
        nb=src.nb;
        tab=new bouton*[nb];
        for(int i=0;i<nb;i++)
        {
            tab[i]=new bouton(*(src.tab[i]));
        }
    }
    return (*this);
}

bool menu::selection(float sx, float sy)
{
    return false;
}
