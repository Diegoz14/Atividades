#include <stdio.h>
float calcular_altitude(float altitude_atual, float variacao) {
    return altitude_atual + variacao;
}
void forcar_altitude(float *altitude, float nova_altitude) {
    *altitude = nova_altitude;
}
int main(void) {
    float altitude = 10000.0;
    float variacao = 1500.0;

    printf("Altitude inicial:   %.2f ft\n", altitude);

    float altitude_calculada = calcular_altitude(altitude, variacao);
    printf("Altitude calculada: %.2f ft\n", altitude_calculada);
    printf("Altitude original apos calculo: %.2f ft\n", altitude);

    forcar_altitude(&altitude, altitude_calculada);
    printf("Altitude apos forcamento: %.2f ft\n", altitude);

    return 0;
}
