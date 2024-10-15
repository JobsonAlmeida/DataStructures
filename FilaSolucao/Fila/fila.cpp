#include <iostream>
#include "fila.h"

using namespace std;

fila::fila() {
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[max_itens];
}

fila::~fila() {
    delete[] estrutura;
}

bool fila::estavazio() { //isempty
    return (primeiro == ultimo);
}

bool fila::estacheio() {//insfull
    return ((ultimo - primeiro) == max_itens);
}

//push enqueue
void fila::inserir(TipoItem item) {

    //verifying if the queue is full
    if (estacheio()) {
        cout << "A fila está cheia. Impossível inserir!\n";
    }
    else {
        estrutura[(ultimo % max_itens)] = item;
        ultimo++;
    }

}

//pop //dequeue
TipoItem fila::remover() {

    //verifying if the queue is empty
    if (estavazio()) {
        cout << "A fila está vazia! Impossível remover!\n";
        return -1;
    }
    else {
        TipoItem item_removido = estrutura[primeiro % max_itens];
        primeiro++;
        return item_removido;
    }

}

void fila::imprimir() {

    int primeiro_aux = primeiro;

    cout << "[ ";

    while ((primeiro_aux < ultimo)) {
        cout << estrutura[primeiro_aux%max_itens] << " ";
        primeiro_aux++;
    }

    cout << "]\n";

}