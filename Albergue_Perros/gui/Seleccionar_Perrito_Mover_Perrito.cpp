#include "Seleccionar_Perrito_Mover_Perrito.h"
#include "Clases.h"
#include "Seleccionadores.h"
#include "Seleccionar_Perrito_Modificar_Perrito.h"
#include "glibmm/ustring.h"
#include "gtkmm/stringlist.h"
#include "gtkmm/window.h"
#include <string>
#include <vector>

SeleccionarPerritoMover::SeleccionarPerritoMover(Gtk::Window& parent, SUCURSAL& backend, const std::vector<std::string>& nombres_perreras,
                                                 bool solo_perreras)
    : SeleccionarPerritoModificar(parent, backend, nombres_perreras) {

  // 1. Inicializamos el destino filtrando la perrera inicial
  std::string perrera_inicial = get_perrera_seleccionada();
  actualizar_lista_perreras_destino(perrera_inicial, nombres_perreras);

  grid.attach(lbl_perrera_dest, 0, 2);
  grid.attach(drop_d_perrera_dest, 1, 2);

  // 2. Usamos property_selected().signal_changed() pero asegurándonos de que solo actúe ante el cambio del usuario:
  drop_d_perrera.property_selected().signal_changed().connect([this, nombres_perreras]() {
    std::string origen_actual = get_perrera_seleccionada();

    // Evitamos ejecuciones vacías o innecesarias
    if (!origen_actual.empty()) {
      actualizar_lista_perreras_destino(origen_actual, nombres_perreras);
    }
  });

  if (solo_perreras == true) {
    lbl_perritos.hide();
    drop_d_perritos.hide();
  }
}

void SeleccionarPerritoMover::actualizar_lista_perreras_destino(const std::string& perrera_origen_excluida,
                                                                const std::vector<std::string>& todas_las_perreras) {
  std::vector<Glib::ustring> filtradas;
  for (const auto& name : todas_las_perreras) {
    if (name != perrera_origen_excluida) {
      filtradas.push_back(name);
    }
  }

  // Creamos el nuevo StringList para el destino
  m_string_list_perrera_dest = Gtk::StringList::create(filtradas);
  drop_d_perrera_dest.set_model(m_string_list_perrera_dest);

  // Opcional: seleccionamos por defecto el primer elemento del destino filtrado para evitar estados nulos
  if (!filtradas.empty()) {
    drop_d_perrera_dest.set_selected(0);
  }
}

std::string SeleccionarPerritoMover::get_perrera_dest_seleccionado() const {
  // 1. Obtenemos el índice numérico seleccionado en el DropDown
  guint index = drop_d_perrera_dest.get_selected();

  // Si no hay selección válida, retornamos vacío
  if (index == GTK_INVALID_LIST_POSITION) {
    return "";
  };

  // 2. Como m_string_list_perrera ya lo tenemos guardado en la clase,
  // le pedimos el string directamente por su índice sin castear nada.
  if (m_string_list_perrera_dest && index < m_string_list_perrera_dest->get_n_items()) {
    return m_string_list_perrera_dest->get_string(index);
  };
}
