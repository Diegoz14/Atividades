#include <stdio.h>

#define MAX_PACIENTES 100
#define MAX_MEDICOS    20

typedef struct {
    char nome[50];
    int  idade;
    int  internado;
} Paciente;

typedef struct {
    char nome[50];
    char especialidade[50];
} Medico;

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    Medico   medicos[MAX_MEDICOS];
    int      leitos_disponiveis;
    float    caixa;
    int      total_pacientes;
} SistemaHospitalar;

float calcular_custo_internacao(int dias, float diaria) {
    return dias * diaria;
}

void realizar_internacao(SistemaHospitalar *sistema, char *nome_paciente, int idade, int dias, float diaria) {
    if (sistema->leitos_disponiveis <= 0) {
        printf("Sem leitos disponiveis.\n");
        return;
    }

    if (sistema->total_pacientes >= MAX_PACIENTES) {
        printf("Capacidade maxima de pacientes atingida.\n");
        return;
    }

    float custo = calcular_custo_internacao(dias, diaria);

    Paciente *p = &sistema->pacientes[sistema->total_pacientes];
    int i;
    for (i = 0; nome_paciente[i] != '\0' && i < 49; i++)
        p->nome[i] = nome_paciente[i];
    p->nome[i]  = '\0';
    p->idade     = idade;
    p->internado = 1;

    sistema->leitos_disponiveis--;
    sistema->caixa += custo;
    sistema->total_pacientes++;

    printf("Paciente: %s | Dias: %d | Custo: %.2f | Leitos: %d | Caixa: %.2f\n",
           p->nome, dias, custo,
           sistema->leitos_disponiveis, sistema->caixa);
}

int main(void) {
    SistemaHospitalar hospital;
    hospital.leitos_disponiveis = 10;
    hospital.caixa              = 5000.0;
    hospital.total_pacientes    = 0;

    realizar_internacao(&hospital, "Diego Silva",  25, 3, 350.0);
    realizar_internacao(&hospital, "Ana Souza",    40, 5, 350.0);
    realizar_internacao(&hospital, "Bruno Santos", 30, 2, 350.0);

    return 0;
}
