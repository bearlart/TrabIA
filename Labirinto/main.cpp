#include <iostream>
#include "Matriz.h"

using namespace std;

int exibeMenu(Matriz* labirinto);

int main()
{
    //--------------------------------------------------- MENU --------------------------------------------------
    /*int menu;
    do menu = exibeMenu(labirinto);
    while(menu>=1 && menu<=7);*/
    //--------------------------------------------------- MENU --------------------------------------------------

    //delete labirinto; //Desalocar labirinto
    return 0;
}

/*int exibeMenu(Grafo* labirinto)
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
        labirinto->backtracking();
        break;
    case 2:
        labirinto->buscaLargura();
        break;
    case 3:
        labirinto->buscaProfundidade();
        break;
    case 4:
        labirinto->buscaOrdenada();
        break;
    case 5:
        labirinto->buscaGulosa();
        break;
    case 6:
        labirinto->buscaA();
        break;
    case 7:
        labirinto->buscaIDA();
        break;
    default: break;
    }
    return opMenu;
}*/
