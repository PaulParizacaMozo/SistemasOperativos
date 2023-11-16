#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h> //Esta libreria nos permite trabajar con hilos

// Definicion de una estructura que contiene los parámetros para la multiplicación
struct parametros {
    int id; // Variable entera id
    float matrizA[3][3]; // Variable flotante escalar
    float matrizB[3][3]; // Matriz de 3 x 3
    float resultado[3][3]; // Matriz de 3 x 3
};

// Funcion para inicializar la matriz con datos aleatorios
void init(float m[3][3]) {
    int i, j; // Indices para ubicarnos en la matriz
    for (i = 0; i < 3; i++) { // Iteramos en las filas
        for (j = 0; j < 3; j++) { // Iteramos en las columnas
            m[i][j] = random() * 100; // Asignamos un valor a la posicion de la matriz
        }
    }
}

// Función entre muil de matrices 
void *matrizpormatriz(void *arg) {
    struct parametros *p; // puntero a la estructura parametros
    int i, j, k; // Indices para ubicarnos en la matriz
    p = (struct parametros *)arg; // Conversion del puntero void a un puntero a la estructura
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Hilo %d multiplicando fila  %d x columna %d\n", p->id, i,j);
            for (k = 0; k < 3; k++) {
                // Multiplica cada elemento de la fila por el elemento de columna 
                p->resultado[i][j] = p->matrizA[i][j] * p->matrizB[i][j];
            }
            usleep(100000);  // Pausa de 100000 microsegundos 
        }
    }
}

// Función para mostrar una matriz de tamaño 3x3
void imprimirMatriz(float matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    pthread_t h1; // Variable para el identificador del primer hilo
    pthread_t h2; // Variable para el identificador del segundo hilo
    struct parametros p1; // Estructura para los parámetros
    struct parametros p2; // Estructura para los parámetros
    
    // Configuración de parámetros
    p1.id = 1; // Asigna el id 1 
    init(p1.matrizA); // Inicializa la matriz del primer hilo con valores aleatorios
    init(p1.matrizB); // Inicializa la matriz del primer hilo con valores aleatorios

    p2.id = 2; // Asigna el id 2 al segundo hilo
    init(p2.matrizA); // Inicializa la matriz del segundo hilo con valores aleatorios
    init(p2.matrizB); // Inicializa la matriz del segundo hilo con valores aleatorios
   
    clock_t inicio, fin; // Variables para medir el tiempo
    double tiempo_total;
    inicio = clock();

    pthread_create(&h1, NULL, matrizpormatriz, (void *)&p1); // Crea el primer hilo y le pasa los parámetros p1
    pthread_create(&h2, NULL, matrizpormatriz, (void *)&p2); // Crea el segundo hilo y le pasa los parámetros p2

    pthread_join(h1, NULL); // Espera a que el primer hilo termine
    pthread_join(h2, NULL); // Espera a que el segundo hilo termine

    printf("\np1.Matriz Resultado\n");
    imprimirMatriz(p1.resultado);
    printf("\np2.Matriz Resultado\n");
    imprimirMatriz(p2.resultado);

    fin = clock();
    tiempo_total = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("\nTiempo total de ejecución: %.6f segundos\n", tiempo_total);

    // Mensaje Final 
    printf("Fin\n");

    return 0;
}

/*
    Compilar y ejecutar el codigo:
    1.- gcc -lpthread -o ejer3 ejer3.c
    2.- ./ejer3.c
*/
