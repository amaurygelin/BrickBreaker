#ifndef RAQUETTE_H_INCLUDED
#define RAQUETTE_H_INCLUDED

#include "rectangle.h"
#include "balle.h"

class raquette : public rectangle
{
    protected :
        float vitesse;
        float longueur;
        float hauteur;
        bool inverse;
    public :
        raquette(float,float,float,float,float,int);
        ~raquette();
        float get_vitesse();
        float get_longueur();
        float get_hauteur();
        int get_couleur();
        bool get_inverse();
        void set_vitesse(float);
        void set_longueur(float);
        void set_hauteur(float);
        void set_couleur(int);
        void set_inverse(bool);
        void affiche();
        void deplace();
        bool selectionDroite(float,float);
        bool selectionGauche(float,float);
        void collision(balle*);
};

#endif // RAQUETTE_H_INCLUDED
