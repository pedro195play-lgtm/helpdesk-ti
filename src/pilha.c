#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
        p->tamanho = 0;
    }
    return p;
}

int pilhaVazia(Pilha* p) {
    if (p == NULL) return 1;
    return (p->topo == NULL);
}

void empilhar(Pilha* p, AcaoPilha acao) {
    if (p == NULL) return;
    NoPilha* novo = (NoPilha*) malloc(sizeof(NoPilha));
    if (novo == NULL) return;
    
    novo->dado = acao;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

AcaoPilha desempilhar(Pilha* p) {
    AcaoPilha vazio = {0, 0};
    if (p == NULL || pilhaVazia(p)) return vazio;

    NoPilha* temp = p->topo;
    AcaoPilha acao = temp->dado;
    
    p->topo = temp->prox;
    free(temp);
    p->tamanho--;

    return acao;
}

void liberarPilha(Pilha* p) {
    if (p == NULL) return;
    while (!pilhaVazia(p)) {
        desempilhar(p);
    }
    free(p);
}
