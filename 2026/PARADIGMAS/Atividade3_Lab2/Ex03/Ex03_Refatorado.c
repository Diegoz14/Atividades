#include <stdio.h>
float calcular_liquido(float horas, float valor_hora, float limite, float taxa_alta, float taxa_baixa) {
    float bruto   = horas * valor_hora;
    float imposto = (bruto > limite) ? bruto * taxa_alta : bruto * taxa_baixa;
    return bruto - imposto;
}
void imprimir_funcionario(char *nome, float horas, float valor_hora, float limite, float taxa_alta, float taxa_baixa) {
    float bruto   = horas * valor_hora;
    float imposto = (bruto > limite) ? bruto * taxa_alta : bruto * taxa_baixa;
    float liquido = calcular_liquido(horas, valor_hora, limite, taxa_alta, taxa_baixa);
    printf("%s | Bruto: %.2f | Imposto: %.2f | Liquido: %.2f\n", nome, bruto, imposto, liquido);
}
int main(void) {
    float limite    = 3000.0;
    float taxa_alta = 0.15;
    float taxa_baixa = 0.08;

    imprimir_funcionario("Ana",   160, 25.0, limite, taxa_alta, taxa_baixa);
    imprimir_funcionario("Bruno", 120, 40.0, limite, taxa_alta, taxa_baixa);
    imprimir_funcionario("Carla", 200, 30.0, limite, taxa_alta, taxa_baixa);

    return 0;
}
