#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char nomesApps[3][50];
    char caminhos[3][300];

    FILE* f;

    f = fopen("Launcher.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    else {
        for (size_t i = 0; i < 3; i++)
        {
            fgets(nomesApps[i], 50, f);
			nomesApps[i][strcspn(nomesApps[i], "\n")] = 0;
            fgets(caminhos[i], 300, f);
			caminhos[i][strcspn(caminhos[i], "\n")] = 0;
        }        
    }
    fclose(f);

    for (size_t i = 0; i < 3; i++)
    {
        printf("App %d: %s esta em %s\n", i + 1, nomesApps[i], caminhos[i]);
    }
    return 0;
}