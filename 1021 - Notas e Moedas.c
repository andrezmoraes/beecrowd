
int main() {
    int valores[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1}; // valores das notas e moedas em centavos
    int quantidade[12] = {0}; 
    double valor; 
    int valorInt; 
    int i;

  
    scanf("%lf", &valor);
    valorInt = (int)(valor * 100 + 0.5); 

   
    for (i = 0; i < 12; i++) {
        quantidade[i] = valorInt / valores[i];
        valorInt %= valores[i];
    }

    
    printf("NOTAS:\n");
    for (i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %d.00\n", quantidade[i], valores[i] / 100);
    }
    
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", quantidade[6]);
    for (i = 7; i < 12; i++) {
        printf("%d moeda(s) de R$ 0.%02d\n", quantidade[i], valores[i]);
    }

    return 0;
}