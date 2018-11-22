#include "No.h"
#include "Adjacente.h"

using namespace std;

Adjacente::Adjacente(No* n, int val)
{
    id=val;
    no=n;
    prox=NULL;
}

Adjacente::~Adjacente()
{
    //dtor
}
