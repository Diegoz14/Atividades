#include <stdio.h>
float celsius_para_fahrenheit(float celsius) {
    return (celsius * 9.0f / 5.0f) + 32.0f;
}
void atualizar_alarme(int *alarme, float temp_c, float limite) {
    *alarme = (temp_c > limite) ? 1 : 0;
}
int main(void) {
    float temp_c  = 38.5f;
    float temp_f  = 0.0f;
    int   alarme  = 0;

    temp_f = celsius_para_fahrenheit(temp_c);
    atualizar_alarme(&alarme, temp_c, 35.0f);

    printf("F: %.2f | Alarme: %d\n", temp_f, alarme);
    return 0;
}
