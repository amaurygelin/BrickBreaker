#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "bouton.h"

class menu : public forme
{
    protected :
        bouton** tab;
        int nb;
    public :
        menu(char*[],int);
        ~menu();
        menu(const menu&);
        menu& operator=(const menu&);
        void affiche();
        bool selection(float,float);
};

#endif // MENU_H_INCLUDED
