//NovenoProyecto.cpp: Se encarga de construir una cola y desplegarla en dos ordenes diferentes

#include <iostream>
#include <conio.h>

using namespace std;

struct s_caja {
	int dato;
	s_caja* enlace;
};

//Variables Globales
s_caja* caja_inicial = NULL, * caja_final = NULL;

int otra_caja() {
	char c;
	int elem = 0;
	cout << "Deseas otro elemento?: ";
	cin >> c; elem = c;
	if (c == 115 || c != 83)
		return false;
	else{
		return true;
	}
};

s_caja* hacer_caja() {
	// aloja memoria 
	s_caja* q;
	q = new s_caja;
	if (q == NULL)
		return NULL;

	// pide los datos
	cout << "Proporciona un numero entero: ";
	cin >> q->dato;
	q->enlace = NULL;
	cout << endl;

	return q;
};

void Formar(s_caja* q) {
	if (q == NULL)
		return;
	q->enlace = NULL;

	// “Forma” una caja al final
	if (caja_final == NULL)
		caja_inicial = q;
	else
		caja_final->enlace = q;
	caja_final = q;
};

void imprimeLista1(s_caja* q) {
	if (q == NULL) {
		cout << "NULL" << endl;
		return;
	};

	cout << q->dato << endl;
	q = q->enlace;
	imprimeLista1(q);
};

void imprimeLista2(s_caja* q) {
	if (q == NULL) {
		cout << "NULL" << endl;
		return;
	};

	imprimeLista2(q->enlace);
	cout << q->dato << endl;
};

int main() {
	s_caja* q;
    int elem = 0, opcion = 0;
	// crear y guardar
	while (otra_caja() == true)
		Formar(hacer_caja());

	// Recorrido de la lista
	do {
		cout << "Como deseas imprimir la cola? " << endl
			<< " 0: en orden (FIFO) \n"
			<< " 1: en orden inverso: ";
		cin >> opcion;
	} while (opcion < 0 || opcion>1);

	if (opcion == 0) {
		cout << "La lista FIFO: \n";
		imprimeLista1(caja_inicial);
	}
	else {
		cout << "La lista FIFO en orden inverso: \n";
		imprimeLista2(caja_inicial);
	};

	// Desalojar la lista
	while (caja_inicial != NULL) {
		q = caja_inicial->enlace;
		delete caja_inicial;
		caja_inicial = q;

	};

	return 0;
}