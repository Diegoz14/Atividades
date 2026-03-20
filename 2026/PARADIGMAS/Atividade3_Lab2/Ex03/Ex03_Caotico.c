#include <stdio.h>

int main(void) {
    char *nome1 = "Ana"; float horas1 = 160; float valor_hora1 = 25.0;
    float bruto1 = horas1 * valor_hora1;
    float imposto1 = 0.0;
    if (bruto1 > 3000) imposto1 = bruto1 * 0.15;
    else imposto1 = bruto1 * 0.08;
    float liquido1 = bruto1 - imposto1;
    printf("%s | Bruto: %.2f | Imposto: %.2f | Liquido: %.2f\n", nome1, bruto1, imposto1, liquido1);

    char *nome2 = "Bruno"; float horas2 = 120; float valor_hora2 = 40.0;
    float bruto2 = horas2 * valor_hora2;
    float imposto2 = 0.0;
    if (bruto2 > 3000) imposto2 = bruto2 * 0.15;
    else imposto2 = bruto2 * 0.08;
    float liquido2 = bruto2 - imposto2;
    printf("%s | Bruto: %.2f | Imposto: %.2f | Liquido: %.2f\n", nome2, bruto2, imposto2, liquido2);

    char *nome3 = "Carla"; float horas3 = 200; float valor_hora3 = 30.0;
    float bruto3 = horas3 * valor_hora3;
    float imposto3 = 0.0;
    if (bruto3 > 3000) imposto3 = bruto3 * 0.15;
    else imposto3 = bruto3 * 0.08;
    float liquido3 = bruto3 - imposto3;
    printf("%s | Bruto: %.2f | Imposto: %.2f | Liquido: %.2f\n", nome3, bruto3, imposto3, liquido3);

    return 0;
}
