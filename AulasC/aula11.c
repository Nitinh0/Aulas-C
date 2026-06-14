#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char nomeApp[50];
    char caminho[300];

    FILE *f;

    f = fopen("Launcher.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    else {
        fgets(nomeApp, 50, f);
        fgets(caminho, 300, f);        
    }
    fclose(f);

    printf("Nome do aplicativo: %s", nomeApp);
    printf("Caminho do aplicativo: %s", caminho);

    return 0;
}
