#include "Matriz.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Matriz::Matriz(int m, int n)
{
    numLinhas = m;
    numColunas = n;

    ///Criação dos nós sem arestas
    for(int i=0; i<numLinhas*numColunas; i++)
        vetor.push_back(new No(i));

    adicionaAresta(0,1);
    adicionaAresta(0,3);
    adicionaAresta(1,4);
    adicionaAresta(2,5);
    adicionaAresta(3,4);
    adicionaAresta(3,6);
    adicionaAresta(4,5);
    adicionaAresta(4,7);
    adicionaAresta(7,8);
    adicionaAresta(8,11);
    adicionaAresta(9,10);
    adicionaAresta(10,11);
}

Matriz::~Matriz() { }

void Matriz::adicionaAresta(int id1, int id2)
{
    if(id1 < id2){
        if(id2-id1 < numColunas){
            vetor.at(id1)->setArestaDireita(true);
            vetor.at(id2)->setArestaEsquerda(true);
        } else {
            vetor.at(id1)->setArestaAbaixo(true);
            vetor.at(id2)->setArestaAcima(true);
        }
    } else if(id1 > id2){
        if(id1-id2 < numColunas){
            vetor.at(id1)->setArestaEsquerda(true);
            vetor.at(id2)->setArestaDireita(true);
        } else {
            vetor.at(id1)->setArestaAcima(true);
            vetor.at(id2)->setArestaAbaixo(true);
        }
    }
}

No* Matriz::consulta(int linha, int coluna)
{
    int k = determinaId(linha, coluna);
    if(k != -1)
        return vetor.at(k);
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
                cout << vetor.at(determinaId(i,j))->getId() << ".";
            else
                cout << vetor.at(determinaId(i,j))->getId() << ", \t";
        }
        cout << endl;
    }
}
