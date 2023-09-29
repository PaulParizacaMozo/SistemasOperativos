#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "defines.h"


char *orden; // Puntero a cadena que sera el comando que se quiere ejecutar
char *argumentos[MAXARG]; // Array de punteros a cadenas que seran los argumentos del comando
int  narg; // Contador para el numero de argumentos
int  es_background;

void construye_orden (char *argv []); // Se declara la funcion

int main(int argc, char *argv[])
{ 
  int i;
  int status;

  if (argc !=2 ) { // Verifica que el numero de argumentos sea 2
    fprintf(stderr, "Uso: %s fich_a_visualizar\n", argv[0]); // imprime mensaje
    exit(1); //sale del programa
  }
  // Si pasa el primer condicional signfica que tiene los argumentos correctos llama a la funcion
  construye_orden(argv);
  /* CODIGO DEL HIJO */
  if (fork() == 0) {  // Crea un proceso hijo
    execvp(orden, argumentos); // Ejecuta el comando con sus argumentos
    fprintf(stderr, "%s no encontrado o no ejecutable\n",orden ); // Si hay algun error ,muestra un mensaje
    exit(1); // Sale del programa
    }

  /* CODIGO DEL PADRE*/
    wait(&status); //Espera a que el proceso hijo termine
    exit(1); // Sale del programa
}


void construye_orden(char * argv[]) // Se define lo que hara la funcion
{ 
  int i,j;
  //Inicializa las variables
  narg=1;
  es_background=FALSE;
  
  //Inicializa el arreglo de argumentos
  for(j=0; j<MAXARG; j++) argumentos[j]=NULL;

  /* Atencion: La asignación de la cadena "cat" a 'orden' que está declarado como 
  un 'char *' se trata como estática, es decir, en tiempo de compilación, el compilador
  reserva espacio de memoria suficiente para almacenar la cadena "cat" (4 bytes). */

  orden="cat"; // El comando a ejecutar sera cat
  
  /* Atención: Por contra, el array de cadenas 'argumentos' no se trata como una
  variable estática, y por eso, es responsabilidad del programador reservar memoria
  para las posiciones que se vayan a utilizar (en el ejemplo, 0 y 1) */
  
  //Asigna memoria y copia la cadena para el primer argumento
  argumentos[0]=(char *)malloc(strlen(orden)+1);
  strcpy(argumentos[0],orden);
  //Asigna memoria y copia la cadena para el segundo argumento
  argumentos[1]=(char *)malloc(strlen(argv[1])+1);
  strcpy(argumentos[1],argv[1]);
}
