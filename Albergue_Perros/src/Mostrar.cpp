#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

using namespace std;

void SUCURSAL::MOSTRAR_PERRERAS() {
  PERRERA* P;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perreras ingresadas, favor de crear al menos una, "
            "gracias."
         << endl;
    return;
  }
  P = INICIO;

  while (P) {
    cout << "\t\t" << P->nombre << " - " << P->provincia << " - " << P->partido << " - " << P->direccion << " " << P->altura << endl;
    P = P->SIG;
  }

  return;
}

void SUCURSAL::MOSTRAR_PERRITOS(char* perr) {
  PERRERA* P;
  PERROS* PE;
  int flag1 = 0;

  if (INICIO == NULL) {
    cout << "\tNo existen perreras actualmente, favor de crear alguna con la "
            "opcion 1 del menu del programa"
         << endl;
    return;
  }

  P = INICIO;

  while (P) {
    if (!strcmp(P->nombre, perr)) {
      if (P->INIP == NULL) {
        cout << "\tEn esta perrera no hay perritos ingresados, favor de "
                "ingresar uno con la opcion 2 del menu del programa"
             << endl;
        return;
      }

      PE = P->INIP;

      while (PE) {
        cout << "\t\tNombre: " << PE->nombre << " - Edad: " << PE->edad << endl;
        PE = PE->SIG;
      }

      flag1 = 1;
      return;
    }

    P = P->SIG;
  }

  if (flag1 == 0) {
    cout << "\t\tNo se encontro la perrera buscada." << endl;
  }

  return;
}
