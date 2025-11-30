#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

using namespace std;

void SUCURSAL::MOVER_PERRITOS(int choi) {
  PERRERA *PE, *AUX;
  PERROS* P;
  int perreras = 0, cantidad = 0, i = 0, pos = 0, j = 0, flag = 0, k = 0, salir = 0;
  char perrera_from[20], perrera_to[20], choice, perritos;

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

    PE = PE->SIG;
  }

  if (perreras >= 2) {
    if (choi == 1) {
      PE = INICIO;

      cout << "\tEn funcion de la siguiente lista; ";
      MOSTRAR_PERRERAS();
      cout << "\tIngrese el nombre de la perrera desde la cual desea migrar a "
              "los perritos: ";
      cin.getline(perrera_from, 20);
      perritos = TOTAL_PERRITOS(perrera_from);
      cout << "\t\tLa cantidad de perritos que tiene la perrera es " << perritos << "\n"
           << "\t\tingrese una cantidad menos o igual al total para movilizar> ";
      cin >> cantidad;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

      if (cantidad <= perritos and cantidad > 0) {
        PERROS* PER[cantidad];

        PE = INICIO;

        while (PE) {
          if (!strcmp(perrera_from, PE->nombre)) {
            if (PE->INIP == NULL) {
              cout << "\t\tEn la perrera ingresada no existen perros ingresados, no "
                      "se puede migrar algo que no existe.";
              return;
            }

            P = PE->INIP;

            while (P) {
              cout << "\t\tEl perrito actual es: " << P->nombre << " de edad " << P->edad << endl;
              cout << "\t\tDesea mover este perrito? S(Si) N(No): ";
              cin >> choice;
              cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

              if (choice == 'S' and pos < cantidad) {
                PER[pos] = P;
                pos += 1;
              }

              P = P->SIG;
            }

            AUX = PE;

            break;
          }

          PE = PE->SIG;
        }

        REORDENAR(AUX, PER, cantidad);

        cout << "\t\tSegun la siguiente lista: " << endl;
        MOSTRAR_PERRERAS();
        cout << "\t\tCual es la perrera de destino?: ";
        cin.getline(perrera_to, 20);

        PE = INICIO;

        while (PE) {
          if (!strcmp(PE->nombre, perrera_to)) {
            P = PE->INIP;

            // Si la perrera esta vacia ingresa al if y agrega a todos los perritos
            if (!P) {
              do {
                if (PER[k]->apuntado == 1) {
                  PE->INIP = PER[k];
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
                if (PER[j]->apuntado == 1) {
                  P->SIG = PER[j];
                  P = P->SIG;
                } else if (PER[j]->apuntado == 0) {
                  continue;
                }
              }

            } else {
              while (P->SIG) {
                P = P->SIG;
              }

              for (i = 0; i < cantidad; i++) {
                if (PER[i]->apuntado == 1) {
                  P->SIG = PER[i];
                  P = P->SIG;
                } else if (PER[i]->apuntado == 0) {
                  continue;
                }
              }
            }

            break;
          }

          PE = PE->SIG;
        }

      } else {
        cout << "\t\tLa cantidad escogida no es un valor valido. Se lo devuelve al menu principal." << endl;
        return;
      }

    } else if (choi == 2) {
      cout << "\t\tEn funcion de la siguiente lista de perreras:" << endl;
      MOSTRAR_PERRERAS();
      cout << "\t\tIngrese el nombre de la perrera desde la que desea migrar a los "
              "perritos: ";
      cin.getline(perrera_from, 20);

      PE = INICIO;
      perritos = TOTAL_PERRITOS(perrera_from);

      while (PE) {
        if (!strcmp(PE->nombre, perrera_from)) {
          AUX = PE;
          P = PE->INIP;

          cantidad = 0;

          while (P) {
            cantidad += 1;
            P = P->SIG;
          }

          flag = 0;
          break;
        }

        flag = 1;
        PE = PE->SIG;
      }

      if (flag == 1) {
        cout << "\tNo se a encontrado la perrera pertinente, se lo devuelve al "
                "menu principal."
             << endl;
        return;
      }

      PERROS* PER[cantidad];
      P = AUX->INIP;

      i = 0;

      while (P) {
        PER[i] = P;
        i += 1;
        P = P->SIG;
      }

      REORDENAR(AUX, PER, cantidad);

      cout << "\tSegun la lista de perreras previamente mostrada, Ingrese la "
              "perrera de destino: ";
      cin.getline(perrera_to, 20);

      PE = INICIO;

      while (PE) {
        if (!strcmp(PE->nombre, perrera_to)) {
          P = PE->INIP;

          // Si la perrera esta vacia ingresa al if y agrega a todos los perritos
          if (!P) {
            if (PER[0]->apuntado == 1) {
              PE->INIP = PER[0];
              P = PER[0];
            } else {
              cout << "\t\tNo hay perros para colocar en la perrera de destino, la proxima vez piense lo que hace.";
              return;
            }

            for (j = 1; j < cantidad; j++) {
              if (PER[j]->apuntado == 1) {
                P->SIG = PER[j];
                P = P->SIG;
              } else {
                continue;
              }
            }
          } else { // Si la perrera ya cuenta con perrito, entonces ingresa al else y agrega al final.
            while (P->SIG) {
              P = P->SIG;
            }

            for (j = 0; j < cantidad; j++) {
              if (PER[j]->apuntado == 1) {
                P->SIG = PER[j];
                P = P->SIG;
              } else {
                continue;
              }
            }
          }

          break;
        }

        PE = PE->SIG;
      }
    }
  } else {
    cout << "\t\tEs imposible dado que en el actual escenario no hay por lo menos dos perreras creadas. Favor de crear al menos dos\n"
         << "y agregar perritos en cada una." << endl;
  }

  return;
}
