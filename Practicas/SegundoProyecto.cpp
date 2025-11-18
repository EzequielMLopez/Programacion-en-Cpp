// SegundoProyecto.cpp : Leer n cantidades y escribirlas en orden inverso
//

#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main() {
    int tamanio, linf, lsup, buscado, mitad;
    int* A = NULL;
    char arreglo[30];

    cout << "Ingrese su nombre: " << endl;
    cin.getline(arreglo, 30, '\n');
    cout << "El arreglo ingresado es: " << arreglo << endl;

    ifstream entrada;
    entrada.open("ArregloOrdenado.txt");
    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        system("PAUSE");
        return -2;
    };
    entrada >> tamanio;
    cout << "El arreglo tiene " << tamanio
        << " elementos y son: \n" << endl;

    //Alojar el arreglo A
    A = new int[tamanio];

    // Leer los datos del archivo
    for (int i = 0; i < tamanio; i++) {
        entrada >> A[i];
        cout << "A[" << i << "]= " << A[i] << endl;
    };
    entrada.close();

    cout << "Que numero quieres buscar? " << endl; cin >> buscado;
    linf = 0;
    lsup = tamanio - 1;

    while (true) {
        mitad = (linf + lsup) / 2;
        if (A[mitad] == buscado || linf == lsup) { break; };
        if (A[mitad] < buscado) { linf = mitad + 1; };
        if (A[mitad] > buscado) { lsup = mitad - 1; };
    };
    if (A[mitad] == buscado) {
        cout << "El numero buscado esta en la posicion: "
            << mitad << " de A \n" << endl;
    }
    else {
        cout << "Lastima!! el numero no esta. . .\n" << endl;
    }

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
