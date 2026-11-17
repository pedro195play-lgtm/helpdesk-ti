#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        exit(1);
    }
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void empilhar(Pilha* p, AcaoPilha acao) {
    NoPilha* novo = (NoPilha*) malloc(sizeof(NoPilha));
    if (novo == NULL) {
        exit(1);
    }
    novo->dado = acao;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

AcaoPilha desempilhar(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    NoPilha* temp = p->topo;
    AcaoPilha acao = temp->dado;
    p->topo = temp->prox;
    free(temp);
    p->tamanho--;
    return acao;
}

int pilhaVazia(Pilha* p) {
    return p->topo == NULL;
}

void liberarPilha(Pilha* p) {
    while (!pilhaVazia(p)) {
        desempilhar(p);
    }
    free(p);
}
