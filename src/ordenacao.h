#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "estruturas.h"

// Ordena os chamados por prioridade decrescente (e número em caso de empate) usando Merge Sort
void mergeSortChamados(Chamado chamados[], int inicio, int fim);

// Busca binária na base de soluções pelo código
int buscaBinariaSolucao(Solucao solucoes[], int tamanho, int codigoBuscado);

#endif
