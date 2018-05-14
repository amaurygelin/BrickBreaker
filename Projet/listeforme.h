#ifndef LISTEFORME_H_INCLUDED
#define LISTEFORME_H_INCLUDED

#include <list>

class forme;

using namespace std;

class listeforme
{
    protected :
        list<forme*> l;
        list<forme*>::iterator it;
        static int nbElems;
    public :
        listeforme();
        ~listeforme();
        void ajoute(forme*);
        void supprime(forme*);
        forme* selection(float,float);
        void affiche();
        static int getnb();
};

#endif // LISTEFORME_H_INCLUDED
