#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> /// biblioteca para as cores.

#define MAX_ARQUIVOS 1121


// 0 = BRANCO (não visitado), 1 = CINZA (em visita), 2 = PRETO (visitado)
#define BRANCO 0
#define CINZA 1
#define PRETO 2

int maximo(int a, int b);

int busca_profundidade(int u, bool visitado[], int grafo[][MAX_ARQUIVOS], int num_arquivos);

bool ordenacao_topologica(int u, int estado[], int ordenados[], int *posicao, int grafo[][MAX_ARQUIVOS], int num_arquivos);


int main() {
    
    int num_arquivos;
    
    while (scanf("%d", &num_arquivos) != EOF) {
        
        
        // Matriz de adjacência para representar as dependências
        int grafo[MAX_ARQUIVOS][MAX_ARQUIVOS] = {0};
        
        // Arrays auxiliares
        int estado[MAX_ARQUIVOS] = {BRANCO}; // Estado de visitação para ordenação topológica
        int ordenados[MAX_ARQUIVOS] = {0};   // Ordem topológica dos arquivos, no inicio está vazio
        bool visitado[MAX_ARQUIVOS] = {false}; // vetor para marcar se o grafo foi visitado
        
        int posicao_ordenacao = num_arquivos;
        
        //for que lê a dependencia de cada arquivo.
        for (int i = 1; i <= num_arquivos; ++i) {
            
            int num_dependencias;
            
            scanf("%d", &num_dependencias);
            
            for (int j = 0; j < num_dependencias; ++j) {
                
                int dependencia;
                
                scanf("%d", &dependencia);
                // aponta para a dependencia de cada grafo
                
                grafo[dependencia][i] = 1;
            }
        }
        
        // Verificando se há ciclo no grafo de dependências
        bool tem_ciclo = false;
        for (int i = 1; i <= num_arquivos && !tem_ciclo; ++i) {
            
            if (estado[i] == BRANCO) {
                tem_ciclo = ordenacao_topologica(i, estado, ordenados, &posicao_ordenacao, grafo, num_arquivos);
            }
            
        }
        
        if (tem_ciclo) {
            printf("-1\n");
            continue;
        }
        
       //// calcula a profundidade máxima do vertice,
        int profundidade_maxima = 0;
        for (int i = 1; i <= num_arquivos; ++i) {
            
            if (!visitado[ordenados[i]]) {
                profundidade_maxima = maximo(profundidade_maxima, 
                                           busca_profundidade(ordenados[i], visitado, grafo, num_arquivos));
            }
            
        }
        
        printf("%d\n", profundidade_maxima); /// printa a resposta
    }
    
    return 0;
}

int maximo(int a, int b) {
    return a > b ? a : b;
}

// Busca em profundidade para calcular a profundidade máxima da compilação
int busca_profundidade(int u, bool visitado[], int grafo[][MAX_ARQUIVOS], int num_arquivos) {
    
    visitado[u] = true;
    int profundidade_maxima = 0;
    
    for (int i = 1; i <= num_arquivos; ++i) {
        
        if (grafo[u][i] && !visitado[i]) { /// se o grafo existe e ele não foi visitado;
            profundidade_maxima = maximo(profundidade_maxima, busca_profundidade(i, visitado, grafo, num_arquivos));
        }
        
    }
    
    return profundidade_maxima + 1;
}

// Ordenação topológica com verificação de ciclo

bool ordenacao_topologica(int u, int estado[], int ordenados[], int *posicao, int grafo[][MAX_ARQUIVOS], int num_arquivos) {
    
    estado[u] = CINZA; // marca que está sendo visitado
    
    for (int i = 1; i <= num_arquivos; ++i) {
        
        if (grafo[u][i]) { // se existe ligação entre 'u' e 'i'
        
            if (estado[i] == CINZA) { //// retorno para o próprio grafo, existe ciclo
                return true;
            }
            
            //// marca como não visitado e ordena.
            else if (estado[i] == BRANCO && ordenacao_topologica(i, estado, ordenados, posicao, grafo, num_arquivos)) {
                return true;
            }
            
        }
    }
    
    // insere na lista ordenada mas na ordem reversa.
    
    ordenados[(*posicao)--] = u;
    
    estado[u] = PRETO; //// marca como visitado
    
    return false;
}

