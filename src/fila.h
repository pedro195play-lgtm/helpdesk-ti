#ifndef FILA_H
#define FILA_H

#include "estruturas.h"

Fila* criarFila();
int filaVazia(Fila* f);
void enfileirar(Fila* f, Chamado c);
Chamado desenfileirar(Fila* f);
void liberarFila(Fila* f);

#endif
