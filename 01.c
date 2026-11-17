#include <stdio.h>

int main(void) {
    int v[5];
    int maior;
    int soma = 0;

    printf("Digite 5 inteiros: ");
    for (int i = 0; i < 5; i++) {
        if (scanf("%d", &v[i]) != 1) {
            return 1;
        }
    }

    maior = v[0];
    for (int i = 0; i < 5; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
        soma += v[i];
    }

    printf("Maior: %d\n", maior);
    printf("Media: %.2f\n", soma / 5.0);
    return 0;
}
