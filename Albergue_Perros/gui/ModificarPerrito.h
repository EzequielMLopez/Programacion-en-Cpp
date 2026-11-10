#ifndef GTKMM_MODIFICAR_PERRITO_H
#define GTKMM_MODIFICAR_PERRITO_H

#include "Clases.h"
#include "gtkmm/entry.h"
#include "gtkmm/grid.h"
#include "gtkmm/label.h"
#include <gtkmm.h>
#include <string>

class ModificarPerrito : public Gtk::Dialog {
private:
  Gtk::Grid grid;
  Gtk::Label m_lbl_titulo;

  // Campos editables del Perrito
  Gtk::Label m_lbl_nombre;
  Gtk::Label m_lbl_edad;

  Gtk::Entry m_entry_nombre;
  Gtk::Entry m_entry_edad;

  std::string nombre_perrera_objetivo;
  std::string nombre_perrito_objetivo;

public:
  ModificarPerrito(Gtk::Window& parent, const std::string& nombre, const int edad);
  ~ModificarPerrito();

  std::string get_nombre() const;
  int get_edad() const;
};

#endif // !GTKMM_MODIFICAR_PERRITO_H
