#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class PERROS {
public:
  char nombre[20];
  int edad, apuntado = 0;
  PERROS* SIG;
  PERROS(char*);
  ~PERROS();
};

PERROS::PERROS(char* nomine) {
  edad = 0;
  SIG = NULL;
  strcpy(nombre, nomine);
};

PERROS::~PERROS() { cout << "Estamos eliminando a " << nombre << endl; };

class PERRERA {
public:
  char nombre[20], pais[20], provincia[20], partido[20], localidad[20], direccion[40];
  int altura;
  PERROS* INIP;
  PERRERA* SIG;
  PERRERA(char*);
  ~PERRERA();
};

PERRERA::PERRERA(char* name) {
  altura = 0;
  INIP = NULL;
  SIG = NULL;
  strcpy(nombre, name);
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

class SUCURSAL {
private:
  PERRERA* INICIO;
  void REORDENAR(PERRERA*, PERROS**, int);
  int TOTAL_PERRITOS(char*);

public:
  SUCURSAL();
  ~SUCURSAL();
  void AGREGAR_PERRERA(char*);
  void AGREGAR_PERRITO(char*);
  void MOSTRAR_PERRERAS();
  void MOSTRAR_PERRITOS(char*);
  void ELIMINAR_PERRERA(char*); // Se elimina una unica perrera
  void ELIMINAR_PERRERA();      // Sobre carga para eliminar a todas las perreras
  void MOVER_PERRITOS(int);
  void BUSCAR_PERRITO(char*);
  void BUSCAR_PERRITO();
  void ELIMINAR_PERRITO();
  void MODIFICAR_PERRITO();
};

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

void SUCURSAL::REORDENAR(PERRERA* PE, PERROS** PERRITOS, int posicion) {
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

int SUCURSAL::TOTAL_PERRITOS(char* perre) {
  PERRERA* PE;
  PERROS* P;
  int perritos = 0, flag;

  PE = INICIO;

  while (PE) {
    if (!strcmp(PE->nombre, perre)) {
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

      return perritos;
    }

    flag = 2;
    PE = PE->SIG;
  }

  return flag;
};

void SUCURSAL::AGREGAR_PERRERA(char* nome) {
  PERRERA *PE, *nuevo;

  // Se crea una nueva perra y se solicita al usuario los datos pertinentes a la
  // misma.
  nuevo = new PERRERA(nome);

  cout << "\tPor favor, ingrese el pais donde se encuentra la perrera: ";
  cin.getline(nuevo->pais, 20);
  cout << "\tAhora la provincia: ";
  cin.getline(nuevo->provincia, 20);
  cout << "\tPartido: ";
  cin.getline(nuevo->partido, 20);
  cout << "\tLocalidad: ";
  cin.getline(nuevo->localidad, 20);
  cout << "\tDireccion: ";
  cin.getline(nuevo->direccion, 40);
  cout << "\tAltura: ";
  cin >> nuevo->altura;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Condicion en caso de que la lista de sucursales/perreras este vacia.
  if (INICIO == NULL) {
    INICIO = nuevo;
    return;
  }

  // Se inicializa el puntero
  PE = INICIO;

  // Se recorre la lista hasta la ultima posicion agregando la nueva perrera al
  // final.
  while (PE->SIG) {
    PE = PE->SIG;
  }

  PE->SIG = nuevo;

  return;
}

void SUCURSAL::AGREGAR_PERRITO(char* perre) {
  PERRERA* P;
  PERROS *PE, *nuevo;
  char perrito[20];
  int flag = 0;

  P = INICIO;

  while (P) {
    if (!strcmp(P->nombre, perre)) {
      PE = P->INIP;

      cout << "\tIngrese el nombre del nuevo integrante del grupo: ";
      cin.getline(perrito, 20);
      nuevo = new PERROS(perrito);
      cout << "\tCual es la edad del perrito/a: ";
      cin >> nuevo->edad;

      if (P->INIP == NULL) {
        P->INIP = nuevo;
        return;
      }

      while (PE->SIG) {
        PE = PE->SIG;
      }
      PE->SIG = nuevo;

      break;
    } else {
      flag = 1;
    }

    P = P->SIG;
  }

  if (flag == 1) {
    cout << "La perrera cuestion no se encuentra en nuestra Base de Datos, le "
            "pedimos que la cree para poder ingresar perritos en la misma."
         << endl;
  }

  return;
}

void SUCURSAL::MOSTRAR_PERRERAS() {
  PERRERA* P;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perreras ingresadas, favor de crear al menos una, "
            "gracias."
         << endl;
    return;
  }
  P = INICIO;

  while (P) {
    cout << "\t\t" << P->nombre << " - " << P->provincia << " - " << P->partido << " - " << P->direccion << " " << P->altura << endl;
    P = P->SIG;
  }

  return;
}

void SUCURSAL::MOSTRAR_PERRITOS(char* perr) {
  PERRERA* P;
  PERROS* PE;
  char perrera[20];
  int flag1 = 0;

  if (INICIO == NULL) {
    cout << "\tNo existen perreras actualmente, favor de crear alguna con la "
            "opcion 1 del menu del programa"
         << endl;
    return;
  }

  P = INICIO;

  while (P) {
    if (!strcmp(P->nombre, perr)) {
      if (P->INIP == NULL) {
        cout << "\tEn esta perrera no hay perritos ingresados, favor de "
                "ingresar uno con la opcion 2 del menu del programa"
             << endl;
        return;
      }

      PE = P->INIP;

      while (PE) {
        cout << "\t\tNombre: " << PE->nombre << " - Edad: " << PE->edad << endl;
        PE = PE->SIG;
      }

      flag1 = 1;
      return;
    }

    P = P->SIG;
  }

  if (flag1 == 0) {
    cout << "\t\tNo se encontro la perrera buscada." << endl;
  }

  return;
}

void SUCURSAL::ELIMINAR_PERRERA(char* perre) {
  PERRERA *P, *AUX;
  int flag = 0;

  if (INICIO == NULL) {
    cout << "\tNo existe perrera alguna en la base de datos actual, favor de "
            "antes de querer eliminar tener una creada almenos."
         << endl;
    return;
  }

  if (!strcmp(INICIO->nombre, perre)) {
    AUX = INICIO;
    INICIO = INICIO->SIG;
    delete AUX;
    return;
  }

  P = INICIO;

  while (P) {
    if (!strcmp(P->nombre, perre)) {
      AUX->SIG = P->SIG;
      P->SIG = NULL;
      delete P;
      return;
    } else {
      flag = 1;
    }

    AUX = P;

    P = P->SIG;
  }

  if (flag == 1) {
    cout << "\tNo se hallo la perrera especificada, favor de revisar si el "
            "nombre de la misma esta escrito correctamente."
         << endl;
  }

  return;
}

void SUCURSAL::ELIMINAR_PERRERA() {
  PERRERA *P, *AUX;

  if (INICIO == NULL) {
    cout << "\tNo existe perrera alguna en la base de datos actual, favor de "
            "antes de querer eliminar tener una creada almenos."
         << endl;
  }

  P = INICIO;

  while (P) {
    AUX = P;
    P = P->SIG;
    delete AUX;
    AUX = NULL;
  }

  INICIO = NULL;

  return;
}

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

void SUCURSAL::BUSCAR_PERRITO(char* perr) {
  PERRERA* PE;
  PERROS* P;
  char perrito[20];

  PE = INICIO;

  cout << "\t\tIngrese el nombre del perrito a buscar: ";
  cin.getline(perrito, 20);

  while (PE) {
    if (!strcmp(PE->nombre, perr)) {
      if (PE->INIP == NULL) {
        cout << "\t\tNo hay perritos dentro de esta perrera, favor de "
                "ingresar "
                "al menos uno con otra opcion del menu principal"
             << endl;
        return;
      }

      P = PE->INIP;

      while (P) {
        if (!strcmp(P->nombre, perrito)) {
          cout << "\t\tSe encontro el perrito buscado, sus datos son:\n"
               << "\t\tNombre: " << P->nombre << "\n"
               << "\t\tEdad: " << P->edad << endl;
          return;
        } else {
          cout << "\t\tNo se encontro al perrito que estaba buscando :(" << endl;
          return;
        }

        P = P->SIG;
      }
    }

    PE = PE->SIG;
  }
}

void SUCURSAL::BUSCAR_PERRITO() {
  PERRERA* PE;
  PERROS* P;
  char perrito[20];
  int flag = 0;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perreras ingresadas, favor de crear al menos una, "
            "gracias."
         << endl;
    return;
  }

  cout << "\t\tIngrese el nombre del perrito a buscar: ";
  cin.getline(perrito, 20);

  PE = INICIO;

  while (PE) {
    if (PE->INIP == NULL) {
      PE = PE->SIG;
      continue;
    } else {

      P = PE->INIP;

      while (P) {
        if (!strcmp(P->nombre, perrito)) {
          cout << "\t\tSe encontro el perrito buscado, sus datos son:\n"
               << "\t\tNombre: " << P->nombre << "\n"
               << "\t\tEdad: " << P->edad << endl;
          return;
        }

        P = P->SIG;
      }
    }

    flag = 1;
  }

  if (flag == 1)
    cout << "\t\tNo se encontro al perro que se estaba buscando en ninguna "
            "perrera."
         << endl;

  return;
}

