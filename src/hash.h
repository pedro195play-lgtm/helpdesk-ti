#ifndef HASH_H
#define HASH_H

#include "estruturas.h"

typedef struct NoHash {
    char matricula[20];
    char nome[50];
    char setor[50];
    struct NoHash* prox;
} NoHash;

typedef struct {
    NoHash* Tabela[TAM_HASH];
} TabelaHash;

TabelaHash* criarTabelaHash();
int funcaoHash(const char* matricula);
void inserirUsuario(TabelaHash* th, const char* matricula, const char* nome, const char* setor);
NoHash* buscarUsuario(TabelaHash* th, const char* matricula);
void liberarTabelaHash(TabelaHash* th);

#endif
