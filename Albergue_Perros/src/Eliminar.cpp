#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

void SUCURSAL::ELIMINAR_PERRERA(const string& perre) {
  PERRERA *PE, *AUX;
  int flag = 0;

  if (INICIO == NULL) {
    cout << "\tNo existe perrera alguna en la base de datos actual, favor de "
            "antes de querer eliminar tener una creada almenos."
         << endl;
    return;
  }

  if (INICIO->nombre == perre) {
    AUX = INICIO;
    INICIO = INICIO->SIG;
    delete AUX;
    return;
  }

  PE = INICIO;

  while (PE) {
    if (PE->nombre == perre) {
      AUX->SIG = PE->SIG;
      PE->SIG = NULL;
      delete PE;
      flag = 1;
      return;
    } else {
    }

    AUX = PE;

    PE = PE->SIG;
  }

  if (flag == 0) {
    cout << "\tNo se hallo la perrera especificada, favor de revisar si el "
            "nombre de la misma esta escrito correctamente."
         << endl;
  }

  return;
}

void SUCURSAL::ELIMINAR_PERRERA() {
  PERRERA *PE, *AUX;

  if (INICIO == NULL) {
    cout << "\tNo existe perrera alguna en la base de datos actual, favor de "
            "antes de querer eliminar tener una creada almenos."
         << endl;
  }

  PE = INICIO;

  while (PE) {
    AUX = PE;
    PE = PE->SIG;
    delete AUX;
    AUX = NULL;
  }

  INICIO = NULL;

  return;
}

void SUCURSAL::ELIMINAR_PERRITO() {
  PERRERA* PE;
  PERROS *P, *ANT;
  char choice;
  string perrera;
  int i = 1, cant_perritos = 0;

  cout << "\t\tEn funcion de la siguiente lista:" << endl;
  MOSTRAR_PERRERAS();
  cout << "\t\tColoque el nombre de la perrera donde esta el perrito a eliminar: ";
  getline(cin, perrera);

  PE = INICIO;

  while (PE) {
    if (PE->nombre == perrera) {
      if (PE->INIP == NULL) {
        cout << "\t\tNo hay ningun perro para eliminar.";
        return;
      }

      P = PE->INIP;

      while (P) {
        P = P->SIG;
        cant_perritos += 1;
      }

      P = PE->INIP;

      do {
        do {
          cout << "\t\t" << i << " es " << P->nombre << " desea eliminarlo S(Si) N(No): ";
          cin >> choice;
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
        } while (choice != 'S' && choice != 'N');

        if (P == PE->INIP && choice == 'S') {
          PE->INIP = P->SIG;
          P->SIG = NULL;
          delete P;
          P = PE->INIP;
        } else if (P != PE->INIP && choice == 'S') {
          ANT->SIG = P->SIG;
          P->SIG = NULL;
          delete P;
          P = ANT->SIG;
        } else if (choice == 'N') {
          ANT = P;
          i += 1;
          P = P->SIG;
        }

      } while (P && i < cant_perritos + 1);

      break;
    }

    PE = PE->SIG;
  }

  return;
}
