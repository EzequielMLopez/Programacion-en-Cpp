#ifndef CLASES_H
#define CLASES_H

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class PERROS {
private:
  string nombre;
  int edad;
  bool apuntado;
  PERROS* SIG;

public:
  void setNombre(const string& nomine);
  string getNombre() const;

  void setEdad(int ed);
  int getEdad() const;

  void setApuntado(bool v);
  bool getApuntado() const;

  void setSIG(PERROS* p);
  PERROS* getSIG() const;

  PERROS(const string&);
  ~PERROS();
};

class PERRERA {
private:
  string nombre, pais, provincia, partido, localidad, direccion;
  int altura;
  PERROS* INIP;
  PERRERA* SIG;

public:
  void setNombre(const string& nomine);
  string getNombre() const;

  void setPais(const string& pais);
  string getPais() const;

  void setProvincia(const string& provincia);
  string getProvincia() const;

  void setPartido(const string& partido);
  string getPartido() const;

  void setLocalidad(const string& localidad);
  string getLocalidad() const;

  void setDireccion(const string& direccion);
  string getDireccion() const;

  void setAltura(int alt);
  int getAltura() const;

  void setINIP(PERROS* p);
  PERROS* getINIP() const;

  void setSIG(PERRERA* pe);
  PERRERA* getSIG() const;

  PERRERA(const string&);
  ~PERRERA();
};

class SUCURSAL {
private:
  PERRERA* INICIO;
  void REORDENAR(PERRERA*, vector<PERROS*>&, int);
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

#endif
