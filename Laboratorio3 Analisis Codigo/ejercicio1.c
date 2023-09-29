//Ejercicio 1
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    pid_t pid;  // Declaración de una variable para almacenar el ID del proceso
    int var = 0;  // Declaración e inicialización de una variable entera "var"

    printf("PID antes de fork(): %d\n", (int) getpid()); // Imprimir el ID del proceso antes de crear un proceso hijo
    if ((pid = fork()) > 0) { // Crear un proceso hijo con fork() y comprueba si se está ejecutando en el proceso padre
        printf("PID del padre: %d\n", (int) getpid()); // Imprimir el ID del proceso padre
        var++; // Incrementar la variable "var" en el proceso padre
    } else {
        if (pid == 0) // Comprueba si se está ejecutando en el proceso hijo
            printf("PID del hijo: %d\n", (int) getpid()); // Imprimir el ID del proceso hijo ademas la variable var no es modificada
        else
            printf("Error al hacer fork()\n"); // Mensaje de error al crear el proceso hijo
    }
    printf("Proceso [%d] -> var = %d\n", (int) getpid(), var); // Imprime el ID del proceso actual y el valor de "var"
    getchar();
}
