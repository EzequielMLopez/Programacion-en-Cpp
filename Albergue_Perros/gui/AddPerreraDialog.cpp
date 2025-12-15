#include "AddPerreraDialog.h"
#include "MainWindow.h"
#include "gtkmm/dialog.h"
#include "gtkmm/entry.h"
#include "gtkmm/grid.h"
#include "sigc++/adaptors/exception_catch.h"
#include "sigc++/functors/mem_fun.h"
#include <gtkmm.h>

AddPerreraDialog::AddPerreraDialog(Gtk::Window& parent) : Gtk::Dialog("Agregar_Perrera", parent) {
  entry_nombre.set_max_length(20);
  entry_nombre.set_text(entry_nombre.get_text());
  entry_nombre.select_region(0, entry_nombre.get_text_length());
  entry_nombre.set_expand(false);

  entry_pais.set_max_length(20);
  entry_pais.set_text(entry_pais.get_text());
  entry_pais.select_region(0, entry_pais.get_text_length());
  entry_pais.set_expand(false);

  entry_provincia.set_max_length(20);
  entry_provincia.set_text(entry_pais.get_text());
  entry_provincia.select_region(0, entry_pais.get_text_length());
  entry_provincia.set_expand(false);

  entry_partido.set_max_length(40);
  entry_partido.set_text(entry_pais.get_text());
  entry_partido.select_region(0, entry_pais.get_text_length());
  entry_partido.set_expand(false);

  entry_localidad.set_max_length(20);
  entry_localidad.set_text(entry_pais.get_text());
  entry_localidad.select_region(0, entry_pais.get_text_length());
  entry_localidad.set_expand(false);

  entry_direccion.set_max_length(20);
  entry_direccion.set_text(entry_pais.get_text());
  entry_direccion.select_region(0, entry_pais.get_text_length());
  entry_direccion.set_expand(false);

  entry_altura.set_max_length(20);
  entry_altura.set_text(entry_pais.get_text());
  entry_altura.select_region(0, entry_pais.get_text_length());
  entry_altura.set_expand(false);

  lbl_nombre.set_text("Nombre de la Perrera:");
  lbl_pais.set_text("Pais:");
  lbl_provincia.set_text("Provincia:");
  lbl_partido.set_text("Partido:");
  lbl_localidad.set_text("Localidad:");
  lbl_direccion.set_text("Direccion/Calle:");
  lbl_altura.set_text("Altura:");

  grid.attach(lbl_nombre, 0, 0);
  grid.attach(entry_nombre, 1, 0);

  grid.attach(lbl_pais, 0, 1);
  grid.attach(entry_pais, 1, 1);

  grid.attach(lbl_provincia, 0, 2);
  grid.attach(entry_provincia, 1, 2);

  grid.attach(lbl_partido, 0, 3);
  grid.attach(entry_partido, 1, 3);

  grid.attach(lbl_localidad, 0, 4);
  grid.attach(entry_localidad, 1, 4);

  grid.attach(lbl_direccion, 0, 5);
  grid.attach(entry_direccion, 1, 5);

  grid.attach(lbl_altura, 0, 6);
  grid.attach(entry_altura, 1, 6);

  get_content_area()->append(grid);

  add_button("Ok", Gtk::ResponseType::OK);
  add_button("Cancelar", Gtk::ResponseType::CANCEL);
}

AddPerreraDialog::~AddPerreraDialog() {}

std::string AddPerreraDialog::get_nombre() const { return entry_nombre.get_text(); }
std::string AddPerreraDialog::get_pais() const { return entry_pais.get_text(); }
std::string AddPerreraDialog::get_provincia() const { return entry_provincia.get_text(); }
std::string AddPerreraDialog::get_partido() const { return entry_partido.get_text(); }
std::string AddPerreraDialog::get_localidad() const { return entry_localidad.get_text(); }
std::string AddPerreraDialog::get_direccion() const { return entry_direccion.get_text(); }
int AddPerreraDialog::get_altura() const {
  try {
    return std::stoi(entry_altura.get_text());
  } catch (...) {
    return 0;
  }
}
