#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char caracter;
    int quantidade;
} letra_contagem;

int main () {


    // declaracao de variaveis
    letra_contagem vetor_letras[26];
    int N,i,j;
    char str_linha[201];
    char vetor_letra_ja_usada[26];
    char vetor_ordenado[26];
    int usou = 0;
    int contador_letras_repetidas=0;
    int maior=0;
    int posicao_vetor_lju=0;
    int posicao_vetor_letras_mais_repetidas=0;
    int contador_ordenado=0;

    // lendo o numero de casos de teste
    scanf("%d", &N);
    getchar(); //// para capturar o \n depois do numero

    
    for(i=0; i<N;i++) {


        fgets(str_linha, sizeof(str_linha), stdin);
        str_linha[strcspn(str_linha, "\n")] = '\0'; //// para remover o \n do final da string capturada

        /// inicializando variaveis para cada nova linha 
        memset(vetor_letra_ja_usada, 0, sizeof(vetor_letra_ja_usada));
        memset(vetor_letras, 0, sizeof(vetor_letras));
        memset(vetor_ordenado, 0, sizeof(vetor_ordenado));
        usou=0;
        contador_letras_repetidas=0;
        maior=0;
        posicao_vetor_lju=0;
        posicao_vetor_letras_mais_repetidas=0;
        contador_ordenado=0;
        
        for(j=0;j<strlen(str_linha);j++)
           str_linha[j]=tolower(str_linha[j]);

        for(j=0;j<strlen(str_linha);j++){

                if(isalpha(str_linha[j])){

                        for(int k=0;k<26;k++){

                                if(str_linha[j]==vetor_letra_ja_usada[k]){
                                    usou=1;
                                    break;
                                }

                            }

                                if(usou==0){

                                    for(int k=0;k<strlen(str_linha);k++){

                                        if(str_linha[j]==str_linha[k]) {

                                            contador_letras_repetidas++;
                                        }

                                    }

                                    if(contador_letras_repetidas>=maior){

                                        maior=contador_letras_repetidas;
                                        vetor_letras[posicao_vetor_letras_mais_repetidas].caracter=str_linha[j];
                                        vetor_letras[posicao_vetor_letras_mais_repetidas].quantidade=maior;
                                        posicao_vetor_letras_mais_repetidas++;
                                    }

                                    contador_letras_repetidas=0;
                                    vetor_letra_ja_usada[posicao_vetor_lju]=str_linha[j];
                                    posicao_vetor_lju++;
                                }

                    
                }

            usou=0;

        }
        
       //// ainda falta ordenar a impressao das letras em ordem alfabetica quando houver empate
       /// teria sido mais usar uma tabela hash para contar as letras e 
       //// depois achar o maior valor e imprimir as letras correspondentes que estavam 
       /// na posição em lista ordenada.

        for(int k=0;k<posicao_vetor_letras_mais_repetidas;k++){

                if(vetor_letras[k].quantidade==maior){
                   
                    vetor_ordenado[ contador_ordenado]=vetor_letras[k].caracter;
                     contador_ordenado++;
                    
                }

            }

        // ordenando o vetor_ordenado em ordem alfabetica
        for(int a=0;a<contador_ordenado-1;a++){

                for(int b=a+1;b<contador_ordenado;b++){

                        if(vetor_ordenado[a]>vetor_ordenado[b]){

                            char temp = vetor_ordenado[a];
                            vetor_ordenado[a]=vetor_ordenado[b];
                            vetor_ordenado[b]=temp;

                        }

                    }

            }
        for(int k=0;k<contador_ordenado;k++){

                printf("%c", vetor_ordenado[k]);

            }
        printf("\n");

        return 0;
    }
}

