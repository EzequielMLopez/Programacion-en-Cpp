#include "Clases.h"
#include <cstdint>
#include <vector>

std::vector<std::string> SUCURSAL::OBTENER_NOMBRES_PERRERAS_GUI() const {
  std::vector<std::string> nombres;
  PERRERA* PE = INICIO;

  while (PE) {
    nombres.push_back(PE->getNombre());
    PE = PE->getSIG();
  }

  return nombres;
}

std::vector<std::string> SUCURSAL::OBTENER_DETALLES_PERRERA_GUI(const std::string& perrera_buscada) const {
  std::vector<std::string> campos;
  PERRERA* PE = INICIO;

  while (PE) {
    if (PE->getNombre() == perrera_buscada) {
      // Guardamos cada atributo en una posición independiente del vector
      campos.push_back(PE->getNombre());                 // [0]
      campos.push_back(PE->getPais());                   // [1]
      campos.push_back(PE->getProvincia());              // [2]
      campos.push_back(PE->getPartido());                // [3]
      campos.push_back(PE->getLocalidad());              // [4]
      campos.push_back(PE->getDireccion());              // [5]
      campos.push_back(std::to_string(PE->getAltura())); // [6]
      break;                                             // Encontramos la perrera, salimos del bucle
    }
    PE = PE->getSIG();
  }

  return campos;
}

std::vector<std::string> SUCURSAL::OBTENER_NOMBRES_PERRITOS_GUI(const std::string& perrera) const {
  std::vector<std::string> nombres_perritos;
  PERRERA* PE = INICIO;
  PERROS* P = nullptr;

  while (PE) {
    if (PE->getNombre() == perrera) {
      P = PE->getINIP();
      while (P) {
        nombres_perritos.push_back(P->getNombre());
        P = P->getSIG();
      }
      break;
    }

    PE = PE->getSIG();
  }

  return nombres_perritos;
}

std::vector<std::string> SUCURSAL::OBTENER_DETALLES_PERRITOS_GUI(const std::string& perrera, const std::string& perrito) const {
  std::vector<std::string> campos;
  PERRERA* PE = INICIO;
  PERROS* P = nullptr;

  while (PE) {
    if (PE->getNombre() == perrera) {
      P = PE->getINIP();
      while (P) {
        if (P->getNombre() == perrito) {
          campos.push_back(P->getNombre());
          campos.push_back(std::to_string(P->getEdad()));
        }
        P = P->getSIG();
      }
    }
    PE = PE->getSIG();
  }

  return campos;
}
