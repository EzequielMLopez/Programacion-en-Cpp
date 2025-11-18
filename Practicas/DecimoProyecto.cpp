#include <iostream>

using namespace std;

//Prototipos
void Pedir_datos(int* a, int m);
void Merge_Sort(int* a, int ini, int fin);
void Mezcla(int* a, int ini, int med, int fin);
void Muestra_datos(int* a, int n);

int main() {
	int* arreglo = NULL, n = 0, inicio = 0;

	cout << "Ingrese el valor de su vector unidimensional: "; cin >> n;

	//Alojamos memoria y Recopilacion de datos
	arreglo = new int[n];
	Pedir_datos(arreglo, n);

	//Procesos encargados de ordenar
	Merge_Sort(arreglo, inicio, n-1);
	Muestra_datos(arreglo, n);
}

void Pedir_datos(int* a, int m) {
	for (int i = 0; i < m; i++) {
		cout << "Ingrese el valor entero que mas guste en ["<<i+1<<"]: ";
		cin >> a[i];
	};
}

void Merge_Sort(int* a, int ini, int fin) {
	int med = 0;
	if (ini < fin) {
		med = (ini + fin) / 2;
		Merge_Sort(a, ini, med);
		Merge_Sort(a, med + 1, fin);
		Mezcla(a, ini, med, fin);
	}
}

void Mezcla(int* a, int ini, int med, int fin) {
	int* aux = NULL;
	aux = new int[fin - ini + 1];
	int i = ini; //Indice sub-vector izquierdo
	int j = med + 1; //Indice sub-vector derecho
	int k = 0; //Indice del vector aux

	//Mientras ninguno de los indices llegue a su fin se hacen comparaciones. El elemento mas pequeño se copia en aux.
	while (i <= med && j <= fin) {
		if (a[i] < a[j]) {
			aux[k] = a[i];
			i++;
		}
		else {
			aux[k] = a[j];
			j++;
		};
		k++;
	};

	//Uno de los dos sub-vectores se copio del todo, se procede a copiar el otro sub-vector.
	while (i <= med) {
		aux[k] = a[i];
		i++;
		k++;
	};

	while (j <= fin) {
		aux[k] = a[j];
		j++;
		k++;
	};

	//Se copian los elementos ordenados de aux al vector a.
	for (int m = 0; m < fin - ini + 1; m++) {
		a[ini + m] = aux[m];
	};

	delete[] aux;
}

void Muestra_datos(int* a, int n) {
	cout << "Los datos ingresados y ordenados de forma ascendente son:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}