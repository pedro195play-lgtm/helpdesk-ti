#ifndef HASH_H
#define HASH_H

#include "estruturas.h"

#define TAM_HASH 31 // Tamanho da tabela hash (número primo)

typedef struct NoHash {
    char matricula[20];
    char nome[50];
    char setor[50];
    struct NoHash* prox; // Tratamento de colisão por encadeamento separado
} NoHash;

typedef struct {
    NoHash* tabela[TAM_HASH];
} TabelaHash;

TabelaHash* criarTabelaHash();
int funcaoHash(const char* matricula);
void inserirUsuario(TabelaHash* th, const char* matricula, const char* nome, const char* setor);
NoHash* buscarUsuario(TabelaHash* th, const char* matricula);
void liberarTabelaHash(TabelaHash* th);

#endif
