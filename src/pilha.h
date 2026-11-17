#ifndef PILHA_H
#define PILHA_H

#include "estruturas.h"


typedef struct {
    int tipoAcao; 
    int numeroChamado;
} AcaoPilha;

typedef struct NoPilha {
    AcaoPilha dado;
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
    int tamanho;
} Pilha;

Pilha* criarPilha();
void empilhar(Pilha* p, AcaoPilha acao);
AcaoPilha desempilhar(Pilha* p);
int pilhaVazia(Pilha* p);
void liberarPilha(Pilha* p);

#endif
