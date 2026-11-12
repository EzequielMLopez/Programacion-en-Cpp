#include "Seleccionar_Perrito_Modificar_Perrito.h"
#include "Clases.h"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtkmm/stringlist.h"
#include <iostream>
#include <string>
#include <vector>

SeleccionarPerritoModificar::SeleccionarPerritoModificar(Gtk::Window& parent, SUCURSAL& backend, const std::vector<std::string>& nombres_perreras)
    : Seleccionador(parent, "Seleccionador ", nombres_perreras, backend) {

  // Creamos una lambda local para reutilizar la lógica de actualización
  auto actualizar_perritos = [this]() {
    std::string perrera_sel = get_perrera_seleccionada();
    if (perrera_sel.empty()) {
      m_string_list_perritos = Gtk::StringList::create({});
      drop_d_perritos.set_model(m_string_list_perritos);
      return;
    }

    // Pedimos al backend los perritos correspondientes a la perrera elegida
    std::vector<std::string> perritos = m_backend.OBTENER_NOMBRES_PERRITOS_GUI(perrera_sel);

    std::cout << "PERRERA SELECCIONADA: " << perrera_sel << " CANTIDAD DE PERRITOS: " << perritos.size() << std::endl;

    std::vector<Glib::ustring> ustring_perritos;
    for (const auto& p : perritos)
      ustring_perritos.push_back(p);

    m_string_list_perritos = Gtk::StringList::create(ustring_perritos);
    drop_d_perritos.set_model(m_string_list_perritos);

    // Seleccionamos el primer perrito por defecto si la lista no está vacía
    if (!ustring_perritos.empty()) {
      drop_d_perritos.set_selected(0);
    }
  };

  // 1. Conectamos la señal en cascada ESCUCHANDO AL PADRE (drop_d_perrera)
  drop_d_perrera.property_selected().signal_changed().connect([actualizar_perritos]() { actualizar_perritos(); });

  // 2. Agregamos el segundo selector en la fila 1 de la grilla heredada
  grid.attach(lbl_perritos, 0, 1);
  grid.attach(drop_d_perritos, 1, 1);

  // 3. CARGA INICIAL: Forzamos el índice 0 en el padre y llamamos a la función de inmediato
  if (!nombres_perreras.empty()) {
    drop_d_perrera.set_selected(0);
    actualizar_perritos(); // Garantiza que los perritos carguen en pantalla al abrir el diálogo
  }
}

std::string SeleccionarPerritoModificar::get_perrito_seleccionado() const {
  // 1. Obtenemos el índice numérico seleccionado en el DropDown del hijo
  guint index = drop_d_perritos.get_selected();

  // Si no hay selección válida, retornamos vacío
  if (index == GTK_INVALID_LIST_POSITION) {
    return "";
  }

  // 2. Extraemos el string de forma segura usando el StringList del hijo
  if (m_string_list_perritos && index < m_string_list_perritos->get_n_items()) {
    return m_string_list_perritos->get_string(index);
  }

  return "";
}

void SeleccionarPerritoModificar::actualizar_lista_perritos(const std::string& perrera_sel) {
  if (perrera_sel.empty()) {
    drop_d_perritos.set_model(Glib::RefPtr<Gtk::StringList>());
    return;
  }

  // Limpiamos el modelo actual
  drop_d_perritos.set_model(Glib::RefPtr<Gtk::StringList>());

  // Pedimos los datos frescos al backend usando la perrera que nos pasaron por parámetro
  std::vector<std::string> perritos = m_backend.OBTENER_NOMBRES_PERRITOS_GUI(perrera_sel);

  std::vector<Glib::ustring> perritos_ustring;
  for (const auto& perrito : perritos) {
    perritos_ustring.push_back(perrito);
  }

  m_string_list_perritos = Gtk::StringList::create(perritos_ustring);
  drop_d_perritos.set_model(m_string_list_perritos);

  if (!perritos_ustring.empty()) {
    drop_d_perritos.set_selected(0);
  } else {
    drop_d_perritos.set_selected(GTK_INVALID_LIST_POSITION);
  }
}
