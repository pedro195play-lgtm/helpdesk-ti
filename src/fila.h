
#ifndef FILA_H
#define FILA_H

#include "estruturas.h"

int fila_vazia(const Fila *fila);
int enfileirar(Fila *fila, const Chamado *chamado);
int desenfileirar(Fila *fila, Chamado *resultado);
void liberar_fila(Fila *fila);

#endif
