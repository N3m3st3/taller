#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>

using namespace std;

/**
 * Encuentra todos los números primos hasta un determinado rango.
 *
 * @param rango El número máximo hasta el cual se buscarán los números primos.
 * @return Un vector que contiene todos los números primos encontrados.
 */
vector<long long> encontrarPrimos(long long rango) {
    vector<bool> compuestos(rango + 1, false); // Vector para marcar los números compuestos
    vector<long long> primos; // Vector para almacenar los números primos encontrados

    primos.push_back(2); // Agregar el número primo 2 a la lista inicialmente

    // Comenzar desde el primer número impar, que es 3
    for (long long p = 3; p <= rango; p += 2) {
        // Si el número no ha sido marcado como compuesto, entonces es primo
        if (!compuestos[p]) {
            // Agregar el número primo a la lista
            primos.push_back(p);
            // Marcar todos los múltiplos impares del número primo como compuestos 
            for (long long i = p * p; i <= rango; i += p + p) {
                compuestos[i] = true;
            }
        }
    }

    return primos;
}

/**
 * Función principal del programa.
 */
int main() {
    // Deshabilitar la sincronización de entrada y salida
    ios_base::sync_with_stdio(false);

    auto start = chrono::high_resolution_clock::now();
	
    omp_set_num_threads(6);

    long long rangoMaximo = 500000000;

    vector<long long> primosEncontrados = encontrarPrimos(rangoMaximo);

    cout << "Números primos encontrados: ";
    #pragma omp parallel for
    for (size_t i = 0; i < primosEncontrados.size(); i++) {
        cout << primosEncontrados[i] << " ";
    }
    cout << endl;

    cout << "Cantidad de números primos encontrados: " << primosEncontrados.size() << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double seconds = duration.count();
    int minutes = static_cast<int>(seconds) / 60;
    seconds -= minutes * 60;
    cout << "\nTiempo de ejecucion: " << minutes << " minutos y " << seconds << " segundos" << endl;

    // Limpiar el buffer
    cout.flush();

    return 0;
}

