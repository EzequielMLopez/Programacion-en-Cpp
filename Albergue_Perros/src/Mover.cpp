#include "Clases.h"
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

/* void SUCURSAL::MOVER_PERRITOS(int choi) {
  PERRERA *PE, *AUX;
  PERROS* P;
  int perreras = 0, cantidad = 0, i = 0, pos = 0, j = 0, flag = 0, k = 0, salir = 0, perritos = 0;
  char choice;
  string perrera_from, perrera_to;
  bool existe = false;

  if (INICIO == NULL) {
    cout << "\tNo existen perreras actualmente ingresadas, favor de crear al "
            "menos dos";
    return;
  }

  PE = INICIO;

  while (PE) {
    perreras += 1;

    if (perreras >= 2) {
      break;
    }

    PE = PE->getSIG();
  }

  if (perreras >= 2) {
    if (choi == 1) {
      PE = INICIO;

      cout << "\tEn funcion de la siguiente lista; ";
      MOSTRAR_PERRERAS();
      cout << "\tIngrese el nombre de la perrera desde la cual desea migrar a "
              "los perritos: ";
      getline(cin, perrera_from);
      perritos = TOTAL_PERRITOS(perrera_from);
      cout << "\t\tLa cantidad de perritos que tiene la perrera es " << perritos << "\n"
           << "\t\tingrese una cantidad menos o igual al total para movilizar> ";
      cin >> cantidad;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

      if (cantidad <= perritos && cantidad > 0) {
        vector<PERROS*> PER;
        PER.reserve(cantidad);

        PE = INICIO;

        while (PE) {
          if (PE->getNombre() == perrera_from) {
            existe = true;

            if (PE->getINIP() == NULL) {
              cout << "\t\tEn la perrera ingresada no existen perros ingresados, no "
                      "se puede migrar algo que no existe.";
              return;
            }

            P = PE->getINIP();

            while (P) {
              cout << "\t\tEl perrito actual es: " << P->getNombre() << " de edad " << P->getEdad() << endl;
              cout << "\t\tDesea mover este perrito? S(Si) N(No): ";
              cin >> choice;
              cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

              if (choice == 'S' && PER.size() < cantidad) {
                PER.push_back(P);
              }

              P = P->getSIG();
            }

            AUX = PE;
            break;
          }

          PE = PE->getSIG();
        }

        if (!existe) {
          cout << "\t\La perrera ingresada no existe. Regresando al Menu Principal." << endl;
          return;
        }

        REORDENAR(AUX, PER, cantidad);

        cout << "\t\tSegun la siguiente lista: " << endl;
        MOSTRAR_PERRERAS();
        cout << "\t\tCual es la perrera de destino?: ";
        getline(cin, perrera_to);

        PE = INICIO;

        while (PE) {
          if (PE->getNombre() == perrera_to) {
            P = PE->getINIP();

            k = 0;

            // Si la perrera esta vacia ingresa al if y agrega a todos los perritos
            if (!P) {
              do {
                if (PER[k]->getApuntado()) {
                  PE->setINIP(PER[k]);
                  P = PER[k];
                  salir = 1;
                } else {
                  k++;
                }
              } while (salir != 1 && k < cantidad);

              if (k == cantidad) {
                cout << "\t\tNo se selecciono ningun perro para mover a otra perrera. Se lo devuelve al menu principal." << endl;
                return;
              }

              for (j = k; j < cantidad; j++) {
                if (PER[j]->getApuntado()) {
                  P->setSIG(PER[j]);
                  P = P->getSIG();
                } else {
                  continue;
                }
              }

              // Setea al ultimo perrito de la lista como un puntero a nulo.
              if (P) {
                P->setSIG(nullptr);
              }

            } else { // Si la perrera ya tiene perritos, va al fondo y los empieza a insertar
              while (P->getSIG()) {
                P = P->getSIG();
              }

              for (i = 0; i < cantidad; i++) {
                if (PER[i]->getApuntado()) {
                  P->setSIG(PER[i]);
                  P = P->getSIG();
                } else
                  continue;
              }
            }

            // Setea al ultimo perrito de la lista como un puntero a nulo.
            if (P) {
              P->setSIG(nullptr);
            }

            break;
          }
          PE = PE->getSIG();
        }
      }

    } else if (choi == 2) {
      cout << "\t\tEn funcion de la siguiente lista de perreras:" << endl;
      MOSTRAR_PERRERAS();
      cout << "\t\tIngrese el nombre de la perrera desde la que desea migrar a los "
              "perritos: ";
      getline(cin, perrera_from);

      PE = INICIO;
      perritos = TOTAL_PERRITOS(perrera_from);

      while (PE) {
        if (PE->getNombre() == perrera_from) {
          AUX = PE;
          P = PE->getINIP();

          cantidad = 0;

          while (P) {
            cantidad += 1;
            P = P->getSIG();
          }

          flag = 1;
          break;
        }

        PE = PE->getSIG();
      }

      if (flag == 0) {
        cout << "\tNo se a encontrado la perrera pertinente, se lo devuelve al "
                "menu principal."
             << endl;
        return;
      }

      vector<PERROS*> PER;
      PER.reserve(cantidad);
      P = AUX->getINIP();

      i = 0;

      while (P) {
        PER.push_back(P);
        P = P->getSIG();
      }

      REORDENAR(AUX, PER, cantidad);

      cout << "\tSegun la lista de perreras previamente mostrada, Ingrese la "
              "perrera de destino: ";
      getline(cin, perrera_to);

      PE = INICIO;

      while (PE) {
        if (PE->getNombre() == perrera_to) {
          P = PE->getINIP();

          // Si la perrera esta vacia ingresa al if y agrega a todos los perritos
          if (!P) {
            if (PER[0]->getApuntado()) {
              PE->setINIP(PER[0]);
              P = PER[0];
            } else {
              cout << "\t\tNo hay perros para colocar en la perrera de destino, la proxima vez piense lo que hace.";
              return;
            }

            for (j = 1; j < cantidad; j++) {
              if (PER[j]->getApuntado()) {
                P->setSIG(PER[j]);
                P = P->getSIG();
              } else
                continue;
            }

            // Setea al ultimo perrito de la lista como un puntero a nulo.
            if (P) {
              P->setSIG(nullptr);
            }

          } else { // Si la perrera ya cuenta con perrito, entonces ingresa al else y agrega al final.
            while (P->getSIG()) {
              P = P->getSIG();
            }

            for (j = 0; j < cantidad; j++) {
              if (PER[j]->getApuntado()) {
                P->setSIG(PER[j]);
                P = P->getSIG();
              } else
                continue;
            }

            // Setea al ultimo perrito de la lista como un puntero a nulo.
            if (P) {
              P->setSIG(nullptr);
            }
          }

          break;
        }

        PE = PE->getSIG();
      }
    } else {
      cout << "\t\tEs imposible dado que en el actual escenario no hay por lo menos dos perreras creadas. Favor de crear al menos dos\n"
           << "y agregar perritos en cada una." << endl;
    }
  }
  return;
} */

