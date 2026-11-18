
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "fila.h"
#include "pilha.h"
#include "hash.h"
#include "ordenacao.h"

int main(void) {
    Fila* filaChamados = criarFila();
    Pilha* pilhaAcoes = criarPilha();
    TabelaHash* tabelaUsuarios = criarTabelaHash();

    int opcao;
    do {
        printf("\n=== SISTEMA HELPDESK - TI ===\n");
        printf("1. Registar Utilizador\n");
        printf("2. Inserir Chamado na Fila\n");
        printf("3. Atender Chamado\n");
        printf("4. Desfazer Ultima Acao (Pilha)\n");
        printf("5. Listar / Consultar Utilizador\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida!\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n'); // Limpar buffer

        switch(opcao) {
            case 1: {
                char mat[20], nome[50], setor[50];
                printf("Matricula: ");
                fgets(mat, 20, stdin);
                mat[strcspn(mat, "\n")] = 0;

                printf("Nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Setor: ");
                fgets(setor, 50, stdin);
                setor[strcspn(setor, "\n")] = 0;

                inserirUsuario(tabelaUsuarios, mat, nome, setor);
                printf("Utilizador registado com sucesso!\n");
                break;
            }
            case 2: {
                Chamado c;
                printf("Numero do Chamado: ");
                scanf("%d", &c.numero);
                c.status = 0; // Aberto
                printf("Prioridade (ex: 1 a 5): ");
                scanf("%d", &c.prioridade);
                while(getchar() != '\n');

                printf("Matricula do solicitante: ");
                fgets(c.matricula, 20, stdin);
                c.matricula[strcspn(c.matricula, "\n")] = 0;

                printf("Descricao do problema: ");
                fgets(c.descricao, 100, stdin);
                c.descricao[strcspn(c.descricao, "\n")] = 0;

                enfileirar(filaChamados, c);
                
                // Registar acao na pilha para desfazer
                AcaoPilha acao = {1, c.numero};
                empilhar(pilhaAcoes, acao);

                printf("Chamado enfileirado com sucesso!\n");
                break;
            }
            case 3: {
                if (filaVazia(filaChamados)) {
                    printf("Nao ha chamados na fila.\n");
                } else {
                    Chamado atendido = desenfileirar(filaChamados);
                    printf("A a tender chamado ID %d (%s)...\n", atendido.numero, atendido.descricao);
                }
                break;
            }
            case 4: {
                if (pilhaVazia(pilhaAcoes)) {
                    printf("Nenhuma acao para desfazer.\n");
                } else {
                    AcaoPilha ultima = desempilhar(pilhaAcoes);
                    printf("Acao desfeita para o chamado ID %d.\n", ultima.numeroChamado);
                }
                break;
            }
            case 5: {
                char mat[20];
                printf("Digite a matricula para consulta: ");
                fgets(mat, 20, stdin);
                mat[strcspn(mat, "\n")] = 0;

                NoHash* u = buscarUsuario(tabelaUsuarios, mat);
                if (u != NULL) {
                    printf("Utilizador Encontrado -> Nome: %s | Setor: %s\n", u->nome, u->setor);
                } else {
                    printf("Utilizador nao encontrado.\n");
                }
                break;
            }
            case 0:
                printf("A encerrar sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    liberarFila(filaChamados);
    liberarPilha(pilhaAcoes);
    liberarTabelaHash(tabelaUsuarios);

    return 0;
}
