// TercerProyecto.cpp : Conversión de Farenheit a Centigrados y viceversa
//

#include <iostream>
#include <conio.h>

using namespace std;

//Prototipos
double F_a_Centigrados(double f) {
	return(((f - 32.0) * 5.0) / 9.0);
};

double C_a_Farenheit(double c) {
	return(9.0 * c / 5.0 + 32.0);
};

int pideOpcion() {
	// elección y validación de opción
	int o;
	cout << " (1).- convertir de grados Farenheit a centigrados.\n"
		<< " (2).- convertir de grados centigrados a Farenheit.\n"
		<< " (3).- Para terminar el programa. \n \n";
	do {
		cout << "Elija una opcion del 1 al 3: ";
		cin >> o;
	} while ((o < 1) || (o > 3));
	return o;
}
void Caso1() {
	double dato, dato_convertido;
	cout << "\nIntroduzca la temperatura en grados Farenheit: ";
	cin >> dato;
	dato_convertido = F_a_Centigrados(dato);
	cout << endl << dato << " grados Farenheit equivalen a: "
		<< dato_convertido << " grados centigrados \n";
}
void Caso2() {
	double dato, dato_convertido;
	cout << "\nIntroduzca la temperatura en grados Centigrados:";
	cin >> dato;
	dato_convertido = C_a_Farenheit(dato);
	cout << endl << dato << " grados centigrados equivalen a: "
		<< dato_convertido << " grados farenheit \n";
}
int main() {
	int opcion;
	cout << " Programa para convertir unidades de temperatura. \n ";
		// repetir lo siguiente
		while (1) {
			opcion = pideOpcion();

			switch (opcion) {
			case 1: Caso1();
				break; // rompe el switch
			case 2: Caso2();
				break; // rompe el switch
			}; // fin del switch
			if (opcion == 3)
				break; // rompe el while( 1 )
		}; // end while( 1 )
	cout << "\n adios....";
}

long int factorial(int monto) {
	long int total = monto;

	for (int i = 1; i < monto; i++)
		total *= i;
	return total;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
