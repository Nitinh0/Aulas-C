#include <stdio.h>
#include <string.h>
#include "launcher.h"

void configurarApps(struct App *lista, int quantidade)
{
	int i;
	for (i = 0; i < quantidade; i++)
	{
		printf("Insira o nome do aplicativo %d: ", i + 1);
		fgets(lista[i].nome, sizeof(lista[i].nome), stdin);
		lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';
		printf("Insira o caminho do aplicativo %d: ", i + 1);
		fgets(lista[i].caminho, sizeof(lista[i].caminho), stdin);
		lista[i].caminho[strcspn(lista[i].caminho, "\n")] = '\0';
	}
}