#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un proceso
typedef struct {
    char id[20];            // Identificador del proceso
    int tiempoServico;      // Tiempo total de ejecucion(CPU) necesario para el proceso
    int tiempoRestante;     // Tiempo de CPU restante para el proceso
} Proceso;

// Función del algoritmo Round Robin
void roundRobin(Proceso procesos[], int n_procesos, int quantum) {
    int tiempoTotal = 0;

    //  Bucle para hallar el tiempo de ejecucion de totos los procesos 
    for (int i = 0; i < n_procesos; i++) {
        tiempoTotal += procesos[i].tiempoServico;
        procesos[i].tiempoRestante = procesos[i].tiempoServico;
    }

    printf("Tiempo\t\tProceso\n");
    // Inicio del algoritmo Round Robin
    int tiempoActual = 0;
    while (tiempoActual < tiempoTotal) { //Ejecucion hasta que cumpla todos los procesos
        for (int i = 0; i < n_procesos; i++) { // Recorrido de proceso en proceso
            if (procesos[i].tiempoRestante > 0) { // Comprueba si el procesos esta completado
                // Calcula el tiempo restante para el procesos actual
                int tiempoServico = (procesos[i].tiempoRestante < quantum) ? procesos[i].tiempoRestante : quantum; // Calculo del valor a restar al tiempo restante
                procesos[i].tiempoRestante -= tiempoServico; //Actualizacion de tiempo restante
                tiempoActual += tiempoServico; // Actualizacion del tiempo actual recorrido
                // Imprime el proceso actual y la informacion del tiempo recorrido
                printf("%d -> %d\t\t%s\n", tiempoActual - tiempoServico, tiempoActual, procesos[i].id);
                // Si un proceso termina mostrar el tiempo que demora en completarse.
                if (procesos[i].tiempoRestante == 0) {
                    printf(">>> Se completo el proceso %s. Tiempo de total de ejecucion(retorno): %d\n\n", procesos[i].id, tiempoActual);
                }
            }
        }
    }
}

int main() {

    //Ejemplo 1
    printf("**** EJEMPLO 1 ****\n");
    // Cantidad de procesos y valor del quantum
    int n_procesos = 4;
    int quantum = 3;

    // Arreglo con los datos del ejemplo 1 
    Proceso procesos[] = {
        {"A", 8, 0},
        {"B", 4, 0},
        {"C", 9, 0},
        {"D", 5, 0}
    };

    // Función Round Robin
    roundRobin(procesos, n_procesos, quantum);

    printf("**** EJEMPLO 2 ****\n");
    // Cantidad de procesos y valor del quantum
    int n_procesos2 = 5;
    int quantum2 = 2;

    // Arreglo con los datos del ejemplo 2
    Proceso procesos2[] = {
        {"P1", 5, 0},
        {"P2", 3, 0},
        {"P3", 1, 0},
        {"P4", 2, 0},
        {"P5", 3, 0}
    };

    // Funcion Round Robin
    roundRobin(procesos2, n_procesos2, quantum2);

    return 0;
}
