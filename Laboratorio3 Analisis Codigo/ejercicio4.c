//Ejercicio 4
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t pid_hijo; int estado, x; long i, j;
    /* Código PADRE: Error */
    // Usando fork() se crea un nuevo proceso hijo y el valor lo almacenamos en la variable pid_hijo
    if ( (pid_hijo= fork()) == -1){ 
        perror("Fallo al hacer fork()"); //Si retorna -1 imprime un mensaje de error
        exit(-1); // Sale del programa
    }
    /* Código HIJO */
    else if (pid_hijo == 0) { //Si se cumple la condicion significa que se ejecuta el proceso hijo
        if ( execl("/bin/ls", "ls", "-l", NULL) < 0) { // Intenta ejecutar el comando ls -l en el proceso hijo
            perror("Fallo al ejecutar: ls"); //Mensaje de error al ejecutar ls
            exit(-1); //Sale del programa
        }
    } 
    /* Código PADRE */
    //Caso contrario se ejecuta el proceso padre
    else  
        if ( (x=wait(&estado)) != pid_hijo) { // Espera a que el proceso hijo termine
            //Si el valor retarnado es distinto al Id del proceso hijo significa que el padre fue interrumpido
            fprintf(stdout, "PADRE: interrumpido por señal\n"); fflush(stdout); //Se imprime mensaje
        }
    exit(0); /* Código PADRE e HIJO, aunque el hijo nunca pasará por aquí */
}
