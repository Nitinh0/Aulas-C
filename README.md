
## 📘 MÓDULO 1: Os Alicerces (Aulas 1 a 4)

<details>

<summary><b>Este volume foca-se em como o programa nasce, como guarda dados simples e como toma as primeiras decisões.</b></summary>

### 1. A Estrutura Obrigatória

Todo o programa em C precisa de um ponto de partida e de um relatório de saída.

- `#include <stdio.h>` -- A biblioteca base que nos permite usar o ecrã e o teclado.
- `int main()` -- A porta de entrada do programa. O Windows procura sempre por esta função para arrancar.
- `return 0;`  -- A "assinatura" de que tudo correu bem. É crucial não esquecer, pois é isto que avisa o sistema operativo de que o programa terminou sem erros.

### 2. Variáveis e Marcadores

O C precisa de saber o formato exato das "caixas" de memória e como as imprimir.

- `int` (Inteiros) -> Marcador: `%d`
- `double` (Decimais) -> Marcador: `%lf`
- `char` (Uma letra) -> Marcador: `%c`

### 3. Ler e Escrever (printf vs scanf)

- `printf("Texto puro");` -- Usado para falar com o utilizador. Só leva marcadores e variáveis se quiseres imprimir valores.
- `scanf("%d", &idade);` -- Usado para ouvir o teclado.

>**Regra de Ouro:** Para ler números, o `scanf` exige o símbolo `&` antes da variável, que significa "guarda nesta morada de memória".

### 4. Tomada de Decisão (if / else)

Servem para que o programa faça escolhas com base em condições lógicas, como comparar números ou verificar se a condição é verdadeira ou falsa.

- `if` -- Executa um bloco de código se a condição for verdadeira.

- `else` -- Executa um bloco de código se a condição for falsa.

Usam operadores de comparação:

- `==` -- Igual a
- `!=` -- Diferente de
- `>` / `>=` -- Maior que / Maoir ou igual a
- `<` / `<=` -- Menor que / Menor ou igual a

```c
if (quantidade <= 5) {
    printf("Stock Crítico!\n");
} else {
    printf("Stock Normal.\n");
}
```

</details>

## 📙 MÓDULO 2: Escala e Automação (Aulas 5 a 6)

<details>

<summary><b>Este volume marca a transição de escrever linhas repetidas para ensinar o computador a trabalhar por ti.</b></summary>

### 5. Arrays (Listas de Variáveis)

Em vez de criar custo1, custo2 e custo3, cria-se um contentor com várias posições.

- `double custos[3];` -- Cria espaço para 3 números.
    > **Atenção:** Em C, as posições começam sempre no zero! (Ou seja: custos[0], custos[1], custos[2]).

### 6. O Ciclo for

A melhor ferramenta para percorrer Arrays. Tem 3 regras: Início, Fim e Incremento.  

```c
for (size_t i = 0; i < 3; i++) {  
 printf("Posicao %d\n", i);  
}
```

> **Nota Profissional:** Usar `size_t` em vez de int para a variável `i` protege o teu código, impedindo que o ciclo tente ler posições negativas de memória por acidente.
</details>

## 📕 MÓDULO 3: Domínio do Texto e Arquitetura (Aulas 7 a 9)

<details>
<summary><b>Onde a programação se cruza com o mundo real (nomes de aplicações, caminhos de pastas e menus interativos).</b></summary>

### 7. Strings (O Texto em C)

Em C, as palavras não são mais do que Arrays de letras (caracteres).

- `char nome[50];` -- Cria espaço para uma palavra até 49 letras (+1 terminador invisível \0).
- A Exceção do `&` -- No `scanf` para ler texto (com o marcador `%s`), não se usa o `&`. **O próprio nome do array já representa a sua memória**.

### 8. Textos com Espaços e o fgets

O `scanf` tradicional não consegue ler frases com espaços (ex: "Program Files"). A alternativa profissional é o `fgets`.

- Sintaxe -- `fgets(nomePasta, 300, stdin);`
- O Problema da Tesoura -- O `fgets` guarda acidentalmente o "Enter" (`\n`) que digitas no teclado.
- A Solução (`strcspn`) -- Importamos a `<string.h>` e ordenamos ao C que encontre a posição do `\n` e o substitua por `\0` (Fim do texto).

