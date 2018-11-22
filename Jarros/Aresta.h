#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"

using namespace std;

class Aresta
{
    public:
        Aresta(No* a, No* b);
        ~Aresta();

        No *getNoAnt() { return noAnt; }
        No *getNoProx() { return noProx; }

    private:
        No *noAnt;
        No *noProx;
};

#endif // ARESTA_H_INCLUDED
