#include <stdio.h>
#include <string.h>
#include "gestion.h"

void agregar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int *total_productos) {
    if (*total_productos >= MAX_PRODUCTOS) {
        printf("No se pueden agregar más productos.\n");
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
        printf("Por favor, ingrese un valor válido para la cantidad (mayor o igual a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    printf("Ingrese el peso del producto (en gramos): ");
    while (scanf("%d", &pesos[*total_productos]) != 1 || pesos[*total_productos] <= 0) {
        printf("Por favor, ingrese un valor válido para el peso (mayor a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    printf("Ingrese el precio del producto: ");
    while (scanf("%f", &precios[*total_productos]) != 1 || precios[*total_productos] <= 0) {
        printf("Por favor, ingrese un valor válido para el precio (mayor a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    printf("Ingrese el tiempo de fabricación (en horas): ");
    while (scanf("%d", &tiempos_fabricacion[*total_productos]) != 1 || tiempos_fabricacion[*total_productos] <= 0) {
        printf("Por favor, ingrese un valor válido para el tiempo (mayor a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    (*total_productos)++;
    printf("Producto agregado exitosamente.\n");
}

void editar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int total_productos) {
    if (total_productos == 0) {
        printf("No hay productos para editar.\n");
        return;
    }

    char nombre_buscado[MAX_NOMBRE];
    printf("Ingrese el nombre del producto que desea editar: ");
    fgets(nombre_buscado, MAX_NOMBRE, stdin);
    nombre_buscado[strcspn(nombre_buscado, "\n")] = '\0';

    for (int i = 0; i < total_productos; i++) {
        if (strcmp(nombres[i], nombre_buscado) == 0) {
            printf("Producto encontrado: %s\n", nombres[i]);

            printf("Ingrese la nueva cantidad: ");
            while (scanf("%d", &cantidades[i]) != 1 || cantidades[i] < 0) {
                printf("Por favor, ingrese un valor válido para la cantidad (mayor o igual a 0): ");
                while (getchar() != '\n');
            }
            getchar();

            printf("Ingrese el nuevo peso (en gramos): ");
            while (scanf("%d", &pesos[i]) != 1 || pesos[i] <= 0) {
                printf("Por favor, ingrese un valor válido para el peso (mayor a 0): ");
                while (getchar() != '\n');
            }
            getchar();

            printf("Ingrese el nuevo precio: ");
            while (scanf("%f", &precios[i]) != 1 || precios[i] <= 0) {
                printf("Por favor, ingrese un valor válido para el precio (mayor a 0): ");
                while (getchar() != '\n');
            }
            getchar();

            printf("Ingrese el nuevo tiempo de fabricación (en horas): ");
            while (scanf("%d", &tiempos_fabricacion[i]) != 1 || tiempos_fabricacion[i] <= 0) {
                printf("Por favor, ingrese un valor válido para el tiempo (mayor a 0): ");
                while (getchar() != '\n');
            }
            getchar();

            printf("Producto editado correctamente.\n");
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

void eliminar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int *total_productos) {
    if (*total_productos == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }

    char nombre_buscado[MAX_NOMBRE];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    fgets(nombre_buscado, MAX_NOMBRE, stdin);
    nombre_buscado[strcspn(nombre_buscado, "\n")] = '\0';

    for (int i = 0; i < *total_productos; i++) {
        if (strcmp(nombres[i], nombre_buscado) == 0) {
            for (int j = i; j < *total_productos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                cantidades[j] = cantidades[j + 1];
                pesos[j] = pesos[j + 1];
                precios[j] = precios[j + 1];
                tiempos_fabricacion[j] = tiempos_fabricacion[j + 1];
            }

            (*total_productos)--;
            printf("Producto '%s' eliminado correctamente.\n", nombre_buscado);
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

void mostrar_resumen(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int total_productos) {
    if (total_productos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n--- Resumen de productos ---\n");
    for (int i = 0; i < total_productos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", nombres[i]);
        printf("  Cantidad: %d\n", cantidades[i]);
        printf("  Peso: %d gramos\n", pesos[i]);
        printf("  Precio: $%.2f\n", precios[i]);
        printf("  Tiempo de fabricación: %d horas\n", tiempos_fabricacion[i]);
    }
}
