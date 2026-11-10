#include "MostrarPerrera.h"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtkmm/entry.h"
#include "gtkmm/enums.h"
#include "gtkmm/label.h"
#include "gtkmm/object.h"
#include "gtkmm/signallistitemfactory.h"
#include "gtkmm/singleselection.h"
#include "gtkmm/stringlist.h"
#include "gtkmm/stringobject.h"
#include <memory>
#include <string>
#include <vector>

Mostrar_Perreras::Mostrar_Perreras(Gtk::Window& parent, const std::vector<std::string>& detalles_perreras)
    : Gtk::Dialog("Listado de Perreras", parent) {

  set_default_size(550, 350);

  // Convertimos el vector de std::string a Glib::ustring que es lo que exige Gtk::StringList
  std::vector<Glib::ustring> vec_det_perreras;
  for (const auto& det : detalles_perreras) {
    vec_det_perreras.push_back(det);
  }

  // Creamos el modelo de lista con los nombres
  m_string_list = Gtk::StringList::create(vec_det_perreras);

  // Lo empaquetamos dentro de un SingleSelection
  m_selection_model = Gtk::SingleSelection::create(m_string_list);

  // Creacion de los factory para decirle a Gtk como mostrar cada fila (usando un label)
  m_factory = Gtk::SignalListItemFactory::create();

  // Se lo configura para usar Labels
  m_factory->signal_setup().connect([](const std::shared_ptr<Gtk::ListItem>& list_item) {
    auto label = Gtk::make_managed<Gtk::Label>();
    label->set_halign(Gtk::Align::START);
    label->set_margin_start(8);
    label->set_margin_top(8);    // Margen superior para que las filas "respiren"
    label->set_margin_bottom(8); // Margen inferior
    list_item->set_child(*label);
  });

  // Enlaza los datos del modelo con las celdas (label)
  m_factory->signal_bind().connect([](const std::shared_ptr<Gtk::ListItem>& list_item) {
    // Obtenemos el widget hijo como un Gtk::Label normal
    auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());

    // Obtenemos el objeto de texto correspondiente a esta fila
    auto str_object = std::dynamic_pointer_cast<const Gtk::StringObject>(list_item->get_item());
    if (label && str_object) {
      label->set_text(str_object->get_string());
    };
  });

  // Configuramos el ListView con el modelo (StringList) y el factory (SingalListItemFactory)
  list_view.set_model(m_selection_model);
  list_view.set_factory(m_factory);

  // Metemos el ListView dentro de una ventana con desplazamiento (ScrolledWindow)
  scrolled_window.set_child(list_view);
  scrolled_window.set_vexpand(true);
  scrolled_window.set_hexpand(true);
  scrolled_window.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);

  // Añadimos el componente al área de contenido del diálogo
  auto content_area = get_content_area();
  content_area->set_margin(12);
  content_area->append(scrolled_window);

  // Botón de cierre
  add_button("OK", Gtk::ResponseType::OK);

  set_size_request();
}

Mostrar_Perreras::~Mostrar_Perreras() {
  // No es necesario liberar memoria manualmente, ya que Gtk::Dialog y sus hijos se encargan de ello.
}
