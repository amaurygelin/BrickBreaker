#include <iostream>
#include <string.h>
#include <list>

#include "forme.h"

using namespace std;

listeforme forme::t;
bool forme::flag = true;

forme::forme()
{
    if(flag==true)
        t.ajoute(this);
}

forme::~forme()
{
    t.supprime(this);
}

void forme::bloque()
{
    flag=false;
}

void forme::debloque()
{
    flag=true;
}

listeforme& forme::gett()
{
    return t;
}
