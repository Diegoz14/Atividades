#include <stdio.h>
int verificar_peca(float medida, float minimo, float maximo) {
    return (medida >= minimo && medida <= maximo) ? 1 : 0;
}
void registrar_resultado(int aprovada, int *boas, int *defeitos) {
    if (aprovada)
        *boas     = *boas + 1;
    else
        *defeitos = *defeitos + 1;
}
int main(void) {
    float peca    = 15.2;
    float minimo  = 14.5;
    float maximo  = 15.5;
    int   boas    = 0;
    int   defeitos = 0;

    int aprovada = verificar_peca(peca, minimo, maximo);
    registrar_resultado(aprovada, &boas, &defeitos);

    printf("Boas: %d | Defeitos: %d\n", boas, defeitos);
    return 0;
}
