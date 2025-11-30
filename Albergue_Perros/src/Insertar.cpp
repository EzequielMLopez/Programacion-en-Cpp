#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

using namespace std;

void SUCURSAL::AGREGAR_PERRERA(char* nome) {
  PERRERA *PE, *nuevo;

  // Se crea una nueva perra y se solicita al usuario los datos pertinentes a la
  // misma.
  nuevo = new PERRERA(nome);

  cout << "\tPor favor, ingrese el pais donde se encuentra la perrera: ";
  cin.getline(nuevo->pais, 20);
  cout << "\tAhora la provincia: ";
  cin.getline(nuevo->provincia, 20);
  cout << "\tPartido: ";
  cin.getline(nuevo->partido, 20);
  cout << "\tLocalidad: ";
  cin.getline(nuevo->localidad, 20);
  cout << "\tDireccion: ";
  cin.getline(nuevo->direccion, 40);
  cout << "\tAltura: ";
  cin >> nuevo->altura;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Condicion en caso de que la lista de sucursales/perreras este vacia.
  if (INICIO == NULL) {
    INICIO = nuevo;
    return;
  }

  // Se inicializa el puntero
  PE = INICIO;

  // Se recorre la lista hasta la ultima posicion agregando la nueva perrera al
  // final.
  while (PE->SIG) {
    PE = PE->SIG;
  }

  PE->SIG = nuevo;

  return;
}

void SUCURSAL::AGREGAR_PERRITO(char* perre) {
  PERRERA* P;
  PERROS *PE, *nuevo;
  char perrito[20];
  int flag = 0;

  P = INICIO;

  while (P) {
    if (!strcmp(P->nombre, perre)) {
      PE = P->INIP;

      cout << "\tIngrese el nombre del nuevo integrante del grupo: ";
      cin.getline(perrito, 20);
      nuevo = new PERROS(perrito);
      cout << "\tCual es la edad del perrito/a: ";
      cin >> nuevo->edad;

      if (P->INIP == NULL) {
        P->INIP = nuevo;
        return;
      }

      while (PE->SIG) {
        PE = PE->SIG;
      }
      PE->SIG = nuevo;

      break;
    } else {
      flag = 1;
    }

    P = P->SIG;
  }

  if (flag == 1) {
    cout << "La perrera cuestion no se encuentra en nuestra Base de Datos, le "
            "pedimos que la cree para poder ingresar perritos en la misma."
         << endl;
  }

  return;
}
