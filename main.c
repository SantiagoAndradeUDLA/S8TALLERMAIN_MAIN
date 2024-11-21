#include <stdio.h>
#include <string.h>
#include "gestion.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int cantidades[MAX_PRODUCTOS];
    int pesos[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int tiempos_fabricacion[MAX_PRODUCTOS];
    int total_productos = 0;
    int opcion;

    do {
        printf("\n--- Menu de opciones ---\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar resumen\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer después de leer la opcion

        switch (opcion) {
            case 1:
                agregar_producto(nombres, cantidades, pesos, precios, tiempos_fabricacion, &total_productos);
                break;
            case 2:
                editar_producto(nombres, cantidades, pesos, precios, tiempos_fabricacion, total_productos);
                break;
            case 3:
                eliminar_producto(nombres, cantidades, pesos, precios, tiempos_fabricacion, &total_productos);
                break;
            case 4:
                mostrar_resumen(nombres, cantidades, pesos, precios, tiempos_fabricacion, total_productos);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}
