// OctavoProyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

struct s_caja{
	int dato = 0;
	s_caja* enlace = NULL;
};

//Variables Globales
s_caja *p = NULL;

//Prototipo
int otra_caja();
s_caja* hacer_caja();
void Push(s_caja* q);
void Orden_normal(s_caja* q);
void Orden_inverso(s_caja* q);

int main() {
	s_caja* q = NULL,* inipila = NULL;
	char c = 't';
	int opcion = 0;

	//Creacion de la pila
	while (otra_caja() == true) {
		Push(hacer_caja());
	}

	//Menu del programa
	do {
		cout << "\nComo deseas imprimir la pila?: " << endl
			<< "(0): En orden normal \n"
			<< "(1): En orden inverso \n"
			<< "Elija la opcion: "; cin >> opcion;
	} while (opcion < 0 || opcion > 1);

	//Recorrido de la lista
	if (opcion == 0) {
		cout << "\nLos elementos de la lista LIFO normal son: " << endl;
		Orden_normal(q);
	}
	else {
		cout << "Los elemntos de la lista LIFO invertida son: " << endl;
		Orden_inverso(q);
	};

	//Desalojar la memoria
	while (p != NULL) {
		q = p->enlace;
		delete p;
		p = q;
	};

	return 0;
}

int otra_caja() {
	int elem = 0;
	char c = 't';

	cout << "Desea ingresar otra caja? \'s\' = NO , \'S\' = SI: ";
	cin >> c; elem = c;
	if (elem == 115 || elem != 83)
		return false;
	else {
		return true;
	};
}

s_caja* hacer_caja() {
	s_caja *q = NULL;
	q = new s_caja;
	if (q == NULL)
		return NULL;

	cout << "Ingrese el dato entero: "; cin >> q->dato;
	cout << endl;
	return q;
}

void Push(s_caja* q) {
	if (q == NULL)
		return;
	// “empuja” una caja
	q->enlace = p;
	p = q;
}

void Orden_normal(s_caja* p) {
	if (p == NULL) return;

	cout << p->dato << endl;
	Orden_normal(p->enlace);
};

void Orden_inverso(s_caja* p) {
	if (p == NULL) return;

	Orden_inverso(p->enlace);
	cout << p->dato << endl;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
