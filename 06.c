#include <stdio.h>

int main(void) {
    int v[10];

    for (int i = 0; i < 10; i++) {
        v[i] = i;
    }

    printf("Ultimo elemento valido: %d\n", v[9]);
    printf("Acessando propositalmente um indice invalido...\n");
    fflush(stdout);

    /* Acesso propositalmente incorreto para teste do AddressSanitizer. */
    volatile int indice_invalido = 10;
    v[indice_invalido] = 100;

    return 0;
}
