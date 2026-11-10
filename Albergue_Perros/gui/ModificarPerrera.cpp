#include "ModificarPerrera.h"
#include "gtkmm/dialog.h"
#include <string>
#include <vector>

ModificarPerrera::ModificarPerrera(Gtk::Window& parent, const std::string& nombre_perrera, const std::string& pais, const std::string& provincia,
                                   const std::string& partido, const std::string& localidad, const std::string& direccion, const int altura)
    : Gtk::Dialog("Modificar_Perrera", parent) {
  set_default_size(450, 300);

  m_entry_nombre.set_max_length(20);
  m_entry_nombre.set_text(m_entry_nombre.get_text());
  m_entry_nombre.select_region(0, m_entry_nombre.get_text_length());
  m_entry_nombre.set_expand(false);

  m_entry_pais.set_max_length(20);
  m_entry_pais.set_text(m_entry_pais.get_text());
  m_entry_pais.select_region(0, m_entry_pais.get_text_length());
  m_entry_pais.set_expand(false);

  m_entry_provincia.set_max_length(20);
  m_entry_provincia.set_text(m_entry_pais.get_text());
  m_entry_provincia.select_region(0, m_entry_provincia.get_text_length());
  m_entry_provincia.set_expand(false);

  m_entry_partido.set_max_length(40);
  m_entry_partido.set_text(m_entry_pais.get_text());
  m_entry_partido.select_region(0, m_entry_partido.get_text_length());
  m_entry_partido.set_expand(false);

  m_entry_localidad.set_max_length(20);
  m_entry_localidad.set_text(m_entry_pais.get_text());
  m_entry_localidad.select_region(0, m_entry_localidad.get_text_length());
  m_entry_localidad.set_expand(false);

  m_entry_direccion.set_max_length(20);
  m_entry_direccion.set_text(m_entry_pais.get_text());
  m_entry_direccion.select_region(0, m_entry_direccion.get_text_length());
  m_entry_direccion.set_expand(false);

  m_entry_altura.set_max_length(20);
  m_entry_altura.set_text(m_entry_altura.get_text());
  m_entry_altura.select_region(0, m_entry_altura.get_text_length());
  m_entry_altura.set_expand(false);

  m_entry_nombre.set_text(nombre_perrera);
  m_entry_pais.set_text(pais);
  m_entry_provincia.set_text(provincia);
  m_entry_partido.set_text(partido);
  m_entry_localidad.set_text(localidad);
  m_entry_direccion.set_text(direccion);
  m_entry_altura.set_text(std::to_string(altura));

  m_lbl_nombre.set_text("Nombre de la Perrera: ");
  m_lbl_pais.set_text("Pais: ");
  m_lbl_provincia.set_text("Provincia: ");
  m_lbl_partido.set_text("Partido: ");
  m_lbl_localidad.set_text("Localidad: ");
  m_lbl_direccion.set_text("Direccion/Calle: ");
  m_lbl_altura.set_text("Altura: ");

  grid.attach(m_lbl_nombre, 0, 0);
  grid.attach(m_entry_nombre, 1, 0);

  grid.attach(m_lbl_pais, 0, 1);
  grid.attach(m_entry_pais, 1, 1);

  grid.attach(m_lbl_provincia, 0, 2);
  grid.attach(m_entry_provincia, 1, 2);

  grid.attach(m_lbl_partido, 0, 3);
  grid.attach(m_entry_partido, 1, 3);

  grid.attach(m_lbl_localidad, 0, 4);
  grid.attach(m_entry_localidad, 1, 4);

  grid.attach(m_lbl_direccion, 0, 5);
  grid.attach(m_entry_direccion, 1, 5);

  grid.attach(m_lbl_altura, 0, 6);
  grid.attach(m_entry_altura, 1, 6);

  get_content_area()->append(grid);

  add_button("Ok", Gtk::ResponseType::OK);
}

ModificarPerrera::~ModificarPerrera() {}

std::string ModificarPerrera::get_nombre() const { return m_entry_nombre.get_text(); }
std::string ModificarPerrera::get_pais() const { return m_entry_pais.get_text(); }
std::string ModificarPerrera::get_provincia() const { return m_entry_provincia.get_text(); }
std::string ModificarPerrera::get_partido() const { return m_entry_partido.get_text(); }
std::string ModificarPerrera::get_localidad() const { return m_entry_localidad.get_text(); }
std::string ModificarPerrera::get_direccion() const { return m_entry_direccion.get_text(); }
int ModificarPerrera::get_altura() const {
  try {
    return std::stoi(m_entry_altura.get_text());
  } catch (...) {
    return 0;
  }
}
