#ifndef GTKMM_SELECCIONAR_PERRITO_MOVER_PERRITO_H
#define GTKMM_SELECCIONAR_PERRITO_MOVER_PERRITO_H
#pragma once
#include "Clases.h"
#include "Seleccionadores.h"
#include "Seleccionar_Perrito_Modificar_Perrito.h"
#include "glibmm/refptr.h"
#include "gtkmm/dropdown.h"
#include "gtkmm/label.h"
#include <vector>

class SeleccionarPerritoMover : public SeleccionarPerritoModificar {
protected:
  Gtk::Label lbl_perrera_dest{"Seleccionar Perrera Destino: "};
  Gtk::DropDown drop_d_perrera_dest;
  Glib::RefPtr<Gtk::StringList> m_string_list_perrera_dest;

public:
  SeleccionarPerritoMover(Gtk::Window& parent, SUCURSAL& backend, const std::vector<std::string>& nombres_perreras, bool solo_perreras = false);

  void actualizar_lista_perreras_destino(const std::string& perrera_origen_excluida, const std::vector<std::string>& perreras);

  std::string get_perrera_dest_seleccionado() const;
};

#endif // GTKMM_SELECCIONAR_PERRITO_MOVER_PERRITO_H
