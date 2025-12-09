# Repositório de Desafios Beecrowd e Utilitários

Este repositório contém soluções para diversos problemas da plataforma Beecrowd (anteriormente conhecida como URI Online Judge) e outros scripts utilitários.

## Conteúdo

Atualmente, o projeto inclui os seguintes arquivos:

-   `calculadora_imc.py`: Um script em Python para calcular o Índice de Massa Corporal (IMC).
-   `Manyfiles.c`: Um programa em C que resolve o problema de determinar o número mínimo de "rodadas" de compilação para um conjunto de arquivos com dependências entre si.

---

## Calculadora de IMC (`calculadora_imc.py`)

Este script em Python calcula o Índice de Massa Corporal (IMC) de uma pessoa com base no peso e altura fornecidos.

### Como usar

1.  Certifique-se de ter o Python instalado.
2.  Execute o arquivo a partir do seu terminal:
    ```bash
    python calculadora_imc.py
    ```
3.  Insira seu peso em quilogramas (kg) quando solicitado.
4.  Insira sua altura em metros (m) quando solicitado.

O programa exibirá o seu IMC e a classificação correspondente (Abaixo do peso, Peso normal, etc.).

---

## Compilação de Múltiplos Arquivos (`Manyfiles.c`)

Este programa em C determina o número mínimo de "rodadas" de compilação necessárias para um conjunto de arquivos com dependências mútuas. Ele modela as dependências como um grafo e encontra o caminho mais longo, que corresponde ao número de rodadas.

### Funcionalidade

-   **Detecção de Ciclo:** O programa primeiro verifica se existem dependências circulares (ex: Arquivo A depende do B e o B depende do A). Se um ciclo for encontrado, a compilação é impossível, e o programa informa `-1`.
-   **Cálculo de Rodadas:** Se não houver ciclos, o programa calcula o número mínimo de rodadas de compilação necessárias.

### Como compilar e usar

1.  Você precisará de um compilador C (como o GCC).
2.  Compile o arquivo:
    ```bash
    gcc Manyfiles.c -o Manyfiles
    ```
3.  Execute o programa:
    ```bash
    ./Manyfiles
    ```
4.  Forneça os dados de entrada no formato esperado pelo problema original do Beecrowd. A entrada consiste no número de arquivos, seguido pelas listas de dependência de cada um. O programa lerá da entrada padrão.