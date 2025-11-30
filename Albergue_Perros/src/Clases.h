#include <stdlib.h>

class PERROS {
public:
  char nombre[20];
  int edad, apuntado = 0;
  PERROS* SIG;
  PERROS(char*);
  ~PERROS();
};

class PERRERA {
public:
  char nombre[20], pais[20], provincia[20], partido[20], localidad[20], direccion[40];
  int altura;
  PERROS* INIP;
  PERRERA* SIG;
  PERRERA(char*);
  ~PERRERA();
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
  void MODIFICAR_PERRERA();
};
