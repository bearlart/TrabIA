#include "Grafo.h"
#include <vector>
#include <iostream>

using namespace std;

Grafo::Grafo(vector<int> j, vector<int> r)
{
    numJarros = j.size();
    capacidadeLitrosCadaJarro = j;
    resultadoEsperado = r;
    vector<Jarro*> jarrosInicio;
    for(int i=0; i<numJarros; i++) { jarrosInicio.push_back(new Jarro(0)); }
    No* raiz = new No(jarrosInicio);
    listaNo.push_back(raiz);
}

Grafo::~Grafo(){}

void Grafo::montaGrafo(No* no)
{
    imprimeNoAdjacentes();
    No* novoNo;
    No* aux;
    for(int i=0; i<numJarros; i++)
    {
        if(no->jarros.at(i)->litros == 0){
            novoNo = encheJarro(no,i);
            aux = verificaExistenciaNo(novoNo); //Verifica se nó já existe
            if(aux != NULL)
                novoNo = aux;

            Aresta* novaAresta = new Aresta(no,novoNo); //Cria aresta entre os nós

            if(!verificaExistenciaAresta(novaAresta))
                no->listaAdjacentes.push_back(novoNo);

            if(aux == NULL)
                montaGrafo(novoNo);
        }
        else{
            novoNo = esvaziaJarro(no,i);
            aux = verificaExistenciaNo(novoNo); //Verifica se nó já existe
            if(aux != NULL)
                novoNo = aux;

            Aresta* novaAresta = new Aresta(no,novoNo); //Cria aresta entre os nós

            if(!verificaExistenciaAresta(novaAresta))
                no->listaAdjacentes.push_back(novoNo);

            if(aux == NULL)
                montaGrafo(novoNo);
            for(int k=i; k<numJarros; k++)
            {
                if(no->jarros.at(k)->litros != capacidadeLitrosCadaJarro.at(k)){
                    novoNo = transfereJarro(no, i, k);
                    aux = verificaExistenciaNo(novoNo); //Verifica se nó já existe
                    if(aux != NULL)
                        novoNo = aux;

                    Aresta* novaAresta = new Aresta(no,novoNo); //Cria aresta entre os nós

                    if(!verificaExistenciaAresta(novaAresta))
                        no->listaAdjacentes.push_back(novoNo);

                    if(aux == NULL)
                        montaGrafo(novoNo);
                }
            }
        }
    }
}

No* Grafo::encheJarro(No* no, int i)
{
    No* novoNo = new No(criaCopiaListaJarros(no)); //Cria nó

    novoNo->jarros.at(i)->litros = capacidadeLitrosCadaJarro.at(i); //Enche o jarro i

    return novoNo;
}

No* Grafo::esvaziaJarro(No* no, int i)
{
    No* novoNo = new No(criaCopiaListaJarros(no)); //Cria nó

    novoNo->jarros.at(i)->litros = 0; //Esvazia o jarro i

    return novoNo;
}

No* Grafo::transfereJarro(No* no, int deNo, int paraNo)
{
    No* novoNo = new No(criaCopiaListaJarros(no));//Cria nó

    ///se a + b <= capacidade de litros de B então A=0 B=(a+b)
    ///se a + b > capacidade de litros de B então A=((a+b)-capacidade de litros de B) B=capacidade de litros de B
    if(novoNo->jarros.at(deNo)->litros + novoNo->jarros.at(paraNo)->litros <= capacidadeLitrosCadaJarro.at(paraNo)){
        novoNo->jarros.at(paraNo)->litros = novoNo->jarros.at(deNo)->litros + novoNo->jarros.at(paraNo)->litros;
        novoNo->jarros.at(deNo)->litros = 0;
    }
    else{
        novoNo->jarros.at(deNo)->litros = (novoNo->jarros.at(deNo)->litros + novoNo->jarros.at(paraNo)->litros) - capacidadeLitrosCadaJarro.at(paraNo);
        novoNo->jarros.at(paraNo)->litros = capacidadeLitrosCadaJarro.at(paraNo);
    }
    return novoNo;
}

vector<Jarro*> Grafo::criaCopiaListaJarros(No* no)
{
    vector<Jarro*> j;
    for(int l = 0; l < numJarros; l++){
        j.push_back(new Jarro(no->jarros.at(l)->litros));
    }
    return j;
}

