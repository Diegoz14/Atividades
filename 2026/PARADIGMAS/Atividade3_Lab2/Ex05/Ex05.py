def aplicar_desconto_perigoso(precos: list, desconto: float) -> None:
    for i in range(len(precos)):
        precos[i] = precos[i] - desconto  

def aplicar_desconto_seguro(precos: list, desconto: float) -> list:
    copia = precos[:]
    for i in range(len(copia)):
        copia[i] = copia[i] - desconto
    return copia

def main():
    estoque = [100.0, 250.0, 80.0]

    print(f"Estoque original:         {estoque}")

    aplicar_desconto_perigoso(estoque, 10.0)
    print(f"Apos desconto perigoso:   {estoque}") 

    estoque = [100.0, 250.0, 80.0]  
    novo_estoque = aplicar_desconto_seguro(estoque, 10.0)
    print(f"Estoque original intacto: {estoque}")
    print(f"Novo estoque com desconto:{novo_estoque}")

main()