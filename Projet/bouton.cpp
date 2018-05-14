#include <iostream>
#include <string.h>
#include <list>
#include <allegro.h>

#include "bouton.h"

using namespace std;

extern BITMAP *page;

bouton::bouton(float x1, float y1, float x2, float y2, int coul, char* pch) : r(x1,y1,x2,y2,coul),ch(pch)
{
    t.supprime(&r);
}

bouton::bouton(point pp1, point pp2, int coul, char* pch) : r(pp1,pp2,coul),ch(pch)
{
    t.supprime(&r);
}

bouton::bouton(rectangle pr, string ps) : r(pr),ch(ps)
{
    t.supprime(&r);
}

bouton::~bouton()
{
}

void bouton::affiche()
{
    float x1,y1,x2,y2,xmil,ymil;
    r.affiche();
    r.getp1p2(&x1,&y1,&x2,&y2);
    xmil=(x1+x2)/2;
    ymil=(y1+y2)/2;
    text_mode(-1);
    textprintf_centre(page,font,xmil,ymil,makecol(100,180,0),"%s",ch.c_str());
}

bool bouton::selection(float sx, float sy)
{
    return r.selection(sx,sy);
}
