//Ejercicio 1
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
   pid_t pid;
   int var= 0;
   printf("PID antes de fork(): %d\n", (int) getpid());
   if ( (pid = fork()) > 0 ) {
      printf ("PID del padre: %d\n", (int) getpid());
      var++;
   } else {
      if (pid == 0) 
         printf ("PID del hijo: %d\n", (int) getpid());
      else
         printf ("Error al hacer fork()\n");
   }
   printf("Proceso [%d] -> var = %d\n", (int) getpid(), var);
}
