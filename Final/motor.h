#ifndef MOTOR_H
#define MOTOR_H

struct AppNode {
	char nome[50];
	char caminho[300];
	struct AppNode* prox;
};

void addApp(struct AppNode** head, const char* nome, const char* caminho);
void exportarJSON(struct AppNode* head);
void liberarLista(struct AppNode* head);
void abrirAplicativo(const char* caminho);

#endif