#include <iostream>
#include <stack>
# include <vector>

using namespace std;

int main(){
    int N, x;
    int i=0, j=0; 
    int flag = 0;
    
    
    
    while(cin >> N){ /// se for zero termina o programa
        if(!N)  break;

        while(cin >> x){ /// se for zero 
            if(!x){
                cout << endl;
                break;
            }

            stack<int> estacao;
            vector < int> entrada;
            vector <int > saida;

            entrada.push_back(1); 
            saida.push_back(x);
        
            for(i=2; i<=N; i++) {

                cin >> x;

                entrada.push_back(i);
                saida.push_back(x);

            }

            i=0; //// ponteiro para o vetor de entrada
            j=0; //// ponteiro para o vetor de saida
            flag = 0; /// flag para indicar se a sequência é possível ou não

            while(j < N) { //// lógica do algoritmo:


                //// verificar se o trem na estação é o próximo a sair, se sim, retirar da estação e avançar o ponteiro de saída
                if ( !estacao.empty() && estacao.top() == saida[j] ) { 
                    estacao.pop();
                    j++;
                }

                //// se o trem na estação não é o próximo a sair, verifica se tem trens chegando e empilha o próximo
                else if (i < N) {
                    estacao.push(entrada[i]);
                    i++;
                }

                else { /// se não tem trens chegando e o trem na estação não é o próximo a sair, a sequência é impossível
                    flag = 1;
                    break;
                }
                
             
        }

        if (flag) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    
}
return 0;
}