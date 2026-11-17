
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define TAM_HASH 101

typedef enum {
    ABERTO,
    EM_ATENDIMENTO,
    FECHADO
} StatusChamado;

typedef struct Usuario {
    char matricula[20];
    char nome[80];
    char setor[60];
    struct Usuario *proximo;
} Usuario;

typedef struct Chamado {
    int numero;
    char matricula[20];
    char categoria[30];
    int prioridade;
    char descricao[200];
    char solucao[300];
    StatusChamado status;
    struct Chamado *proximo;
} Chamado;

typedef struct {
    Chamado *inicio;
    Chamado *fim;
} Fila;

typedef struct Acao {
    int tipo;
    Chamado chamado;
    struct Acao *proximo;
} Acao;

typedef struct {
    Acao *topo;
} Pilha;

typedef struct {
    int codigo;
    char titulo[100];
    char procedimento[300];
} Solucao;

#endif
