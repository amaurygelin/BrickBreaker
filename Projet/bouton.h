#ifndef BOUTON_H_INCLUDED
#define BOUTON_H_INCLUDED

#include <string.h>

#include "rectangle.h"

class bouton : public forme
{
    protected :
        rectangle r;
        string ch;
    public :
        bouton(float,float,float,float,int,char*);
        bouton(point,point,int,char*);
        bouton(rectangle,string);
        ~bouton();
        void affiche();
        bool selection(float,float);
};

#endif // BOUTON_H_INCLUDED
