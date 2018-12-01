#include "No.h"

No::No(int id)
{
    id = id;
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
