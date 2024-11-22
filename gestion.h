#ifndef GESTION_H
#define GESTION_H

#define MAX_PRODUCTOS 10  //define maximos productos
#define MAX_NOMBRE 50  //define maximos nombres

void agregar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, float *tiempos_fabricacion, int *total_productos);
void editar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, float *tiempos_fabricacion, int total_productos);
void eliminar_producto(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, float *tiempos_fabricacion, int *total_productos);
void mostrar_resumen(char (*nombres)[MAX_NOMBRE], int *cantidades, int *pesos, float *precios, float *tiempos_fabricacion, int total_productos);
float calcular_demanda(int cantidad, float precio, float tiempo_fabricacion);


#endif
