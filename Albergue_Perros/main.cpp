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
  int edad;
  PERROS *SIG;
  PERROS(char *);
  ~PERROS();
};

PERROS::PERROS(char *nomine) {
  edad = 0;
  SIG = NULL;
  strcpy(nombre, nomine);
};

PERROS::~PERROS() { cout << "Estamos eliminando a " << nombre << endl; };

class PERRERA {
public:
  char nombre[20], pais[20], provincia[20], partido[20], localidad[20],
      direccion[40];
  int altura;
  PERROS *INIP;
  PERRERA *SIG;
  PERRERA(char *);
  ~PERRERA();
};

PERRERA::PERRERA(char *name) {
  altura = 0;
  INIP = NULL;
  SIG = NULL;
  strcpy(nombre, name);
};

PERRERA::~PERRERA() {
  PERROS *P, *AUX;

  P = INIP;

  cout << "Eliminando perrera '" << nombre << "' hasta hacerla persistente :/"
       << endl;

  while (P) {
    AUX = P;
    P = P->SIG;
    delete AUX;
  }
};

class SUCURSAL {
private:
  PERRERA *INICIO;
  void REORDENAR(PERRERA *, PERROS **, int);
  void DESACOPLAR(PERRERA *, PERROS **, int);

public:
  SUCURSAL();
  ~SUCURSAL();
  void AGREGAR_PERRERA(char *);
  void AGREGAR_PERRITO(char *);
  void MOSTRAR_PERRERAS();
  void MOSTRAR_PERRITOS();
  void ELIMINAR_PERRERA(char *); // Se elimina una unica perrera
  void ELIMINAR_PERRERA(); // Sobre carga para eliminar a todas las perreras
  void MOVER_PERRITOS(int);
  void MOVER_PERRITOS();
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

void SUCURSAL::REORDENAR(PERRERA *PE, PERROS **PERRITOS, int posicion) {
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

void SUCURSAL::AGREGAR_PERRERA(char *nome) {
  PERRERA *P, *nuevo;

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
  P = INICIO;

  // Se recorre la lista hasta la ultima posicion agregando la nueva perrera al
  // final.
  while (P->SIG) {
    P = P->SIG;
  }

  P->SIG = nuevo;

  return;
}

void SUCURSAL::AGREGAR_PERRITO(char *perre) {
  PERRERA *P;
  PERROS *PE, *nuevo;
  char perrito[20];
  int flag = 0;

  P = INICIO;

  if (INICIO == NULL) {
    cout << "No hay ninguna perrera ingresada como para permitir el ingreso de "
            "un perrito/a, favor de antes crear una perrera."
         << endl;
    return;
  }

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
  PERRERA *P;

  P = INICIO;

  while (P) {
    cout << "\t\t" << P->nombre << " - " << P->provincia << " - " << P->partido
         << " - " << P->direccion << " " << P->altura << endl;
    P = P->SIG;
  }

  return;
}

void SUCURSAL::MOSTRAR_PERRITOS() {
  PERRERA *P;
  PERROS *PE;
  char perrera[20];

  if (INICIO == NULL) {
    cout << "\tNo existen perreras actualmente, favor de crear alguna con la "
            "opcion 1 del menu del programa"
         << endl;
    return;
  }

  P = INICIO;

  cout << "\tIngrese el nombre de la perrera de donde desea saber los "
          "perritos que contiene: ";
  cin.getline(perrera, 20);

  while (P) {
    if (!strcmp(P->nombre, perrera)) {
      if (P->INIP == NULL) {
        cout << "\tEn esta perrera no hay perritos ingresados, favor de "
                "ingresar uno con la opcion 2 del menu del programa"
             << endl;
        return;
      }

      PE = P->INIP;

      while (PE) {
        cout << "\t\t" << PE->nombre << " - " << PE->edad << endl;
        PE = PE->SIG;
      }
    }

    P = P->SIG;
  }

  return;
}

void SUCURSAL::ELIMINAR_PERRERA(char *perre) {
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

void SUCURSAL::MOVER_PERRITOS(int cant) {
  PERRERA *P, *AUX;
  PERROS *PE, *PER[cant];
  int perreras = 0, cantidad = 0, i = 0;
  char perrera_from[20], perrera_to[20], choice;

  if (INICIO == NULL) {
    cout << "\tNo existen perreras actualmente ingresadas, favor de crear al "
            "menos dos";
    return;
  }

  P = INICIO;

  while (P) {
    perreras += 1;

    if (perreras >= 2) {
      break;
    }

    P = P->SIG;
  }

  if (perreras >= 2) {
    cout << "\tEn funcion de la siguiente lista; ";
    MOSTRAR_PERRERAS();
    cout << "\tIngrese el nombre de la perrera desde la cual desea migrar a "
            "los perritos: ";
    cin.getline(perrera_from, 20);

    P = INICIO;

    while (P) {
      if (!strcmp(perrera_from, P->nombre)) {
        if (P->INIP == NULL) {
          cout << "\tEn la perrera ingresada no existen perros ingresados, no "
                  "se puede migrar algo que no existe.";
          return;
        }

        PE = P->INIP;

        while (PE) {
          cout << "\t\tEl perrito actual es: " << PE->nombre << " de edad "
               << PE->edad << endl;

          cout << "\t\tDesea mover este perrito? S(Si) N(No): ";
          cin >> choice;
          cin.ignore(numeric_limits<streamsize>::max(),
                     '\n'); // Limpia el buffer

          if (choice == 'S' and cantidad < cant) {
            PER[cantidad] = PE;
            cantidad += 1;
          }

          PE = PE->SIG;
        }

        AUX = P;

        break;
      }

      P = P->SIG;
    }

    REORDENAR(AUX, PER, cantidad);

    cout << "\tSegun la siguiente lista: " << endl;
    MOSTRAR_PERRERAS();
    cout << "\tCual es la perrera de destino?: ";
    cin.getline(perrera_to, 20);

    P = INICIO;

    while (P) {
      if (!strcmp(P->nombre, perrera_to)) {
        PE = P->INIP;

        while (PE->SIG) {
          PE = PE->SIG;
        }

        for (i = 0; i < cantidad; i++) {
          PE->SIG = PER[i];
          PE = PE->SIG;
        }
      }

      P = P->SIG;
    }

  } else {
    cout << "\tEn este escenario es imcantidadible mover perros de una perrera "
            "a "
            "otra dado que la cantidad de perreras actuales son menores a 2"
         << endl;
  }

  return;
}

void SUCURSAL::MOVER_PERRITOS() {
  PERRERA *PE, *AUX;
  PERROS *P;
  char perrera_from[20], perrera_to[20];
  int cantidad = 0, i = 0, j = 0, flag = 0;

  AUX = NULL;

  cout << "\tEn funcion de la siguiente lista de perreras:" << endl;
  MOSTRAR_PERRERAS();
  cout << "\tIngrese el nombre de la perrera desde la que desea migrar a los "
          "perritos: ";
  cin.getline(perrera_from, 20);

  PE = INICIO;

  while (PE) {
    if (!strcmp(PE->nombre, perrera_from)) {
      P = PE->INIP;
      AUX = PE;

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

  PERROS *PERRITOS[cantidad];
  P = AUX->INIP;

  while (P) {
    PERRITOS[i] = P;
    i += 1;
    P = P->SIG;
  }

  REORDENAR(AUX, PERRITOS, cantidad);

  cout << "\tSegun la lista de perreras previamente mostrada, Ingrese la "
          "perrera de destino: ";
  cin.getline(perrera_to, 20);

  PE = INICIO;

  while (PE) {
    if (!strcmp(PE->nombre, perrera_to)) {
      P = PE->INIP;

      while (P) {
        P = P->SIG;
      }

      for (j = 0; j < cantidad; j++) {
        P = PERRITOS[j];
        P = P->SIG;
      }

      break;
    } else {
      flag = 1;
      PE = PE->SIG;
    }
  }

  return;
}

int main(int argc, char **argv, char **envp) {
  SUCURSAL S;
  int choice, choice1, cantidad;
  char perrera[20], perrera_elegida[20], know;

  cout << "Bienvenido al Albergue de Perros simulado" << endl;

  while (choice) {
    cout
        << "Para facilitar la gestion de este programa usted puede escoger "
           "entre las siguientes opciones:\n"
        << "1- Agregar una perrera nueva\n"
        << "2- Agregar perritos a una perrera ya existente\n"
        << "3- Mostrar Perreras\n"
        << "4- Mostrar Perritos de una Perrera determinada\n"
        << "5- Eliminar una perrera o todas las perreras (esto incluye la "
           "perdida de los datos de los "
           "perritos)\n"
        << "6- Mover los datos de algunos u todos los perritos a otra perrera\n"
        << "7- Buscar un perro especifigo en una perrera concreta o en todas\n"
        << "8- Eliminar un perrito de alguna perrera especifica\n"
        << "9- Modificar los datos de un perro o perrera\n"
        << "0- Sale del programa\n"
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
      cout << "\tSabe el nombre de la perrera en donde desea ingresar al nuevo "
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
          cout
              << "\tSiendo que no conoce el nombre de la perrera ni tampoco la "
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
      S.MOSTRAR_PERRITOS();
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
        cout << "\tNo corresponde a ninguna opcion para elegir, se devuelve al "
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
        cout << "\t\tCuantos perritos desea mover: ";
        cin >> cantidad;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
        S.MOVER_PERRITOS(cantidad);
      } else if (choice1 == 2) {
        S.MOVER_PERRITOS();
      }
      break;
    }
  }

  return 0;
}
