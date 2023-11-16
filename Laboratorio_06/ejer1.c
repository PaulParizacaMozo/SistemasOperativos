#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h> //Esta libreria nos permite trabajar con hilos

// Definicion de una estructura que contiene los parámetros para la multiplicación
struct parametros {
    int id; // Variable entera id
    float escalar; // Variable flotante escalar
    float matriz[3][3]; // Matriz de 3 x 3
};

// Funcion para inicializar la matriz con datos aleatorios(0 y 100)
void init(float m[3][3]) {
    int i, j; // Indices para ubicarnos en la matriz
    for (i = 0; i < 3; i++) { // Iteramos en las filas
        for (j = 0; j < 3; j++) { // Iteramos en las columnas
            m[i][j] = random() * 100; // Asignamos un valor a la posicion de la matriz
        }
    }
}

// Función que sera ejecutada por cada hilo para multiplicar una matriz por escalar
void *matrizporescalar(void *arg) {
    struct parametros *p; // puntero a la estructura parametros
    int i, j; // Indices para ubicarnos en la matriz
    p = (struct parametros *)arg; // Conversion del puntero void a un puntero a la estructura
    for (i = 0; i < 3; i++) {
        // Muestra un mensaje que indica que hilo multiplica cierta fila
        printf("Hilo %d multiplicando fila %d\n", p->id, i);
        for (j = 0; j < 3; j++) {
            // Multiplica cada elemento de la fila por el escalar
            p->matriz[i][j] = p->matriz[i][j] * p->escalar;
            usleep(100000);  // Pausa de 100000 microsegundos(genera un retraso para el uso del hilo) 
        }
    }
    pthread_exit(NULL);  // Finaliza el hilo
}

int main(int argc, char *argv[]) {
    pthread_t h1; // Variable para el identificador del primer hilo
    pthread_t h2; // Variable para el identificador del segundo hilo
    struct parametros p1; // Estructura para los parámetros del primer hilo
    struct parametros p2; // Estructura para los parámetros del segundo hilo
    
    // Configuración de parámetros para ambos hilos hilo
    p1.id = 1; // Asigna el id 1 al primer hilo
    p1.escalar = 5.0; // Asigna el escalar 5.0 al primer hilo
    init(p1.matriz); // Inicializa la matriz del primer hilo con valores aleatorios
    p2.id = 2; // Asigna el id 2 al segundo hilo
    p2.escalar = 10.0; // Asigna el escalar 10.0 al segundo hilo
    init(p2.matriz); // Inicializa la matriz del segundo hilo con valores aleatorios
    
    pthread_create(&h1, NULL, matrizporescalar, (void *)&p1); // Crea el primer hilo y le pasa los parámetros p1
    pthread_create(&h2, NULL, matrizporescalar, (void *)&p2); // Crea el segundo hilo y le pasa los parámetros p2

    pthread_join(h1, NULL); // Espera a que el primer hilo termine
    pthread_join(h2, NULL); // Espera a que el segundo hilo termine
    
    // Mensaje Final 
    printf("Fin\n");

    return 0;
}

/*
    Compilar y ejecutar el codigo:
    1.- gcc -lpthread -o ejer1 ejer1.c
    2.- ./ejer1.c
*/
