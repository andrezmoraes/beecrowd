"""

1.Álcool 2.Gasolina 3.Diesel 4.Fim)
"""


codigo=0
alcool=0
gasolina=0
diesel=0


while(codigo!=4) :
    codigo=int(input())

    if(codigo==1) :
        alcool = alcool+1
    elif(codigo==2) :
        gasolina+=1
    elif(codigo==3) :
        diesel+=1

print("MUITO OBRIGADO")
print("Alcool: %d" %alcool)
print("Gasolina: %d" %gasolina)
print("Diesel: %d" %diesel)