# Laboratório prático — Ponteiros e Arrays (Unidade 5)

Resolução dos **6 exercícios** do laboratório de Linguagem C sobre vetores, matrizes, strings, ponteiros e acesso à memória. Cada exercício está em um arquivo próprio, conforme solicitado na atividade.

## Organização dos arquivos

| Exercício | Arquivo | Tema |
|---|---|---|
| 1 | [01.c](01.c) | Maior e média de um vetor |
| 2 | [02.c](02.c) | Dobrar um vetor por referência |
| 3 | [03.c](03.c) | Inverter uma string sem strlen |
| 4 | [04.c](04.c) | Soma de cada linha de uma matriz 3x3 |
| 5 | [05.c](05.c) | Aritmética de ponteiros e endereços |
| 6 | [06.c](06.c) | Acesso fora dos limites com AddressSanitizer |

## Respostas finais

### Exercício 1 — Maior e média de um vetor

**Resposta:** o programa lê 5 números inteiros, identifica o maior e calcula a média dividindo a soma por `5.0`, para obter um resultado decimal com duas casas.

**Exemplo:**

```text
Digite 5 inteiros: 4 9 2 7 3
Maior: 9
Media: 5.00
```

**Código:** [`b1.c`](b1.c).

### Exercício 2 — Dobrar um vetor por referência

**Resposta:** a função `void dobra(int *v, int n)` recebe o endereço do primeiro elemento do vetor e multiplica seus `n` elementos por 2, alterando o vetor original.

**Saída:**

```text
2 4 6 8 10
```

**Código:** [`b2.c`](b2.c).

### Exercício 3 — Inverter uma string sem `strlen`

**Resposta:** o programa conta os caracteres até encontrar `\0` e imprime a palavra em ordem inversa, sem usar `strlen`.

**Exemplo:**

```text
Digite uma palavra: casa
Invertida: asac
```

**Código:** [`b3.c`](b3.c).

### Exercício 4 — Soma de cada linha de uma matriz 3×3

**Resposta:** dois laços percorrem a matriz: o primeiro seleciona a linha e o segundo soma seus três elementos.

**Saída:**

```text
Linha 0: 6
Linha 1: 15
Linha 2: 24
```

**Código:** [`b4.c`](b4.c).

### Exercício 5 — Aritmética de ponteiros (endereços reais)

**Resposta:** os endereços consecutivos aumentam de acordo com o tamanho de cada elemento. Em uma plataforma comum, `int` ocupa 4 bytes e `double`, 8 bytes; por isso, os endereços avançam de 4 em 4 e de 8 em 8, respectivamente. **Sim**, isso corresponde à fórmula:

```text
endereco(v[i]) = endereco_base + i × sizeof(tipo)
```

O programa imprime os **endereços reais da execução**, que mudam conforme o sistema e a execução. Exemplo *apenas ilustrativo* de dois endereços consecutivos de `int`:

```text
&v[0] = 0x1000
&v[1] = 0x1004
Diferenca = 4 bytes
```

**Código:** [`b5.c`](b5.c). Execute-o para copiar os endereços reais observados no seu computador.

### Exercício 6 — Acesso fora dos limites com AddressSanitizer

**Resposta:** o vetor `v` tem 10 posições válidas, de `v[0]` até `v[9]`. O acesso a `v[10]` é inválido. Ao executar com AddressSanitizer, a ferramenta deve sinalizar um erro de **`stack-buffer-overflow`**, indicando a linha do acesso fora dos limites.

**Importante:** este arquivo contém um erro **intencional**, exigido pela atividade. Não use esse acesso em programas reais.

**Código:** [`b6.c`](b6.c).

## Perguntas para entregar / discutir

**1. Por que `dobra` consegue alterar o vetor do `main` sem `return`?**

Porque um vetor passado como argumento fornece à função um ponteiro para seus elementos. Assim, `dobra` modifica diretamente os dados do vetor original, sem precisar devolver outro vetor.

**2. No exercício 5, mostre dois endereços consecutivos de `int` e a diferença em bytes.**

Exemplo ilustrativo: `0x1000` e `0x1004`, com diferença de **4 bytes**. Os endereços reais devem ser obtidos executando [`b5.c`](b5.c); o valor da diferença depende de `sizeof(int)` na plataforma.

**3. O que o AddressSanitizer detectou e por que, sem ele, o erro poderia passar despercebido?**

O AddressSanitizer detectou uma escrita fora do vetor (`v[10]`), que poderia passar despercebida sem a ferramenta porque C não verifica automaticamente os limites dos arrays.

**O programa funcionaria sem o `-fsanitize=address`?** Talvez pareça funcionar, trave ou produza comportamento inesperado; o acesso é **comportamento indefinido**. O sanitizer adiciona verificações em execução que ajudam a identificar e localizar o erro.

## Como compilar e executar

Abra um terminal dentro da pasta do projeto e execute, por exemplo, para o exercício 1:

```bash
gcc -std=c11 -Wall -Wextra b1.c -o b1
./b1
```

Para os exercícios **2 a 5**, substitua `b1` pelo número correspondente (`b2`, `b3`, `b4` ou `b5`).

Para o **exercício 6**, use obrigatoriamente o AddressSanitizer para verificar o erro esperado:

```bash
gcc -std=c11 -Wall -Wextra -g -fsanitize=address b6.c -o b6
./b6
```

> No Windows, se estiver usando PowerShell, execute os programas com `./b1.exe` ou `.\b1.exe` conforme o ambiente. O exercício 6 encerra com erro de propósito ao detectar o acesso inválido.

---

**Referência:** atividade *Lab prático — Ponteiros e arrays (Unidade 5)*, exercícios 1 a 6 e questões para discussão.
