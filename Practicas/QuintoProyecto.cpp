// QuintoProyecto.cpp : Programa que construye una cola, calculo y despliega su longitud antes de despachar sus elementos
//
#include <iostream>
#include <conio.h>
#define NULL 0

using namespace std;

struct s_caja {
	char nombre[20];
	float precio;
	s_caja* siguiente;
};

s_caja* caja_inicial = NULL, * caja_final = NULL;
int j = 0;

bool otra_caja() {
	char c, cr[2];
	int elem = 0;
	cout << "\n Desea introducir los datos de otra caja? \'s\' = NO o \'S\' = SI: ";
	cin >> c;
	elem = c;
	if (elem == 115 || elem != 83)
		return false;
	if (elem == 83)
		return true;
};

s_caja* hacer_caja() {
	// aloja memoria 
	s_caja* q;
	char cr[2];
	q = new s_caja;
	if (q == NULL)
		return NULL;

	// pide los datos
	cout << " Nombre del producto?: "; 
	cin.getline(q->nombre, 30, '\t'); cin.getline(cr, 2);
    cout << " Precio?: "; cin >> q->precio;
	return q;
}

void Formar(s_caja* q) {
	if (q == NULL)
		return;
	q->siguiente = NULL;

	// “forma” una caja al final
	if (caja_final == NULL)
		caja_inicial = q;
	else
		caja_final->siguiente = q;
	caja_final = q; //Acá corregi
	j++; //Acá corregi
}

s_caja* Despachar() {
	// si ya está vacía
	if (caja_inicial == NULL)
		return NULL;
	s_caja* q;
	q = caja_inicial;
	caja_inicial = caja_inicial->siguiente;
	q->siguiente = NULL; 
		// si queda vacía
		if (caja_inicial == NULL)
			caja_final = NULL; //Acá corregi
	return q;
}

int main() {
	s_caja* q = NULL;

	// crear y guardar
	while (otra_caja() == true) {
		Formar( hacer_caja() );
	}

	cout << " \n La longitud de la cola es: " << j << endl;
	q = caja_inicial;

	// sacar, usar y desechar
	while (NULL != (q = Despachar()) ){
		// trabajar con la caja
		cout << q->nombre << " cuesta: " << q->precio << endl;
		delete q;
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
