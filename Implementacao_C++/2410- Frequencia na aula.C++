#include <iostream>
# include <set>
using namespace std;

int main() 
{
  
  set <int> chamada;
  int N; ///// numero de registros
  int i=0;
  int v;
    
    cin >> N;
    
    for(i=0; i<N; i++) {
      
      cin >> v;
      
      chamada.insert(v);
      
    }
    
    cout << chamada.size() << endl;
}