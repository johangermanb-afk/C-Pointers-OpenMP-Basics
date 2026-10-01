/**
 * @file ce_02_array_sum_pointers.c
 * @brief Suma de los valores de un arreglo de enteros utilizando punteros.
 * @author Johan Germán Beltrán Acevedo
 * @date 2026-09-30
 */

#include <stdio.h>

int main() {
    int arreglo[5] = {10, 20, 30, 40, 50};
    int *ptr = arreglo;
    int suma = 0;
    int n = 5;

    for (int i = 0; i < n; i++) {
        suma += *(ptr + i);
    }

    printf("--- Ejercicio 2: Suma con punteros ---\n");
    printf("La suma total es: %d\n", suma);
    return 0;
}
