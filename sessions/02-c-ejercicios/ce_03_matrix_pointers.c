/**
 * @file ce_03_matrix_pointers.c
 * @brief Implementación y recorrido de una matriz 3x3 inicializada dinámicamente usando punteros a punteros.
 * @author Johan Germán Beltrán Acevedo
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas = 3, columnas = 3;
    int **matriz;

    matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    printf("--- Ejercicio 3: Matriz 3x3 ---\n");
    int contador = 1;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j) = contador++;
            printf("%d\t", *(*(matriz + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
