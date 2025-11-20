#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
  int dir_num;
  PERROS *INIP;
  PERRERA *SIG;
  PERRERA(char *);
  ~PERRERA();
};

PERRERA::PERRERA(char *name) {
  dir_num = 0;
  INIP = NULL;
  SIG = NULL;
  strcpy(nombre, name);
};

PERRERA::~PERRERA() {
  PERROS *P, *AUX;

  P = INIP;

  cout << "Eliminando Perrera " << nombre << " hasta hacerla persistente :/"
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

int main(int argc, char **argv, char **envp) {

  SUCURSAL S;
  int cantidad = 0, i = 0, salida = 0;
  char perrera[20];

  cout << "Bienvenido al Albergue de Perros simulado" << endl;

  while (salida) {
    cout
        << "Para facilitar la gestion de este programa usted puede escoger entre las siguientes opciones:\
1- Agregar una perrera nueva\
2- Agregar perritos a una perrera ya existente\
3- Eliminar perreras (esto incluye la perdida de los datos de los perritos)\
4- Mover los datos de algunos u todos los perritos a otra perrera\
5- Buscar un perro especifigo en una perrera concreta o en todas\
6- Eliminar un perrito de alguna perrera especifica\
7- Modificar los datos de un perro o perrera\
0- Sale del programa";
  }

  return 0;
}
