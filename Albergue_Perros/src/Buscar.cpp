#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

using namespace std;

void SUCURSAL::BUSCAR_PERRITO(char* perr) {
  PERRERA* PE;
  PERROS* P;
  char perrito[20];

  PE = INICIO;

  cout << "\t\tIngrese el nombre del perrito a buscar: ";
  cin.getline(perrito, 20);

  while (PE) {
    if (!strcmp(PE->nombre, perr)) {
      if (PE->INIP == NULL) {
        cout << "\t\tNo hay perritos dentro de esta perrera, favor de "
                "ingresar "
                "al menos uno con otra opcion del menu principal"
             << endl;
        return;
      }

      P = PE->INIP;

      while (P) {
        if (!strcmp(P->nombre, perrito)) {
          cout << "\t\tSe encontro el perrito buscado, sus datos son:\n"
               << "\t\tNombre: " << P->nombre << "\n"
               << "\t\tEdad: " << P->edad << endl;
          return;
        } else {
          cout << "\t\tNo se encontro al perrito que estaba buscando :(" << endl;
          return;
        }

        P = P->SIG;
      }
    }

    PE = PE->SIG;
  }
}

void SUCURSAL::BUSCAR_PERRITO() {
  PERRERA* PE;
  PERROS* P;
  char perrito[20];
  int flag = 0;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perreras ingresadas, favor de crear al menos una, "
            "gracias."
         << endl;
    return;
  }

  cout << "\t\tIngrese el nombre del perrito a buscar: ";
  cin.getline(perrito, 20);

  PE = INICIO;

  while (PE) {
    if (PE->INIP == NULL) {
      PE = PE->SIG;
      continue;
    } else {

      P = PE->INIP;

      while (P) {
        if (!strcmp(P->nombre, perrito)) {
          cout << "\t\tSe encontro el perrito buscado, sus datos son:\n"
               << "\t\tNombre: " << P->nombre << "\n"
               << "\t\tEdad: " << P->edad << endl;
          return;
        }

        P = P->SIG;
      }
    }

    flag = 1;
  }

  if (flag == 1)
    cout << "\t\tNo se encontro al perro que se estaba buscando en ninguna "
            "perrera."
         << endl;

  return;
}
