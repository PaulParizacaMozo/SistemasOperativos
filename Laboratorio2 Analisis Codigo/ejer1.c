#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int status; // Variable que almacena el estado de finalización del hijo.
    pid_t fork_return; // Variable que almacena el resultado de la llamada a fork().

    fork_return = fork(); // Crear un nuevo proceso hijo y almacenar su PID en fork_return.(-1 = error, 0 = proceso hijo, otro = proceso padre)

    if (fork_return == -1) { // Comprobar si hubo un error al crear el proceso hijo.
        perror("Fork failed"); // Imprimir un mensaje de error 
        exit(1); //Salir si falla el fork.
    } 
    else if (fork_return == 0) { // Código que se ejecutará en el proceso hijo.
        printf("\nI'm the child!\n"); // Imprimir un mensaje para el proceso hijo.
        exit(0); // Salir del proceso hijo con un estado de salida 0 (éxito).
    } 
    else { // Código que se ejecutará en el proceso padre.
        wait(&status); // Esperar a que el proceso hijo termine y almacenar su estado de salida en 'status'.
        printf("\nI'm the parent!\n"); // Imprimir un mensaje para el proceso padre.
        if (WIFEXITED(status)) { // Verificar si el proceso hijo terminó normalmente.
            printf("Child returned: %d\n", WEXITSTATUS(status)); // Imprimir el estado de salida del proceso hijo.
        }
    }
    return 0;
}