std::string SUCURSAL::MOVER_PERRITO_GUI(const string& perrera_orig, const string& perrera_dest, const string& perrito) {
  PERRERA* PE = INICIO;
  PERROS *P = nullptr, *AUX = nullptr, *AUX2 = nullptr;
  int flag = 0;

  while (PE) {
    if (PE->getNombre() == perrera_orig) {
      AUX = PE->getINIP();

      // En caso de que sea el primero el perrito el seleccionado
      if (AUX->getNombre() == perrito) {
        PE->setINIP(AUX->getSIG());
        AUX->setSIG(nullptr);
        break;
      }

      AUX2 = PE->getINIP();
      AUX = AUX->getSIG();

      // En caso de que no sea el primer perrito el seleccionado
      while (AUX) {
        if (AUX->getNombre() == perrito) {
          AUX2->setSIG(AUX->getSIG());
          AUX->setSIG(nullptr);
          flag = 1;
          break;
        };

        AUX2 = AUX;
        AUX = AUX->getSIG();
      }

      if (flag == 1)
        break;
    }

    PE = PE->getSIG();
  }

  PE = INICIO;
  while (PE) {
    if (PE->getNombre() == perrera_dest) {
      if (PE->getINIP() != NULL) {
        P = PE->getINIP();

        while (P->getSIG()) {
          P = P->getSIG();
        }

        P->setSIG(AUX);
        return "Operacion de Movilidad Exitosa!";
      } else {
        PE->setINIP(AUX);
        return "Operacion de Movilidad Exitosa!";
      }
    }

    PE = PE->getSIG();
  }

  return "Operacion de Movilidad Exitosa!";
}

std::string SUCURSAL::MOVER_TODOS_PERRITOS_GUI(const string& perrera_orig, const string& perrera_dest) {
  PERRERA *Perrera_Origen = nullptr, *Perrera_Destino = nullptr, *AUX = INICIO;
  PERROS* Perro_Destino = nullptr;

  while (AUX) {
    if (AUX->getNombre() == perrera_orig)
      Perrera_Origen = AUX;
    if (AUX->getNombre() == perrera_dest)
      Perrera_Destino = AUX;

    AUX = AUX->getSIG();
  }

  // Verificamos que ambas existan y que la origen tenga perritos para mover
  if (!Perrera_Origen || !Perrera_Destino) {
    return "Error: No se encontró la perrera de origen o destino.";
  }

  if (Perrera_Origen->getINIP() == nullptr) {
    return "La perrera de origen está vacía, no hay perritos para mover.";
  }

  // En caso de que la perrera de destino no tenga Perros cargados
  if (Perrera_Destino->getINIP() == nullptr) {
    Perrera_Destino->setINIP(Perrera_Origen->getINIP());
  } else {
    Perro_Destino = Perrera_Destino->getINIP();
    while (Perro_Destino->getSIG()) {
      Perro_Destino = Perro_Destino->getSIG();
    }

    Perro_Destino->setSIG(Perrera_Origen->getINIP());
  }

  Perrera_Origen->setINIP(nullptr);

  return "Operacion de Movilidad Total Completada Exitosamente!";
}
