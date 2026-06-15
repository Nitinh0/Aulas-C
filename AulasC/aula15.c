#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct App {
    char nome[50];
    char caminho[300];
};

int main() {
    // Variáveis de Controlo
    int opcao = -1;
    int appsConfiguradas = 0; // Serve como interruptor (0 = Falso, 1 = Verdadeiro)

	// Array de Estruturas para guardar as apps
	struct App listaApps[3];

    FILE* f;

    if ((f = fopen("Launcher.txt", "r")) == NULL) {
        printf("Nenhuma configuração guardada. Menu limpo.\n");
    }
    else
    {
        appsConfiguradas = 1;
        for (size_t i = 0; i < 3; i++) {
            fgets(listaApps[i].nome, 50, f);
            listaApps[i].nome[strcspn(listaApps[i].nome, "\n")] = '\0';
            fgets(listaApps[i].caminho, 300, f);
            listaApps[i].caminho[strcspn(listaApps[i].caminho, "\n")] = '\0';
        }
        fclose(f); // Fechar sempre após terminar a leitura!
        printf("Configuracoes anteriores carregadas com sucesso!\n");
    }

    //O Ciclo Infinito do Menu
    while (opcao != 0) {
        printf("\n========== GESTOR HTPC ==========\n");
        printf("1. Configurar 3 Aplicacoes\n");
        printf("2. Mostrar Lista do Launcher\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o "Enter" fantasma da memoria!

        //Lógica das Opções
        if (opcao == 1) {
            printf("\n--- MODO DE CONFIGURACAO ---\n");
            f = fopen("Launcher.txt", "w");
            if (f == NULL) {
                printf("Erro critico: Nao foi possivel criar o ficheiro!\n");
                return 1;
            }
            for (size_t i = 0; i < 3; i++) {
                printf("Insira o nome da aplicacao %d: \n", i + 1);
                fgets(listaApps[i].nome, 50, stdin);
                listaApps[i].nome[strcspn(listaApps[i].nome, "\n")] = '\0';
                fprintf(f, "%s\n", listaApps[i].nome);

                printf("Insira o caminho da aplicacao %d: \n", i + 1);
                fgets(listaApps[i].caminho, 300, stdin);
                listaApps[i].caminho[strcspn(listaApps[i].caminho, "\n")] = '\0';
                fprintf(f, "%s\n", listaApps[i].caminho);
            }
            fclose(f);
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
                    printf("[%d] %s -> %s\n", i + 1, listaApps[i].nome, listaApps[i].caminho);
                }
            }

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