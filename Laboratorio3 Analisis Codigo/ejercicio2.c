//Ejercicio2
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
   pid_t pid; //Declaracion de una variable tipo pid_t que almacenara el Identificador del proceso
   int i, n= 4; // Variable i sera el contador del bucle, y la variable n la cantidad maxima del bucle
   for (i=0; i<n; i++){
      if ( (pid = fork()) < 0 ){//Se llama al proceso fork() las n veces ejecutandose como  proceso hijo o padre
          break;} //Si el proceso es menor que 0 se detiene el bucle.
   }
   printf ("Proceso: %d / Padre: %d\n", (int) getpid(), (int) getppid()); // Imprime el Id del proceso actual y del padre
   //El printf se ejecutara por cada proceso creado es decir 2 a la n veces.
   getchar();
}
