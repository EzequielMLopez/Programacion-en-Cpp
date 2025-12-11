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

  if (INICIO->getNombre() == perre) {
    AUX = INICIO;
    INICIO = INICIO->getSIG();
    delete AUX;
    return;
  }

  PE = INICIO;
  AUX = nullptr;

  while (PE) {
    if (PE->getNombre() == perre) {
      AUX->setSIG(PE->getSIG());
      PE->setSIG(NULL);
      delete PE;
      flag = 1;
    }

    AUX = PE;

    PE = PE->getSIG();
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
    PE = PE->getSIG();
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
  int i = 1, cant_perritos = 0, flag = 0;

  cout << "\t\tEn funcion de la siguiente lista:" << endl;
  MOSTRAR_PERRERAS();
  cout << "\t\tColoque el nombre de la perrera donde esta el perrito a eliminar: ";
  getline(cin, perrera);

  PE = INICIO;

  while (PE) {
    if (PE->getNombre() == perrera) {
      if (PE->getINIP() == NULL) {
        cout << "\t\tNo hay ningun perro para eliminar.";
        return;
      }

      P = PE->getINIP();

      while (P) {
        P = P->getSIG();
        cant_perritos += 1;
      }

      P = PE->getINIP();

      do {
        do {
          cout << "\t\t" << i << " es " << P->getNombre() << " desea eliminarlo S(Si) N(No): ";
          cin >> choice;
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
        } while (choice != 'S' && choice != 'N');

        if (P == PE->getINIP() && choice == 'S') {
          PE->setINIP(P->getSIG());
          P->setSIG(NULL);
          delete P;
          P = PE->getINIP();
          ANT = nullptr;
        } else if (P != PE->getINIP() && choice == 'S') {
          ANT->setSIG(P->getSIG());
          P->setSIG(NULL);
          delete P;
          P = ANT->getSIG();
        } else if (choice == 'N') {
          ANT = P;
          i += 1;
          P = P->getSIG();
        }

      } while (P && i < cant_perritos + 1);

      flag = 1;
      break;
    }

    PE = PE->getSIG();
  }

  if (flag == 0)
    cout << "\t\tLa perrera ingresada no existe. Se lo retorna al Menu Principal." << endl;

  return;
}
