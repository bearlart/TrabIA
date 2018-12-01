#include "Matriz.h"

Matriz::Matriz(int m, int n)
{
    numLinhas = m;
    numColunas = n;
    vetor = new No[numLinhas*numColunas];
}

Matriz::~Matriz()
{
    delete [] vetor;
}

No* Matriz::consulta(int linha, int coluna)
{
    int k = determinaId(linha, coluna);
    if(k != -1)
        return vetor[k];
    else
    {
        cout << "Indice invalido!" << endl;
        exit(1);
    }
}

int Matriz::determinaId(int linha, int coluna)
{
    if(linha >= 0 && linha < numLinhas && coluna >= 0 && coluna < numColunas)
        return numColunas*linha + coluna;
    else
        return -1;
}

void Matriz::imprime()
{
    for(int i=0; i<numLinhas; i++)
    {
        for(int j=0; j<numColunas; j++)
        {
            if(i==nl-1 && j==nc-1)
                cout << vetor[detInd(i,j)] << ".";
            else
                cout << vetor[detInd(i,j)] << ", \t";
        }
        cout << endl;
    }
}
