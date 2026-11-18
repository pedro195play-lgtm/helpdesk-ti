
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "fila.h"
#include "pilha.h"
#include "hash.h"
#include "ordenacao.h"

// Exemplo de base de soluções inicial para busca binária (pelo menos 15 itens ordenados por código)
Solucao baseSolucoes[15] = {
    {10, "Erro de Conexao", "Reinicie o roteador e verifique o cabo de rede."},
    {20, "Wi-Fi Nao Conecta", "Esqueca a rede e insira a senha novamente."},
    {30, "Projetor Sem Video", "Verifique o cabo HDMI e a entrada correta."},
    {40, "Senha Bloqueada", "Solicite o reset com o administrador de rede."},
    {50, "Impressora Offline", "Remova a fila de impressao e reinicie o spooler."},
    {60, "Lentidao Geral", "Feche programas pesados e verifique o uso de memoria."},
    {70, "Erro de Login", "Confirme se o Caps Lock esta desativado."},
    {80, "Mouse Nao Responde", "Troca as pilhas ou mude a porta USB."},
    {90, "Teclado Desconfigurado", "Ajuste o idioma do teclado para ABNT2."},
    {100, "Tela Azul", "Anote o codigo do erro e reinicie o computador."},
    {110, "Audio Sem Som", "Verifique o icone de volume e o dispositivo padrao."},
    {120, "Arquivo Apagado", "Recupere o arquivo da Lixeira."},
    {130, "Atualizacao Travada", "Reinicie o servico de Windows Update."},
    {140, "VPN Desconectada", "Reinsira as credenciais de acesso corporativo."},
    {150, "Sistema Lento no Boot", "Desative programas desnecessarios na inicializacao."}
};

int main(void) {
    Fila* filaChamados = criarFila();
    Pilha* pilhaAcoes = criarPilha();
    TabelaHash* usuarios = criarTabelaHash();

    // Carregar dados iniciais de exemplo (Requisito T5)
    inserirUsuario(usuarios, "20231045", "Ana Souza", "Redes");
    inserirUsuario(usuarios, "20231046", "Carlos Lima", "Suporte");
    inserirUsuario(usuarios, "20231047", "Mariana Silva", "Financeiro");

    int opcao;
    int seqChamado = 231230;

    do {
        printf("\n=== HELPDESK DE TI ===\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Abrir Chamado\n");
        printf("3. Atender Proximo Chamado\n");
        printf("4. Desfazer Ultima Acao (Undo)\n");
        printf("5. Relatorio de Chamados (Ordenados por Prioridade)\n");
        printf("6. Consultar Base de Solucoes (Busca Binaria)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1: {
                char mat[20], nome[50], setor[50];
                printf("Matricula: ");
                scanf("%s", mat);
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Setor: ");
                scanf(" %[^\n]", setor);
                inserirUsuario(usuarios, mat, nome, setor);
                printf("Usuario cadastrado com sucesso!\n");
                break;
            }
            case 2: {
                char mat[20], desc[100];
                int prioridade;
                printf("Matricula do solicitante: ");
                scanf("%s", mat);
                
                NoHash* u = buscarUsuario(usuarios, mat);
                if (u == NULL) {
                    printf("Erro: Matricula nao cadastrada!\n");
                    break;
                }

                printf("Prioridade (1 a 5): ");
                scanf("%d", &prioridade);
                if (prioridade < 1 || prioridade > 5) {
                    printf("Erro: Prioridade invalida (deve ser entre 1 e 5)!\n");
                    break;
                }

                printf("Descricao do problema: ");
                scanf(" %[^\n]", desc);

                seqChamado++;
                Chamado novoC = {seqChamado, 0, prioridade}; // status 0: aberto
                strcpy(novoC.matricula, mat);
                strcpy(novoC.descricao, desc);

                enfileirar(filaChamados, novoC);

                // Empilhar ação para o Desfazer (Tipo 1: Abrir)
                AcaoPilha acao = {1, seqChamado};
                empilhar(pilhaAcoes, acao);

                printf("Chamado #%d aberto com sucesso!\n", seqChamado);
                break;
            }
            case 3: {
                if (filaVazia(filaChamados)) {
                    printf("Erro: Nao ha chamados na fila de espera!\n");
                    break;
                }
                Chamado atendido = desenfileirar(filaChamados);
                
                // Empilhar ação (Tipo 2: Atender)
                AcaoPilha acao = {2, atendido.numero};
                empilhar(pilhaAcoes, acao);

                printf("Atendendo chamado #%d (Prioridade %d): \"%s\"\n", 
                       atendido.numero, atendido.prioridade, atendido.descricao);
                break;
            }
            case 4: {
                if (pilhaVazia(pilhaAcoes)) {
                    printf("Erro: Nao ha acoes para desfazer!\n");
                    break;
                }
                AcaoPilha ultimaAcao = desempilhar(pilhaAcoes);
                printf("Acao desfeita com sucesso para o chamado #%d (Tipo de acao: %d)\n", 
                       ultimaAcao.numeroChamado, ultimaAcao.tipoAcao);
                break;
            }
            case 5: {
                if (filaVazia(filaChamados)) {
                    printf("Fila de chamados vazia!\n");
                    break;
                }
                // Copia os elementos da fila para um vetor temporário para ordenar
                int total = filaChamados->tamanho;
                Chamado* vetorTemp = (Chamado*) malloc(total * sizeof(Chamado));
                
                No* atual = filaChamados->inicio;
                int idx = 0;
                while (atual != NULL) {
                    vetorTemp[idx++] = atual->dado;
                    atual = atual->prox;
                }

                mergeSortChamados(vetorTemp, 0, total - 1);

                printf("\n--- RELATORIO DE CHAMADOS ORDENADOS ---\n");
                for (int i = 0; i < total; i++) {
                    printf("Chamado #%d | Prioridade: %d | Solicitante: %s | Descricao: %s\n",
                           vetorTemp[i].numero, vetorTemp[i].prioridade, 
                           vetorTemp[i].matricula, vetorTemp[i].descricao);
                }
                free(vetorTemp);
                break;
            }
            case 6: {
                int cod;
                printf("Digite o codigo da solucao desejada (ex: 10, 20, 30...): ");
                scanf("%d", &cod);

                int pos = buscaBinariaSolucao(baseSolucoes, 15, cod);
                if (pos != -1) {
                    printf("\n[Encontrado]\nTitulo: %s\nProcedimento: %s\n",
                           baseSolucoes[pos].titulo, baseSolucoes[pos].procedimento);
                } else {
                    printf("Solucao nao encontrada na base.\n");
                }
                break;
            }
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    // Liberar memoria alocada
    liberarFila(filaChamados);
    liberarPilha(pilhaAcoes);
    liberarTabelaHash(usuarios);

    return 0;
}
