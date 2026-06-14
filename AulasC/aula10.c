#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char nomeApp[50];
    char caminho[300];

    printf("Insira o nome do Programa\n");
    fgets(nomeApp, 50, stdin);
    nomeApp[strcspn(nomeApp, "\n")] = '\0';


    printf("Insira o caminho do Programa\n");
    fgets(caminho, 300, stdin);
    caminho[strcspn(caminho, "\n")] = '\0';

    FILE *f;
    f = fopen("Launcher.txt", "w");
    fprintf(f, "Programa: %s\n", nomeApp);
    fprintf(f, "Caminho: %s\n", caminho);
    fclose(f);

    printf("Dados guardados");

    return 0;
}
