#include <iostream>
#include "Grafo.h"
#include "Aresta.h"

using namespace std;

int exibeMenu(Grafo* grafo);

int main()
{
    //--------------------------------------------------- MENU --------------------------------------------------
    /*int menu;
    do menu = exibeMenu(grafo);
    while(menu>=1 && menu<=7);*/
    //--------------------------------------------------- MENU --------------------------------------------------

    //delete grafo; //Desalocar grafo
    return 0;
}

/*int exibeMenu(Grafo* grafo)
{
    int opMenu;
    cout << "------------------ MENU ------------------" << endl;
    cout << "1- Backtracking" << endl;
    cout << "2- Busca em largura" << endl;
    cout << "3- Busca em profundidade" << endl;
    cout << "4- Busca Ordenada" << endl;
    cout << "5- Busca Gulosa" << endl;
    cout << "6- Busca A*" << endl;
    cout << "7- Busca IDA*" << endl;
    cout << "0 ou outro- Sair" << endl;
    cout << "Opcao: ";
    cin >> opMenu;
    system("cls");

    switch (opMenu)
    {
    case 1:
        grafo->backtracking();
        break;
    case 2:
        grafo->buscaLargura();
        break;
    case 3:
        grafo->buscaProfundidade();
        break;
    case 4:
        grafo->buscaOrdenada();
        break;
    case 5:
        grafo->buscaGulosa();
        break;
    case 6:
        grafo->buscaA();
        break;
    case 7:
        grafo->buscaIDA();
        break;
    default: break;
    }
    return opMenu;
}*/
