#ifndef ADJACENTE_H_INCLUDED
#define ADJACENTE_H_INCLUDED
#include "No.h"

using namespace std;

class No;
class Adjacente
{
    public:
        Adjacente(No* n, int val);
        ~Adjacente();

        int getId() { return id; }
        void setId(int val) { id = val; }
        No* getNo() { return no; }
        void setNo(No* val) { no = val; }
        Adjacente* getProx() { return prox; }
        void setProx(Adjacente* val) { prox = val; }

    protected:

    private:
        int id;
        No* no;
        Adjacente* prox;
};

#endif // ADJACENTE_H_INCLUDED
