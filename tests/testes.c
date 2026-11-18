#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../src/estruturas.h"
#include "../src/fila.h"
#include "../src/pilha.h"
#include "../src/hash.h"
#include "../src/ordenacao.h"

void testarFila() {
    printf("Executando testes da Fila...\n");
    Fila* f = criarFila();
    assert(filaVazia(f) == 1); // Fila vazia

    Chamado c1 = {1, 0, 3};
    strcpy(c1.matricula, "20231045");
    strcpy(c1.descricao, "Teste 1");

    enfileirar(f, c1);
    assert(filaVazia(f) == 0); // Fila com um elemento
    assert(f->tamanho == 1);

    Chamado removido = desenfileirar(f);
    assert(removido.numero == 1);
    assert(filaVazia(f) == 1); // Fila vazia novamente

    liberarFila(f);
    printf("Testes da Fila passaram com sucesso!\n");
}

void testarPilha() {
    printf("Executando testes da Pilha...\n");
    Pilha* p = criarPilha();
    assert(pilhaVazia(p) == 1); // Pilha vazia

    AcaoPilha a1 = {1, 101};
    empilhar(p, a1);
    assert(pilhaVazia(p) == 0); // Pilha com um elemento

    AcaoPilha desempilhado = desempilhar(p);
    assert(desempilhado.numeroChamado == 101);
    assert(pilhaVazia(p) == 1); // Pilha vazia novamente
