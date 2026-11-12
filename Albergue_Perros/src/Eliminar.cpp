#include "Clases.h"
#include "gtkmm/alertdialog.h"
#include "gtkmm/dialog.h"
#include "gtkmm/enums.h"
#include <cinttypes>
#include <functional>
#include <gtkmm.h>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

/* void SUCURSAL::ELIMINAR_PERRERA(const string& perre) {
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
*/

/* void SUCURSAL::ELIMINAR_PERRITO() {
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
} */

std::string SUCURSAL::ELIMINAR_PERRERA_GUI(const string& perrera) {
  PERRERA *PE = nullptr, *AUX = nullptr;
  int flag = 0;

  if (INICIO == NULL) {
    return "\tNo existe perrera alguna en la base de datos actual, favor de "
           "antes de querer eliminar tener una creada almenos.";
  }

  if (INICIO->getNombre() == perrera) {
    AUX = INICIO;
    INICIO = INICIO->getSIG();
    delete AUX;
    return "Operacion Exitosa!";
  }

  AUX = INICIO;
  PE = INICIO->getSIG();

  while (PE) {
    if (PE->getNombre() == perrera) {
      AUX->setSIG(PE->getSIG());
      PE->setSIG(nullptr);
      delete PE;
      flag = 1;
      break;
    }

    AUX = PE;
    PE = PE->getSIG();
  }

  if (flag == 0) {
    return "\tNo se hallo la perrera especificada, favor de revisar si el "
           "nombre de la misma esta escrito correctamente.";
  }

  return "Operacion Exitosa!";
}

std::string SUCURSAL::ELIMINAR_PERRITO_GUI(const string& perrera, const string& perrito) {
  PERRERA* PE = INICIO;
  PERROS *P = nullptr, *AUX = nullptr;
  int flag = 0;

  while (PE) {
    if (PE->getNombre() == perrera && PE->getINIP() != NULL) {
      P = PE->getINIP();

      // En caso de que sea el primero
      if (P->getNombre() == perrito) {
        PE->setINIP(P->getSIG());
        P->setSIG(nullptr);
        delete P;
        return "Operacion Exitosa!";
      }

      AUX = PE->getINIP();
      P = P->getSIG();

      while (P) {
        if (P->getNombre() == perrito) {
          AUX->setSIG(P->getSIG());
          P->setSIG(nullptr);
          delete P;
          flag = 1;
          return "Operacion Exitosa!";
        }
        P = P->getSIG();
      }
    }

    PE = PE->getSIG();
  }

  if (flag == 0) {
    return "\tNo se hallo el perrito especificado, favor de revisar si el "
           "nombre del/la mismo/a esta escrito correctamente.";
  }
}
