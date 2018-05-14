#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class point
{
    protected :
        float x,y;
    public :
        point();
        point(float);
        point(float,float);
        float getx();
        float gety();
        void affiche();
        void deplace(float,float);
        ~point();
};

#endif // POINT_H_INCLUDED
