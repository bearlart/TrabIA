#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <vector>
#include "No.h"
#include "Aresta.h"

using namespace std;

class Grafo
{
    public:
        Grafo(vector<int> j);
        ~Grafo();

        vector<No*> listaNo;
        vector<Aresta*> listaAresta;

        void montaGrafo(No* no);
        No* encheJarro(No* no, int i);
        No* esvaziaJarro(No* no, int i);
        No* transfereJarro(No* no, int deNo, int paraNo);
        vector<Jarro*> criaCopiaListaJarros(No* no);
        No* verificaExistenciaNo(No* no);
        bool verificaExistenciaAresta(Aresta* aresta);
        void imprimeNoAdjacentes();

        void backtracking();
        /*void buscaLargura();
        void buscaProfundidade();
        void buscaOrdenada();
        void buscaGulosa();
        void buscaA*();
        void buscaIDA*();*/

    private:
        vector<int> capacidadeLitrosCadaJarro;
        vector<int> resultadoEsperado;
        int numJarros;

};

#endif // GRAFO_H_INCLUDED
