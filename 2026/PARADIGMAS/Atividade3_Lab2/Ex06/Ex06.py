import os

def buscar_arquivo(pasta: str, nome: str) -> str:
    for item in os.listdir(pasta):
        caminho_atual = os.path.join(pasta, item)

        if item == nome:
            return f"Arquivo encontrado: {caminho_atual}"

        if os.path.isdir(caminho_atual):
            resultado = buscar_arquivo(caminho_atual, nome)
            if resultado:
                return resultado

    return ""

def main():
    raiz = os.path.dirname(__file__)
    print(buscar_arquivo(raiz, "Curriculo.docx") or "Arquivo nao encontrado.")
    print(buscar_arquivo(raiz, "Planilha.xlsx") or "Arquivo nao encontrado.")
    print(buscar_arquivo(raiz, "Config.ini") or "Arquivo nao encontrado.")
    print(buscar_arquivo(raiz, "apresentacao.txt") or "Arquivo nao encontrado.")

main()