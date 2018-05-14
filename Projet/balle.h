#ifndef BALLE_H_INCLUDED
#define BALLE_H_INCLUDED

#include "cercle.h"

class balle : public cercle
{
    protected :
        float vitesse;
        float pas_x;
        float pas_y;
    public :
        balle(float,float,float,float,int);
        ~balle();
        float get_vitesse();
        void set_vitesse(float);
        void deplace();
        float get_pas_x();
        float get_pas_y();
        void set_pas_x(float);
        void set_pas_y(float);
};

#endif // BALLE_H_INCLUDED
