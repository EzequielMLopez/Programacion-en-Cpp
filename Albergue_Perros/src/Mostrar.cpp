#include "Clases.h"

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

std::vector<std::string> SUCURSAL::MOSTRAR_DETALLES_PERRERAS_GUI() const {
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

std::vector<std::string> SUCURSAL::MOSTRAR_DETALLES_PERRITOS_GUI(const std::string& perrera) const {
  std::vector<std::string> detalles_perritos;
  PERRERA* PE = INICIO;

  while (PE) {
    if (PE->getNombre() == perrera) {
      // Obtenemos la lista de perritos de la perrera encontrada
      std::vector<PERROS> perritos = PE->getPerritos();

      for (const auto& perrito : perritos) {
        std::string detalle_perrito = "Nombre: " + perrito.getNombre() + " | " + "Edad: " + std::to_string(perrito.getEdad()) + " años";
        // Guardamos cada atributo del perrito en una posición independiente del vector
        detalles_perritos.push_back(detalle_perrito);
      }
      break; // Encontramos la perrera, salimos del bucle
    }
    PE = PE->getSIG();
  }

  return detalles_perritos;
}
