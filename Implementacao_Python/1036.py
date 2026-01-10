
import math
# Pede "10 20" e atribui x=10, y=20
x = input().split()

A = float(x[0])
B = float(x[1])
C = float(x[2])

delta = (B**2) - (4*A*C)

#

if (A==0.0):
    print("Impossivel calcular")


elif(delta<0):
    print("Impossivel calcular")

else:
    
    R1= ((-B) + (math.sqrt(delta)))/(2*A)
    R2= ((-B) - (math.sqrt(delta)))/(2*A)

    if(delta==0):
        print(f"R1 = {R1:.5f}")
        print(f"R1 = {R1:.5f}")
    
    else:
        print(f"R1 = {R1:.5f}")
        print(f"R2 = {R2:.5f}")