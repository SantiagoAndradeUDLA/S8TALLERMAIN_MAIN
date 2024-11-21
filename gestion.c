#include <stdio.h>
#include <string.h>
#include "gestion.h"

void agregar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int *total_productos) {
    if (*total_productos >= MAX_PRODUCTOS) {
        printf("No se pueden agregar mas productos.\n");
        return;
    }

    char nuevo_nombre[MAX_NOMBRE];
    int nombre_repetido;

    do {
        nombre_repetido = 0;
        printf("Ingrese el nombre del producto: ");
        fgets(nuevo_nombre, MAX_NOMBRE, stdin);
        nuevo_nombre[strcspn(nuevo_nombre, "\n")] = '\0';

        for (int i = 0; i < *total_productos; i++) {
            if (strcmp(nombres[i], nuevo_nombre) == 0) {
                printf("El nombre '%s' ya existe. Por favor, ingrese un nombre diferente.\n", nuevo_nombre);
                nombre_repetido = 1;
                break;
            }
        }
    } while (nombre_repetido);

    strncpy(nombres[*total_productos], nuevo_nombre, MAX_NOMBRE);

    printf("Ingrese la cantidad del producto: ");
    while (scanf("%d", &cantidades[*total_productos]) != 1 || cantidades[*total_productos] < 0) {
        printf("Por favor, ingrese un valor valido para la cantidad (mayor o igual a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    printf("Ingrese el peso del producto (en gramos): ");
    while (scanf("%d", &pesos[*total_productos]) != 1 || pesos[*total_productos] <= 0) {
        printf("Por favor, ingrese un valor valido para el peso (mayor a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    printf("Ingrese el precio del producto: ");
    while (scanf("%f", &precios[*total_productos]) != 1 || precios[*total_productos] <= 0) {
        printf("Por favor, ingrese un valor valido para el precio (mayor a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    printf("Ingrese el tiempo de fabricacion (en horas): ");
    while (scanf("%d", &tiempos_fabricacion[*total_productos]) != 1 || tiempos_fabricacion[*total_productos] <= 0) {
        printf("Por favor, ingrese un valor valido para el tiempo (mayor a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    (*total_productos)++;
    printf("Producto agregado exitosamente.\n");
}

void editar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int total_productos) {
    // Implementación de editar producto (igual a la incluida en el código original)
}

void eliminar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int *total_productos) {
    // Implementación de eliminar producto (igual a la incluida en el código original)
}

void mostrar_resumen(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int total_productos) {
    // Implementación de mostrar resumen (igual a la incluida en el código original)
}
