#ifndef FORME_H_INCLUDED
#define FORME_H_INCLUDED

#include "listeforme.h"

class forme
{
    protected :
        static listeforme t;
        static bool flag;
    public :
        forme();
        virtual ~forme();
        virtual void affiche()=0;
        virtual bool selection(float,float)=0;
        void bloque();
        void debloque();
        static listeforme& gett();
};

#endif // FORME_H_INCLUDED
