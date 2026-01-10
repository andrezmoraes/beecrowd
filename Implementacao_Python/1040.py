import math

x = input().split()

N1 = float(x[0])
N2 = float(x[1])
N3 = float(x[2])
N4 = float(x[3])

media = (N1*2 + N2*3 + N3*4 + N4*1)/10

print(f"Media: {media:.1f}")

if(media>=7.0):
    print("Aluno aprovado.")

elif(media<5.0):
    print("Aluno reprovado.")

elif(media>=5.0 and media<=6.9):
    print("Aluno em exame.")

    NE = float(input())

    print(f"Nota do exame: {NE:.1f}")

    media = (media + NE)/2

    if(media>=5.0):
        print("Aluno aprovado.")
    else:
        print("Aluno reprovado.")

    print(f"Media final: {media:.1f}")

    


