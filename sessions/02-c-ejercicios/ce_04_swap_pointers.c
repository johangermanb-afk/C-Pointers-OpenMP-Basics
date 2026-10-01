/**
 * @file ce_04_swap_pointers.c
 * @brief Intercambio del contenido de dos variables utilizando punteros y paso por referencia.
 * @author Johan Germán Beltrán Acevedo
 * @date 2026-09-30
 */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 15, y = 82;
    printf("--- Ejercicio 4: Swap ---\n");
    printf("Antes: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Despues: x = %d, y = %d\n", x, y);
    return 0;
}
