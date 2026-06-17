
## 📘 VOLUME 1: Os Alicerces (Aulas 1 a 4)
<details>

<summary><b>Este volume foca-se em como o programa nasce, como guarda dados simples e como toma as primeiras decisões.</b></summary>

### 1. A Estrutura Obrigatória
Todo o programa em C precisa de um ponto de partida e de um relatório de saída.

-   **#include <stdio.h>** -- A biblioteca base que nos permite usar o ecrã e o teclado.
-   **int main()** -- A porta de entrada do programa. O Windows procura sempre por esta função para arrancar.
-   **return 0;**  -- A "assinatura" de que tudo correu bem. É crucial não esquecer, pois é isto que avisa o sistema operativo de que o programa terminou sem erros.

### 2. Variáveis e Marcadores
O C precisa de saber o formato exato das "caixas" de memória e como as imprimir.

-   **int** (Inteiros) -> Marcador: **%d**    
-   **double** (Decimais) -> Marcador: **%lf**
-   **char** (Uma letra) -> Marcador: **%c**

### 3. Ler e Escrever (printf vs scanf)

-   **printf("Texto puro");** -- Usado para falar com o utilizador. Só leva marcadores e variáveis se quiseres imprimir valores.    
-   **scanf("%d", &idade);** -- Usado para ouvir o teclado. 
>**Regra de Ouro:** Para ler números, o scanf exige o símbolo **&** antes da variável, que significa "guarda nesta morada de memória".

### 4. Tomada de Decisão (if / else)

Servem para que o programa faça escolhas com base em condições lógicas, como comparar números ou verificar se a condição é verdadeira ou falsa.
   
   - if: Executa um bloco de código se a condição for verdadeira.

   - else: Executa um bloco de código se a condição for falsa.

Usam operadores de comparação:
   - **==** -- Igual a
   - **!=** -- Diferente de
   - **>** / **>=** -- Maior que / Maoir ou igual a
   - **<** / **<=** -- Menor que / Menor ou igual a

```c
if (quantidade <= 5) {
    printf("Stock Crítico!\n");
} else {
    printf("Stock Normal.\n");
}
```
</details>


## 📙 VOLUME 2: Escala e Automação (Aulas 5 a 6)
<details>

<summary><b>Este volume marca a transição de escrever linhas repetidas para ensinar o computador a trabalhar por ti.</b></summary>

### 5. Arrays (Listas de Variáveis)
Em vez de criar custo1, custo2 e custo3, cria-se um contentor com várias posições.
-   **double custos[3];** -- Cria espaço para 3 números.
    > **Atenção:** Em C, as posições começam sempre no zero! (Ou seja: custos[0], custos[1], custos[2]).

### 6. O Ciclo for

A melhor ferramenta para percorrer Arrays. Tem 3 regras: Início, Fim e Incremento.  
```c
for (size_t i = 0; i < 3; i++) {  
	printf("Posicao %d\n", i);  
}
```
> **Nota Profissional:** Usar size_t em vez de int para a variável i protege o teu código, impedindo que o ciclo tente ler posições negativas de memória por acidente.
</details>

## 📕 VOLUME 3: Domínio do Texto e Arquitetura (Aulas 7 a 9)
<details>
<summary><b>Onde a programação se cruza com o mundo real (nomes de aplicações, caminhos de pastas e menus interativos).</b></summary>

### 7. Strings (O Texto em C)
Em C, as palavras não são mais do que Arrays de letras (caracteres).
- **char nome[50];** -- Cria espaço para uma palavra até 49 letras (+1 terminador invisível \0).
- A Exceção do &: No scanf para ler texto (com o marcador %s), não se usa o &. **O próprio nome do array já representa a sua memória**.

### 8. Textos com Espaços e o fgets
O scanf tradicional não consegue ler frases com espaços (ex: "Program Files"). A alternativa profissional é o **fgets**.

-   Sintaxe: **fgets(nomePasta, 300, stdin);**    
-   O Problema da Tesoura: O fgets guarda acidentalmente o "Enter" (\n) que digitas no teclado.    
-   A Solução (**strcspn**): Importamos a **<string.h>** e ordenamos ao C que encontre a posição do **\n** e o substitua por **\0** (Fim do texto).
```c
nomePasta[strcspn(nomePasta, "\n")] = '\0';
```

### 9. Matrizes (Arrays 2D) e Choques de Memória
-   Arrays de Texto: Para guardar uma lista de nomes, juntamos duas dimensões. Ex: **char listaApps[3][50];** (3 apps, até 50 letras cada). Para ler/gravar, usas apenas listaApps[i].
    
#### O Choque Mortal (scanf vs fgets):
-   O que acontece: Se usares um **scanf** para ler um menu (ex: opção 1) e logo a seguir o código tentar ler um texto com **fgets**, o fgets vai encravar porque encontra o "Enter" fantasma deixado para trás pelo scanf.
    
