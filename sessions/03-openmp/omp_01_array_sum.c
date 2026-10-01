/**
 * @file omp_01_array_sum.c
 * @brief Suma de los elementos de un arreglo de tamaño N evaluando el desempeño secuencial vs paralelo.
 * @author Johan Germán Beltrán Acevedo
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *arreglo = (int *)malloc(N * sizeof(int));
    long long suma_sec = 0, suma_par = 0;
    double inicio, fin, ts, tp;

    for (int i = 0; i < N; i++) arreglo[i] = 1;

    // Secuencial
    inicio = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        suma_sec += arreglo[i];
    }
    fin = omp_get_wtime();
    ts = fin - inicio;

    // Paralelo
    inicio = omp_get_wtime();
    #pragma omp parallel for reduction(+:suma_par)
    for (int i = 0; i < N; i++) {
        suma_par += arreglo[i];
    }
    fin = omp_get_wtime();
    tp = fin - inicio;

    printf("Suma Secuencial: %lld | Ts: %f seg\n", suma_sec, ts);
    printf("Suma Paralela: %lld | Tp: %f seg\n", suma_par, tp);

    free(arreglo);
    return 0;
}
