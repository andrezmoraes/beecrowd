#include <stdio.h>
 
int main() {
 
    float p1,num1,valor1,p2,num2,valor2;
    scanf("%f %f %f", &p1, &num1, &valor1);
    scanf("%f %f %f", &p2, &num2, &valor2);
    //VALOR A PAGAR= num1*valor1 + num2*valor2
    printf("VALOR A PAGAR: R$ %.2f\n",num1*valor1 + num2*valor2);
    return 0;
}