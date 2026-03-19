'''

                            
'''

N = int(input())

mais_poderoso = ['', 0, 0, 0] # criou uma tupla

for i in range(N):
    
    personagem = input().split() # recebeu uma lista
    
    if int(personagem[1]) > int(mais_poderoso[1]) :
        
        mais_poderoso = personagem.copy()
    
    elif int(personagem[1]) == int(mais_poderoso[1]):
        
        if int(personagem[2]) > int(mais_poderoso[2]):
            
            mais_poderoso = personagem.copy()
            
        elif int(personagem[2]) == int(mais_poderoso[2]):
            
            if int(personagem[3]) < int(mais_poderoso[3]):
                mais_poderoso = personagem.copy()
                
            elif int(personagem[3]) == int(mais_poderoso[3]):
                
                if personagem[0] < mais_poderoso[0]:
                    mais_poderoso = personagem.copy()
                    
                    
   
    

print(mais_poderoso[0])
            
            
        


