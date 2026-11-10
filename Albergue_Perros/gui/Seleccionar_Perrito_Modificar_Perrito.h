#pragma once
#include "Clases.h"
#include "Seleccionadores.h"
#include "glibmm/refptr.h"
#include <string>
#include <vector>

class SeleccionarPerritoModificar : public Seleccionador {
private:
  SUCURSAL& m_backend;
  Gtk::Label lbl_perritos{"Seleccionar Perrito: "};
  Gtk::DropDown drop_d_perritos;
  Glib::RefPtr<Gtk::StringList> m_string_list_perritos;

public:
  SeleccionarPerritoModificar(Gtk::Window& parent, SUCURSAL& backend, const std::vector<std::string>& nombres_perreras);
  void actualizar_lista_perritos(const std::string& perrera_sel);

  // Getter exclusivo para el perrito
  std::string get_perrito_seleccionado() const;
};