No* Grafo::verificaExistenciaNo(No* no)
{
    for(int i=0; i<listaNo.size(); i++){
        if(listaNo.at(i)==no){
            return listaNo.at(i);
        }
    }
    listaNo.push_back(no);
    return NULL;
}

bool Grafo::verificaExistenciaAresta(Aresta* aresta)
{
    for(int i=0; i<listaAresta.size(); i++){
        if(listaAresta.at(i)==aresta){
            return true;
        }
    }
    listaAresta.push_back(aresta);
    return false;
}

void Grafo::imprimeNoAdjacentes()
{
    cout << "No|Lista de Adjacentes:"  << endl;
    No* aux;
    for(int i=0; i<listaNo.size(); i++)
    {
        aux = listaNo.at(i);
        cout << "( ";
        for(int j=0; j<numJarros; j++)
            cout << aux->jarros.at(j)->litros << ", ";
        cout << "): ";
    }
    cout << endl;
    /*
    for(int i=0; i<listaNo.size(); i++)
    {
        aux = listaNo.at(i);

        cout << "( ";
        for(int j=0; j<numJarros; j++)
            cout << aux->jarros.at(j)->litros << ", ";
        cout << "): ";

        for(int k=0; k<aux->listaAdjacentes.size(); k++){
            aux = aux->listaAdjacentes.at(k);
            cout << "( ";
            for(int l=0; l<aux->jarros.size(); l++)
                cout << aux->jarros.at(l)->litros << ", ";
            cout << "), ";
        }

        cout << endl;
    }*/
}

void Grafo::backtracking()
{
    bool sucesso = false;
    bool fracasso = false;
    char resultado;
    int i = 0;

    while(sucesso || fracasso){
        resultado = auxBacktracking(No* atual, int i);
        if(resultado == 's')
            sucesso = true;
        else if(resultado == 'f')
            fracasso == true;
        else{
            if(i < numJarros)
                i++;
            else
                fracasso == true;
        }
    }
}

char Grafo::auxBacktracking(No* atual, int i)
{
    No* novoNo, aux;
    char resultado;

    ///ENCHE JARRO
    if(atual->jarros.at(i)->litros == 0)
    {
        novoNo = encheJarro(atual,i);
        aux = verificaExistenciaNo(novoNo); //Verifica se nó já existe

        if(aux != NULL)
            (aux == listaNo.at(0))? return 'f': return 'b';

        listaNo.push_back(novoNo);
        atual->listaAdjacentes.push_back(novoNo);

        resultado = auxBacktracking(novoNo, 0);
        if(resultado = 'b')
        else if(resultado == 'f')
            return 'f';
        else if(resultado == 's')
            return 's';
    }
    else{
    ///ESVAZIA JARRO
        novoNo = esvaziaJarro(atual,i);
        aux = verificaExistenciaNo(novoNo); //Verifica se nó já existe

        if(aux != NULL)
            (aux == listaNo.at(0))? return 'f': return 'b';

        listaNo.push_back(novoNo);
        atual->listaAdjacentes.push_back(novoNo);

        resultado = auxBacktracking(novoNo, 0);
        if(resultado == 'f')
            return 'f';
        else if(resultado == 's')
            return 's';

    ///TRANSFERE JARRO
        for(int k=i; k<numJarros; k++)
        {
            if(no->jarros.at(k)->litros != capacidadeLitrosCadaJarro.at(k)){
                novoNo = transfereJarro(no, i, k);
                aux = verificaExistenciaNo(novoNo); //Verifica se nó já existe
                if(aux != NULL)
                    (aux == listaNo.at(0))? return 'f': return 'b';

                listaNo.push_back(novoNo);
                atual->listaAdjacentes.push_back(novoNo);

                resultado = auxBacktracking(novoNo, 0);
                if(resultado == 'f')
                    return 'f';
                else if(resultado == 's')
                    return 's';
            }
        }

    ///BACKTRACKING
        if(resultado == 'b')
            return 'b';
    }
}

/*void Grafo::buscaLargura()

void Grafo::buscaProfundidade()

void Grafo::buscaOrdenada()

void Grafo::buscaGulosa()

void Grafo::buscaA*()

void Grafo::buscaIDA*()*/
