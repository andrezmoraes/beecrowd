/**
 * @file Manyfiles.c
 * @brief Este programa determina o número mínimo de "rodadas" de compilação necessárias para um conjunto de arquivos com dependências entre si.
 *
 * O problema é modelado como um grafo de dependências, onde cada arquivo é um vértice e uma dependência de um arquivo A para um arquivo B é uma aresta direcionada A -> B.
 * O número mínimo de rodadas de compilação é o comprimento do caminho mais longo no grafo de dependências.
 *
 * O algoritmo funciona em duas etapas principais:
 * 1. **Ordenação Topológica com Detecção de Ciclo:** Primeiro, o programa verifica se o grafo de dependências contém um ciclo. Se um ciclo existir (ex: A depende de B e B depende de A), é impossível compilar os arquivos em uma ordem linear. Nesse caso, o programa imprime -1. A ordenação topológica também nos dá uma ordem linear dos vértices (arquivos).
 * 2. **Cálculo do Caminho Mais Longo (Busca em Profundidade):** Se não houver ciclos, o programa calcula o caminho mais longo no grafo acíclico direcionado (DAG). Isso é feito usando uma busca em profundidade (DFS) a partir dos resultados da ordenação topológica, encontrando a "profundidade" máxima do grafo. O comprimento do caminho mais longo + 1 (para contar o nó inicial) é o número de rodadas de compilação.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // biblioteca para as cores.

#define MAX_ARQUIVOS 1121

// Define os estados de um vértice durante a busca em profundidade para a ordenação topológica.
#define BRANCO 0 // O vértice ainda não foi visitado.
#define CINZA  1 // O vértice está sendo visitado (na pilha de recursão). A detecção de um vértice CINZA indica um ciclo.
#define PRETO  2 // O vértice e todos os seus descendentes já foram visitados.

/**
 * @brief Retorna o maior entre dois números inteiros.
 * @param a O primeiro número.
 * @param b O segundo número.
 * @return O maior dos dois números.
 */
int maximo(int a, int b);

/**
 * @brief Realiza uma busca em profundidade (DFS) para encontrar o comprimento do caminho mais longo a partir de um vértice 'u'.
 * @param u O vértice inicial da busca.
 * @param visitado Array para marcar os vértices já visitados nesta busca específica (diferente do 'estado' da ordenação topológica).
 * @param grafo A matriz de adjacência que representa o grafo de dependências.
 * @param num_arquivos O número total de arquivos (vértices) no grafo.
 * @return O comprimento do caminho mais longo começando em 'u'.
 */
int busca_profundidade(int u, bool visitado[], int grafo[][MAX_ARQUIVOS], int num_arquivos);

/**
 * @brief Realiza a ordenação topológica do grafo e detecta a presença de ciclos.
 * @param u O vértice atual a ser visitado.
 * @param estado Array que armazena o estado de cada vértice (BRANCO, CINZA, PRETO).
 * @param ordenados Array para armazenar o resultado da ordenação topológica (em ordem reversa).
 * @param posicao Ponteiro para a próxima posição livre no array 'ordenados'.
 * @param grafo A matriz de adjacência do grafo.
 * @param num_arquivos O número total de arquivos.
 * @return `true` se um ciclo for detectado, `false` caso contrário.
 */
bool ordenacao_topologica(int u, int estado[], int ordenados[], int *posicao, int grafo[][MAX_ARQUIVOS], int num_arquivos);


