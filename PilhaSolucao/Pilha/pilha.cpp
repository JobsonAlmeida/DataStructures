#include <iostream>
#include "pilha.h"

using namespace std;

//contrutora
pilha::pilha() {
    tamanho = 0;
    estrutura = new TipoItem[max_items];
}

//destrutora
pilha::~pilha() {
    delete[] estrutura;
}

//verifica se a pilha est� cheia
bool pilha::estacheia() {
    return (tamanho == max_items);
}

//verifica se a pilha est� vazia
bool pilha::estavazia() {
    return (tamanho == 0);
}

void pilha::inserir(TipoItem item) {
    if (estacheia()) {
        cout << "A pilha est� cheia!\n";
        cout << "N�o � poss�vel inserir este elemento!\n";
    }
    else {
        estrutura[tamanho] = item;
        tamanho++;
    }

}

TipoItem pilha::remover() {

    if (estavazia()) {
        cout << "A pilha est� vazia!";
        cout << "N�o tem elemento para ser removido!";
        return 0;
    }
    else {
        tamanho--;
        return estrutura[tamanho];
    }
}

void pilha::imprimir() {

    cout << "Pilha: [ ";
    for (int i = 0; i < tamanho; i++) {
        cout << estrutura[i] << " ";
    }
    cout << "]\n\n";
}

int pilha::qualtamanho() {
    return tamanho;
}


