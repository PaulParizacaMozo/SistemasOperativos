#include <stdio.h>
#include <pthread.h> // Esta librería nos permite trabajar con hilos

#define N 8 // Definicion de N = 8
#define M 16 // Definicion de M = 16

//Variables globales
const char *mensaje[2] = {"Hola Mundo", "Mundo Hola"}; //Arreglo de dos elementos de tipo *char
const int cantidad[2] = {N, M}; // Arreglo de dos elementos de cantidades N=8 y M=16

//Funcion que imprime mensaje que recibe como parametro un puntero a char
void imprime_mensaje(void *ptr) { 
    int i; // Entero i que servira de iterador mas adelante
    int id; // Entero que recibira valor de 1 o 0 (servira para saber que indice sera del array cantidad(0,1) ) 
    // Toma un puntero void * que apunta a un entero y lo convierte a un puntero a un entero (int *),
    // luego desreferencia ese puntero para obtener el valor entero apuntado,
    // finalmente, asigna ese valor a la variable id.
    id = *(int *) ptr;
    for(i=0; i<cantidad[id]; i++){ //Bucle que recorre N o M veces segun el id(0,1)
        printf("%s\n", mensaje[id]); //Imprime el mensaje segun el id(0,1)
    }
    return; // Salida de la funcion
}

int main(int argc, char *argv[]){
    pthread_t hilo0, hilo1; // Declaramos dos identificadores de hilos
    int id0=0, id1=1; // Declaramos e inicializamos dos identificadores para los hilos

    // Se creao el primer hilo y asocia con la función 'imprime_mensaje', pasando 'id0' como argumento
    pthread_create(&hilo0, NULL, (void *) &imprime_mensaje, (void *) &id0);
    // Se crear el segundo hilo y asocia con la función 'imprime_mensaje', pasando 'id1' como argumento
    pthread_create(&hilo1, NULL, (void *) &imprime_mensaje, (void *) &id1);

    // Se espera a que el primer hilo termine de ejecutarse
    pthread_join(hilo0, NULL);
    // Se espera a que el segundo hilo termine de ejecutarse
    pthread_join(hilo1, NULL);

    return 0; // Salida del programa
}
