import random
import time

def gerador_de_log():
    niveis  = ["INFO", "WARNING", "ERROR"]
    entrada = 1
    while True:
        nivel     = random.choice(niveis)
        timestamp = time.strftime("%H:%M:%S")
        yield f"[{timestamp}] [{nivel}] Entrada #{entrada} processada"
        entrada += 1

def main():
    log = gerador_de_log()

    for _ in range(10):
        print(next(log))

main()