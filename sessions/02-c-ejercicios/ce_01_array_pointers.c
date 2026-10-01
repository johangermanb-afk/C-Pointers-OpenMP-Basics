/**
 * @file ce_01_array_pointers.c
 * @brief Acceso a elementos de un arreglo utilizando aritmética de punteros.
 * @author Johan Germán Beltrán Acevedo
 * @date 2026-09-30
 */

#include <stdio.h>

int main() {
    int arreglo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = arreglo; // Apunta al primer elemento

    printf("--- Ejercicio 1: Acceso con punteros ---\n");
    for (int i = 0; i < 10; i++) {
        printf("Elemento %d: %d\n", i, *(ptr + i));
    }
    return 0;
}
