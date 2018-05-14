#include <iostream>
#include <string.h>
#include <list>

#include "listeforme.h"
#include "forme.h"

using namespace std;

int listeforme::nbElems = 0;

listeforme::listeforme()
{}

listeforme::~listeforme()
{}

void listeforme::ajoute(forme* p)
{
    l.push_back(p);
    nbElems++;
}

void listeforme::supprime(forme* p)
{
    l.remove(p);
    nbElems--;
}

void listeforme::affiche()
{
    for(it=l.begin();it!=l.end();it++)
    {
        (*it)->affiche();
    }
}

forme* listeforme::selection(float sx,float sy)
{
    for(it=l.begin();it!=l.end();it++)
    {
        if( (*it)->selection(sx,sy) )
            return (*it);
    }
    return NULL;
}

int listeforme::getnb()
{
    return nbElems;
}

