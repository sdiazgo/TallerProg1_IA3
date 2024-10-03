#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

using namespace std;

void generar_vuelo(int vuelo_num) {
    // Genera aleatoriamente el número de pasajeros (entre 50 y 100)
    int num_pasajeros = rand() % 51 + 50; // Aleatorio entre 50 y 100
    
    // Genera aleatoriamente la distancia del vuelo (entre 500 y 5000 kilómetros)
    int distancia = rand() % 4501 + 500; // Aleatorio entre 500 y 5000
    
    cout << "\nVuelo " << vuelo_num << ": " << num_pasajeros << " pasajeros, Distancia: " << distancia << " km\n";

    // Arreglos para almacenar los códigos de los pasajeros y las millas
    int codigos_pasajeros[num_pasajeros];
    double millas_pasajeros[num_pasajeros];

    // Para cada pasajero, generamos su ID y calculamos sus millas
    for (int i = 0; i < num_pasajeros; ++i) {
        int codigo_pasajero = rand() % 900 + 100; // Aleatorio entre 100 y 999
        double millas_base = distancia;
        double millas_extra;
        string estatus;

        // Determinar si es VIP o Diamante
        if (codigo_pasajero % 12 == 0) {
            estatus = "Diamante";
            millas_extra = distancia / 20.0;
        } else if (codigo_pasajero % 7 == 0) {
            estatus = "VIP";
            millas_extra = distancia / 60.0;
        } else {
            estatus = "Normal";
            millas_extra = distancia / 100.0;
        }

        // Calcular las millas totales
        double millas_totales = millas_base + millas_extra;

        // Guardar los códigos y las millas en los arreglos
        codigos_pasajeros[i] = codigo_pasajero;
        millas_pasajeros[i] = millas_totales;

        // Imprimir información del pasajero
        cout << "  Pasajero " << codigo_pasajero << " - Estatus: " << estatus 
             << " - Millas totales: " << millas_totales << endl;
    }

    // Imprimir los arreglos de códigos y millas para el vuelo
    cout << "\nCódigos de pasajeros del Vuelo " << vuelo_num << ": ";
    for (int i = 0; i < num_pasajeros; ++i) {
        cout << codigos_pasajeros[i] << " ";
    }
    cout << endl;

    cout << "Millas de pasajeros del Vuelo " << vuelo_num << ": ";
    for (int i = 0; i < num_pasajeros; ++i) {
        cout << millas_pasajeros[i] << " ";
    }
    cout << endl;
}

int main() {
    // Inicializar la semilla para los números aleatorios
    srand(time(0));

    int n;

    // Solicitar al usuario el número de vuelos
    do {
        cout << "Ingrese el número de vuelos a generar (n > 0): ";
        cin >> n;
        if (n <= 0) {
            cout << "Por favor, ingrese un número mayor que cero.\n";
        }
    } while (n <= 0);

    // Generar n vuelos
    for (int vuelo = 1; vuelo <= n; ++vuelo) {
        generar_vuelo(vuelo);
    }

    return 0;
}