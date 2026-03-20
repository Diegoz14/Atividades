#include <stdio.h>
void contagem_regressiva(int n) {
    if (n < 0)             
        return;
    printf("%d\n", n);
    contagem_regressiva(n - 1);  
}

int main(void) {
    contagem_regressiva(10);
    return 0;
}
