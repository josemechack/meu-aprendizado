/*
    José Mechack
    Projecto: EDITOR DE TEXTOS.
    Data de finalização: 7/12/2024.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_vetor 2000
#define MAX_TEXTOS 2000
typedef struct {
    char textoVazio[MAX_vetor];
    char nomeTexto[100];
} editor;

int main() {
    editor texto[MAX_TEXTOS];
    int Quantchar = 0, opcao, alteracao;

    FILE *informacaoTextoDocumento = fopen("JoseM.dat", "r");
    if (informacaoTextoDocumento) {
        while (fscanf(informacaoTextoDocumento, " %[^\n]s", texto[Quantchar].nomeTexto) == 1) {
            fscanf(informacaoTextoDocumento, " %[^\n]s", texto[Quantchar].textoVazio);
            Quantchar++;
        }
        fclose(informacaoTextoDocumento);
    }

    while (true) {
        puts("################################################################################");
        printf("\t\t\tEDITOR DE TEXTO DO MUKONGO\n################################################################################\n");
        puts("- Criar um novo texto [1]");
        puts("- Editar texto [2]");
        puts("- Ver textos [3]");
        puts("- Buscar textos [4]");
        puts("- excluir textos [5]");
        puts("- Sair [6]");
        printf("\n> ");
        scanf("%d", &opcao);
        getchar();
        system("clear");

        switch (opcao) {
            case 1:
                if (Quantchar < MAX_TEXTOS) {
                    printf("Título do texto\n> ");
                    fgets(texto[Quantchar].nomeTexto, sizeof(texto[Quantchar].nomeTexto), stdin);
                    texto[Quantchar].nomeTexto[strcspn(texto[Quantchar].nomeTexto, "\n")] = 0; // Remover '\n'

                    printf("\nEscreva seu texto. Pressione Enter duas vezes para finalizar.\n");
                    char linha[200];
                    texto[Quantchar].textoVazio[0] = '\0';

                    while (true) {
                        printf("> ");
                        fgets(linha, sizeof(linha), stdin);
                        if (linha[0] == '\n') {
                            break;
                        }
                        strcat(texto[Quantchar].textoVazio, linha);
                    }
                    Quantchar++;
                    system("clear");
                } else {
                    printf("Atingiu o limite de textos!\n");
                    system("clear");
                }
                break;
            case 2:
            char linha[200];
                if (Quantchar == 0) {
                    printf("Não há textos para editar.\n");
                    break;
                }
                printf("Escolha o texto a ser editado:\n");
                for (int i = 0; i < Quantchar; i++) {
                    printf("%d - %s\n", i + 1, texto[i].nomeTexto);
                }
                printf("> ");
                scanf("%d", &alteracao);
                getchar();
                alteracao--;
                system("clear");
                if (alteracao < 0 || alteracao >= Quantchar) {
                    printf("Opção inválida!\n");
                    break;
                }
                printf("Digite o novo nome para o documento: ");
                fgets(texto[alteracao].nomeTexto, sizeof(texto[alteracao].nomeTexto), stdin);
                texto[alteracao].nomeTexto[strcspn(texto[alteracao].nomeTexto, "\n")] = 0;
                printf("Digite o novo conteúdo do texto. Pressione Enter duas vezes para finalizar.\n");
                texto[alteracao].textoVazio[0] = '\0';

                while (true) {
                    printf("> ");
                    fgets(linha, sizeof(linha), stdin);
                    if (linha[0] == '\n') {
                        break;
                    }
                    strcat(texto[alteracao].textoVazio, linha);
                }
                system("clear");
                break;
            case 3:
                if (Quantchar == 0) {
                    printf("Não há textos para visualizar.\n");
                    break;
                }
                printf("Textos salvos:\n");
                for (int i = 0; i < Quantchar; i++) {
                    printf("%d - %s\n", i + 1, texto[i].nomeTexto);
                }
                printf("Digite o número do texto para visualizar seu conteúdo: ");
                scanf("%d", &alteracao);
                getchar();
                alteracao--;

                if (alteracao < 0 || alteracao >= Quantchar) {
                    printf("Texto não encontrado!\n");
                    break;
                }
                system("clear");
                printf("Conteúdo do texto:\n%s\n\n", texto[alteracao].textoVazio);
                break;
            case 4:
                char termoBusca[100];
                int encontrados = 0;
                if (Quantchar == 0) {
                     printf("Não há textos para buscar.\n");
                    break;
                }

                printf("Digite o termo de busca: ");
                fgets(termoBusca, sizeof(termoBusca), stdin);
                termoBusca[strcspn(termoBusca, "\n")] = 0;

                printf("Resultados da busca:\n");
                for (int i = 0; i < Quantchar; i++) {
                    if (strstr(texto[i].nomeTexto, termoBusca)) {
                        printf("%d - %s\n", i + 1, texto[i].nomeTexto);
                        encontrados++;
                    }

                }
                if (encontrados == 0) {
                    printf("Nenhum texto encontrado com o termo '%s'.\n\n", termoBusca);
                }

                break;
            case 5:
                if (Quantchar == 0) {
                    printf("Não há textos para excluir.\n");
                    break;
                }
                printf("Escolha o texto a ser excluído:\n");
                for (int i = 0; i < Quantchar; i++) {
                    printf("%d - %s\n", i + 1, texto[i].nomeTexto);
                }
                printf("> ");
                scanf("%d", &alteracao);
                getchar();
                alteracao--;
                system("clear");

                if (alteracao < 0 || alteracao >= Quantchar) {
                    printf("Opção inválida!\n");
                    break;
                }

                for (int i = alteracao; i < Quantchar - 1; i++) {
                    texto[i] = texto[i + 1];
                }
                Quantchar--;
                printf("Texto excluído com sucesso.\n");
                break;

            case 6:
                FILE *informacaoTextoDocumento = fopen("JoseM.dat", "w");
                if (informacaoTextoDocumento) {
                    for (int i = 0; i < Quantchar; i++) {
                        fprintf(informacaoTextoDocumento, "%s\n", texto[i].nomeTexto);
                        fprintf(informacaoTextoDocumento, "%s\n", texto[i].textoVazio);
                    }
                    fclose(informacaoTextoDocumento);
                }
                printf("Saindo do editor. Até a próxima!\n");
                exit("EXIT_FAILURE");
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
    return 0;
}
