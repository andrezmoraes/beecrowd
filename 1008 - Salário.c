#include <stdio.h>

int main()
{
    int NUMBER, HOUR;
    float SALARY, VALOR_HOUR;
    
    scanf("%d", &NUMBER);
    scanf("%d", &HOUR);
    scanf("%f", &VALOR_HOUR);
    
    SALARY = VALOR_HOUR * HOUR;
    
    printf("NUMBER = %d\n", NUMBER);
    printf("SALARY = U$ %.2f\n", SALARY);
    
    return 0;
    
    
}