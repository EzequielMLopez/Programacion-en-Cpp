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

  PERROS(const string&, const int);
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

  std::vector<PERROS> getPerritos() const;

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
  // void AGREGAR_PERRERA(const string& nome);
  void AGREGAR_PERRERA_GUI(const string& nombre, const string& pais, const string& provincia, const string& partido, const string& localidad,
                           const string& direccion, const int altura); // Se implementa en src/Insertar.cpp
  // void AGREGAR_PERRITO(const string&);
  void AGREGAR_PERRITO_GUI(const string& nombre, const int edad, const string& perre); // Se implementa en src/Insertar.cpp
  // void MOSTRAR_PERRERAS();
  // void MOSTRAR_PERRITOS(const string&);
  std::vector<std::string> MOSTRAR_DETALLES_PERRERAS_GUI() const;                          // Se implementa en src/Mostrar.cpp
  std::vector<std::string> MOSTRAR_DETALLES_PERRITOS_GUI(const string& perrera) const;     // Se implementa en src/Mostrar.cpp
  std::vector<std::string> OBTENER_NOMBRES_PERRERAS_GUI() const;                           // Se implementa en src/ObtenerDetalles.cpp
  std::vector<std::string> OBTENER_NOMBRES_PERRITOS_GUI(const std::string& perrera) const; // Se implementa en src/ObtenerDetalles.cpp
  std::vector<std::string> OBTENER_DETALLES_PERRERA_GUI(const string& perrera) const;      // Se implementa en src/ObtenerDetalles.cpp
  std::vector<std::string> OBTENER_DETALLES_PERRITOS_GUI(const string& perrera,
                                                         const string& perrito) const; // Se implementa en src/ObtenerDetalles.cpp
  //  void ELIMINAR_PERRERA(const string&);                                                // Se elimina una unica perrera. Se implementa en
  //  Eliminar.cpp void ELIMINAR_PERRERA();                                                // Sobre carga para eliminar a todas las
  //  perreras. Se implementa en src/E
  std::string ELIMINAR_PERRERA_GUI(const string&); // Se implementa en src/Eliminar.cpp
  // void ELIMINAR_PERRITO();                                                              // Se implementa en src/Eliminar.cpp
  std::string ELIMINAR_PERRITO_GUI(const string& perrera, const string& perritos); // Se implementa en src/Eliminar.cpp
  void MOVER_PERRITOS(int);
  void BUSCAR_PERRITO(const string&);
  void BUSCAR_PERRITO();
  // void MODIFICAR_PERRITO();
  bool MODIFICAR_PERRITO_GUI(const string& perrera, const string& nombre_buscado, const string& nombre_nuevo,
                             const int edad_nueva); // Se implementa en src/Modificar.cpp
  // void MODIFICAR_PERRERA();
  bool MODIFICAR_PERRERA_GUI(const string& nombre_buscado, const string& nombre_nuevo, const string& pais_nuevo, const string& provincia_nueva,
                             const string& partido_nuevo, const string& localidad_nueva, const string& direccion_nueva,
                             const int altura_nueva); // Se implementa en src/Modificar.cpp

  PERRERA* getINICIO() const;
};

#endif
