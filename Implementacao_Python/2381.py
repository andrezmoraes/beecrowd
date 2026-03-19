
lista = input().split()

print(type(lista))

N = int(lista[0])
K = int(lista[1])

lista_nomes = list()

for i in range(1,N+1):
    nome = input()
    lista_nomes.append(nome)
    

lista_nomes.sort()

print(lista_nomes[K-1])