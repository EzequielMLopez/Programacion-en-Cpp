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

PERROS::~PERROS() {
  cout << "Estamos eliminando a los perritos, aunque despues los vamos a hacer "
          "persistentes :)"
       << endl;
};

class PERRERA {
public:
  char nombre[20], pais[20], provincia[20], partido[20], localidad[20],
      direccion[20];
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
  cin.getline(nuevo->direccion, 20);
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
  while (P) {
    P = P->SIG;
  }

  P->SIG = nuevo;
}

int main(int argc, char **argv, char **envp) {
  SUCURSAL S;
  int cantidad = 0, i = 0, choice;
  char perrera[20];

  cout << "Bienvenido al Albergue de Perros simulado" << endl;

  while (choice) {
    cout
        << "Para facilitar la gestion de este programa usted puede escoger "
           "entre las siguientes opciones:\n"
        << "1- Agregar una perrera nueva\n"
        << "2- Agregar perritos a una perrera ya existente\n"
        << "3- Eliminar perreras (esto incluye la perdida de los datos de los "
           "perritos)\n"
        << "4- Mover los datos de algunos u todos los perritos a otra perrera\n"
        << "5- Buscar un perro especifigo en una perrera concreta o en todas\n"
        << "6- Eliminar un perrito de alguna perrera especifica\n"
        << "7- Modificar los datos de un perro o perrera\n"
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
    }
  }

  return 0;
}
