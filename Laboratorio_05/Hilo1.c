#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h> //Esta libreria nos permite trabajar con hilos

// Función que sera relacionada con el primer hilo 
void *hola(void *arg) {
    char *msg = "Hola"; // Cadena de caracteres
    int i; // Entero que servira de iterador
    for(i=0; i<strlen(msg); i++) { //Bucle que recorrera cada letra del msg = "Hola"
        printf("%c", msg[i]); // Imprime el caracter
        fflush(stdout);  // Fuerza que se muestre el caracter inmediatamente
        usleep(1000000);  // Retraso de 1 segundo entre cada carácter
    }
    return NULL ; // Retorna NULL
}

// Función que sera relacionada con el segundo hilo 
void *mundo(void *arg) {
    char *msg = "mundo"; // Cadena de caracteres
    int i;  //Entero que servira de iterador
    for(i=0; i<strlen(msg); i++) { //Bucle que recorrera cada letra del msg = "mundo"
        printf("%c", msg[i]); //Imprime el caracter
        fflush(stdout); //Fuerza que se muestre el caracter inmediatamente
        usleep(1000000); // Retraso de 1 segundo entre cada caracter
    }
    return NULL ; // Retorna NULL
}

// Función principal
int main (int argc, char *argv[]) {
    pthread_t h1;  // Identificador del primer hilo
    pthread_t h2;  // Identificador del segundo hilo

    // Crea el primer hilo y lo asocia con la función 'hola'
    pthread_create(&h1, NULL, hola, NULL);
    // Crea el segundo hilo y asocia con la función 'mundo'
    pthread_create(&h2, NULL, mundo, NULL);

    // Espera a que el primer hilo finalize 
    pthread_join(h1, NULL);
    // Espera a que el segundo hilo finalize 
    pthread_join(h2, NULL);

    // Imprime "Fin" cuando terminan de ejecutar ambos hilos
    printf("Fin \n");

    return 0;  
}
