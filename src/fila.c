
#include <stdlib.h>
#include "fila.h"

int fila_vazia(const Fila *fila) {
    return fila == NULL || fila->inicio == NULL;
}

int enfileirar(Fila *fila, const Chamado *chamado) {
    if (fila == NULL || chamado == NULL) {
        return 0;
    }

    Chamado *novo = malloc(sizeof(Chamado));

    if (novo == NULL) {
        return 0;
    }

    *novo = *chamado;
    novo->proximo = NULL;

    if (fila_vazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }

    fila->fim = novo;
    return 1;
}

int desenfileirar(Fila *fila, Chamado *resultado) {
    if (fila_vazia(fila) || resultado == NULL) {
        return 0;
    }

    Chamado *removido = fila->inicio;
    *resultado = *removido;

    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);
    return 1;
}

void liberar_fila(Fila *fila) {
    if (fila == NULL) {
        return;
    }

    Chamado *atual = fila->inicio;

    while (atual != NULL) {
        Chamado *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
}
