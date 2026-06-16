# 📘 Manual de Programação em C:

Este repositório contém os meus apontamentos de estudo e a evolução dos meus projetos em linguagem C.

---

## MÓDULO 1: Fundamentos Básicos (Aulas 1 a 5)

### 1. Estrutura Base de um Programa
Todo o código em C precisa de uma estrutura inicial para saber por onde começar a execução e como comunicar com o sistema operativo.

```c
#define _CRT_SECURE_NO_WARNINGS // Desativa avisos de segurança no Visual Studio
#include <stdio.h>              // Biblioteca para Input/Output (printf/scanf)
#include <string.h>             // Biblioteca para manipulação de texto (strings)

int main() {
    // O código começa a ser executado aqui
    return 0; // Indica ao sistema que o programa terminou com sucesso
}
```

### 2. Variáveis e Tipos de Dados

As variáveis são caixas na memória RAM com tipos estritos:

   - int: Números inteiros (ex: 10, -5). Usa %d no printf.

   - float / double: Números decimais (ex: 10.5). Usa %f ou %lf.

   - char: Um único caractere (ex: 'A'). Usa %c.


### Operadores Lógicos e Condições (if / else)

Servem para o programa tomar decisões baseadas em testes matemáticos:

```c
if (quantidade <= 5) {
    printf("Stock Crítico!\n");
} else {
    printf("Stock Normal.\n");
}
```


### MÓDULO 2: Loops e Menus Interativos (Aulas 6 a 9)

### 1. Ciclos de Repetição

   - for: Ideal para quando sabemos exatamente quantas vezes o código deve rodar. Usa-se frequentemente com size_t para índices.

   - while: Ideal para quando o código deve rodar até que uma condição mude (ex: menus).

    // Exemplo de menu interativo retentivo
    int opcao = -1;
    while (opcao != 0) {
        printf("1. Continuar\n0. Sair\n");
        scanf("%d", &opcao);
        getchar(); // CRÍTICO: Limpa o 'Enter' (\n) que fica esquecido no buffer do teclado
    }