```c
nomePasta[strcspn(nomePasta, "\n")] = '\0';
```

### 9. Matrizes (Arrays 2D) e Choques de Memória

- Arrays de Texto -- Para guardar uma lista de nomes, juntamos duas dimensões. Ex: `char listaApps[3][50];` (3 apps, até 50 letras cada). Para ler/gravar, usas apenas `listaApps[i]`.

#### O Choque Mortal (scanf vs fgets)

- O que acontece -- Se usares um `scanf` para ler um menu (ex: opção 1) e logo a seguir o código tentar ler um texto com `fgets`, o `fgets` vai encravar porque encontra o "Enter" (`\n`) fantasma deixado para trás pelo `scanf`.

- ***A Cura*** -- Usar sempre a função `getchar();` imediatamente após um `scanf` para "limpar" o buffer do teclado antes de chamar um `fgets`.

</details>

## 📂 MÓDULO 4: Persistência de Dados (Aulas 10 a 13)

<details>

<summary><b>O módulo onde o programa aprende a guardar e ler dados do disco rígido, criando uma memória permanente.</b></summary>

### 1. O Ponteiro de Ficheiro (FILE *)

- Para comunicar com o disco rígido, o C usa um tipo de dados especial em maiúsculas acompanhado por um asterisco: `FILE *f;`. O asterisco indica que a variável guarda a "morada" do ficheiro no disco (um ponteiro).

#### As Três Etapas Sagradas

Manipular ficheiros em C **segue sempre uma ordem obrigatória**:

1. Abrir (`fopen`) -- Liga o programa ao ficheiro num determinado modo.

- `"w"` (Write / Escrever) -- Cria o ficheiro do zero. Se já existir, apaga tudo o que lá estava.

- `"r"` (Read / Ler) -- Abre um ficheiro existente para extrair dados.

1. Manipular (`fprintf` / `fgets`) -- Escreve ou lê os dados.

2. Fechar (`fclose`) -- Fecha o canal. ***Obrigatório para evitar ficheiros corrompidos ou bloqueados pelo Windows***.

```c
FILE *f = fopen("dados.txt", "w");
fprintf(f, "Texto para o ficheiro\n");
fclose(f);
```

#### A Rede de Segurança (NULL)

- Se tentares abrir um ficheiro para ler (`"r"`), mas o ficheiro não existir, o `fopen` falha e devolve o valor `NULL` (vazio).

- Tentar ler ou fechar um ficheiro que vale `NULL` faz o programa crashar imediatamente.

- **Boa Prática: Usar sempre um `if` de controlo logo após a abertura.**

```c
FILE *f = fopen("Launcher.txt", "r");  
if (f == NULL) {  
 printf("Aviso: Ficheiro nao encontrado!\n");  
 // Aqui podes decidir se fechas o programa (return 1;) ou se geras um novo ("w")  
} 
```

### 2. O Cursor de Leitura e Ciclos (Aulas 11 e 12)

- O Windows usa um "cursor invisível" dentro do ficheiro. Sempre que um `fgets(variável, tamanho, f);` é executado, ele **lê a linha atual e empurra o cursor para o início da linha seguinte**.

- Graças a este cursor, podemos enfiar o `fgets` dentro de um ciclo `for` para ler várias linhas seguidas de forma organizada, sem misturar os dados.

### 3. Arquitetura de Software: RAM vs Disco (Aula 13)

- **A Rasteira do Ciclo: O carregamento de ficheiros (`"r"`) deve ser feito apenas uma vez, logo no início do main**. Fazer a leitura dentro de um ciclo de menu (`while`) faz o programa ler o disco desnecessariamente a cada segundo, gerando lentidão e bugs.

#### O Fluxo Correto

1. O programa arranca e verifica o disco (`fopen` em modo `"r"`).

2. Se encontrar o ficheiro, puxa os dados para os Arrays (Memória RAM) e **fecha o ficheiro** com `fclose`

3. O utilizador mexe no menu, altera os dados na RAM.

4. Se o utilizador escolher gravar, o programa abre o ficheiro em modo `"w"`, esvazia o disco, descarrega a RAM para lá e volta a fechar.

