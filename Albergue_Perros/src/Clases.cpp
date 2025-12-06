#include "Clases.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// ========== PERROS ========== //
PERROS::PERROS(const string& nomine) {
  edad = 0;
  SIG = NULL;
  nombre = nomine;
};

PERROS::~PERROS() { cout << "Estamos eliminando a " << nombre << endl; };

// ========== PERRERAS ========== //
PERRERA::PERRERA(const string& name) {
  altura = 0;
  INIP = NULL;
  SIG = NULL;
  nombre = name;
};

PERRERA::~PERRERA() {
  PERROS *P, *AUX;

  P = INIP;

  cout << "Eliminando perrera '" << nombre << "' hasta hacerla persistente :/" << endl;

  while (P) {
    AUX = P;
    P = P->SIG;
    delete AUX;
  }
};

// ========== SUCURSAL ========== //
SUCURSAL::SUCURSAL() { INICIO = NULL; };

SUCURSAL::~SUCURSAL() {
  PERRERA *P, *AUX;

  if (INICIO == NULL) {
    return;
  }

  P = INICIO;

  while (P) {
    AUX = P;
    P = P->SIG;
    delete AUX;
  }
}

// ========== METODOS PRIVADOS DE SUCURSAL ========== //
void SUCURSAL::REORDENAR(PERRERA* PE, vector<PERROS*>& PERRITOS, int posicion) {
  PERROS *P, *AUX, *ANTERIOR;
  int i = 0, j = 0;

  AUX = NULL;
  ANTERIOR = NULL;
  P = PE->INIP;

  while (P) {
    // Ver si este PERRO está en la lista de seleccionados
    bool seleccionado = false;

    for (i = 0; i < posicion; i++) {
      if (P == PERRITOS[i]) {
        seleccionado = true;
        PERRITOS[i]->apuntado = 1;
        break;
      }
    }

    if (seleccionado) {
      // Sacarlo de la lista
      if (ANTERIOR == NULL) {
        // Si el primero de la lista coincide con el del array.
        PE->INIP = P->SIG;
      } else {
        ANTERIOR->SIG = P->SIG;
      }

      AUX = P;
      P = P->SIG;

      // Cortar puntero SIG para que quede “limpio”
      AUX->SIG = NULL;
    } else {
      // Al menos dio una primera vuelta.
      ANTERIOR = P;
      P = P->SIG;
    }
  }

  // Desengancho a los Perritos del array de la lista original.
  for (j = 0; j < posicion; j++) {
    PERRITOS[j]->SIG = NULL;
  }
}

int SUCURSAL::TOTAL_PERRITOS(const string& perre) {
  PERRERA* PE;
  PERROS* P;
  int perritos = 0, flag = 0;

  PE = INICIO;

  while (PE) {
    if (PE->nombre == perre) {
      if (PE->INIP == NULL) {
        cout << "\t\tNo hay perritos ingresados en la perrera como para seleccionar.\n"
             << "\t\tSe lo devuelve al menu principal." << endl;
        return 1;
      }

      P = PE->INIP;

      while (P) {
        perritos += 1;
        P = P->SIG;
      }

      flag = 1;

      return perritos;
    }

    PE = PE->SIG;
  }

  if (flag == 0) {
    cout << "\tNo se encontro la perrera especificada." << endl;
  }

  return 1;
};
