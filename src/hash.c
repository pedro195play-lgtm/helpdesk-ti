#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

TabelaHash* criarTabelaHash() {
    TabelaHash* th = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (th == NULL) exit(1);
    for (int i = 0; i < TAM_HASH; i++) {
        th->tabela[i] = NULL;
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
    int indice = funcaoHash(matricula);
    
    // Verificar se já existe
    NoHash* atual = th->tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->matricula, matricula) == 0) {
            strcpy(atual->nome, nome);
            strcpy(atual->setor, setor);
            return;
        }
        atual = atual->prox;
    }
    
    // Inserir no início da lista (tratamento de colisão por encadeamento)
    NoHash* novo = (NoHash*) malloc(sizeof(NoHash));
    if (novo == NULL) exit(1);
    strcpy(novo->matricula, matricula);
    strcpy(novo->nome, nome);
    strcpy(novo->setor, setor);
    novo->prox = th->tabela[indice];
    th->tabela[indice] = novo;
}

NoHash* buscarUsuario(TabelaHash* th, const char* matricula) {
    int indice = funcaoHash(matricula);
    NoHash* atual = th->tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->matricula, matricula) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void liberarTabelaHash(TabelaHash* th) {
    for (int i = 0; i < TAM_HASH; i++) {
        NoHash* atual = th->tabela[i];
        while (atual != NULL) {
            NoHash* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(th);
}
