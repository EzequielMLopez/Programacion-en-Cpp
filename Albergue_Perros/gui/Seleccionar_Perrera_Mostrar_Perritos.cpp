#include "Seleccionar_Perrera_Mostrar_Perritos.h"
#include <string>
#include <vector>

Seleccionar_Perrera_Mostrar_Perritos::Seleccionar_Perrera_Mostrar_Perritos(Gtk::Window& parent, const std::vector<std::string>& nombres_perreras)
    : Gtk::Dialog("Seleccionar Perrera", parent) {

  set_default_size(450, 300);

  // Convertimos el vector a Glib::ustring para el StringList
  std::vector<Glib::ustring> perreras_ustring;
  for (const auto& name : nombres_perreras) {
    perreras_ustring.push_back(name);
  }

  m_string_list = Gtk::StringList::create(perreras_ustring);
  drop_d.set_model(m_string_list);

  // Organizamos en la grilla
  grid.set_margin(15);
  grid.set_row_spacing(10);
  grid.set_column_spacing(10);

  grid.attach(lbl_perrera, 0, 0);
  grid.attach(drop_d, 1, 0);

  get_content_area()->append(grid);

  add_button("OK", Gtk::ResponseType::OK);
  add_button("Cancelar", Gtk::ResponseType::CANCEL);
};

Seleccionar_Perrera_Mostrar_Perritos::~Seleccionar_Perrera_Mostrar_Perritos() {};

std::string Seleccionar_Perrera_Mostrar_Perritos::get_perrera_seleccionada() const {
  auto selected_item = std::dynamic_pointer_cast<const Gtk::StringObject>(drop_d.get_selected_item());
  if (selected_item) {
    return selected_item->get_string();
  }
  return "";
}
