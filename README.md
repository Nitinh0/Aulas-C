# 📘 Manual de Programação em C:

Este repositório contém os meus apontamentos de estudo e a evolução dos meus projetos em linguagem C.

---

## MÓDULO 1: Fundamentos Básicos (Aulas 1 a 5)

### 1. Estrutura Base de um Programa

Todo o programa em C precisa de um ponto de partida e de um relatório de saída.

   - #include <stdio.h>: A biblioteca base que nos permite usar o ecrã e o teclado.

   - int main(): A porta de entrada do programa. O Windows procura sempre por esta função para arrancar.

   - return 0;: A tua "assinatura" de que tudo correu bem. É crucial não esquecer, pois é isto que avisa o sistema operativo de que o programa terminou sem erros.


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

O C precisa de saber o formato exato das "caixas" de memória e como as imprimir.

   - int: Números inteiros (ex: 10, -5). Usa %d no printf.

   - float / double: Números decimais (ex: 10.5). Usa %f ou %lf.

   - char: Um único caractere (ex: 'A'). Usa %c.

### 3. Ler e Escrever (printf vs scanf)

   - printf("Texto puro");: Usado para falar com o utilizador. Só leva marcadores e variáveis se quiseres imprimir valores.

   - scanf("%d", &idade);: Usado para ouvir o teclado. Regra de Ouro: Para ler números, o scanf exige o símbolo & antes da variável, que significa "guarda nesta morada de memória".



### 4. Operadores Lógicos e Condições (if / else)

Servem para que o programa faça escolhas com base em condições lógicas, como comparar números ou verificar se a condição é verdadeira ou falsa.
   
   - if: Executa um bloco de código se a condição for verdadeira.

   - else: Executa um bloco de código se a condição for falsa.

Usam operadores de comparação:
   - == : Igual a
   - != : Diferente de
   - ">" ou >=  : Maior que / Maoir ou igual a
   - < ou <= : Menor que / Menor ou igual a

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

```c
// Exemplo de menu interativo retentivo
int opcao = -1;
while (opcao != 0) {
    printf("1. Continuar\n0. Sair\n");
    scanf("%d", &opcao);
    getchar(); // CRÍTICO: Limpa o 'Enter' (\n) que fica esquecido no buffer do teclado
}
```
