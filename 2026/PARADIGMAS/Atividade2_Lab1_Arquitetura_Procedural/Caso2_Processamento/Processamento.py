def aplicar_taxa(saldo: float, taxa: float, limite: float) -> float:
    if saldo > limite:
        return saldo - taxa
    return saldo

def processar_contas(saldos: list, taxa: float, limite: float) -> float:
    total_taxas = 0.0
    for i in range(len(saldos)):
        novo_saldo = aplicar_taxa(saldos[i], taxa, limite)
        if novo_saldo != saldos[i]:
            total_taxas += taxa
        saldos[i] = novo_saldo
    return total_taxas

def main():
    saldos = [1000.0, 2500.0, 300.0]
    taxa = 15.0
    limite = 500.0

    total_taxas = processar_contas(saldos, taxa, limite)

    print(f"Saldos: {saldos} | Taxas: {total_taxas}")

main()