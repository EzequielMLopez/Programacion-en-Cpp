#include "Clases.h"
#include <cstdio>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>

using namespace std;

void SUCURSAL::AGREGAR_PERRERA(const string& nome) {
  PERRERA *PE, *nuevo;
  string pais, provincia, partido, localidad, direccion;
  int altura = 0;

  // Se crea una nueva perra y se solicita al usuario los datos pertinentes a la
  // misma.
  nuevo = new PERRERA(nome);

  cout << "\tPor favor, ingrese el pais donde se encuentra la perrera: ";
  getline(cin, pais);
  nuevo->setPais(pais);

  cout << "\tAhora la provincia: ";
  getline(cin, provincia);
  nuevo->setProvincia(provincia);

  cout << "\tPartido: ";
  getline(cin, partido);
  nuevo->setPartido(partido);

  cout << "\tLocalidad: ";
  getline(cin, localidad);
  nuevo->setLocalidad(localidad);

  cout << "\tDireccion: ";
  getline(cin, direccion);
  nuevo->setDireccion(direccion);

  cout << "\tAltura: ";
  cin >> altura;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  nuevo->setAltura(altura);

  // Condicion en caso de que la lista de sucursales/perreras este vacia.
  if (INICIO == NULL) {
    INICIO = nuevo;
    return;
  }

  // Se inicializa el puntero
  PE = INICIO;

  // Se recorre la lista hasta la ultima posicion agregando la nueva perrera al
  // final.
  while (PE->getSIG()) {
    PE = PE->getSIG();
  }

  PE->setSIG(nuevo);

  return;
}

void SUCURSAL::AGREGAR_PERRITO(const string& perre) {
  PERRERA* PE;
  PERROS *P, *nuevo;
  string perrito;
  int flag = 0, edad = 0;

  PE = INICIO;

  while (PE) {
    if (PE->getNombre() == perre) {
      P = PE->getINIP();

      cout << "\tIngrese el nombre del nuevo integrante del grupo: ";
      getline(cin, perrito);
      nuevo = new PERROS(perrito);
      cout << "\tCual es la edad del perrito/a: ";
      cin >> edad;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      nuevo->setEdad(edad);

      if (PE->getINIP() == NULL) {
        PE->setINIP(nuevo);
        return;
      }

      while (P->getSIG()) {
        P = P->getSIG();
      }
      P->setSIG(nuevo);

      break;
    } else {
      flag = 1;
    }

    PE = PE->getSIG();
  }

  if (flag == 1) {
    cout << "La perrera cuestion no se encuentra en nuestra Base de Datos, le "
            "pedimos que la cree para poder ingresar perritos en la misma."
         << endl;
  }

  return;
}
