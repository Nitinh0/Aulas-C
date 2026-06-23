#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct App{
    char nome[50];
    char caminho[300];
};

int main(){
    struct App app1, app2;
    FILE *f;

    f = fopen("saida.json", "w");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    printf("Digite o nome do aplicativo 1: ");
    fgets(app1.nome, sizeof(app1.nome), stdin);
    app1.nome[strcspn(app1.nome, "\n")] = '\0';

    printf("Digite o caminho do aplicativo 1: ");
    fgets(app1.caminho, sizeof(app1.caminho), stdin);
    app1.caminho[strcspn(app1.caminho, "\n")] = '\0';

    printf("Digite o nome do aplicativo 2: ");
    fgets(app2.nome, sizeof(app2.nome), stdin);
    app2.nome[strcspn(app2.nome, "\n")] = '\0';

    printf("Digite o caminho do aplicativo 2: ");
    fgets(app2.caminho, sizeof(app2.caminho), stdin);
    app2.caminho[strcspn(app2.caminho, "\n")] = '\0';

    // 1. Abrir a lista
    fprintf(f, "[\n"); 

    // 2. Escrever a App 1 (com a vírgula no fim, pois vem aí mais uma)
    fprintf(f, "  {\n    \"nome\": \"%s\",\n    \"caminho\": \"%s\"\n  },\n", app1.nome, app1.caminho);

    // 3. Escrever a App 2 (SEM a vírgula no fim da chaveta, porque é a última)
    fprintf(f, "  {\n    \"nome\": \"%s\",\n    \"caminho\": \"%s\"\n  }\n", app2.nome, app2.caminho);

    // 4. Fechar a lista
    fprintf(f, "]\n");
    
    fclose(f);
    return 0;
}