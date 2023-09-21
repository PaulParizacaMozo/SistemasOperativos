#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COUNT 200

void ChildProcess(void); // Declaración de la función que se ejecutará en el proceso hijo.
void ParentProcess(void); // Declaración de la función que se ejecutará en el proceso padre.

int main(void)
{
    pid_t pid; // Variable para almacenar el PID del proceso hijo.

    pid = fork(); // Crear un nuevo proceso hijo y almacenar su PID en 'pid'.
    if (pid == 0) // Si 'pid' es igual a 0, se está ejecutando en el proceso hijo.
        ChildProcess(); // Llamar a la función que contiene el código del proceso hijo.
    else if (pid > 0) // Si 'pid' es mayor que 0, se está ejecutando en el proceso padre.
    {
        wait(NULL); // Esperar a que el proceso hijo termine (no se captura el estado de salida).
        ParentProcess(); // Llamar a la función que contiene el código del proceso padre.
    }
    else // Si 'pid' es negativo, hubo un error al crear el proceso hijo.
    {
        perror("Fork failed"); // Imprimir un mensaje de error.
        return 1; // Salir del programa con un código de error.
    }

    return 0; // Terminar el programa con un código de salida exitoso.
}

void ChildProcess(void)
{
    int i;

    for (i = 1; i <= MAX_COUNT; i++)
        printf("   This line is from child, value = %d\n", i); // Imprime líneas desde el proceso hijo.
    printf("   *** Child process is done ***\n"); // Imprime un mensaje cuando el proceso hijo ha terminado.
}

void ParentProcess(void)
{
    int i;

    for (i = 1; i <= MAX_COUNT; i++)
        printf("This line is from parent, value = %d\n", i); // Imprime líneas desde el proceso padre.
    printf("*** Parent is done ***\n"); // Imprime un mensaje cuando el proceso padre ha terminado.
}
