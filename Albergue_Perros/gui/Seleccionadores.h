#ifndef GTKMM_SELECCIONAR_PERRERA_MOSTRAR_PERRITOS_H
#define GTKMM_SELECCIONAR_PERRERA_MOSTRAR_PERRITOS_H

#include "Clases.h"
#pragma once
#include <gtkmm.h>
#include <string>
#include <vector>

class Seleccionador : public Gtk::Dialog {
protected:
  SUCURSAL& m_backend;
  Gtk::Grid grid;
  Gtk::Label lbl_perrera;
  Gtk::DropDown drop_d_perrera;
  Glib::RefPtr<Gtk::StringList> m_string_list_perrera;

public:
  Seleccionador(Gtk::Window& parent, const std::string& titulo, const std::vector<std::string>& nombres_perreras, SUCURSAL& backend);
  virtual ~Seleccionador() = default;
  void actualizar_lista_perreras();

  // Getter unificado que ya no necesitas repetir en ningún lado
  std::string get_perrera_seleccionada() const;
};

#endif // !GTKMM_SELECCIONAR_PERRERA_MOSTRAR_PERRITOS_H
