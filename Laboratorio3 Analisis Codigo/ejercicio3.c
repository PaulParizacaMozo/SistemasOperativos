//Ejercicio 3
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    //Declaracion de variables
    pid_t pid_hijo; int estado, x; long i, j;

    if ( (pid_hijo= fork()) == -1){ /* Código que ejecuta por el proceso PADRE: Error */
        perror("Fallo al hacer fork()"); //Mensaje de error
        exit(-1); // Salir del programa con un Código de error
    } else if (pid_hijo == 0) { /* Código que ejecuta por el proceso HIJO */
        fprintf(stdout, "PID hijo: %ld\n", (long) getpid()); // Imprime el id del proceso hijo
        fflush(stdout); // Limpia el buffer
        sleep(2); // Espera dos segundos
    } else { /* Código que ejecuta el proceso PADRE */
        //Espera a que termine el proceso hijo y almacena su estado. Si el valor que retorna wait() es distinto
        //al del id del proceso hijo significa que el proceso padre fue interrumpido.
        if ( (x=wait(&estado)) != pid_hijo) //
            fprintf(stdout, "PADRE: interrumpido por señal\n"); // Imprime un mensaje a causa de una interrupcion
        else
            // Imprime el ID del padre, el ID del hijo y el estado del hijo 
            fprintf(stdout, "PID padre: %ld / PID hijo: %ld / estado hijo: %d\n",(long) getpid(), (long) pid_hijo, estado);
        fflush(stdout); // Limpia el buffer
    }
    //sale del programa con codigo 0
    getchar();
    exit(0); /* Código PADRE e HIJO */
}
