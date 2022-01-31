#include <iostream>
#include <conio.h>
#define NULL 0

using namespace std;

void pedirDatosArreglo(int* A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "A[" << i+1 << "]= ";
		cin >> A[i];
	};
}

int particion(int* a, int izq, int der) {
	int i = izq, j = der;
	int tmp;
	int pivote = a[(izq + der) / 2];
	
	while (i <= j) {
		while (a[i] < pivote)
			i++;
		while (a[j] > pivote)
			j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		};
	};
	
	return i;
}

void quick_sort(int* a, int prim, int ult) {
	int pivote = particion(a, prim, ult);
	if (prim < pivote - 1)
		quick_sort(a, prim, pivote-1);
	if (pivote < ult)
		quick_sort(a, pivote, ult);
}

void mezcla(int* a, int ini, int med, int fin) {
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
};

void merge_sort(int* a, int ini, int fin) {
	// Si ini = fin el sub-vector es de un solo elemento y,
	// por lo tanto ya está ordenado por definición
	int med = 0;
	if (ini < fin) {
		med = (ini + fin) / 2;
		merge_sort(a, ini, med);
		merge_sort(a, med + 1, fin);
		mezcla(a, ini, med, fin);
	}
};

int main()
{
	int opcion, n, * A = NULL, inicio = 0;
	char c;

	do
	{
		cout << "Cuantos numeros (enteros) deseas ordenar?: ";
		cin >> n;
		// Alojar el arreglo de tamaño n;
		A = new int[n];

		pedirDatosArreglo(A, n);

		do {
			cout << endl
				<< "¿Opción para ordenarlos (menor a mayor)?:\n"
				<< " (1) : QuickSort " << endl
				<< " (2) : MergeSort: ";
				cin >> opcion;
		} while ((opcion < 1) || (opcion > 2));

		switch (opcion)
		{
		case 1: quick_sort(A, inicio, n-1);
			cout << "\nLos datos con Quick Sort son: \n";
			break;
		case 2: merge_sort(A, inicio, n);
			cout << "\nLos datos con Merge Sort son: \n";
			break;
		};

		for (int i = 0; i < n; i++)
			cout << "A[" << i << "]=" << A[i] << endl;

		cout << "oprime \"S\" para terminar: ";
		cin >> c; int elem = c;
	} while (c != 83);

	cout << " Adios! ";

	return 0;
}