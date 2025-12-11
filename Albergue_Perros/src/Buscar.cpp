#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

using namespace std;

void SUCURSAL::BUSCAR_PERRITO(const string& perr) {
  PERRERA* PE;
  PERROS* P;
  string perrito;
  int flag0 = 0, flag1 = 0;

  PE = INICIO;

  cout << "\t\tIngrese el nombre del perrito a buscar: ";
  getline(cin, perrito);

  while (PE) {
    if (PE->getNombre() == perr) {
      flag0 = 1;

      if (PE->getINIP() == NULL) {
        cout << "\t\tNo hay perritos dentro de esta perrera, favor de "
                "ingresar al menos uno con otra opcion del menu principal"
             << endl;
        return;
      }

      P = PE->getINIP();

      while (P) {
        if (P->getNombre() == perrito) {
          flag1 = 1;
          cout << "\t\tSe encontro el perrito buscado, sus datos son:\n"
               << "\t\tNombre: " << P->getNombre() << "\n"
               << "\t\tEdad: " << P->getEdad() << endl;

          break;
        }

        P = P->getSIG();
      }

      break;
    }

    PE = PE->getSIG();
  }

  if (flag0 == 1 && flag1 == 0)
    cout << "\t\tSe encontro la perrera solicitada pero no se corrio la misma suerte con el perrito." << endl;

  if (flag0 == 0)
    cout << "\t\tNo se encontro la perrera solicitada." << endl;

  return;
}

void SUCURSAL::BUSCAR_PERRITO() {
  PERRERA* PE;
  PERROS* P;
  string perrito;
  int flag = 0;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perreras ingresadas, favor de crear al menos una, "
            "gracias."
         << endl;
    return;
  }

  cout << "\t\tIngrese el nombre del perrito a buscar: ";
  getline(cin, perrito);

  PE = INICIO;

  while (PE) {
    if (PE->getINIP() == NULL) {
      PE = PE->getSIG();
      continue;
    } else {

      P = PE->getINIP();

      while (P) {
        if (P->getNombre() == perrito) {
          cout << "\t\tSe encontro el perrito buscado, sus datos son:\n"
               << "\t\tNombre: " << P->getNombre() << "\n"
               << "\t\tEdad: " << P->getEdad() << endl;

          flag = 1;
          return;
        }

        P = P->getSIG();
      }
    }

    PE = PE->getSIG();
  }

  if (flag == 0)
    cout << "\t\tNo se encontro al perro que se estaba buscando en ninguna perrera." << endl;

  return;
}
