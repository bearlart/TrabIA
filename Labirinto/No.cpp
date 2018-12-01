#include "No.h"

No::No(int indice)
{
    id = indice;
    arestaAbaixo = false;
    arestaAcima = false;
    arestaDireita = false;
    arestaEsquerda = false;
    visitado = false;
}

No::~No()
{
    //dtor
}
