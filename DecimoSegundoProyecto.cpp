//Creación y recorrido 

#include <iostream>
#include <stdlib.h>
#include <vector>
#define NULL 0

using namespace std;

struct s_nodo {
	int numero = 0;
	s_nodo* sub_izqui = NULL;
	s_nodo* sub_derec = NULL;
};

//Prototipos de funcion
s_nodo* Construye_arbol();
int hay_hijo(int n);
void Pre_orden(s_nodo* p);
void Post_orden(s_nodo* p);
void Entre_orden(s_nodo* p);
void Destruye_arbol(s_nodo* p);

int main() {
	s_nodo* inicio = NULL;
	int opcion = 0;

	cout << "Ingresa los nodos del arbol en pre-orden \n"
	    << "\nPara cada nodo indicar si tiene un subarbol izq. y der"
		<< "\n\'S\' para indicar que si, cualquier otra tecla para"
		<< "indicar que no \n";
	inicio = Construye_arbol();

	while (true) {
		do {
			cout << "\n Para imprimir el arbol, indica el recorrido: \n"
				<< " 1: pre-orden: raiz-izq-der \n"
				<< " 2: post-orden: izq-der-raiz \n"
				<< " 3: entre-orden: izq-raiz-der \n"
				<< " 4: salir \n";
			cin >> opcion;
		} while (opcion < 1 || opcion > 4);

		switch (opcion) {
		case 1: cout << " El arbol en pre-orden es: \n";
			Pre_orden(inicio);
			break;
		case 2: cout << " El árbol en post-orden es: \n";
			Post_orden(inicio);
			break;
		case 3: cout << " El arbol en entre-orden es: \n";
			Entre_orden(inicio);
			break;
		case 4: Destruye_arbol(inicio);
			return 0;
		};
	};
}

s_nodo* Construye_arbol() {
	s_nodo* raiz = NULL;
	raiz = new s_nodo;

	cout << "\nQue dato desea ingresar?: "; cin >> raiz->numero;
	raiz->sub_izqui = NULL; raiz->sub_derec = NULL;

	if (hay_hijo(0))
		raiz->sub_izqui = Construye_arbol(); //Hacer sub-arbol izquierdo
	if (hay_hijo(1))
		raiz->sub_derec = Construye_arbol(); //Hacer sub-arbol derecho

	return raiz;
}

int hay_hijo(int n){
	char lado[2] = { {'I'}, {'D'} };
	char c = 't';
	int elem = 0;
	cout << " hay hijo: "
	     << lado[n] << "?";
	cin >> c; elem = c;

	if (elem == 115 || elem != 83)
		return false;
	if (elem == 83)
		return true;
}

void Pre_orden(s_nodo* p) {
	if (p == NULL) return;

	cout << " " << p->numero << endl;
	Pre_orden(p->sub_izqui);
	Pre_orden(p->sub_derec);
}

void Post_orden(s_nodo* p) {
	if (p == NULL) return;

	Pre_orden(p->sub_izqui);
	Pre_orden(p->sub_derec);
	cout << " " << p->numero << endl;
}

void Entre_orden(s_nodo* p) {
	if (p == NULL) return;
	Pre_orden(p->sub_izqui);
	cout << " " << p->numero <<endl;
	Pre_orden(p->sub_derec);
}

void Destruye_arbol(s_nodo* p) {
	if (p == NULL)
		return;
	Destruye_arbol(p->sub_izqui);
	Destruye_arbol(p->sub_derec);
	delete p;
}