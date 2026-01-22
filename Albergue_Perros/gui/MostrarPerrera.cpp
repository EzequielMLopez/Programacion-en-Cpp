#include "MostrarPerrera.h"
#include "Clases.h"
#include "glibmm/ustring.h"
#include "gtk/gtk.h"
#include <string>

// ===================================================
// MostrarPerrera::ModelColumns
// ===================================================
MostrarPerrera::ModelColumns::ModelColumns(const std::string& nombre_, const std::string& pais_, const std::string& provincia_,
                                           const std::string& partido_, const std::string& localidad_, const std::string& direccion_, int altura_)
    : nombre(nombre_), pais(pais_), provincia(provincia_), partido(partido_), localidad(localidad_), direccion(direccion_), altura(altura_) {}

Glib::RefPtr<MostrarPerrera::ModelColumns> MostrarPerrera::ModelColumns::create(const std::string& nombre, const std::string& pais,
                                                                                const std::string& provincia, const std::string& partido,
                                                                                const std::string& localidad, const std::string& direccion,
                                                                                int altura) {
  return Glib::make_refptr_for_instance<ModelColumns>(new ModelColumns(nombre, pais, provincia, partido, localidad, direccion, altura));
}

// ===================================================
// MostrarPerrera (ColumnView)
// ===================================================
MostrarPerrera::MostrarPerrera() {
  m_ListStore = Gio::ListStore<ModelColumns>::create();
  m_Selection = Gtk::SingleSelection::create(m_ListStore);
  set_model(m_Selection);

  // ---- Columnas ----
  auto factory = Gtk::SignalListItemFactory::create();
  auto factory_nombre = Gtk::SignalListItemFactory::create();
  auto factory_pais = Gtk::SignalListItemFactory::create();
  auto factory_provincia = Gtk::SignalListItemFactory::create();
  auto factory_partido = Gtk::SignalListItemFactory::create();
  auto factory_localidad = Gtk::SignalListItemFactory::create();
  auto factory_direccion = Gtk::SignalListItemFactory::create();
  auto factory_altura = Gtk::SignalListItemFactory::create();

  factory_nombre->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });
  factory_pais->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });
  factory_provincia->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });
  factory_partido->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });
  factory_localidad->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });
  factory_direccion->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });
  factory_altura->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });

  factory_nombre->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(row->nombre);
  });

  auto column = Gtk::ColumnViewColumn::create("Nombre", factory_nombre);
  append_column(column);

  factory_pais->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(row->pais);
  });

  auto column1 = Gtk::ColumnViewColumn::create("Pais", factory_pais);
  append_column(column1);

  factory_provincia->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(row->provincia);
  });

  auto column2 = Gtk::ColumnViewColumn::create("Provincia", factory_provincia);
  append_column(column2);

  factory_partido->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(row->partido);
  });

  auto column3 = Gtk::ColumnViewColumn::create("Partido", factory_partido);
  append_column(column3);

  factory_localidad->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(row->localidad);
  });

  auto column4 = Gtk::ColumnViewColumn::create("Localidad", factory_localidad);
  append_column(column4);

  factory_direccion->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(row->direccion);
  });

  auto column5 = Gtk::ColumnViewColumn::create("Direccion", factory_direccion);
  append_column(column5);

  factory_altura->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(std::to_string(row->altura));
  });

  auto column6 = Gtk::ColumnViewColumn::create("Altura", factory_altura);
  append_column(column6);
}

void MostrarPerrera::cargar_desde_sucursal(const SUCURSAL& sucursal) {
  m_ListStore->remove_all();

  PERRERA* actual = sucursal.getINICIO();

  while (actual != nullptr) {
    m_ListStore->append(ModelColumns::create(actual->getNombre(), actual->getPais(), actual->getProvincia(), actual->getPartido(),
                                             actual->getLocalidad(), actual->getDireccion(), actual->getAltura()));

    actual = actual->getSIG();
  }
}

// ===================================================
// MostrarPerreraWindow
// ===================================================
MostrarPerreraWindow::MostrarPerreraWindow() {
  set_title("Listado de Perreras");
  set_default_size(900, 400);

  m_scroll.set_child(m_column_view);
  set_child(m_scroll);
}

void MostrarPerreraWindow::cargar_desde_sucursal(const SUCURSAL& sucursal) { m_column_view.cargar_desde_sucursal(sucursal); }
