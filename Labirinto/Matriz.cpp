#include "Matriz.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Matriz::Matriz(int m, int n)
{
    numLinhas = m;
    numColunas = n;

    ///Criação dos nós sem arestas
    for(int i=0; i<numLinhas; i++)
    {
        for(int j=0; j<numColunas; j++)
        {
            atribui(i,j,new No(i+j));
        }
    }
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
            if(i==numLinhas-1 && j==numColunas-1)
                cout << vetor[determinaId(i,j)] << ".";
            else
                cout << vetor[determinaId(i,j)] << ", \t";
        }
        cout << endl;
    }
}
