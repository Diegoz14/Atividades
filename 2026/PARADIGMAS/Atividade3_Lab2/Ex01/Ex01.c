#include <stdio.h>
int fib(int parm);
int main(void){
	int num = 40;
	int pos, v1, v2, res = 0;
	printf("Recursividade: %d", fib(num));
	for(pos=1;pos<=num;pos++){	
		res = v1 + v2; 
		v1 = v2;
		v2 = res;
	}
	printf("\nRepeticao: %d\n", res);
	return 0;
}
int fib(int parm){
	if(parm == 1 || parm == 2){
		return 1;
	}
	return fib(parm-1)+fib(parm-2);
}

/*
	Análise Exigida:

A versão recursiva recalcula os mesmos valores várias vezes do zero, 
pois para calcular `fib(40)` ela precisa de `fib(39)` e `fib(38)`, 
e para calcular `fib(39)` ela precisa de `fib(38)` novamente, 
e assim por diante. 
Isso faz o número de chamadas crescer absurdamente, 
chegando a 331 milhões para `n=40`, 
onde cada chamada reserva espaço na pilha de memória para guardar
seu estado até receber a resposta. 
A versão iterativa simplesmente percorre o loop 38 vezes somando 
os dois valores anteriores, sem recalcular nada e sem ocupar a pilha, 
sendo muito mais rápida e eficiente para valores grandes.
*/
