#include "Clases.h"
#include <cstdio>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>

using namespace std;

void SUCURSAL::AGREGAR_PERRERA(const string& nome) {
  PERRERA *PE, *nuevo;

  // Se crea una nueva perra y se solicita al usuario los datos pertinentes a la
  // misma.
  nuevo = new PERRERA(nome);

  cout << "\tPor favor, ingrese el pais donde se encuentra la perrera: ";
  getline(cin, nuevo->pais);
  cout << "\tAhora la provincia: ";
  getline(cin, nuevo->provincia);
  cout << "\tPartido: ";
  getline(cin, nuevo->partido);
  cout << "\tLocalidad: ";
  getline(cin, nuevo->localidad);
  cout << "\tDireccion: ";
  getline(cin, nuevo->direccion);
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

void SUCURSAL::AGREGAR_PERRITO(const string& perre) {
  PERRERA* P;
  PERROS *PE, *nuevo;
  string perrito;
  int flag = 0;

  P = INICIO;

  while (P) {
    if (P->nombre == perre) {
      PE = P->INIP;

      cout << "\tIngrese el nombre del nuevo integrante del grupo: ";
      getline(cin, perrito);
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
