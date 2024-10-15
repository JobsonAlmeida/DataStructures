# include <iostream>
#include "fila.h"

using namespace std;

int main() {

    system("chcp 65001");
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    fila fila1;

    TipoItem item;

    int opcao;

    cout << "Programa gerador de filas:\n";

    do {
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 pra imprimir a pilha\n";

        cin >> opcao;
        if (opcao == 1) {
            cout << "Digite o elemento a ser inserido: \n";
            cin >> item;
            fila1.inserir(item);
            cout << "\n";
        }
        else if (opcao == 2) {
            item = fila1.remover();
            cout << "Elemento removido: " << item << endl;
            cout << "\n";
        }
        else if (opcao == 3) {
            fila1.imprimir();
            cout << "\n";
        }
    } while (opcao != 0);


    return 0;
}