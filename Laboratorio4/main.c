#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i; // Iterador
    int j; // Iterador
    pid_t rf; // Variable que almacenara el id del proceso
    rf = fork(); // Creamos un nuevo proceso haciendo uso de la funcion fork()
    switch (rf) {
        case -1: // Fallo al ejecutar el fork
            printf("\nNo he podido crear el proceso hijo"); // Imprime mensaje de error
            break;
        case 0: // Proceso hijo
            i = 0; // Asigna una valor a i
            printf("\nSoy el hijo, mi PID es %d y mi variable i (inicialmente a %d) es par", getpid( ), i);
            for (j = 0; j < 5; j++) {
                i++;
                i++;
                printf("\nSoy el hijo, mi variable i es %d", i);
            };
            break;
        default:
            i = 1;
            printf("\nSoy el padre, mi PID es %d y mi variable i (inicialmente a %d) es impar", getpid( ), i);
            for (j = 0; j < 5; j++) {
                i++;
                i++;
                printf("\nSoy el padre, mi variable i es %d", i);
            };
    };
    printf ("\nFinal de ejecucion de %d \n", getpid());
    exit (0);
}
