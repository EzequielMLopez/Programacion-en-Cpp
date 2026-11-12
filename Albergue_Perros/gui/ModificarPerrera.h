#ifndef GTKMM_MODIFICAR_PERRERA_H
#define GTKMM_MODIFICAR_PERRERA_H

#include "Clases.h"
#include <gtkmm.h>
#include <string>

class ModificarPerrera : public Gtk::Dialog {
private:
  Gtk::Grid grid;
  Gtk::Label m_lbl_titulo;

  // Campos editables de la Perrera
  Gtk::Label m_lbl_nombre;
  Gtk::Label m_lbl_pais;
  Gtk::Label m_lbl_provincia;
  Gtk::Label m_lbl_partido;
  Gtk::Label m_lbl_localidad;
  Gtk::Label m_lbl_direccion;
  Gtk::Label m_lbl_altura;

  Gtk::Entry m_entry_nombre; // Modificable Entry Name, Modificable Entry Country, etc.
  Gtk::Entry m_entry_pais;
  Gtk::Entry m_entry_provincia;
  Gtk::Entry m_entry_partido;
  Gtk::Entry m_entry_localidad;
  Gtk::Entry m_entry_direccion;
  Gtk::Entry m_entry_altura;

  std::string nombre_perrera_objetivo;

public:
  ModificarPerrera(Gtk::Window& parent, const std::string& nombre_perrera, const std::string& pais, const std::string& provincia,
                   const std::string& partido, const std::string& localidad, const std::string& direccion, const int altura);

  ~ModificarPerrera();

  std::string get_nombre() const;
  std::string get_pais() const;
  std::string get_provincia() const;
  std::string get_partido() const;
  std::string get_localidad() const;
  std::string get_direccion() const;
  int get_altura() const;
};

#endif // GTKMM_MODIFICAR_PERRERA_H
