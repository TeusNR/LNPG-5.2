#include <stdio.h>

int main(void) {
    char s[50];
    int tamanho = 0;

    printf("Digite uma palavra: ");
    if (scanf("%49s", s) != 1) {
        return 1;
    }

    while (s[tamanho] != '\0') {
        tamanho++;
    }

    printf("Invertida: ");
    for (int i = tamanho - 1; i >= 0; i--) {
        putchar(s[i]);
    }
    putchar('\n');

    return 0;
}
