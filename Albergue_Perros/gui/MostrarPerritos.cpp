#include "MostrarPerritos.h"
#include "Clases.h"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtkmm/enums.h"
#include "gtkmm/error.h"
#include "gtkmm/label.h"
#include "gtkmm/listitem.h"
#include "gtkmm/object.h"
#include "gtkmm/signallistitemfactory.h"
#include "gtkmm/singleselection.h"
#include "gtkmm/stringlist.h"
#include "gtkmm/stringobject.h"
#include <memory>
#include <string>
#include <vector>

Mostrar_Perritos::Mostrar_Perritos(Gtk::Window& parent, const std::vector<std::string>& detalles_perritos)
    : Gtk::Dialog("Listado de Perritos", parent) {
  set_default_size(450, 300);

  // Convertimos el vector de std::string a Glib::ustring que es lo que exige Gtk::StringList
  std::vector<Glib::ustring> vec_det_perritos;
  for (const auto& det : detalles_perritos) {
    vec_det_perritos.push_back(det);
  }

  // Creamos el modelo de lista con los detalles de los perritos
  m_string_list = Gtk::StringList::create(vec_det_perritos);

  // Lo empaquetamos dentro de un SingleSelection
  m_selection_model = Gtk::SingleSelection::create(m_string_list);

  // Creacion de los factory para decirle a Gtk como mostrar cada fila (usando un label)
  m_factory = Gtk::SignalListItemFactory::create();

  // Se lo configura para usar Labels
  m_factory->signal_setup().connect([](const std::shared_ptr<Gtk::ListItem>& list_item) {
    auto label = Gtk::make_managed<Gtk::Label>();
    label->set_halign(Gtk::Align::START);
    label->set_valign(Gtk::Align::START);
    list_item->set_child(*label);
  });

  // Enlaza los datos del modelo con las celdas (label)
  m_factory->signal_bind().connect([](const std::shared_ptr<Gtk::ListItem>& list_item) {
    // Obtenemos el widget hijo como un Gtk::Label normal
    auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());

    // Obtenemos el objeto de texto correspondiente a la fila
    auto str_object = std::dynamic_pointer_cast<const Gtk::StringObject>(list_item->get_item());
    if (label && str_object) {
      label->set_text(str_object->get_string());
    }
  });

  // Configuramos el ListView con el modelo (StringList) y el factory (SignalListItemFactory)
  list_view.set_model(m_selection_model);
  list_view.set_factory(m_factory);

  // Metemos el ListView dentro de una ventana con desplazamiento (ScrolledWindow)
  scrolled_window.set_child(list_view);
  scrolled_window.get_vexpand();
  scrolled_window.get_hexpand();
  scrolled_window.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);

  // Añadimos el componente al área de contenido del diálogo
  get_content_area()->append(scrolled_window);

  // Botón de cierre
  add_button("Cerrar", Gtk::ResponseType::CLOSE);
};

Mostrar_Perritos::~Mostrar_Perritos() {
  // No es necesario liberar memoria manualmente, ya que Gtk::Dialog y sus hijos se encargan de ello.
}
