#include "No.h"
#include <iostream>

No::No(int indice)
{
    id = indice;
    arestaAbaixo = false;
    arestaAcima = false;
    arestaDireita = false;
    arestaEsquerda = false;
    visitado = false;
    pai = NULL;
}

No::~No()
{
    //dtor
}
