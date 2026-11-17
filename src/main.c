
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int opcao;

    do {
        printf("\n================================\n");
        printf("       SISTEMA HELPDESK TI\n");
        printf("================================\n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Abrir chamado\n");
        printf("3 - Atender proximo chamado\n");
        printf("4 - Fechar chamado\n");
        printf("5 - Desfazer ultima acao\n");
        printf("6 - Consultar base de solucoes\n");
        printf("7 - Gerar relatorio\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            return 1;
        }

        switch (opcao) {
            case 1:
                printf("Cadastro de usuario selecionado.\n");
                break;
            case 2:
                printf("Abertura de chamado selecionada.\n");
                break;
            case 3:
                printf("Atendimento selecionado.\n");
                break;
            case 4:
                printf("Fechamento de chamado selecionado.\n");
                break;
            case 5:
                printf("Desfazer acao selecionado.\n");
                break;
            case 6:
                printf("Consulta de solucoes selecionada.\n");
                break;
            case 7:
                printf("Relatorio selecionado.\n");
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
