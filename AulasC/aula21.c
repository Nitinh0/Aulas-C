#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(){
    int opcao;
    
    printf("=====MENU=====\n");
    printf("1. Bloco de Notas\n");
    printf("2. Calculadora\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            ShellExecute(NULL, "open", "notepad.exe", NULL, NULL, SW_SHOWNORMAL);
            printf("A carregar aplicação...\n");
            break;
        case 2:
            ShellExecute(NULL, "open", "calc.exe", NULL, NULL, SW_SHOWNORMAL);
            printf("A carregar aplicação...\n");
            break;
        case 0:
            printf("Saindo da aplicação...\n");
            return 0;
        default:
            printf("Opção inválida. Saindo da aplicação...\n");
            return 0;
    }
    return 0;
}