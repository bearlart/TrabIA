#include "Matriz.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Matriz::Matriz(int m, int n)
{
    numLinhas = m;
    numColunas = n;

    ///Criação dos nós sem arestas
    for(int i=0; i<numLinhas*numColunas; i++){
        listaNo.push_back(new No(i));
    }

    ///Adicionando as arestas manualmente
    ///Seguindo o modelo do slide 76 da unidade 1
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

    ///Adicionando nó inicio e fim manualmente
    inicio = listaNo.at(11);
    fim = listaNo.at(9);
}

Matriz::~Matriz() { }

void Matriz::adicionaAresta(int id1, int id2)
{
    listaAresta.push_back(new Aresta(listaNo.at(id1),listaNo.at(id2)));
    if(id1 < id2){
        if(id2-id1 < numColunas){
            listaNo.at(id1)->setArestaDireita(true);
            listaNo.at(id2)->setArestaEsquerda(true);
        } else {
            listaNo.at(id1)->setArestaAbaixo(true);
            listaNo.at(id2)->setArestaAcima(true);
        }
    } else if(id1 > id2){
        if(id1-id2 < numColunas){
            listaNo.at(id1)->setArestaEsquerda(true);
            listaNo.at(id2)->setArestaDireita(true);
        } else {
            listaNo.at(id1)->setArestaAcima(true);
            listaNo.at(id2)->setArestaAbaixo(true);
        }
    }
}

Aresta* Matriz::buscaAresta(No* ant, No* prox){
    for(int i=0; i<listaAresta.size(); i++){
        if((listaAresta.at(i)->getNoAnt() == ant) && (listaAresta.at(i)->getNoProx() == prox))
            return listaAresta.at(i);
        if((listaAresta.at(i)->getNoAnt() == prox) && (listaAresta.at(i)->getNoProx() == ant))
            return listaAresta.at(i);
    }
    return NULL;
}

No* Matriz::consulta(int linha, int coluna)
{
    int k = determinaId(linha, coluna);
    if(k != -1)
        return listaNo.at(k);
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
                cout << listaNo.at(determinaId(i,j))->getId() << ".";
            else
                cout << listaNo.at(determinaId(i,j))->getId() << ", \t";
        }
        cout << endl;
    }
}

void Matriz::backtracking()
{
    defineRegrasBackTracking();
    vector<int> caminho;
    No* aux;
    No* no = inicio;
    bool fracasso = false;
    bool sucesso = false;

    caminho.push_back(no->getId());
    while(!(sucesso || fracasso)){
        no->setVisitado(true);
        if(no->regras.size() != 0){
            aux = no->regras.back();
            no->regras.pop_back();
            if(((no == inicio) || (aux != no->getPai()))&&(!aux->getVisitado())){
                aux->setPai(no);
                no = aux;
                caminho.push_back(no->getId());
            }
            if(no == fim){
                sucesso = true;
            }
        } else {
            if(no == inicio){
                fracasso = true;
            } else {
                no = no->getPai();
                caminho.push_back(no->getId());
            }
        }
    }

    for(int i=0; i<caminho.size(); i++){
        cout << caminho.at(i) << " - ";
    }
}

void Matriz::defineRegrasBackTracking(){
    for(int i=0; i<listaNo.size(); i++){
        if(listaNo.at(i)->getArestaEsquerda())
            listaNo.at(i)->regras.push_back(listaNo.at(listaNo.at(i)->getId() - 1));
        if(listaNo.at(i)->getArestaAbaixo())
            listaNo.at(i)->regras.push_back(listaNo.at(listaNo.at(i)->getId() + numColunas));
        if(listaNo.at(i)->getArestaDireita())
            listaNo.at(i)->regras.push_back(listaNo.at(listaNo.at(i)->getId() + 1));
        if(listaNo.at(i)->getArestaAcima())
            listaNo.at(i)->regras.push_back(listaNo.at(listaNo.at(i)->getId() - numColunas));
    }
}
