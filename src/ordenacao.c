#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

// Função auxiliar para o Merge Sort de Chamados
void merge(Chamado chamados[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Chamado* esquerda = (Chamado*) malloc(n1 * sizeof(Chamado));
    Chamado* direita = (Chamado*) malloc(n2 * sizeof(Chamado));

    for (int i = 0; i < n1; i++) esquerda[i] = chamados[inicio + i];
    for (int j = 0; j < n2; j++) direita[j] = chamados[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        // Critério: Prioridade decrescente; se empatar, menor número de chamado primeiro
        if (esquerda[i].prioridade > direita[j].prioridade || 
           (esquerda[i].prioridade == direita[j].prioridade && esquerda[i].numero < direita[j].numero)) {
            chamados[k++] = esquerda[i++];
        } else {
            chamados[k++] = direita[j++];
        }
    }

    while (i < n1) chamados[k++] = esquerda[i++];
    while (j < n2) chamados[k++] = direita[j++];

    free(esquerda);
    free(direita);
}

void mergeSortChamados(Chamado chamados[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSortChamados(chamados, inicio, meio);
        mergeSortChamados(chamados, meio + 1, fim);
        merge(chamados, inicio, meio, fim);
    }
}

// Busca binária na base de soluções
int buscaBinariaSolucao(Solucao solucoes[], int tamanho, int codigoBuscado) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (solucoes[meio].codigo == codigoBuscado) {
            return meio; // Retorna o índice onde encontrou
        }
        if (solucoes[meio].codigo < codigoBuscado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Não encontrado
}
