def calcular_imc(peso, altura):
    """
    Calcula o Índice de Massa Corporal (IMC).

    Args:
        peso (float): O peso da pessoa em quilogramas.
        altura (float): A altura da pessoa em metros.

    Returns:
        float: O valor do IMC calculado.
    """
    # Garante que a altura não é zero ou negativa para evitar divisão por zero.
    if altura <= 0:
        raise ValueError("A altura deve ser um valor positivo.")
    # Fórmula do IMC: peso / (altura * altura)
    return peso / (altura ** 2)

def classificar_imc(imc):
    """
    Classifica o IMC de acordo com as categorias da OMS.

    Args:
        imc (float): O valor do IMC.

    Returns:
        str: A classificação do IMC.
    """
    # Estrutura condicional para determinar a faixa de classificação do IMC.
    if imc < 18.5:
        return "Abaixo do peso"
    elif 18.5 <= imc < 25:
        return "Peso normal"
    elif 25 <= imc < 30:
        return "Sobrepeso"
    elif 30 <= imc < 35:
        return "Obesidade Grau I"
    elif 35 <= imc < 40:
        return "Obesidade Grau II"
    else:
        return "Obesidade Grau III (mórbida)"

# O bloco a seguir será executado apenas quando o script for executado diretamente.
if __name__ == "__main__":
    try:
        # Solicita ao usuário que insira seu peso e altura.
        peso_usuario = float(input("Digite seu peso em kg (ex: 70.5): "))
        altura_usuario = float(input("Digite sua altura em metros (ex: 1.75): "))
        
        # Chama a função para calcular o IMC.
        imc_calculado = calcular_imc(peso_usuario, altura_usuario)
        # Chama a função para classificar o IMC.
        classificacao = classificar_imc(imc_calculado)
        
        # Exibe o resultado formatado para o usuário.
        print(f"\nSeu IMC é: {imc_calculado:.2f}")
        print(f"Classificação: {classificacao}")
        
    except ValueError as e:
        # Trata o erro caso o usuário insira um valor não numérico.
        print(f"\nErro: {e}. Por favor, insira valores numéricos válidos.")
    except Exception as e:
        # Trata quaisquer outros erros inesperados que possam ocorrer.
        print(f"\nOcorreu um erro inesperado: {e}")