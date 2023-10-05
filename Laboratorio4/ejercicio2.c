#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
int main() {
    int i; // Variable que servira de iterador
    int fd1, fd2; // Son los identificadores(descriptores) que se usaran para los ficheros
    const char string1[10]= "*********"; // Cadena a escribir en el fichero
    const char string2[10]= "---------"; // Cadena a escribir en el fichero
    pid_t rf; // Variable que almacenara el identificador de su respectivo proceso
    fd1 = creat("ficheroA", 0666); // Crea el fichero A con permisos de lectura y escritura para usuario, grupo y otros.
    fd2 = creat("ficheroB", 0666); // Crea el fichero B con permisos de lectura y escritura para usuario, grupo y otros.
    rf = fork(); // Creamos un nuevo proceso haciendo uso de la funcion fork()
    switch (rf) {
        case -1: // Fallo al ejecutar el fork
            printf("\nNo he podido crear el proceso hijo"); // Imprime mensaje de error
            break;
        case 0: // Proceso hijo
            for (i = 0; i < 10; i++) { // Bucle que itera 10 veces
                // Escribimos en el proceso hijo 
                write(fd1, string2, sizeof(string2)); // Escribir la cadena string2 en los archivos fd1
                write(fd2, string2, sizeof(string2)); // Escribir la cadena string2 en los archivos fd2
                usleep(1); /* Abandonamos voluntariamente el procesador */
            }
            break;
        default: // Proceso padre 
            for (i = 0; i < 10; i++) { // Bucle que itera 10 veces
                // Escribimos en el proceso padre
                write(fd1, string1, sizeof(string1)); // Escribir la cadena string1 en los archivos fd1
                write(fd2, string1, sizeof(string1)); // Escribir la cadena string1 en los archivos fd2
                usleep(1); /* Abandonamos voluntariamente el procesador */
            }
    }
    printf("\nFinal de ejecucion de %d \n", getpid()); //Imprime el id del ambos procesos padre e hijo
    exit(0);
}