- **A Cura:** Usar sempre a função **getchar();** imediatamente após um scanf para "limpar" o buffer do teclado antes de chamar um **fgets**.

</details>



## 📂 Volume4: Persistência de Dados (Aulas 10 a 13)
<details>

<summary><b>O módulo onde o programa aprende a guardar e ler dados do disco rígido, criando uma memória permanente.</b></summary>

### 1. O Ponteiro de Ficheiro (FILE *)

-   Para comunicar com o disco rígido, o C usa um tipo de dados especial em maiúsculas acompanhado por um asterisco: **FILE *f;**. O asterisco indica que a variável guarda a "morada" do ficheiro no disco (um ponteiro).

####  As Três Etapas Sagradas

Manipular ficheiros em C **segue sempre uma ordem obrigatória**:

1.  Abrir (**fopen**) -- Liga o programa ao ficheiro num determinado modo.

	-   **"w"** (Write / Escrever): Cria o ficheiro do zero. Se já existir, apaga tudo o que lá estava.
    
	-   **"r"** (Read / Ler) -- Abre um ficheiro existente para extrair dados.
    

2.  Manipular (**fprintf** / **fgets**) -- Escreve ou lê os dados.
    
3.  Fechar (**fclose**) -- Fecha o canal. Obrigatório para evitar ficheiros corrompidos ou bloqueados pelo Windows.
```c
FILE *f = fopen("dados.txt", "w");
fprintf(f, "Texto para o ficheiro\n");
fclose(f);
```

####  A Rede de Segurança (NULL)

-   Se tentares abrir um ficheiro para ler (**"r"**), mas o ficheiro não existir, o fopen falha e devolve o valor **NULL** (vazio).
    
-   Tentar ler ou fechar um ficheiro que vale **NULL** faz o programa crashar imediatamente.
    
-   **Boa Prática: Usar sempre um if de controlo logo após a abertura.**
```c
FILE *f = fopen("Launcher.txt", "r");  
if (f == NULL) {  
	printf("Aviso: Ficheiro nao encontrado!\n");  
	// Aqui podes decidir se fechas o programa (return 1;) ou se geras um novo ("w")  
} 
```

### 2. O Cursor de Leitura e Ciclos (Aulas 11 e 12)

-   O Windows usa um "cursor invisível" dentro do ficheiro. Sempre que um **fgets(variável, tamanho, f);** é executado, ele **lê a linha atual e empurra o cursor para o início da linha seguinte**.
    
-   Graças a este cursor, podemos enfiar o fgets dentro de um ciclo for para ler várias linhas seguidas de forma organizada, sem misturar os dados.

### 3. Arquitetura de Software: RAM vs Disco (Aula 13)

-   **A Rasteira do Ciclo: O carregamento de ficheiros ("r") deve ser feito apenas uma vez, logo no início do main**. Fazer a leitura dentro de um ciclo de menu (while) faz o programa ler o disco desnecessariamente a cada segundo, gerando lentidão e bugs.
    
#### O Fluxo Correto:
1. O programa arranca e verifica o disco (fopen em modo "r").

2. Se encontrar o ficheiro, puxa os dados para os Arrays (Memória RAM) e **fecha o ficheiro** com **fclose**
    
3.  O utilizador mexe no menu, altera os dados na RAM.
    
4.  Se o utilizador escolher gravar, o programa abre o ficheiro em modo "w", esvazia o disco, descarrega a RAM para lá e volta a fechar.

</details>

## 🧱 Volume 5: O Mundo das Structs (Aulas 14 e 15)
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

Para aceder, ler ou modificar qualquer propriedade dentro da tua struct, usas o operador ponto (**.**)

Para Variáveis Normais (int, double): Mexes nelas diretamente usando o ponto.
```c
minhaApp.vezesAberta = 5;
```

Para Arrays de Texto (char[]): Se fores preencher manualmente no código, precisas da função strcpy da <string.h>. Mas se fores ler do teclado ou de um ficheiro, o fgets faz o trabalho diretamente:
```c
fgets(minhaApp.nome, 50, stdin); // Grava direto na propriedade da struct!
```

### 4. Arrays de Structs (Escala Profissional)

O verdadeiro poder surge quando criamos um array de estruturas. Em vez de gerires matrizes paralelas complexas, geras uma lista simples de fichas:
```c
struct App listaApps[3]; // Uma lista com 3 posições, onde cada uma tem nome, caminho e contador.
````

Para navegar nisto dentro de um ciclo for, combinamos o índice do array [i] com o operador ponto (.):
```c
for (size_t i = 0; i < 3; i++) {
    printf("Nome da App %d: %s\n", i + 1, listaApps[i].nome);
}
```


### 5. Structs unidas a Ficheiros (Persistência Organizada)

Quando guardamos ou lemos dados do disco rígido (armazem.txt ou Launcher.txt), a lógica de ponteiros (FILE *) mantém-se exatamente a mesma. A única diferença é que apontamos o fprintf ou o fgets para a propriedade exata da struct:

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