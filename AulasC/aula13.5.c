#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Função cifra de Cesar
void codificar(char str[20]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        str[i] = c + 1;
    }
}
// Função ler cifra de Cesar
void descodificar(char str[20]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        str[i] = c - 1;
    }
}

int main() {
    // Variaveis de controlo
    int opcao = -1;
    int estadoArmazem = 0;

    // Arrays de produtos
    char produtos[4][20];
    int quantidades[4];

    FILE* f;

    if ((f = fopen("armazem.txt", "r")) == NULL) {
        printf("Sem dados de armazem guardados, configure o inventário.\n");
    }
    else
    {
        estadoArmazem = 1;
        for (int i = 0; i < 4; i++) {
            fgets(produtos[i], 20, f);
            produtos[i][strcspn(produtos[i], "\n")] = 0; // Remove newline character
			descodificar(produtos[i]); // Decodificar o nome do produto
            fgets((char*)&quantidades[i], 20, f);
        }
        fclose(f);
        printf("Dados de armazem carregados com sucesso.\n");
    }

    // Menu de opções
    while (opcao != 0) {
        printf("\nMenu de opções:\n");
        printf("1. Registar/Atualizar inventário\n");
        printf("2. Consultar inventário\n");
        printf("0. Sair e Gravar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar newline character do input buffer

        if (opcao == 1) {
			printf("Registar/Atualizar inventário:\n");
			f = fopen("armazem.txt", "w");
            if (f == NULL) {
                printf("Erro ao criar o arquivo para escrita.\n");
                return 1;
			}
            for (int i = 0; i < 4; i++) {
                printf("Produto %d: ", i + 1);
                fgets(produtos[i], 20, stdin);
                produtos[i][strcspn(produtos[i], "\n")] = 0; // Remove newline character
				codificar(produtos[i]); // Codificar o nome do produto
				fprintf(f, "%s\n", produtos[i]);
                printf("Quantidade %d: ", i + 1);
                scanf("%d", &quantidades[i]);
                getchar(); // Limpar newline character do input buffer
				fprintf(f, "%d\n", quantidades[i]);
            }
            estadoArmazem = 1;
			fclose(f);
        }
        else if (opcao == 2) {
            if (estadoArmazem == 0) {
                printf("Inventário vazio. Por favor, registe o inventário primeiro.\n");
            }
            else {
                printf("\nInventário:\n");
                for (int i = 0; i < 4; i++) {
					descodificar(produtos[i]); // Decodificar o nome do produto
                    if (quantidades[i] <= 5) {
                        printf("Produto: %s, Quantidade: %d (STOCK CRTITICO)\n", produtos[i], quantidades[i]);
                    }
                    else {
                        printf("Produto: %s, Quantidade: %d\n", produtos[i], quantidades[i]);
                    }
                }
            }
        }
        else if (opcao == 0) {
            if (estadoArmazem == 1) {
                f = fopen("armazem.txt", "w");
                for (int i = 0; i < 4; i++) {
                    codificar(produtos[i]); // Codificar o nome do produto antes de salvar
                    fprintf(f, "%s\n%d\n", produtos[i], quantidades[i]);
                }
                fclose(f);
                printf("Dados de armazem gravados com sucesso.\n");
            }
            else {
                printf("Nenhum dado para gravar. Saindo sem salvar\n");
            }
        }
        else {
            printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    }
    return 0;
}