#ifndef LAUNCHER_H
#define LAUNCHER_H

struct App
{
	char nome[50];
	char caminho[300];
};

void configurarApps(struct App* lista, int quantidade);

#endif
