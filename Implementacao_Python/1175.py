
lista_numeros = list()
lista_invertida = list()

for i in range(0,20):
    
    x = int(input())
    lista_numeros.append(x)
    
    
for i in range(19,-1,-1):
    
    lista_invertida.append(lista_numeros[i])
    
for i in range(0,20):
    print(f"N[{i}] = {lista_invertida[i]}")


    
    