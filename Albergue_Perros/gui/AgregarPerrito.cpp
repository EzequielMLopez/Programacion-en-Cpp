#include "AgregarPerrito.h"
#include "glibmm/ustring.h"
#include "gtkmm/dialog.h"
#include "gtkmm/stringlist.h"
#include <gtkmm.h>
#include <vector>

Agregar_Perrito::Agregar_Perrito(Gtk::Window& parent, const std::vector<std::string>& nombres_perreras) : Gtk::Dialog("Agregar_Perrito", parent) {
  entry_nombre.set_max_length(20);
  entry_nombre.set_text(entry_nombre.get_text());
  entry_nombre.select_region(0, entry_nombre.get_text_length());
  entry_nombre.set_expand(false);

  entry_edad.set_max_length(20);
  entry_edad.set_text(entry_edad.get_text());
  entry_edad.select_region(0, entry_edad.get_text_length());
  entry_edad.set_expand(false);

  // Configuracion del Dropdown
  // Convertimos el vector de std::string a Glib::ustring que es lo que exige Gtk::StringList
  std::vector<Glib::ustring> perreras_ustring;
  for (const auto& name : nombres_perreras) {
    perreras_ustring.push_back(name);
  }

  // Creamos el modelo de lista con los nombres
  m_string_list = Gtk::StringList::create(perreras_ustring);

  // Asignamos el modelo al Dropdown
  drop_d.set_model(m_string_list);

  lbl_nombre.set_text("Nombre del Perrito: ");
  lbl_edad.set_text("Edad del Perrito: ");
  lbl_perrera.set_text("Perrera: ");

  grid.attach(lbl_nombre, 0, 0);
  grid.attach(entry_nombre, 1, 0);

  grid.attach(lbl_edad, 0, 1);
  grid.attach(entry_edad, 1, 1);

  grid.attach(lbl_perrera, 0, 2);
  grid.attach(drop_d, 1, 2);

  get_content_area()->append(grid);

  add_button("OK", Gtk::ResponseType::OK);
  add_button("Cancelar", Gtk::ResponseType::CANCEL);
}

Agregar_Perrito::~Agregar_Perrito() {}

std::string Agregar_Perrito::get_nombre() const { return entry_nombre.get_text(); }

int Agregar_Perrito::get_edad() const {
  try {
    return std::stoi(entry_edad.get_text());
  } catch (...) {
    return 0;
  }
}

std::string Agregar_Perrito::get_perrera() const {
  // Convertimos el elemento seleccionado del DropDown a un objeto de tipo StringObject de GTK
  auto selected_item = std::dynamic_pointer_cast<const Gtk::StringObject>(drop_d.get_selected_item());

  if (selected_item) {
    return selected_item->get_string(); // Retorna el nombre de la perrera elegida
  }

  return ""; // Retorna vacío si ocurriera algún fallo en la selección
}
