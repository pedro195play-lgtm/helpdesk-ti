#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criarFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

int filaVazia(Fila* f) {
    if (f == NULL) return 1;
    return (f->inicio == NULL);
}

void enfileirar(Fila* f, Chamado c) {
    if (f == NULL) return;
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));
    if (novo == NULL) return;

    novo->dado = c;
    novo->prox = NULL;

    if (filaVazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->tamanho++;
}

Chamado desenfileirar(Fila* f) {
    Chamado vazio = {0, 0, 0, "", ""};
    if (f == NULL || filaVazia(f)) return vazio;

    NoFila* temp = f->inicio;
    Chamado c = temp->dado;

    f->inicio = temp->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    f->tamanho--;

    return c;
}

void liberarFila(Fila* f) {
    if (f == NULL) return;
    while (!filaVazia(f)) {
        desenfileirar(f);
    }
    free(f);
}
