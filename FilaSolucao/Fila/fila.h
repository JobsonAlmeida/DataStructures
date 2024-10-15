#pragma once

//fila = queue

typedef int TipoItem;
const int max_itens = 5;

class fila {
private:
    int primeiro, ultimo;
    TipoItem* estrutura;

public:
    fila();
    ~fila();
    bool estavazio();
    bool estacheio();
    void inserir(TipoItem item); //push enqueue
    TipoItem remover(); //pop //dequeue
    void imprimir();
};