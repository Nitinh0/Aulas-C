#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    // 1. Variáveis de Controlo
    int opcao = -1;
    int appsConfiguradas = 0; // Serve como interruptor (0 = Falso, 1 = Verdadeiro)

    // 2. Os nossos Arrays para guardar as 3 Apps
    char nomesApps[3][50];
    char caminhos[3][300];

    // 3. O Ciclo Infinito do Menu
    while (opcao != 0) {
        printf("\n========== GESTOR HTPC ==========\n");
        printf("1. Configurar 3 Aplicacoes\n");
        printf("2. Mostrar Lista do Launcher\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o "Enter" fantasma da memoria!

        // 4. Lógica das Opções
        if (opcao == 1) {
            printf("\n--- MODO DE CONFIGURACAO ---\n");
            for (size_t i = 0; i < 3; i++){
                printf("Insira o nome da aplicacao %d: \n", i + 1);
                fgets(nomesApps[i], 50, stdin);
                nomesApps[i][strcspn(nomesApps[i], "\n")] = '\0';

                printf("Insira o caminho da aplicacao %d: \n", i + 1);
                fgets(caminhos[i], 300, stdin);
                caminhos[i][strcspn(caminhos[i], "\n")] = '\0';
            }

            // TODO: Cria um ciclo 'for' que rode 3 vezes.
            // Lá dentro, usa o printf para pedir o nome, o fgets para ler para nomesApps[i], e o strcspn para limpar o \n.
            // A seguir, pede o caminho, usa o fgets para caminhos[i], e o strcspn para o limpar.

            appsConfiguradas = 1; // Avisamos o sistema que já há apps na memoria
            printf("Aplicacoes guardadas com sucesso!\n");
        }
        else if (opcao == 2) {
            printf("\n--- APPS DO LAUNCHER ---\n");
            if (appsConfiguradas == 0) {
                printf("Erro: Nenhuma app registada!\n");
            }
            else {
                for (size_t i = 0; i < 3; i++) {
                    printf("[%d] %s -> %s\n", i + 1, nomesApps[i], caminhos[i]);
                }
            }

            // TODO: Escreve um if/else.
            // Se 'appsConfiguradas' for 0, dá um printf a dizer "Erro: Nenhuma app registada!".
            // Se for 1, usa um ciclo 'for' para mostrar a lista no formato: "[1] Stremio -> C:\Pasta\Stremio"
        }
        else if (opcao == 0) {
            printf("A desligar o Gestor... Ate logo!\n");
        }
        else {
            printf("Opcao invalida. Tenta novamente.\n");
        }
    }
    return 0;
}