#pragma once


typedef  int  TipoItem;

const int max_items = 5;

class pilha {
private:

    int tamanho;
    TipoItem* estrutura;

public:
    pilha(); //contrutora
    ~pilha(); //destrutora
    bool estacheia(); //verifica se a pilha está cheia
    bool estavazia(); //verifica se a pilha está vazia
    void inserir(TipoItem item);
    TipoItem remover();
    void imprimir();
    int qualtamanho();
};