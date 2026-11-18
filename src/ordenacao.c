#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

// Função auxiliar para o Merge Sort de Chamados por prioridade (decrescente)
void intercalarChamados(Chamado v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Chamado* esquerda = (Chamado*) malloc(n1 * sizeof(Chamado));
    Chamado* direita = (Chamado*) malloc(n2 * sizeof(Chamado));

    for (int i = 0; i < n1; i++) esquerda[i] = v[inicio + i];
    for (int j = 0; j < n2; j++) direita[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (esquerda[i].prioridade >= direita[j].prioridade) {
            v[k++] = esquerda[i++];
        } else {
            v[k++] = direita[j++];
        }
    }

    while (i < n1) v[k++] = esquerda[i++];
    while (j < n2) v[k++] = direita[j++];

    free(esquerda);
    free(direita);
}

void mergeSortChamados(Chamado v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSortChamados(v, inicio, meio);
        mergeSortChamados(v, meio + 1, fim);
        intercalarChamados(v, inicio, meio, fim);
    }
}

// Busca Binária na base de soluções (por idErro)
int buscaBinariaSolucao(Solucao solucoes[], int tamanho, int codigoBuscado) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (solucoes[meio].idErro == codigoBuscado) {
            return meio; // Encontrado
        }
        if (solucoes[meio].idErro < codigoBuscado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Não encontrado
}
