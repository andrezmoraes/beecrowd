#include <stdio.h>
#include <math.h>

int main()
{
    double raio;
    double volume =0;
    
    scanf("%lf", &raio);
    
    volume = ((4./3)) * 3.14159 * pow(raio, 3);
    
    printf("VOLUME = %.3lf\n", volume);
}
