// SeptimoProyecto.cpp : Compara si los elementos de dos colas son iguales
//

#include <iostream>
#include <conio.h>
#define NULL 0
#define TRUE 1
#define FALSE 0

using namespace std;

struct s_caja {
    int dato;
    s_caja* siguiente;
};

int j = 0;

bool otra_caja() {
    char c; int elem = 0;
    cout << "\n Desea introducir los datos de otra caja? ";
    cin >> c; elem = c;
    if (elem == 115 || elem != 83)
        return FALSE;
    if (elem == 83)
        return TRUE;
};

s_caja* hacer_caja() {
    // aloja memoria 
    s_caja* q;
    q = new s_caja;
    if (q == NULL)
        return NULL;
    // pide el dato
    cout << " Numero entero?: ";
    cin >> q->dato;

    return q;
}

void Formar(s_caja* q, s_caja*& caja_inicial, s_caja*& caja_final){
    if (q == NULL)
        return;
    q->siguiente = NULL;
    // "forma" una caja al final
    if (caja_final == NULL)
        caja_inicial = q;
    else
        caja_final->siguiente = q;
    caja_final = q;
    j++;
}

s_caja* Despachar(s_caja*& caja_inicial, s_caja*& caja_final) {
    // si ya está vacía
    if (caja_inicial == NULL)
        return NULL;
    s_caja* q;
    q = caja_inicial;
    caja_inicial = caja_inicial->siguiente;
    q->siguiente = NULL;
        // si queda vacía
        if (caja_inicial == NULL)
            caja_final = NULL;
    return q;
}

int main() {
    s_caja* q;
    s_caja* inicioC1 = NULL, * inicioC2 = NULL, * finC1 = NULL,
        * finC2 = NULL;

    // crear y guardar elementos de la cola 1
    cout << "Proporciona los elementos de la cola 1 \n";
    while (otra_caja()) {
        q = hacer_caja();
        Formar(q, inicioC1, finC1);
    };
    cout << " \n La longitud de la cola 1 es: " << j << endl;
    j = 0;

    // crear y guardar elementos de la cola 2
    cout << "Proporciona los elementos de la cola 2 \n";
    while (otra_caja()) {
        q = hacer_caja();
        Formar(q, inicioC2, finC2);
    };
    cout << " \n La longitud de la cola 2 es: " << j << endl;

    q = inicioC1;
    cout << "\n Los elementos de la cola 1 son: \n";
    while (q != NULL) {
        cout << q->dato << endl;
        q = q->siguiente;
    };

    q = inicioC2;
    cout << "\n Los elementos de la cola 2 son: \n";
    while (q != NULL) {
        cout << q->dato << endl;
        q = q->siguiente;
    };

    // Determinar si el contenido de la cola 1 y 
    // el de la cola 2 es el mismo
    q = inicioC1;
    s_caja* q2 = inicioC2;
    bool iguales;
    if (q == NULL && q2 == NULL)
        // Las dos colas están vacías
        iguales = TRUE;
    else
    {
        if (q != NULL && q2 != NULL)
            // las dos colas tienen elementos
            iguales = TRUE;
        else
            // una de las dos colas está vacía
            iguales = FALSE;
    };

    while (q != NULL && q2 != NULL && (q->dato == q2->dato)){
        q = q->siguiente;
        q2 = q2->siguiente;
    };

    if (q == NULL && q2 == NULL)
        cout << "\nEl contenido de las dos colas es el mismo";
    else
        cout << "\nEl contenido de las dos colas es diferente";
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
