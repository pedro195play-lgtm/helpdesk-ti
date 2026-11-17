#ifndef PILHA_H
#define PILHA_H

#include "estruturas.h"

// Exemplo de estrutura de ação para a pilha de desfazer
typedef struct {
    int tipoAcao; // 1: Abrir, 2: Atender, 3: Fechar
    int numeroChamado;
    // Outros dados necessários para reverter a ação
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
