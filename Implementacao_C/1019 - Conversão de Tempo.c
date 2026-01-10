#include <stdio.h>
 
int main() {
 
   int tempo; 
  int  aux1=0, aux2=0, aux3=0;
   
   scanf("%d", &tempo);
   
   aux1= (tempo/3600);
   tempo=(tempo%3600);
   aux2= (tempo/60);
   aux3=(tempo%60);
   
   printf("%d:%d:%d\n", aux1, aux2, aux3);
}