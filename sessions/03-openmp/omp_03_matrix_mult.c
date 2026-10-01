/**
 * @file omp_03_matrix_mult.c
 * @brief Multiplicación de dos matrices cuadradas de tamaño NxN comparando la ejecución secuencial y paralela.
 * @author Johan Germán Beltrán Acevedo
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500

int A[N][N], B[N][N], C_sec[N][N], C_par[N][N];

int main() {
    double inicio, fin, ts, tp;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            A[i][j] = 1; B[i][j] = 2;
        }

    // Secuencial
    inicio = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C_sec[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C_sec[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    fin = omp_get_wtime();
    ts = fin - inicio;

    // Paralelo
    inicio = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (i % 100 == 0) {
            printf("Fila %d calculada por el hilo %d\n", i, omp_get_thread_num());
        }
        for (int j = 0; j < N; j++) {
            C_par[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C_par[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    fin = omp_get_wtime();
    tp = fin - inicio;

    printf("\nMultiplicacion Secuencial (Ts): %f seg\n", ts);
    printf("Multiplicacion Paralela (Tp): %f seg\n", tp);

    return 0;
}