int main() {
    int num_arquivos;
    
    // Lê o número de arquivos de cada caso de teste até o final da entrada (EOF).
    while (scanf("%d", &num_arquivos) != EOF) {
        
        // Inicializa a matriz de adjacência que representa o grafo. grafo[i][j] = 1 significa que j depende de i.
        int grafo[MAX_ARQUIVOS][MAX_ARQUIVOS] = {0};
        
        // Arrays auxiliares para os algoritmos.
        int estado[MAX_ARQUIVOS] = {BRANCO};   // Para a ordenação topológica.
        int ordenados[MAX_ARQUIVOS] = {0};    // Armazena a ordem topológica.
        bool visitado[MAX_ARQUIVOS] = {false}; // Para a busca de profundidade do caminho mais longo.
        
        int posicao_ordenacao = num_arquivos; // Começa a preencher o array 'ordenados' do final.
        
        // Lê as dependências de cada arquivo para construir o grafo.
        for (int i = 1; i <= num_arquivos; ++i) {
            int num_dependencias;
            scanf("%d", &num_dependencias);
            for (int j = 0; j < num_dependencias; ++j) {
                int dependencia;
                scanf("%d", &dependencia);
                // Cria uma aresta de 'dependencia' para 'i', indicando que 'i' depende de 'dependencia'.
                grafo[dependencia][i] = 1;
            }
        }
        
        // Executa a ordenação topológica para verificar a existência de ciclos.
        bool tem_ciclo = false;
        for (int i = 1; i <= num_arquivos && !tem_ciclo; ++i) {
            if (estado[i] == BRANCO) {
                // Se encontrar um ciclo, a variável 'tem_ciclo' se tornará 'true'.
                if (ordenacao_topologica(i, estado, ordenados, &posicao_ordenacao, grafo, num_arquivos)) {
                    tem_ciclo = true;
                }
            }
        }
        
        // Se um ciclo foi detectado, é impossível compilar. Imprime -1.
        if (tem_ciclo) {
            printf("-1\n");
            continue; // Pula para o próximo caso de teste.
        }
        
        // Se não há ciclos, calcula o caminho mais longo (profundidade máxima).
        int profundidade_maxima = 0;
        // Itera sobre os arquivos na ordem topológica.
        for (int i = 1; i <= num_arquivos; ++i) {
            int no_atual = ordenados[i];
            // Se o nó ainda não foi visitado para o cálculo da profundidade...
            if (!visitado[no_atual]) {
                // ...calcula a profundidade a partir dele e atualiza o máximo global.
                profundidade_maxima = maximo(profundidade_maxima, 
                                           busca_profundidade(no_atual, visitado, grafo, num_arquivos));
            }
            
        }
        
        // O resultado é a profundidade máxima encontrada.
        printf("%d\n", profundidade_maxima); /// printa a resposta
    }
    
    return 0;
}

int maximo(int a, int b) {
    return a > b ? a : b;
}

// Busca em profundidade para calcular a profundidade máxima da compilação
int busca_profundidade(int u, bool visitado[], int grafo[][MAX_ARQUIVOS], int num_arquivos) {
    
    visitado[u] = true; // Marca o vértice atual como visitado.
    int profundidade_maxima_local = 0;
    
    // Percorre todos os vizinhos do vértice 'u'.
    for (int i = 1; i <= num_arquivos; ++i) {
        
        // Se 'i' é um vizinho de 'u' (ou seja, 'u' depende de 'i')...
        if (grafo[u][i]) { // Note que a lógica do problema inverte a seta da dependência
             profundidade_maxima_local = maximo(profundidade_maxima_local, busca_profundidade(i, visitado, grafo, num_arquivos));
        }
        
    }
    
    // A profundidade a partir de 'u' é 1 (ele mesmo) + a profundidade máxima de seus vizinhos.
    return profundidade_maxima_local + 1;
}

// Ordenação topológica com verificação de ciclo

bool ordenacao_topologica(int u, int estado[], int ordenados[], int *posicao, int grafo[][MAX_ARQUIVOS], int num_arquivos) {
    
    estado[u] = CINZA; // Marca 'u' como "em visita".
    
    // Percorre os vizinhos de 'u'.
    for (int i = 1; i <= num_arquivos; ++i) {
        
        if (grafo[u][i]) { // Se existe uma aresta de 'u' para 'i'.
        
            // Se o vizinho 'i' está no estado CINZA, encontramos uma aresta de retorno, o que significa que há um ciclo.
            if (estado[i] == CINZA) { 
                return true; // Ciclo detectado.
            }
            
            // Se o vizinho 'i' ainda não foi visitado, continua a busca a partir dele.
            else if (estado[i] == BRANCO && ordenacao_topologica(i, estado, ordenados, posicao, grafo, num_arquivos)) {
                return true; // Propaga a detecção do ciclo.
            }
            
        }
    }
    
    // Quando terminamos de visitar todos os descendentes de 'u', ele é marcado como PRETO.
    estado[u] = PRETO; //// marca como visitado
    
    // Adiciona 'u' ao final da lista de ordenação topológica (que está sendo preenchida de trás para frente).
    ordenados[(*posicao)--] = u;
    
    return false; // Nenhum ciclo encontrado a partir de 'u'.
}