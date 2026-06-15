#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Função cifra de Cesar
void codificar(char str[20]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + 1;
    }
}

// Função ler cifra de Cesar
void descodificar(char str[20]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] - 1;
    }
}

int main() {
    int opcao = -1;
    int estadoArmazem = 0;

    char produtos[4][20];
    int quantidades[4];

    FILE* f;

    // 1. CARREGAMENTO (Executa apenas 1 vez ao arrancar)
    f = fopen("armazem.txt", "r");
    if (f == NULL) {
        printf("Sem dados de armazem guardados, configure o inventario.\n");
    }
    else {
        estadoArmazem = 1;
        for (int i = 0; i < 4; i++) {
            fgets(produtos[i], 20, f);
            produtos[i][strcspn(produtos[i], "\n")] = 0;
            descodificar(produtos[i]); // Traduz para a RAM ficar limpa

            // CORRIGIDO: fscanf para ler inteiros do ficheiro de forma segura
            fscanf(f, "%d\n", &quantidades[i]);
        }
        fclose(f);
        printf("Dados de armazem carregados com sucesso.\n");
    }

    // 2. MENU DE OPÇÕES
    while (opcao != 0) {
        printf("\nMenu de opcoes:\n");
        printf("1. Registar/Atualizar inventario (Apenas na RAM)\n");
        printf("2. Consultar inventario\n");
        printf("0. Sair e Gravar no Disco\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            printf("\nRegistar/Atualizar inventario:\n");
            // CORRIGIDO: Não abrimos o ficheiro aqui. Guardamos APENAS na RAM limpa.
            for (int i = 0; i < 4; i++) {
                printf("Produto %d: ", i + 1);
                fgets(produtos[i], 20, stdin);
                produtos[i][strcspn(produtos[i], "\n")] = 0;

                printf("Quantidade %d: ", i + 1);
                scanf("%d", &quantidades[i]);
                getchar();
            }
            estadoArmazem = 1;
            printf("Dados guardados temporariamente na RAM. Escolha 0 para gravar no disco.\n");
        }
        else if (opcao == 2) {
            if (estadoArmazem == 0) {
                printf("Inventario vazio. Por favor, registe o inventario primeiro.\n");
            }
            else {
                printf("\nInventario Atual (RAM):\n");
                for (int i = 0; i < 4; i++) {
                    // CORRIGIDO: Retirada a função descodificar daqui. A RAM já está limpa!
                    if (quantidades[i] <= 5) {
                        printf("Produto: %s, Quantidade: %d (STOCK CRITICO)\n", produtos[i], quantidades[i]);
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
                if (f == NULL) {
                    printf("Erro ao criar o arquivo para escrita.\n");
                    return 1;
                }
                for (int i = 0; i < 4; i++) {
                    codificar(produtos[i]); // Cifra apenas no momento de enviar para o arquivo.
                    fprintf(f, "%s\n%d\n", produtos[i], quantidades[i]);
                }
                fclose(f);
                printf("Dados cifrados e gravados com sucesso. Ate logo!\n");
            }
            else {
                printf("Nenhum dado para gravar. Saindo...\n");
            }
        }
        else {
            printf("Opcao invalida. Tenta novamente.\n");
        }
    }
    return 0;
}