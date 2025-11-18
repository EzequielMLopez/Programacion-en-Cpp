// Cuarto Proyecto.cpp : Pide nombre y una calificacion guardandola en una pila
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#define NULL 0

using namespace std;

struct s_alumno {
	char name[30];
	float promedio = 0;
};
struct s_nodo {
	s_alumno elemento;
	s_nodo* link = NULL;
};

int main() {
	s_nodo* inicio = NULL, * q = NULL;
	int elem;
	char c, cr[2];
	inicio = NULL;
	do {
		cout << "Oprime ""S"" para agregar otro elemento: "; cin >> c; elem = c;
		if (elem == 83) {
			q = new s_nodo;
			cout << "\n Nombre?: "; cin.getline(q->elemento.name, 30, '\t'); cin.getline(cr, 2);
			cout << "\n Promedio?: "; cin >> q->elemento.promedio;
			cout << "\n";
			q->link = inicio;
			inicio = q;
		};
	} while (elem == 83);

	// Recorrido de la lista
	q = inicio;
	while (q != NULL) {
		cout << q->elemento.name << " tiene de promedio: "
			<< q->elemento.promedio << endl;
		q = q->link;
	};

	// Desalojar la lista
	while (inicio != NULL) {
		q = inicio->link;
		delete inicio;
		inicio = q;
	};
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
