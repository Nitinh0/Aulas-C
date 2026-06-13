#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // Biblioteca de textos para manipular texto

int main() {
    char nomePrograma[50];
    char caminhoPasta[300];

    printf("Insira o nome do Programa: \n");
    fgets(nomePrograma, 50, stdin);
    // Remove o \n do nome do programa
    nomePrograma[strcspn(nomePrograma, "\n")] = '\0';
    //Função strcspn recebe nome do array de carateres onde procura e o que procura, neste caso "\n", e devolve o numero da posição
    // assim a linha 12 traduz-se em -> nomePrograma[ tamanho da minha string até ao \n ] = '\0'; no final substitui o \n por \0 para terminar a string

    printf("Insira o caminho do Programa: \n");
    fgets(caminhoPasta, 300, stdin);
    // Remove o \n do caminho
    caminhoPasta[strcspn(caminhoPasta, "\n")] = '\0'; 

    // Agora o print já sai numa linha contínua!
    printf("A registar o programa %s no caminho %s \n", nomePrograma, caminhoPasta);

    return 0;
}