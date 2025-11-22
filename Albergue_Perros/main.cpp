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

public:
  SUCURSAL();
  ~SUCURSAL();
  void AGREGAR_PERRERA(char *);
  void AGREGAR_PERRITO(char *);
  void MOSTRAR_PERRERAS();
  void MOSTRAR_PERRITOS();
};

SUCURSAL::SUCURSAL() { INICIO = NULL; };

SUCURSAL::~SUCURSAL() {
  PERRERA *P, *AUX;

  P = INICIO;

  while (P) {
    AUX = P;
    P = P->SIG;
    delete AUX;
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
    cout << "\t\t" << P->nombre << " - " << P->provincia << " - "
         << P->direccion << " " << P->altura << endl;
    P = P->SIG;
  }
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

int main(int argc, char **argv, char **envp) {
  SUCURSAL S;
  int cantidad = 0, i = 0, choice;
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
        << "5- Eliminar perreras (esto incluye la perdida de los datos de los "
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
      } else {
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
        } else {
          cout << "Siendo que no conoce el nombre de la perrera ni tampoco la "
                  "supo reconocer en el listado dado, le pedimos que cree la "
                  "Perrera para poder ingresar a los perritos"
               << endl;
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
    }
  }

  return 0;
}
