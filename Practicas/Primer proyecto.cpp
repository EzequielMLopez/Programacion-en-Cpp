// Primer proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.//

#include <iostream>
#include <conio.h>
#include <fstream>
#include <math.h>

using namespace std;

struct s_transaccion {
	int anio, mes, dia;
	int hora, minuto, segundo;
	int opcion;
	double cuenta;
	double monto;
};

ifstream entrada;
ofstream salida;
#define NUM_TR 100

int main() {
	// declaracion del arreglo de registros de tamaño 100
	s_transaccion tr[NUM_TR];

	// Solicitar los datos de los 100 registros al usuario
	for (int i = 0; i < 2; i++) {
		cout << "Fecha de la transaccion:";
		cin >> tr[i].anio; cout << "\t\t\t"; cin >> tr[i].mes; cout << "\t\t\t"; cin >> tr[i].dia;
		cout << "Hora de la transaccion";
		cin >> tr[i].hora; cout << "\t\t"; cin >> tr[i].minuto; cout << "\t\t"; cin >> tr[i].segundo;
		cout << "Opcion (1: deposito, 2: retiro)";
		cin >> tr[i].opcion;
		while (tr[i].opcion < 1 || tr[i].opcion > 2) {
			cout << "Ingrese un valor entre 1 y 2:";
			cin >> tr[i].opcion;
		};
		cout << "Numero de cuenta (10 digitos):";
		cin >> tr[i].cuenta;
		cout << "Monto de la transaccion:";
		cin >> tr[i].monto;
	};

	// abrir el archivo de salida
	salida.open("Transacciones.txt");

	// escribe el encabezado del archivo
	cout << "Año Mes Dia Hora Minuto Segundo Opción Cuenta Monto";

	// escribe los datos por renglón para cada uno de los registros
	for (int i = 0; i < 2; i++) {
		salida << tr[i].anio
			<< tr[i].mes
			<< tr[i].dia
			<< tr[i].hora
			<< tr[i].minuto
			<< tr[i].segundo
			<< tr[i].opcion
			<< tr[i].cuenta
			<< tr[i].monto << endl;
	};

	salida.close();
	return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccion e el archivo .sln
