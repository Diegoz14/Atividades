#include <stdio.h>
int fat(int parm);
int main(void){
	int num = 40;
	int pos, v1, v2, res = 0;
	printf("Recursividade: %d", fat(num));
	for(pos=1;pos<=num;pos++){	
		res = v1 + v2; 
		v1 = v2;
		v2 = res;
	}
	printf("\nRepeticao: %d\n", res);
	return 0;
}
int fat(int parm){
	if(parm == 1 || parm == 2){
		return 1;
	}
	return fat(parm-1)+fat(parm-2);
}
