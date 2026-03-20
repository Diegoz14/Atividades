def normalizar_ponto(valor: float, maximo: float, fator: float) -> float:
    return (valor / maximo) + fator

def processar_normalizacao(brutos: list, normalizados: list,
                           fator: float) -> None:
    maximo = max(brutos)
    for p in brutos:
        normalizados.append(normalizar_ponto(p, maximo, fator))

def main():
    brutos      = [10.0, 20.0, 50.0]
    normalizados = []
    fator       = 0.5

    processar_normalizacao(brutos, normalizados, fator)

    print(f"IA Dados: {normalizados}")

main()