#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "motor.h"

void addApp(struct AppNode** head, const char* nome, const char* caminho) {
	struct AppNode* newNode = (struct AppNode*)malloc(sizeof(struct AppNode));
	if (newNode == NULL) {
		fprintf(stderr, "Erro ao alocar memória para novo aplicativo.\n");
		return;
	}
	strncpy(newNode->nome, nome, sizeof(newNode->nome) - 1);
	newNode->nome[sizeof(newNode->nome) - 1] = '\0';
	strncpy(newNode->caminho, caminho, sizeof(newNode->caminho) - 1);
	newNode->caminho[sizeof(newNode->caminho) - 1] = '\0';
	newNode->prox = *head;
	*head = newNode;
}

void exportarJSON(struct AppNode* head) {
	FILE* file = fopen("ui_config.json", "w");
	if (file == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo para escrita\n");
		return;
	}
	fprintf(file, "[\n");
	struct AppNode* current = head;
	while (current != NULL) {
		fprintf(file, "  {\n");
		fprintf(file, "    \"nome\": \"%s\",\n", current->nome);
		fprintf(file, "    \"caminho\": \"%s\"\n", current->caminho);
		fprintf(file, "  }");
		if (current->prox != NULL) {
			fprintf(file, ",\n");
		} else {
			fprintf(file, "\n");
		}
		current = current->prox;
	}
	fprintf(file, "]\n");
	fclose(file);
}

void liberarLista(struct AppNode* head) {
	struct AppNode* current = head;
	while (current != NULL) {
		struct AppNode* temp = current;
		current = current->prox;
		free(temp);
	}
}

void abrirAplicativo(const char* caminho) {
	if (ShellExecute(NULL, "open", caminho, NULL, NULL, SW_SHOWNORMAL) <= (HINSTANCE)32) {
		fprintf(stderr, "Erro ao abrir o aplicativo: %s\n", caminho);
	}
}