#ifndef GTKMM_AGREGAR_PERRERA_H
#define GTKMM_AGREGAR_PERRERA_H

#include "Clases.h"
#include "gtkmm/entry.h"
#include "gtkmm/grid.h"
#include "gtkmm/label.h"
#include <gtkmm/dialog.h>
#include <string>

class Agregar_Perrera : public Gtk::Dialog {
private:
  Gtk::Grid grid;

  Gtk::Entry entry_nombre;
  Gtk::Entry entry_pais;
  Gtk::Entry entry_provincia;
  Gtk::Entry entry_partido;
  Gtk::Entry entry_localidad;
  Gtk::Entry entry_direccion;
  Gtk::Entry entry_altura;

  Gtk::Label lbl_nombre;
  Gtk::Label lbl_pais;
  Gtk::Label lbl_provincia;
  Gtk::Label lbl_partido;
  Gtk::Label lbl_localidad;
  Gtk::Label lbl_direccion;
  Gtk::Label lbl_altura;

public:
  Agregar_Perrera(Gtk::Window& parent);
  ~Agregar_Perrera();

  std::string get_nombre() const;
  std::string get_pais() const;
  std::string get_provincia() const;
  std::string get_partido() const;
  std::string get_localidad() const;
  std::string get_direccion() const;
  int get_altura() const;
};

#endif
