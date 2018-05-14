#include <iostream>
#include <string.h>
#include <list>

#include "point.h"

using namespace std;

point::point()
{
    x=0;
    y=0;
}

point::point(float p)
{
    x=p;
    y=p;
}

point::point(float px, float py)
{
    x=px;
    y=py;
}

point::~point()
{
}

float point::getx()
{
    return x;
}

float point::gety()
{
    return y;
}

void point::affiche()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

void point::deplace(float dx, float dy)
{
    x+=dx;
    y+=dy;
}