void SUCURSAL::ELIMINAR_PERRITO() {
  PERRERA* PE;
  PERROS *P, *ANT;
  char perrera[20], choice;
  int i = 1, cant_perritos = 0;

  cout << "\t\tEn funcion de la siguiente lista:" << endl;
  MOSTRAR_PERRERAS();
  cout << "\t\tColoque el nombre de la perrera donde esta el perrito a eliminar: ";
  cin.getline(perrera, 20);

  PE = INICIO;

  while (PE) {
    if (!strcmp(PE->nombre, perrera)) {
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
        cout << "\t\t" << i << " es " << P->nombre << " desea eliminarlo S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

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
        } else {
          do {
            cout << "\t\tDebe elegir un valor valido S(Si) N(No): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
          } while (choice != 'S' && choice != 'N');
        }
      } while (P && i < cant_perritos + 1);

      break;
    }

    PE = PE->SIG;
  }
}

void SUCURSAL::MODIFICAR_PERRITO() {
  PERRERA* PE;
  PERROS* P;
  char perrera[20], perrito[20], choice;
  int flag1 = 0, flag2 = 0;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perrera ingresada donde buscar perrito alguno, favor de crear al menos una perrera con un perrito dentro." << endl;
    return;
  }

  cout << "\t\tSegun la siguiente lista de perreras:" << endl;
  MOSTRAR_PERRERAS();
  cout << "\t\tCual es la perrera donde se encuentra su perrito: ";
  cin.getline(perrera, 20);

  PE = INICIO;

  while (PE) {
    if (!strcmp(PE->nombre, perrera)) {
      if (PE->INIP == NULL) {
        cout << "\t\tLa perrera no cuenta con ningun perrito, favor de al menos ingresar uno." << endl;
        return;
      }

      cout << "\t\tSegun la siguiente lista de perritos ingresados:" << endl;
      MOSTRAR_PERRITOS(perrera);
      cout << "\t\tCual desea modificar: ";
      cin.getline(perrito, 20);

      P = PE->INIP;

      while (P) {
        if (!strcmp(P->nombre, perrito)) {
          do {
            cout << "\t\tDesea modificar el nombre? S(Si) N(No): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
          } while (choice != 'S' && choice != 'N');

          if (choice == 'S') {
            cout << "\t\tCual es el nuevo nombre para " << P->nombre << ": ";
            cin.getline(P->nombre, 20);
          }

          do {
            cout << "\t\tDesea modificar la edad? S(Si) N(No): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
          } while (choice != 'S' && choice != 'N');

          if (choice == 'S') {
            cout << "\t\tCual es la nueva edad para " << P->nombre << ": ";
            cin >> P->edad;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }

          flag2 = 1;
          break;
        }

        P = P->SIG;
      }

      if (flag2 == 0) {
        cout << "\t\tLa perrera se encontro pero no el perro correspondiente :(" << endl;
      }

      flag1 = 1;
      break;
    }

    PE = PE->SIG;
  }

  if (flag1 == 0) {
    cout << "\t\tNo se encontro la perrera pertinente." << endl;
  }

  return;
}

