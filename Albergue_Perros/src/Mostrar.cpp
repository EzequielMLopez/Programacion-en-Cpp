#include "Clases.h"
#include <cstddef>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
/*
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
    cout << "\t\t" << PE->getNombre() << " - " << PE->getProvincia() << " - " << PE->getPartido() << " - " << PE->getDireccion() << " "
         << PE->getAltura() << endl;
    PE = PE->getSIG();
  }

  return;
}
*/

/*
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
    if (PE->getNombre() == perr) {
      if (PE->getINIP() == NULL) {
        cout << "\tEn esta perrera no hay perritos ingresados, favor de "
                "ingresar uno con la opcion 2 del menu del programa"
             << endl;
        flag1 = 1;
        return;
      }

      P = PE->getINIP();

      while (P) {
        cout << "\t\tNombre: " << P->getNombre() << " - Edad: " << P->getEdad() << endl;
        P = P->getSIG();
      }

      flag1 = 1;
      return;
    }

    PE = PE->getSIG();
  }

  if (flag1 == 0) {
    cout << "\t\tNo se encontro la perrera buscada." << endl;
  }

  return;
}
 */

std::vector<std::string> SUCURSAL::OBTENER_NOMBRES_PERRERAS_GUI() const {
  std::vector<std::string> nombres;
  PERRERA* PE = INICIO;

  while (PE) {
    std::string detalle = PE->getNombre();
    nombres.push_back(detalle);
    PE = PE->getSIG();
  }

  return nombres;
}

std::vector<std::string> SUCURSAL::OBTENER_DETALLES_PERRERAS_GUI() const {
  std::vector<std::string> lista_detalles;
  PERRERA* PE = nullptr;

  if (INICIO == nullptr) {
    lista_detalles.push_back("No hay perreras ingresadas.");
    return lista_detalles;
  }

  PE = INICIO;

  while (PE) {
    std::string detalle = PE->getNombre() + " | " + PE->getPais() + " | " + PE->getProvincia() + " | " + PE->getPartido() + " | " +
                          PE->getLocalidad() + " | " + PE->getDireccion() + " | " + std::to_string(PE->getAltura());

    lista_detalles.push_back(detalle);
    PE = PE->getSIG();
  }

  return lista_detalles;
}

std::vector<std::string> SUCURSAL::OBTENER_DETALLES_PERRITOS_GUI(const std::string& perrera) const {
  std::vector<std::string> lista_detalles;
  PERRERA* PE = nullptr;
  PERROS* P = nullptr;
  int flag1 = 0;

  if (INICIO == nullptr) {
    lista_detalles.push_back("No existen perreras ingresadas.");
    return lista_detalles;
  }

  PE = INICIO;

  while (PE) {
    if (PE->getNombre() == perrera) {
      if (PE->getINIP() == NULL) {
        flag1 = 1;
        lista_detalles.push_back("Ingrese un perro dentro de la perrera deseada con la Opcion 2 del Menu Principal");
        return lista_detalles;
      }

      P = PE->getINIP();

      while (P) {
        std::string detalle_perri = "Nombre: " + P->getNombre() + " | " + "Edad: " + std::to_string(P->getEdad()) + " | ";
        lista_detalles.push_back(detalle_perri);
        P = P->getSIG();
      }

      flag1 = 1;
    }

    PE = PE->getSIG();
  }

  if (flag1 == 0) {
    lista_detalles.push_back("No se encontro la perrera buscada.");
    return lista_detalles;
  }

  return lista_detalles;
}
