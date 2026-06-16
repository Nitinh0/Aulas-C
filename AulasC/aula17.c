#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct App
{
	char nome[50];
	int vezesAberta;
};

void excutarApp (struct App *app)
{
	app->vezesAberta++;
	printf("Executando o app: %s \nTotal de vezes aberta: %d\n", app->nome, app->vezesAberta);
}

int main() {
	struct App Jogo;

	strcpy(Jogo.nome, "GTA V");
	Jogo.vezesAberta = 0;

	for (int i = 0; i < 3; i++)
	{
		excutarApp(&Jogo);
	}

	printf("\nO app %s foi aberto %d vezes\n", Jogo.nome, Jogo.vezesAberta);
	return 0;
}