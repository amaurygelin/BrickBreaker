#ifndef CERCLE__H_INCLUDED
#define CERCLE__H_INCLUDED

#include "point.h"
#include "forme.h"

class cercle : public forme
{   protected :
        point p;
        float rayon;
        int couleur;
    public :
        cercle(float,float,float,int);
        ~cercle();
        float get_rayon();
        int get_couleur();
        void set_rayon(float);
        void set_couleur(int);
        void affiche();
        bool selection(float,float);
};

#endif // CERCLE__H_INCLUDED
