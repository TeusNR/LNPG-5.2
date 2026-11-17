#include <stdio.h>

int main(void) {
    int v[4] = {10, 20, 30, 40};
    double d[4] = {1.0, 2.0, 3.0, 4.0};

    printf("Enderecos dos elementos int:\n");
    for (int i = 0; i < 4; i++) {
        printf("&v[%d] = %p\n", i, (void *)&v[i]);
    }

    printf("\nEnderecos dos elementos double:\n");
    for (int i = 0; i < 4; i++) {
        printf("&d[%d] = %p\n", i, (void *)&d[i]);
    }

    printf("\nTamanho de int: %zu bytes\n", sizeof(v[0]));
    printf("Tamanho de double: %zu bytes\n", sizeof(d[0]));
    printf("Avanco entre v[0] e v[1]: %td bytes\n",
           (char *)&v[1] - (char *)&v[0]);
    printf("Avanco entre d[0] e d[1]: %td bytes\n",
           (char *)&d[1] - (char *)&d[0]);

    return 0;
}
