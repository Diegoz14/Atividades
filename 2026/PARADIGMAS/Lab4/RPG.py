from abc import ABC, abstractmethod

# Interface (Contrato)
class Curavel(ABC):
    @abstractmethod
    def receber_cura(self, valor):
        pass


# Classe Abstrata
class Heroi(ABC):
    def __init__(self, nome, hp_inicial):
        if hp_inicial <= 0:
            raise ValueError("HP inicial deve ser maior que zero.")
        self._nome = nome
        self._hp = hp_inicial  # protegido (não público direto)

    @abstractmethod
    def receber_dano(self, dano):
        pass

    def get_hp(self):
        return self._hp

    def get_nome(self):
        return self._nome

    def esta_vivo(self):
        return self._hp > 0


# Classe Guerreiro
class Guerreiro(Heroi, Curavel):
    def __init__(self, nome, hp_inicial, armadura):
        super().__init__(nome, hp_inicial)
        self.armadura = armadura  # reduz dano

    def receber_dano(self, dano):
        if dano < 0:
            raise ValueError("Dano nao pode ser negativo.")

        dano_reduzido = max(0, dano - self.armadura)
        self._hp = max(0, self._hp - dano_reduzido)

    def receber_cura(self, valor):
        if valor < 0:
            raise ValueError("Cura nao pode ser negativa.")
        self._hp += valor


# Classe Mago
class Mago(Heroi, Curavel):
    def __init__(self, nome, hp_inicial, mana):
        super().__init__(nome, hp_inicial)
        self.mana = mana

    def receber_dano(self, dano):
        if dano < 0:
            raise ValueError("Dano nao pode ser negativo.")

        # Usa mana primeiro para absorver dano
        if self.mana >= dano:
            self.mana -= dano
        else:
            dano_restante = dano - self.mana
            self.mana = 0
            self._hp = max(0, self._hp - dano_restante)

    def receber_cura(self, valor):
        if valor < 0:
            raise ValueError("Cura nao pode ser negativa.")

        self._hp += valor
        self.mana += valor * 0.5  # mago também recupera mana


# Classe de Batalha
class Batalha:
    def __init__(self, herois):
        self.herois = herois  # lista de Heroi

    def bola_de_fogo(self, dano):
        print("\n🔥 Bola de Fogo lançada!\n")

        for heroi in self.herois:  # POLIMORFISMO aqui
            heroi.receber_dano(dano)
            print(f"{heroi.get_nome()} | HP: {heroi.get_hp()}")


# Teste
def main():
    g1 = Guerreiro("Thor", 150, armadura=10)
    m1 = Mago("Merlin", 100, mana=80)

    herois = [g1, m1]

    batalha = Batalha(herois)

    batalha.bola_de_fogo(50)

    print("\n💚 Aplicando cura...\n")
    for h in herois:
        h.receber_cura(20)
        print(f"{h.get_nome()} | HP: {h.get_hp()}")


main()