#include "Seleccionadores.h" // O el nombre de tu archivo .h
#include "Clases.h"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtk/gtkshortcut.h"
#include "gtkmm/stringlist.h"
#include <algorithm>
#include <string>
#include <vector>

Seleccionador::Seleccionador(Gtk::Window& parent, const std::string& titulo, const std::vector<std::string>& nombres_perreras, SUCURSAL& backend)
    : Gtk::Dialog(titulo, parent), m_backend(backend) {

  set_default_size(450, 250);

  // 1. Convertir y configurar el primer dropdown genérico
  std::vector<Glib::ustring> ustring_list;
  for (const auto& name : nombres_perreras) {
    ustring_list.push_back(name);
  }
  m_string_list_perrera = Gtk::StringList::create(ustring_list);
  drop_d_perrera.set_model(m_string_list_perrera);
  lbl_perrera.set_text("Perrera: ");

  // 2. Configurar y poblar la grilla base
  grid.set_margin(15);
  grid.set_row_spacing(10);
  grid.set_column_spacing(10);

  // Adjuntamos la etiqueta y el dropdown de perreras en la fila 0
  grid.attach(lbl_perrera, 0, 0);
  grid.attach(drop_d_perrera, 1, 0);

  // Añadimos la grilla al área de contenido del diálogo
  get_content_area()->append(grid);

  // 3. Botones estándar
  add_button("OK", Gtk::ResponseType::OK);
  add_button("Cancelar", Gtk::ResponseType::CANCEL);
}

std::string Seleccionador::get_perrera_seleccionada() const {
  // 1. Obtenemos el índice numérico seleccionado en el DropDown
  guint index = drop_d_perrera.get_selected();

  // Si no hay selección válida, retornamos vacío
  if (index == GTK_INVALID_LIST_POSITION) {
    return "";
  }

  // 2. Como m_string_list_perrera ya lo tenemos guardado en la clase,
  // le pedimos el string directamente por su índice sin castear nada.
  if (m_string_list_perrera && index < m_string_list_perrera->get_n_items()) {
    return m_string_list_perrera->get_string(index);
  }

  return "";
}

void Seleccionador::actualizar_lista_perreras() {
  // Limpiamos el modelo actual
  drop_d_perrera.set_model(Glib::RefPtr<Gtk::StringList>());

  // Pedimos los datos frescos al backend
  std::vector<std::string> perreras = m_backend.OBTENER_NOMBRES_PERRERAS_GUI();

  std::vector<Glib::ustring> perreras_ustring;
  for (const auto& perrera : perreras) {
    perreras_ustring.push_back(perrera);
  }

  m_string_list_perrera = Gtk::StringList::create(perreras_ustring);
  drop_d_perrera.set_model(m_string_list_perrera);

  if (!perreras_ustring.empty()) {
    drop_d_perrera.set_selected(0);
  } else {
    drop_d_perrera.set_selected(GTK_INVALID_LIST_POSITION);
  }
}
