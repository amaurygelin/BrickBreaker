#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "point.h"
#include "forme.h"

class rectangle : public forme
{
    protected :
        point p1,p2;
        int couleur;
    public :
        rectangle(float,float,float,float,int);
        rectangle(point,point,int);
        ~rectangle();
        void affiche();
        bool selection(float,float);
        void getp1p2(float*,float*,float*,float*);
};

#endif // RECTANGLE_H_INCLUDED
