class Personagem:
    def __init__(self, nome, hp_inicial):
        if hp_inicial <= 0:
            raise ValueError("HP inicial deve ser maior que zero.")
        self.__nome = nome
        self.__hp   = hp_inicial           # atributo privado, nasce valido

    def receber_dano(self, dano):
        if dano < 0:
            raise ValueError("Dano nao pode ser negativo.")
        self.__hp = max(0, self.__hp - dano)   # invariante: hp trava em zero

    def get_hp(self):
        return self.__hp

    def get_nome(self):
        return self.__nome

    def esta_vivo(self):
        return self.__hp > 0


def main():
    heroi = Personagem("Diego", 100)

    print(f"Personagem: {heroi.get_nome()} | HP: {heroi.get_hp()}")

    heroi.receber_dano(30)
    print(f"Apos 30 de dano | HP: {heroi.get_hp()}")

    heroi.receber_dano(9999)               # tentando deixar vida negativa
    print(f"Apos dano de 9999 | HP: {heroi.get_hp()}")
    print(f"Heroi ainda vivo? {heroi.esta_vivo()}")

    try:
        heroi.receber_dano(-50)            # tentando dano negativo
    except ValueError as e:
        print(f"BLOQUEADO: {e}")

main()