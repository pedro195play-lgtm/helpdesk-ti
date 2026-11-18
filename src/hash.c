#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

TabelaHash* criarTabelaHash() {
    TabelaHash* th = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (th != NULL) {
        for (int i = 0; i < TAM_HASH; i++) {
            th->Tabela[i] = NULL;
        }
    }
    return th;
}

int funcaoHash(const char* matricula) {
    int soma = 0;
    for (int i = 0; matricula[i] != '\0'; i++) {
        soma += matricula[i];
    }
    return soma % TAM_HASH;
}

void inserirUsuario(TabelaHash* th, const char* matricula, const char* nome, const char* setor) {
    if (th == NULL) return;
    int indice = funcaoHash(matricula);

    NoHash* novo = (NoHash*) malloc(sizeof(NoHash));
    if (novo == NULL) return;

    strcpy(novo->matricula, matricula);
    strcpy(novo->nome, nome);
    strcpy(novo->setor, setor);
    novo->prox = th->Tabela[indice];
    th->Tabela[indice] = novo;
}

NoHash* buscarUsuario(TabelaHash* th, const char* matricula) {
    if (th == NULL) return NULL;
    int indice = funcaoHash(matricula);

    NoHash* atual = th->Tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->matricula, matricula) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void liberarTabelaHash(TabelaHash* th) {
    if (th == NULL) return;
    for (int i = 0; i < TAM_HASH; i++) {
        NoHash* atual = th->Tabela[i];
        while (atual != NULL) {
            NoHash* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(th);
}
