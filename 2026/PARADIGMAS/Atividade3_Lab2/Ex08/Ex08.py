def linha_de_montagem():
    numero = 1
    while True:
        peca = f"Peca #{numero} montada"
        yield peca
        numero += 1

def main():
    linha = linha_de_montagem()

    print(next(linha))  
    print(next(linha))  
    print(next(linha))
    print(next(linha))
    print(next(linha))

main()