#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i; // Variable i
    int j; // Variable j
    pid_t rf; // Variable que almacenara el id del proceso
    rf = fork(); // Creamos un nuevo proceso haciendo uso de la funcion fork()
    switch (rf) {
        case -1: // Fallo al ejecutar el fork
            printf("\nNo he podido crear el proceso hijo"); // Imprime mensaje de error
            break;
        case 0: // Proceso hijo
            i = 0; // Asigna una valor a i el cual es 0
            // Imprime el id del proceso hijo con la funcion getpid() y el valor de i
            printf("\nSoy el hijo, mi PID es %d y mi variable i (inicialmente a %d) es par", getpid( ), i);
            for (j = 0; j < 5; j++) { // Repite 5 veces el bucle
                i++; 
                i++;
                //Incrementa el valor de i en 2
                printf("\nSoy el hijo, mi variable i es %d", i); // Imprime el valor de i
            };
            break;
        default: // Proceso padre
            i = 1; // Asigna un valor a i el cual es 1
            // Imprime el id del proceso hijo con la funcion getpid() y el valor de i
            printf("\nSoy el padre, mi PID es %d y mi variable i (inicialmente a %d) es impar", getpid( ), i);
            for (j = 0; j < 5; j++) { // Repite 5 veces el bucle
                i++;
                i++;
                //Incrementa el valor de i en 2
                printf("\nSoy el padre, mi variable i es %d", i); // Imprime el valor de i
            };
    };
    printf ("\nFinal de ejecucion de %d \n", getpid()); //Imprime el id del ambos procesos padre e hijo 
    exit (0); // Finaliza el programa
}
