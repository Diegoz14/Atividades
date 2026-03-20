#include <stdio.h>
void altera_falha(int saldo);
void altera_correto(int *saldo);
int main(void){
	int saldo_bancario=50;
	printf("Valor Original: %d\n", saldo_bancario);
	altera_falha(saldo_bancario);
	printf("Alteracao falha: %d\n", saldo_bancario);
	altera_correto(&saldo_bancario);
	printf("Alteracao correta: %d\n", saldo_bancario);
	return 0;
}
void altera_falha(int saldo){
	saldo = 20;
}
void altera_correto(int *saldo){
	*saldo = 30;
}

/*
Quando altera_falha e chamada, o compilador copia o valor de saldo_bancario 
para um novo espaco na pilha de memoria destinado ao parametro formal saldo. 
As duas variaveis tem o mesmo valor no inicio da chamada, 
mas sao espacos de memoria completamente diferentes. 
Qualquer modificacao feita em saldo dentro da funcao afeta apenas essa copia local, 
que e descartada junto com o Stack Frame da funcao ao retornar. 
Ja altera_correto recebe o endereco de saldo_bancario com o operador &,
entao o *saldo dentro da funcao aponta diretamente para a memoria original no main,
e a modificacao persiste apos o retorno.
*/
