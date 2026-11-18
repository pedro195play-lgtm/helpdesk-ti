
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define TAM_HASH 101

// Estrutura para os Chamados
typedef struct {
    int numero;
    int status; // 0: Aberto, 1: Atendido
    int prioridade;
    char matricula[20];
    char descricao[100];
} Chamado;

// Estrutura para os nós da Fila
typedef struct NoFila {
    Chamado dado;
    struct NoFila* prox;
} NoFila;

// Estrutura da Fila
typedef struct {
    NoFila* inicio;
    NoFila* fim;
    int tamanho;
} Fila;

// Estrutura para as Ações da Pilha (Undo)
typedef struct {
    int tipoAcao;
    int numeroChamado;
} AcaoPilha;

// Estrutura para os nós da Pilha
typedef struct NoPilha {
    AcaoPilha dado;
    struct NoPilha* prox;
} NoPilha;

// Estrutura da Pilha
typedef struct {
    NoPilha* topo;
    int tamanho;
} Pilha;

// Estrutura para Soluções (Busca Binária)
typedef struct {
    int idErro;
    char titulo[50];
    char procedimento[150];
} Solucao;

#endif
