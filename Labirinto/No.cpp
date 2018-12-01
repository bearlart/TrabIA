#include "No.h"

No::No(int id, bool acima, bool abaixo, bool esquerda, bool direita)
{
    id = id;
    arestaAbaixo = abaixo;
    arestaAcima = acima;
    arestaDireita = direita;
    arestaEsquerda = esquerda;
    visitado = false;
}

No::~No()
{
    //dtor
}
