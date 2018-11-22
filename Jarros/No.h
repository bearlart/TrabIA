#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include <iostream>
#include <vector>
#include "Jarro.h"

using namespace std;

class No
{
    public:
        No(vector<Jarro*> j);
        ~No();

        vector<Jarro*> jarros;
        vector<No*> listaAdjacentes;
};

#endif // NO_H_INCLUDED
