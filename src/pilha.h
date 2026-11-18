
#ifndef PILHA_H
#define PILHA_H

#include "estruturas.h"

Pilha* criarPilha();
int pilhaVazia(Pilha* p);
void empilhar(Pilha* p, AcaoPilha acao);
AcaoPilha desempilhar(Pilha* p);
void liberarPilha(Pilha* p);

#endif
