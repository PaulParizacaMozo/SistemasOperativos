/*
Laboratorio 08
Por: Paul Antony Parizaca Mozo
Grupo: A
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Estructura para representar un proceso
struct Proceso {
    char id[20];            // Identificador del proceso
    int tiempoRafaga;       // Tiempo total de ejecucion (CPU) necesario para el proceso
    int tiempoLlegada;      // Tiempo de llegada del proceso
};

//Funcion para sort, para ordenar los procesos en orden de llegada
bool ordenar(const struct Proceso &a, const struct Proceso &b) {
    return a.tiempoLlegada < b.tiempoLlegada;
}

// Algoritmo FCFS
void FCFS(vector<Proceso>& procesos) {
    //Ordenamos los procesos
    sort(procesos.begin(),procesos.end(),ordenar);

    int tiempoActual = 0; //Tiempo actual del CPU
    int tiempoEsperaTotal = 0; //Variable para almacenar el tiempo total
    int tiempoRetornoTotal = 0; //Variable para almacenar el retorno total

    // Calculamos el tiempo de espera y retorno para cada proceso
    for (const auto& proceso : procesos) { // Recorremos el vector de procesos uno a uno
        int tiempoEspera = tiempoActual - proceso.tiempoLlegada; //Timempo de Espera del proceso actual
        tiempoEsperaTotal += tiempoEspera; // Sumamos el tiempo para el calculo del tiempo de espera promedio
        tiempoActual += proceso.tiempoRafaga; // Sumamos al tiempo actual el tiempo de Rafaga del proceso 
        tiempoRetornoTotal += tiempoActual; // Sumamos el tiempo de retorno de cada proceso para el promedio
        // Imprimir resultados para el proceso actual
        cout << "Proceso " << proceso.id << ":\n";
        cout << "Tiempo de espera: " << tiempoEspera << "\n";
        cout << "Tiempo de retorno: " << tiempoActual << "\n\n";
    }

    // Calcular tiempos promedio para el tiempo de espera y retorno
    float tiempoEsperaPromedio = static_cast<float>(tiempoEsperaTotal) / procesos.size();
    float tiempoRetornoPromedio = static_cast<float>(tiempoRetornoTotal) / procesos.size();

    // Imprimir tiempos promedio
    cout<<"Tiempo de espera promedio: "<<tiempoEsperaPromedio<<endl;
    cout<<"Tiempo de retorno promedio: "<<tiempoRetornoPromedio<<endl<<endl;
}

int main() {
    // Ejemplo 1
    cout << "**** EJEMPLO 1 ****\n";

    // Vector con los datos del ejemplo 1 
    vector<Proceso> procesos = {
        //id,t_rafaga,t_llegada
        {"P1", 10, 0},
        {"P2", 1, 0},
        {"P3", 2, 0},
        {"P4", 1, 0},
        {"P5", 5, 0}
    };
    // Algoritmo FCFS
    FCFS(procesos);

    // Ejemplo 2
    cout << "**** EJEMPLO 2 ****\n";
    // Vector con los datos del ejemplo2 
    vector<Proceso> procesos2 = {
        //id,t_rafaga,t_llegada
        {"P1", 4, 0},
        {"P2", 6, 2},
        {"P3", 8, 6},
        {"P4", 4, 8},
        {"P5", 4, 10}
    };
    // Algoritmo FCFS
    FCFS(procesos2);

    return 0;
}

