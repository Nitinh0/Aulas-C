#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int ano;
    double custo;

    printf("Digita o ano de lançamento previsto do projeto: ");
    scanf("%d", &ano); // Corrigido (tudo junto)

    printf("Digita o custo estimado de produção: ");
    scanf("%lf", &custo); // Corrigido o espaço que dava erro fatal!

    if (custo > 5000.0) {
        printf("Alerta: Projeto de Alto Custo!\n");
    }
    else {
        printf("Projeto dentro do orçamento base.\n");
    }

    printf("Ano de lançamento: %d\n", ano);

    return 0;
}