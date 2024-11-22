#ifndef GESTION_H
#define GESTION_H

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

void agregar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, float *tiempos_fabricacion, int *total_productos);
void editar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, float *tiempos_fabricacion, int total_productos);
void eliminar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, float *tiempos_fabricacion, int *total_productos);
void mostrar_resumen(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, float *tiempos_fabricacion, int total_productos);

#endif
