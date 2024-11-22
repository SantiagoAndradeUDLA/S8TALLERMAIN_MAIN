#include <stdio.h>
#include <string.h>
#include "gestion.h"

/*
bueno funciones.c
*/

void agregar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int *total_productos) {
    if (*total_productos >= MAX_PRODUCTOS) {  //totalproductos++ mas abajo, comparacion de totalproductos con maxproductos(definido en main)
        printf("No se pueden agregar mas productos.\n");
        return;
    }

    char nuevo_nombre[MAX_NOMBRE];
    int nombre_repetido;

    do {  //loop1
        nombre_repetido = 0; //seteo a 0 para un compare dsp
        printf("Ingrese el nombre del producto: ");
        fgets(nuevo_nombre, MAX_NOMBRE, stdin);  //ingreso el nombre, furado en MAX_NOMBRE 
        nuevo_nombre[strcspn(nuevo_nombre, "\n")] = '\0';

        for (int i = 0; i < *total_productos; i++) //for para NO repetir nombres strcompare
        {
            if (strcmp(nombres[i], nuevo_nombre) == 0) {
                printf("El nombre '%s' ya existe. Por favor, ingrese un nombre diferente.\n", nuevo_nombre);
                nombre_repetido = 1;
                break;
            }
        }
    } while (nombre_repetido);

    strncpy(nombres[*total_productos], nuevo_nombre, MAX_NOMBRE);  //se copia nuevo_nombre a una parte del arreglo

    printf("Ingrese la cantidad del producto: "); 
    while (scanf("%i", &cantidades[*total_productos]) != 1 || cantidades[*total_productos] < 0) //para solo admitir nums
     {
        printf("Por favor, ingrese un valor valido para la cantidad (mayor o igual a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    printf("Ingrese el peso del producto (en gramos): ");
    while (scanf("%i", &pesos[*total_productos]) != 1 || pesos[*total_productos] <= 0) //alt 1
    {
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

    printf("Ingrese el tiempo de fabricación (en horas): ");
    while (scanf("%i", &tiempos_fabricacion[*total_productos]) != 1 || tiempos_fabricacion[*total_productos] <= 0) {
        printf("Por favor, ingrese un valor valido para el tiempo (mayor a 0): ");
        while (getchar() != '\n');
    }
    getchar();

    (*total_productos)++;
    printf("Producto agregado exitosamente.\n");
}

void editar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, int *tiempos_fabricacion, int total_productos) {
    if (total_productos == 0) //si no hay productos no hay nada que hacer jaja :)(error 303) 
    {
        printf("No hay productos para editar.\n");
        
        return;
    }

    char nombre_buscado[MAX_NOMBRE];
    printf("Ingrese el nombre del producto que desea editar: ");
    fgets(nombre_buscado, MAX_NOMBRE, stdin);
    nombre_buscado[strcspn(nombre_buscado, "\n")] = '\0';

    for (int i = 0; i < total_productos; i++) {
        if (strcmp(nombres[i], nombre_buscado) == 0) //si 0 entonces stringcompare devuelve 0, por lo tanto 
         {
            printf("Producto encontrado: %s\n", nombres[i]);

            printf("Ingrese la nueva cantidad: ");
            while (scanf("%i", &cantidades[i]) != 1 || cantidades[i] < 0) //alt 1
            {
                printf("Por favor, ingrese un valor valido para la cantidad (mayor o igual a 0): ");
                while (getchar() != '\n');
            }
            getchar();

            printf("Ingrese el nuevo peso (en gramos): ");
            while (scanf("%d", &pesos[i]) != 1 || pesos[i] <= 0) {
                printf("Por favor, ingrese un valor valido para el peso (mayor a 0): ");
                while (getchar() != '\n');
            }
            getchar();

            printf("Ingrese el nuevo precio: ");
            while (scanf("%f", &precios[i]) != 1 || precios[i] <= 0) {
                printf("Por favor, ingrese un valor valido para el precio (mayor a 0): ");
                while (getchar() != '\n');
            }
            getchar();

            printf("Ingrese el nuevo tiempo de fabricación (en horas): ");
            while (scanf("%d", &tiempos_fabricacion[i]) != 1 || tiempos_fabricacion[i] <= 0) {
                printf("Por favor, ingrese un valor valido para el tiempo (mayor a 0): ");
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

        printf("Nombre      | Cantidad | Peso (gr) | Precio | Tiempo Fabricacion (horas)\n");
        printf("------------|----------|-----------|--------|------------------------\n");
        printf("%i:", i + 1), printf("%s", nombres[i]), printf("%i", cantidades[i]), printf("%i", pesos[i]), printf("$%.2f", precios[i]), printf("%d", tiempos_fabricacion[i]);
        /*
        printf("Producto %i:\n", i + 1);
        printf("  Nombre: %s\n", nombres[i]);
        printf("  Cantidad: %i\n", cantidades[i]);
        printf("  Peso: %i gramos\n", pesos[i]);
        printf("  Precio: $%.2f\n", precios[i]);
        printf("  Tiempo de fabricación: %d horas\n", tiempos_fabricacion[i]);
        */
    }
}
