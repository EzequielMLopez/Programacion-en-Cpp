#include "Clases.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// ========== PERROS CONSTRUCTOR ========== //
PERROS::PERROS(const string& nomine) {
  edad = 0;
  SIG = nullptr;
  nombre = nomine;
  apuntado = false;
};

// ========== PERROS SETTERS AND GETTERS ========== //

void PERROS::setNombre(const string& nomine) { nombre = nomine; }
string PERROS::getNombre() const { return nombre; }

void PERROS::setEdad(int ed) { edad = ed; }
int PERROS::getEdad() const { return edad; }

void PERROS::setApuntado(bool v) { apuntado = v; }
bool PERROS::getApuntado() const { return apuntado; }

void PERROS::setSIG(PERROS* p) { SIG = p; }
PERROS* PERROS::getSIG() const { return SIG; }

// ========== PERROS DESTRUCTOR ========== //
PERROS::~PERROS() { cout << "Estamos eliminando a " << nombre << endl; };

// ========== PERRERAS CONSTRUCTOR ========== //
PERRERA::PERRERA(const string& name) {
  altura = 0;
  INIP = nullptr;
  SIG = nullptr;
  nombre = name;
};

// ========== PERRERAS GETTERS AND SETTERS ========== //

void PERRERA::setNombre(const string& nomine) { nombre = nomine; }
string PERRERA::getNombre() const { return nombre; }

void PERRERA::setPais(const string& pai) { pais = pai; }
string PERRERA::getPais() const { return pais; }

void PERRERA::setProvincia(const string& provinci) { provincia = provinci; }
string PERRERA::getProvincia() const { return provincia; }

void PERRERA::setPartido(const string& partid) { partido = partid; }
string PERRERA::getPartido() const { return partido; }

void PERRERA::setLocalidad(const string& localida) { localidad = localida; }
string PERRERA::getLocalidad() const { return localidad; }

void PERRERA::setDireccion(const string& direccio) { direccion = direccio; }
string PERRERA::getDireccion() const { return direccion; }

void PERRERA::setAltura(int alt) { altura = alt; }
int PERRERA::getAltura() const { return altura; }

void PERRERA::setINIP(PERROS* p) { INIP = p; };
PERROS* PERRERA::getINIP() const { return INIP; }

void PERRERA::setSIG(PERRERA* pe) { SIG = pe; }
PERRERA* PERRERA::getSIG() const { return SIG; }

// ========== PERRERAS DESTRUCTOR ========== //
PERRERA::~PERRERA() {
  PERROS *P, *AUX;

  P = INIP;

  cout << "Eliminando perrera '" << nombre << "' hasta hacerla persistente :/" << endl;

  while (P) {
    AUX = P;
    P = P->getSIG();
    delete AUX;
  }
};

// ========== SUCURSAL ========== //
SUCURSAL::SUCURSAL() { INICIO = nullptr; };

SUCURSAL::~SUCURSAL() {
  PERRERA *PE, *AUX;

  if (INICIO == nullptr) {
    return;
  }

  PE = INICIO;

  while (PE) {
    AUX = PE;
    PE = PE->getSIG();
    delete AUX;
  }
}

// ========== METODOS PRIVADOS DE SUCURSAL ========== //
void SUCURSAL::REORDENAR(PERRERA* PE, vector<PERROS*>& PERRITOS, int posicion) {
  PERROS *P, *AUX, *ANTERIOR;
  int i = 0, j = 0;

  AUX = nullptr;
  ANTERIOR = nullptr;
  P = PE->getINIP();

  while (P) {
    // Ver si este PERRO está en la lista de seleccionados
    bool seleccionado = false;

    for (i = 0; i < posicion; i++) {
      if (P == PERRITOS[i]) {
        seleccionado = true;
        PERRITOS[i]->setApuntado(seleccionado);
        break;
      }
    }

    if (seleccionado) {
      // Sacarlo de la lista
      if (ANTERIOR == nullptr) {
        // Si el primero de la lista coincide con el del array.
        PE->setINIP(P->getSIG());
      } else {
        ANTERIOR->setSIG(P->getSIG());
      }

      AUX = P;
      P = P->getSIG();

      // Cortar puntero SIG para que quede “limpio”
      AUX->setSIG(nullptr);
    } else {
      // Al menos dio una primera vuelta.
      ANTERIOR = P;
      P = P->getSIG();
    }
  }

  // Desengancho a los Perritos del array de la lista original.
  for (j = 0; j < posicion; j++) {
    PERRITOS[j]->setSIG(nullptr);
  }
}

int SUCURSAL::TOTAL_PERRITOS(const string& perre) {
  PERRERA* PE;
  PERROS* P;
  int perritos = 0, flag = 0;

  PE = INICIO;

  while (PE) {
    if (PE->getNombre() == perre) {
      if (PE->getINIP() == nullptr) {
        cout << "\t\tNo hay perritos ingresados en la perrera como para seleccionar.\n"
             << "\t\tSe lo devuelve al menu principal." << endl;
        return 1;
      }

      P = PE->getINIP();

      while (P) {
        perritos += 1;
        P = P->getSIG();
      }

      flag = 1;

      return perritos;
    }

    PE = PE->getSIG();
  }

  if (flag == 0) {
    cout << "\tNo se encontro la perrera especificada." << endl;
  }

  return 1;
};
