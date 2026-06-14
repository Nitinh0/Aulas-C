#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis de Controlo
    int opcao = -1;
    int appsConfiguradas = 0; // Serve como interruptor (0 = Falso, 1 = Verdadeiro)

    //Os nossos Arrays para guardar as 3 Apps
    char nomesApps[3][50];
    char caminhos[3][300];

    FILE* f;

    if ((f = fopen("Launcher.txt", "r")) == NULL) {
        printf("Nenhuma configuração guardada. Menu limpo.\n");
    }
    else
    {
        appsConfiguradas = 1;
        for (size_t i = 0; i < 3; i++) {
            fgets(nomesApps[i], 50, f);
            nomesApps[i][strcspn(nomesApps[i], "\n")] = '\0';
            fgets(caminhos[i], 300, f);
            caminhos[i][strcspn(caminhos[i], "\n")] = '\0';
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
                fgets(nomesApps[i], 50, stdin);
                nomesApps[i][strcspn(nomesApps[i], "\n")] = '\0';            
				fprintf(f, "%s\n", nomesApps[i]);

                printf("Insira o caminho da aplicacao %d: \n", i + 1);
                fgets(caminhos[i], 300, stdin);
                caminhos[i][strcspn(caminhos[i], "\n")] = '\0';
				fprintf(f, "%s\n", caminhos[i]);
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
                    printf("[%d] %s -> %s\n", i + 1, nomesApps[i], caminhos[i]);
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