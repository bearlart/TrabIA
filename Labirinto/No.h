#ifndef NO_H
#define NO_H


class No
{
    public:
        No(int id);
        No() { }
        ~No();

        int getId() { return id; }
        void setId(int val) { id = val; }
        bool getArestaAcima() { return arestaAcima; }
        void setArestaAcima(bool acima) { arestaAcima = acima; }
        bool getArestaAbaixo() { return arestaAbaixo; }
        void setArestaAbaixo(bool abaixo) { arestaAbaixo = abaixo; }
        bool getArestaEsquerda() { return arestaEsquerda; }
        void setArestaEsquerda(bool esquerda) { arestaEsquerda = esquerda; }
        bool getArestaDireita() { return arestaDireita; }
        void setArestaDireita(bool direita) { arestaDireita = direita; }
        bool getVisitado() { return visitado; }
        void setVisitado(bool val) { visitado = val; }

    protected:

    private:
        int id;
        bool arestaAcima;
        bool arestaAbaixo;
        bool arestaEsquerda;
        bool arestaDireita;
        bool visitado;
};

#endif // NO_H
