#include "ModificarPerrito.h"
#include "gtkmm/dialog.h"
#include "string"
#include "vector"
#include <string>

ModificarPerrito::ModificarPerrito(Gtk::Window& parent, const std::string& nombre, const int edad) : Gtk::Dialog("Modificar_Perrito", parent) {
  set_default_size(450, 300);

  m_entry_nombre.set_max_length(20);
  m_entry_nombre.set_text(m_entry_nombre.get_text());
  m_entry_nombre.select_region(0, m_entry_nombre.get_text_length());
  m_entry_nombre.set_expand(false);

  m_entry_edad.set_max_length(20);
  m_entry_edad.set_text(m_entry_edad.get_text());
  m_entry_edad.select_region(0, m_entry_edad.get_text_length());
  m_entry_edad.set_expand(false);

  m_entry_nombre.set_text(nombre);
  m_entry_edad.set_text(std::to_string(edad));

  m_lbl_nombre.set_text("Nombre del Perrito: ");
  m_lbl_edad.set_text("Edad: ");

  grid.attach(m_lbl_nombre, 0, 0);
  grid.attach(m_entry_nombre, 1, 0);

  grid.attach(m_lbl_edad, 0, 1);
  grid.attach(m_entry_edad, 1, 1);

  get_content_area()->append(grid);

  add_button("Ok", Gtk::ResponseType::OK);
}

ModificarPerrito::~ModificarPerrito() {};

std::string ModificarPerrito::get_nombre() const { return m_entry_nombre.get_text(); }
int ModificarPerrito::get_edad() const {
  try {
    return std::stoi(m_entry_edad.get_text());
  } catch (...) {
    return 0;
  }
}
