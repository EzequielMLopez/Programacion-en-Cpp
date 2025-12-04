#include <stdlib.h>
#include <string>

using namespace std;

class PERROS {
public:
  string nombre;
  int edad, apuntado = 0;
  PERROS* SIG;
  PERROS(const string&);
  ~PERROS();
};

class PERRERA {
public:
  char pais[20], provincia[20], partido[20], localidad[20], direccion[40];
  string nombre;
  int altura;
  PERROS* INIP;
  PERRERA* SIG;
  PERRERA(const string&);
  ~PERRERA();
};

class SUCURSAL {
private:
  PERRERA* INICIO;
  void REORDENAR(PERRERA*, PERROS**, int);
  int TOTAL_PERRITOS(const string&);

public:
  SUCURSAL();
  ~SUCURSAL();
  void AGREGAR_PERRERA(const string&);
  void AGREGAR_PERRITO(const string&);
  void MOSTRAR_PERRERAS();
  void MOSTRAR_PERRITOS(const string&);
  void ELIMINAR_PERRERA(const string&); // Se elimina una unica perrera
  void ELIMINAR_PERRERA();              // Sobre carga para eliminar a todas las perreras
  void MOVER_PERRITOS(int);
  void BUSCAR_PERRITO(const string&);
  void BUSCAR_PERRITO();
  void ELIMINAR_PERRITO();
  void MODIFICAR_PERRITO();
  void MODIFICAR_PERRERA();
};