</details>

## 🧱 MÓDULO 5: O Mundo das Structs (Aulas 14 e 15)

<details>

<summary><b>O módulo onde o programa evolui de um amontoado de variáveis para uma estrutura organizada e profissional.</b></summary>

### 1. O que é uma struct e porquê usá-la?

Até agora, para gerir dados complexos, usávamos arrays paralelos (ex: um array para nomes e outro para caminhos). O problema é que o compilador não sabe que eles estão interligados.
Uma struct permite-te criar o teu próprio tipo de variável. Ela serve como um "modelo" ou uma "ficha de inscrição" que agrupa variáveis de tipos diferentes (como char, int, double) debaixo do mesmo teto.

### 2. Como se Define e Declara (Sintaxe)

A definição do modelo é feita **fora da função main (lá em cima, junto aos #include)**, para que todo o programa conheça o novo formato:

```c
struct App {
    char nome[50];
    char caminho[300];
    int vezesAberta;
}; // <-- ATENÇÃO: Nunca esquecer este ponto e vírgula no final da definição!
```

Depois de definido o modelo, podes criar uma variável desse tipo dentro do main assim:

```c
struct App minhaApp; // Criámos uma variável que transporta os 3 dados lá dentro
```

### 3. O Operador Ponto (.)

Para aceder, ler ou modificar qualquer propriedade dentro da tua struct, usas o operador ponto `.`

Para Variáveis Normais (int, double): Mexes nelas diretamente usando o ponto.

```c
minhaApp.vezesAberta = 5;
```

Para Arrays de Texto (`char[]`): Se fores preencher manualmente no código, precisas da função `strcpy` da `<string.h>`. Mas se fores ler do teclado ou de um ficheiro, o `fgets` faz o trabalho diretamente:

```c
fgets(minhaApp.nome, 50, stdin); // Grava direto na propriedade da struct!
```

### 4. Arrays de Structs (Escala Profissional)

O verdadeiro poder surge quando criamos um array de estruturas. Em vez de gerires matrizes paralelas complexas, geras uma lista simples de fichas:

```c
struct App listaApps[3]; // Uma lista com 3 posições, onde cada uma tem nome, caminho e contador.
````

Para navegar nisto dentro de um ciclo `for`, combinamos o índice do array `[i]` com o operador ponto `.`:

```c
for (size_t i = 0; i < 3; i++) {
    printf("Nome da App %d: %s\n", i + 1, listaApps[i].nome);
}
```

### 5. Structs unidas a Ficheiros (Persistência Organizada)

Quando guardamos ou lemos dados do disco rígido (armazem.txt ou Launcher.txt), a lógica de ponteiros `FILE *` mantém-se exatamente a mesma. A única diferença é que apontamos o `fprintf` ou o `fgets` para a propriedade exata da struct:

Escrever no Disco:

```c
fprintf(f, "%s\n", listaApps[i].nome);
```

Ler do Disco:

```c
fgets(listaApps[i].nome, 50, f);
listaApps[i].nome[strcspn(listaApps[i].nome, "\n")] = '\0'; // Mantém-se a tesoura!
```

> Vantagem de Arquitetura: Se amanhã decidires que o teu Gestor HTPC também deve guardar a categoria da app ou um ícone personalizado, basta ires lá acima à struct App e adicionar a linha. Todo o teu código cá em baixo continuará perfeitamente alinhado.

</details>

## 🧭 MÓDULO 6: Ponteiros e Memória Dinâmica (Aulas 16 a 18)

<details>

<summary><b>Onde o programa ganha acesso direto à RAM, quebrando barreiras entre funções e pedindo memória sob demanda.</b></summary>

### 1. Ponteiros Básicos (& e *)

O C protege as variáveis originais fazendo cópias delas quando as enviamos para funções. Para alterar a variável verdadeira, enviamos a sua morada (Ponteiro).

- **O Operador `&` (Endereço)** -- Lê-se *"a morada de"*. Serve para descobrir onde a variável vive na RAM. Ex: `&idade`
- **O Operador `*` (Desreferenciação)** - Lê-se *"o conteúdo de"*. Serve para criar a variável ponteiro, e mais tarde para entrar nessa morada e alterar o valor.

```c
int numero = 10;
int *ponteiro = &numero; // Guarda a morada
*ponteiro = 20;          // Vai à morada e altera o valor original para 20
```

### 2. Ponteiros e Structs (A Setinha ->)

Passar uma struct inteira para uma função consome muita RAM (cópia de dados). A solução é passar apenas o ponteiro da struct.
Para aceder às propriedades da struct através de um ponteiro, o ponto `.` não funciona. Usamos o operador Setinha `->`.

```c
void executarApp(struct App *alvo) {
    alvo->vezesAberta++; // Viaja pela morada e soma 1 diretamente na struct original
}
```

### 3. Memória Dinâmica (malloc e free)

Quando não sabemos o tamanho de um array antes do programa arrancar (ex: o utilizador é que escolhe a quantidade), pedimos RAM emprestada ao Windows em tempo real usando a biblioteca `<stdlib.h>`.

   `malloc` (Memory Allocation) -- Reserva o espaço na RAM e devolve o ponteiro inicial. Usamos o `sizeof()` para garantir o tamanho exato.

   `free` -- **Obrigatório** no fim do programa. Devolve a RAM ao sistema operativo para evitar falhas de memória (*Memory Leaks**).

```c
int quantidade = 5;
// 1. Criar o ponteiro
struct Jogo *catalogo; 

// 2. Pedir espaço exato para 5 videojogos
catalogo = malloc(quantidade * sizeof(struct Jogo)); 

// 3. Usar normalmente como um array
strcpy(catalogo[0].nome, "Steam");

// 4. Devolver a RAM no fim
free(catalogo);
```

</details>

## 🏗️ MÓDULO 7: Arquitetura e Modularização (Aula 19)

<details>

<summary><b>Como dividir um projeto gigante em múltiplos ficheiros organizados, imitando a estrutura de software real.</b></summary>

### 1. Ficheiros de Cabeçalho (.h) - O Contrato

Servem apenas como um índice ou manual de instruções do módulo. Não contêm a lógica executável.

- **Guardas de Cabeçalho** -- Usamos `#ifndef`, `#define` e `#endif` para impedir que o compilador leia o mesmo ficheiro duas vezes (o que causaria erros de redefinição).
- **O que contêm** -- A definição das `structs` e as **assinaturas das funções** (apenas o nome, os parâmetros e um ponto e vírgula no fim).

```c
// AS GUARDAS DE CABEÇALHO: Protegem contra inclusões duplas (O VS Code e o compilador adoram isto)
#ifndef HTPC_H
#define HTPC_H

// 1. Definir o modelo (A struct)
struct App {
    char nome[50];
    int vezesAberta;
};

// 2. Definir a assinatura da função (Sem abrir chavetas! Só o "contrato")
void executarApp(struct App *alvo);

#endif
```

### 2. Ficheiros de Origem (.c) - O Trabalhador

Ficheiros `.c` contêm a magia toda.

- Devem sempre importar o seu próprio ficheiro de cabeçalho usando aspas duplas (ex: `#include "inventario.h"`). As aspas dizem ao C para procurar o ficheiro na nossa pasta local em vez de procurar no sistema operativo.
- É aqui que abrimos as chavetas `{ }` e escrevemos o corpo real das funções.

```c
#include <stdio.h>
// IMPORTANTE: Incluir o nosso próprio ficheiro .h com aspas duplas em vez de <>
#include "htpc.h" 

// Escrever a função real
void executarApp(struct App *alvo) {
    alvo->vezesAberta++;
    printf("Executando o app: %s \nTotal de vezes aberta: %d\n", alvo->nome, alvo->vezesAberta);
}
```

### 3. Ficheiro Principal (main.c) - O Centro de Comando

O ficheiro que arranca o programa.

- Para usar as ferramentas que criámos noutros ficheiros, basta fazer o `#include "inventario.h"`.
- O `main` não precisa de saber como a função foi escrita internamente; ao incluir o `.h`, ele tem a garantia de que a função existe e chama-a de forma limpa. Isto mantém a função principal livre de "ruído" e fácil de ler.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// Incluir apenas o nosso "índice"
#include "htpc.h" 

int main() {
    struct App jogo;
    strcpy(jogo.nome, "GTA V");
    jogo.vezesAberta = 0;

    // O main não faz ideia de como a função está escrita no htpc.c, mas o htpc.h garante que ela existe!
    executarApp(&jogo); 
    
    return 0;
}
```

</details>

## 🔗 MÓDULO 8: Listas Ligadas / Linked Lists (Aula 20)

<details>

<summary><b>Como quebrar as limitações de tamanho dos arrays criando correntes infinitas de dados na memória RAM.</b></summary>

### 1. O Problema dos Arrays vs A Solução das Listas

Os arrays exigem blocos contínuos de memória. Se não houver espaço todo junto, o programa falha. Nas **Listas Ligadas**, cada elemento (chamado **Nó** ou *Node*) pode estar espalhado por qualquer parte da RAM, pois cada um guarda a morada do elemento seguinte.

### 2. A Estrutura Auto-Referenciada

Para criar um Nó, adicionamos um ponteiro dentro da própria `struct` que aponta para outra `struct` do mesmo tipo.

```c
struct JogoNode {
    char nome[50];
    struct JogoNode *proxima; // O elo da corrente que guarda a morada do próximo jogo
    };
```

### 3. A Âncora e a Parede (inicio e NULL)

   `inicio` (Cabeça) -- É um ponteiro crucial que guarda sempre a morada do primeiro elemento. Se perdermos este ponteiro, a lista inteira fica perdida na memória (*Memory Leak*).

   `NULL` -- O último elemento da corrente aponta sempre para `NULL`. É assim que o programa sabe que a lista acabou.

### 4. Navegar na Corrente

Como não existem índices `[i]`, usamos um ponteiro temporário (`atual`) e um ciclo `while` para "saltar" de nó em nó até batermos no `NULL`.

```c
struct JogoNode *atual = inicio;
while (atual != NULL) {
    printf("Jogo: %s\n", atual->nome);
    atual = atual->proxima; // O ponteiro salta para o próximo vagão
}
```

### 5. Destruição Segura (O free em Listas)

Para limpar a memória alocada com `malloc` no fim do programa, não podemos simplesmente apagar o nó atual, senão perdemos a morada do seguinte. Usamos um ponteiro temporário para segurar o próximo elemento antes de apagar o atual:

```c

atual = inicio; //garantir que começamos do início da lista
struct JogoNode* proximoTemporario;

while (atual != NULL) {
    proximoTemporario = atual->proxima; // 1. Segura o próximo
    free(atual);                        // 2. Apaga o atual em segurança
    atual = proximoTemporario;          // 3. Salta para o que guardou
}
```

</details>

## ⚙️ MÓDULO 9: Chamadas de Sistema e OS API (Aula 21)

**Como fazer o código C falar diretamente com o Windows para controlar processos externos e criar um Launcher.**

### 1. A Forma Simples (system)

A função `system()` da biblioteca `<stdlib.h>` abre uma linha de comandos invisível e executa instruções simples.

- **O grande defeito:** É síncrona. O programa em C fica "congelado" à espera que a aplicação que abrimos seja fechada para poder continuar a ler o código. Inviável para um Launcher que precisa de continuar a correr em segundo plano.

### 2. A Forma Profissional (ShellExecute)

A função `ShellExecute` pertence à API nativa do Windows (`<windows.h>`). Permite lançar processos, abrir sites ou ficheiros de forma **assíncrona**.

- O C envia a ordem para o Windows e continua imediatamente a ler a próxima linha de código, permitindo gerir a interface enquanto o jogo/app carrega.

```c
// O caminho exige sempre barras duplas no C para não ser confundido com caracteres de fuga
ShellExecute(NULL, "open", "C:\\Programas\\Steam\\steam.exe", NULL, NULL, SW_SHOWNORMAL);
```

### 3. Controlo de Janela

O último parâmetro do ShellExecute dita a forma como o programa arranca.

- `SW_SHOWNORMAL` -- Abre a aplicação na sua janela padrão.

- `SW_MAXIMIZE` -- Força a janela a abrir maximizada.

- `SW_HIDE` -- Executa a aplicação de forma totalmente invisível (ideal para correr serviços de background sem abrir caixas pretas de terminal no ecrã).

</details>
