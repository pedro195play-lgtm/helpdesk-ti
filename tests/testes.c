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

    Chamado c1;
    c1.numero = 1;
    c1.status = 0;
    c1.prioridade = 3;
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

    liberarPilha(p);
    printf("Testes da Pilha passaram com sucesso!\n");
}

void testarHash() {
    printf("Executando testes da Tabela Hash...\n");
    TabelaHash* th = criarTabelaHash();

    // Busca com chave ausente
    assert(buscarUsuario(th, "99999999") == NULL);

    // Inserção e consulta
    inserirUsuario(th, "20231045", "Ana Souza", "Redes");
    NoHash* u = buscarUsuario(th, "20231045");
    assert(u != NULL);
    assert(strcmp(u->nome, "Ana Souza") == 0);

    liberarTabelaHash(th);
    printf("Testes da Tabela Hash passaram com sucesso!\n");
}

void testarOrdenacaoEBusca() {
    printf("Executando testes de Ordenação e Busca Binária...\n");
    
    // Teste de ordenação (Merge Sort por prioridade decrescente)
    Chamado vetor[3] = {
        {1, 0, 2, "1", "Desc 1"},
        {2, 0, 5, "2", "Desc 2"},
        {3, 0, 1, "3", "Desc 3"}
    };
    mergeSortChamados(vetor, 0, 2);
    assert(vetor[0].prioridade == 5); // Maior prioridade primeiro
    assert(vetor[1].prioridade == 2);
    assert(vetor[2].prioridade == 1);

    // Teste de Busca Binária em Soluções
    Solucao solucoes[3] = {
        {10, "Erro 10", "Proc 1"},
        {20, "Erro 20", "Proc 2"},
        {30, "Erro 30", "Proc 3"}
    };
    int pos = buscaBinariaSolucao(solucoes, 3, 20);
    assert(pos == 1); // Encontrado no índice 1

    int posInexistente = buscaBinariaSolucao(solucoes, 3, 99);
    assert(posInexistente == -1); // Não encontrado

    printf("Testes de Ordenação e Busca Binária passaram com sucesso!\n");
}

int main(void) {
    printf("=== INICIANDO TESTES AUTOMATIZADOS ===\n");
    testarFila();
    testarPilha();
    testarHash();
    testarOrdenacaoEBusca();
    printf("=== TODOS OS TESTES PASSARAM COM SUCESSO! ===\n");
    return 0;
}
