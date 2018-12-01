#ifndef MATRIZ_H
#define MATRIZ_H

#include "No.h"

#define X 4
#define Y 3

class Matriz
{
    public:
        Matriz(int m, int n);
        ~Matriz();

        No** vetor;

        No* consulta(int linha, int coluna);
        int determinaId(int linha, int coluna);
        void imprime();

    protected:

    private:
        No* inicio;
        No* fim;
        int numLinhas;
        int numColunas;
};

#endif // MATRIZ_H
