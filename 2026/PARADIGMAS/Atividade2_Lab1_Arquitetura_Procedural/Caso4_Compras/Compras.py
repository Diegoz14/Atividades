def calcular_frete(peso_total: float, limite: float,
                   taxa_alta: float, taxa_baixa: float) -> float:
    if peso_total > limite:
        return peso_total * taxa_alta
    return peso_total * taxa_baixa

def adicionar_item(carrinho: list, item: str, peso: float,
                   peso_total: float) -> float:
    carrinho.append(item)
    return peso_total + peso

def main():
    carrinho   = []
    peso_total = 0.0

    peso_total = adicionar_item(carrinho, "Placa de Video", 1.5, peso_total)
    frete      = calcular_frete(peso_total, 1.0, 15.0, 10.0)

    print(f"Carrinho: {carrinho} | Frete: {frete}")

main()