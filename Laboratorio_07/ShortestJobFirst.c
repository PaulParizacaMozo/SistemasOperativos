#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un proceso
typedef struct {
    char id[20];            // Identificador del proceso
    int tiempoServicio;     // Tiempo total de ejecucion(CPU) necesario para el proceso
    int tiempoRestante;     // Tiempo de CPU restante para el proceso
} Proceso;

// Función del algoritmo Shortest Job First (SJF)
void sjf(Proceso procesos[], int n_procesos) {
    // Ordena los procesos por tiempo de servicio del menor a mayor 
    for (int i = 0; i < n_procesos - 1; i++) {
        for (int j = 0; j < n_procesos - i - 1; j++) {
            if (procesos[j].tiempoServicio > procesos[j + 1].tiempoServicio) {
                // Intercambio de procesos
                Proceso temp = procesos[j];
                procesos[j] = procesos[j + 1];
                procesos[j + 1] = temp;
            }
        }
    }

    printf("Tiempo\t\tProceso\n");
    int tiempoActual = 0;
    for (int i = 0; i < n_procesos; i++) {
        // Imprime el proceso actual y la información del tiempo recorrido
        printf("%d -> %d\t\t%s\n", tiempoActual, tiempoActual + procesos[i].tiempoServicio, procesos[i].id);
        // Actualiza el tiempo actual
        tiempoActual += procesos[i].tiempoServicio;
        // Muestra el mensaje de proceso completado
        printf(">>> Se completo el proceso %s. Tiempo total de ejecucion(retorno): %d\n", procesos[i].id, tiempoActual);
    }
}

int main() {

    // Ejemplo 1
    printf("**** EJEMPLO 1 ****\n");
    // Cantidad de procesos
    int n_procesos = 4;

    // Arreglo con los datos del ejemplo 1 
    Proceso procesos[] = {
        {"A", 8, 0},
        {"B", 4, 0},
        {"C", 9, 0},
        {"D", 5, 0}
    };

    // Función SJF
    sjf(procesos, n_procesos);

    printf("\n**** EJEMPLO 2 ****\n");
    // Cantidad de procesos
    int n_procesos2 = 5;

    // Arreglo con los datos del ejemplo 2
    Proceso procesos2[] = {
        {"P1", 5, 0},
        {"P2", 3, 0},
        {"P3", 1, 0},
        {"P4", 2, 0},
        {"P5", 3, 0}
    };

    // Función SJF
    sjf(procesos2, n_procesos2);

    return 0;
}
