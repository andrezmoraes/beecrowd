
N = input()

N = float(N) # primeiro converte para float

N = int(N*100) # depois multiplica e converte

print("NOTAS:")

print(f"{int(N//10000)} nota(s) de R$ 100.00")

N = N % 10000 # funciona para numeros de ponto flutuante

print(f"{int(N//5000)} nota(s) de R$ 50.00")

N = N % 5000

print(f"{int(N//2000)} nota(s) de R$ 20.00")

N = N % 2000

print(f"{int(N//1000)} nota(s) de R$ 10.00")

N = N % 1000

print(f"{int(N//500)} nota(s) de R$ 5.00")

N = N % 500

print(f"{int(N//200)} nota(s) de R$ 2.00")

N = N % 200

print("MOEDAS:")

print(f"{int(N//100)} moeda(s) de R$ 1.00")

N = N % 100

print(f"{int(N//50)} moeda(s) de R$ 0.50")

N = N % 50

print(f"{int(N//25)} moeda(s) de R$ 0.25")

N = N % 25

print(f"{int(N//10)} moeda(s) de R$ 0.10")

N = N % 10

print(f"{int(N//5)} moeda(s) de R$ 0.05")

N = N % 5

print(f"{int(N//1)} moeda(s) de R$ 0.01")




