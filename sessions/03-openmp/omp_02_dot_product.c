/**
 * @file omp_02_dot_product.c
 * @brief Cálculo del producto escalar de dos vectores en paralelo indicando los hilos participantes.
 * @author Johan Germán Beltrán Acevedo
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000

int main() {
    int *A = (int *)malloc(N * sizeof(int));
    int *B = (int *)malloc(N * sizeof(int));
    long long dot_product = 0;

    for (int i = 0; i < N; i++) {
        A[i] = 2; B[i] = 3;
    }

    printf("--- Ejercicio 7: Producto Escalar ---\n");
    #pragma omp parallel for reduction(+:dot_product)
    for (int i = 0; i < N; i++) {
        dot_product += A[i] * B[i];

        if (i % 25000 == 0) {
            printf("Iteracion %d procesada por el hilo %d de %d\n",
                   i, omp_get_thread_num(), omp_get_num_threads());
        }
    }

    printf("Producto escalar total: %lld\n", dot_product);

    free(A); free(B);
    return 0;
}