int main(int argc, char** argv, char** envp) {
  SUCURSAL S;
  int choice, choice1, cantidad, perritos;
  char perrera[20], perrera_elegida[20], know;

  cout << "Bienvenido al Albergue de Perros simulado" << endl;

  while (choice) {
    cout << "Para facilitar la gestion de este programa usted puede escoger "
            "entre las siguientes opciones:\n"
         << "1- Agregar una perrera nueva\n"
         << "2- Agregar perritos a una perrera ya existente\n"
         << "3- Mostrar Perreras\n"
         << "4- Mostrar Perritos de una Perrera determinada\n"
         << "5- Eliminar una perrera o todas las perreras (esto incluye la "
            "perdida de los datos de los "
            "perritos)\n"
         << "6- Mover los datos de algunos u todos los perritos a otra "
            "perrera\n"
         << "7- Buscar un perro especifigo en una perrera concreta o en "
            "todas\n"
         << "8- Eliminar un perrito de alguna perrera especifica\n"
         << "9- Modificar los datos de un perro\n"
         << "10- Modificar los datos de una perrera\n"
         << "0- Salir del programa\n"
         << "Ingrese la accion que desea realizar: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

    switch (choice) {
      case 1:
        cout << "\tEscoge un nombre para la nueva perrera: ";
        cin.getline(perrera, 20);
        S.AGREGAR_PERRERA(perrera);
        break;

      case 2:
        cout << "\tSabe el nombre de la perrera en donde desea ingresar al "
                "nuevo "
                "integrante S(Si) N(No): ";
        cin >> know;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (know == 'S') {
          cout << "\tColoca por favor el nombre de la perrera a donde esta "
                  "destinado el nuevo perrito/a: ";
          cin.getline(perrera, 20);
          S.AGREGAR_PERRITO(perrera);
        } else if (know == 'N') {
          cout << "\tEste es el listado de las perreras que actualmente tenemos "
                  "en nuestra base de datos:"
               << endl;
          S.MOSTRAR_PERRERAS();
          cout << "\tLa perrera deseada se encuentra entre una de ellas? S(Si) "
                  "N(No): ";
          cin >> know;
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

          if (know == 'S') {
            cout << "\tFavor de indicar el nombre de la misma: ";
            cin.getline(perrera_elegida, 20);
            S.AGREGAR_PERRITO(perrera_elegida);
          } else if (know == 'N') {
            cout << "\tSiendo que no conoce el nombre de la perrera ni tampoco "
                    "la "
                    "supo reconocer en el listado dado, le pedimos que cree la "
                    "Perrera para poder ingresar a los perritos"
                 << endl;
          } else {
            cout << "\tNo es un valor valido, se lo devuelve al menu principal.";
          }
        }
        break;

      case 3:
        cout << "\tLas perreras con las que contamos son:" << endl;
        S.MOSTRAR_PERRERAS();
        break;

      case 4:
        cout << "\t\tSegun la siguiente lista de perreras:" << endl;
        S.MOSTRAR_PERRERAS();
        cout << "\t\tEscriba el nombre de la perrera para mostrar sus perritos: ";
        cin.getline(perrera, 20);
        S.MOSTRAR_PERRITOS(perrera);
        break;

      case 5:
        cout << "\tDesea usted:\n"
             << "\t1- Eliminar una perrera determinada\n"
             << "\t2- Eliminar todas las perreras\n"
             << "\tAccion a realizar: ";
        cin >> choice1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (choice1 == 1) {
          cout << "\tFavor de ingresar el nombre de la Perrera: ";
          cin.getline(perrera, 20);
          S.ELIMINAR_PERRERA(perrera);
        } else if (choice1 == 2) {
          cout << "\tSe van a eliminar todas las perreras" << endl;
          S.ELIMINAR_PERRERA();
        } else {
          cout << "\tNo corresponde a ninguna opcion para elegir, se devuelve "
                  "al "
                  "menu principal"
               << endl;
        }
        break;

      case 6:
        cout << "\tQue desea hacer:\n"
             << "\t1- Mover algunos perros\n"
             << "\t2- Mover todos los perros de una perrera a otra\n"
             << "\tColoque la opcion deseada: ";
        cin >> choice1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (choice1 == 1) {
          S.MOVER_PERRITOS(choice1);
        } else if (choice1 == 2) {
          S.MOVER_PERRITOS(choice1);
        }
        break;

      case 7:
        cout << "\tEntre las siguientes opciones:\n"
             << "\t1- Buscar en una perrera concreta\n"
             << "\t2- Buscar en todas las perreras\n"
             << "\tCual busqueda prefiere: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (choice == 1) {
          cout << "\tEn funcion de la siguiente lista de perreras:" << endl;
          S.MOSTRAR_PERRERAS();
          cout << "\tIndique el nombre de la perrera en la que vamos a buscar "
                  "al perrito: ";
          cin.getline(perrera, 20);
          S.BUSCAR_PERRITO(perrera);
        } else if (choice == 2) {
          S.BUSCAR_PERRITO();
        } else {
          cout << "\tNo se indico ninguna de las opciones validas, se lo "
                  "devuelve al menu principal"
               << endl;
        }
        break;

      case 8: S.ELIMINAR_PERRITO(); break;

      case 9: S.MODIFICAR_PERRITO(); break;
    }
  }

  return 0;
}
