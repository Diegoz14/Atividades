#include <stdio.h>
void contagem_regressiva_quebrada(int n) {
    printf("%d\n", n);
    contagem_regressiva_quebrada(n - 1);
}

int main(void) {
    contagem_regressiva_quebrada(10);
    return 0;
}
