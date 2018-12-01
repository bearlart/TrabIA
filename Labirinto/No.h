#ifndef NO_H
#define NO_H


class No
{
    public:
        No(int id, bool acima, bool abaixo, bool esquerda, bool direita);
        ~No();

        int getId() { return id; }
        void setId(int val) { id = val; }
        bool getArestaAcima() { return arestaAcima; }
        bool getArestaAbaixo() { return arestaAbaixo; }
        bool getArestaEsquerda() { return arestaEsquerda; }
        bool getArestaDireita() { return arestaDireita; }
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
