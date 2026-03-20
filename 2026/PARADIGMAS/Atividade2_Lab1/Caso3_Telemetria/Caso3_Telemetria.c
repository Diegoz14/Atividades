#include <stdio.h>
float calcular_posicao(float pos, float velocidade, float tempo) {
    return pos + (velocidade * tempo);
}
void atualizar_posicao(float *pos_x, float *pos_y,
                       float v_x, float v_y, float t) {
    *pos_x = calcular_posicao(*pos_x, v_x, t);
    *pos_y = calcular_posicao(*pos_y, v_y, t);
}
int main(void) {
    float pos_x = 100.0, pos_y = 200.0;
    float v_x   = 5.5,   v_y   = -2.0;
    float t     = 2.5;

    atualizar_posicao(&pos_x, &pos_y, v_x, v_y, t);

    printf("X=%.2f, Y=%.2f\n", pos_x, pos_y);
    return 0;
}
