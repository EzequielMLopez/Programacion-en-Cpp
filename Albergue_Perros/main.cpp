#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class PERROS {
public:
  char nombre[20];
  int edad;
  PERROS *SIG;
  PERROS();
  ~PERROS();
};

PERROS::PERROS() {
  edad = 0;
  SIG = NULL;
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
  PERRERA();
  ~PERRERA();
};

PERRERA::PERRERA() {
  dir_num = 0;
  INIP = NULL;
  SIG = NULL;
};

PERRERA::~PERRERA() {
  cout << "Eliminando Perreras hasta hacerlas persistentes :/" << endl;
};

class SUCURSAL {
public:
  PERRERA *INICIO = NULL;
};

int main(int argc, char **argv) {
  printf("Hello there.\n");
  return 0;
}
