#include <stdio.h>
#include <math.h>
 
int main() {   

    char name[1000];
    double salario_fixo;
    double vendas;
    double comissao;

    scanf("%s", &name);
    scanf("%lf", &salario_fixo);
    scanf("%lf", &vendas);

    comissao = vendas * (0.15);

    printf("TOTAL = R$ %.2lf\n", salario_fixo + comissao);

    return 0;


}