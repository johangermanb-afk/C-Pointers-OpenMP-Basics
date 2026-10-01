/**
 * @file ce_05_string_pointers.c
 * @brief Recorrido de una cadena de caracteres usando un puntero, imprimiendo el carácter y su dirección.
 * @author Johan Germán Beltrán Acevedo
 * @date 2026-09-30
 */

#include <stdio.h>

int main() {
    char cadena[] = "Hola Pamplona";
    char *ptr = cadena;

    printf("--- Ejercicio 5: Cadena y memoria ---\n");
    while (*ptr != '\0') {
        printf("Caracter: '%c' | Direccion: %p\n", *ptr, (void *)ptr);
        ptr++;
    }
    return 0;
}
