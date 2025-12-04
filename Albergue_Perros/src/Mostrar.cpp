#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

using namespace std;

void SUCURSAL::MOSTRAR_PERRERAS() {
  PERRERA* PE;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perreras ingresadas, favor de crear al menos una, "
            "gracias."
         << endl;
    return;
  }

  PE = INICIO;

  while (PE) {
    cout << "\t\t" << PE->nombre << " - " << PE->provincia << " - " << PE->partido << " - " << PE->direccion << " " << PE->altura << endl;
    PE = PE->SIG;
  }

  return;
}

void SUCURSAL::MOSTRAR_PERRITOS(const string& perr) {
  PERRERA* PE;
  PERROS* P;
  int flag1 = 0;

  if (INICIO == NULL) {
    cout << "\tNo existen perreras actualmente, favor de crear alguna con la "
            "opcion 1 del menu del programa"
         << endl;
    return;
  }

  PE = INICIO;

  while (PE) {
    if (PE->nombre == perr) {
      if (PE->INIP == NULL) {
        cout << "\tEn esta perrera no hay perritos ingresados, favor de "
                "ingresar uno con la opcion 2 del menu del programa"
             << endl;
        return;
      }

      P = PE->INIP;

      while (P) {
        cout << "\t\tNombre: " << P->nombre << " - Edad: " << P->edad << endl;
        P = P->SIG;
      }

      flag1 = 1;
      return;
    }

    PE = PE->SIG;
  }

  if (flag1 == 0) {
    cout << "\t\tNo se encontro la perrera buscada." << endl;
  }

  return;
}
