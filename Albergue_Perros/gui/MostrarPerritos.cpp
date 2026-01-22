#include "MostrarPerritos.h"
#include "Clases.h"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtkmm/signallistitemfactory.h"
#include "gtkmm/singleselection.h"
#include <string>

// ===================================================
// MostrarPerritos::ModelColumns
// ===================================================
MostrarPerritos::ModelColumns::ModelColumns(const std::string& nombre_, int edad_) : nombre(nombre_), edad(edad_) {}

Glib::RefPtr<MostrarPerritos::ModelColumns> MostrarPerritos::ModelColumns::create(const std::string& nombre, int edad) {
  return Glib::make_refptr_for_instance<ModelColumns>(new ModelColumns(nombre, edad));
};
// ===================================================
// MostrarPerritos (ColumnView)
// ===================================================
MostrarPerritos::MostrarPerritos() {
  m_ListStore = Gio::ListStore<ModelColumns>::create();
  m_Selection = Gtk::SingleSelection::create(m_ListStore);
  set_model(m_Selection);

  // ---- Columnas ----
  auto factory = Gtk::SignalListItemFactory::create();
  auto factory_nombre = Gtk::SignalListItemFactory::create();
  auto factory_edad = Gtk::SignalListItemFactory::create();

  factory_nombre->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });
  factory_edad->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& item) { item->set_child(*Gtk::make_managed<Gtk::Label>()); });

  factory_nombre->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(row->nombre);
  });

  auto column = Gtk::ColumnViewColumn::create("Nombre", factory_nombre);
  append_column(column);

  factory_edad->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& item) {
    auto row = std::dynamic_pointer_cast<ModelColumns>(item->get_item());
    auto label = dynamic_cast<Gtk::Label*>(item->get_child());
    label->set_text(std::to_string(row->edad));
  });

  auto column6 = Gtk::ColumnViewColumn::create("Edad", factory_edad);
  append_column(column6);
}

void MostrarPerritos::cargar_desde_perrera(const SUCURSAL& sucursal) {
  m_ListStore->remove_all();

  PERRERA* actual = sucursal.getINICIO();

  while (actual != nullptr) {
    PERROS* perrito = actual->getINIP();

    while (perrito != nullptr) {
      m_ListStore->append(ModelColumns::create(perrito->getNombre(), perrito->getEdad()));
      perrito = perrito->getSIG();
    };

    actual = actual->getSIG();
  };
}

// ===================================================
// MostrarPerritosWindow
// ===================================================
MostrarPerritosWindow::MostrarPerritosWindow() {
  set_title("Listado de Perritos");

  set_default_size(900, 400);

  m_scroll.set_child(m_column_view);
  set_child(m_column_view);
}

void MostrarPerritosWindow::cargar_desde_perrera(const SUCURSAL& sucursal) { m_column_view.cargar_desde_perrera(sucursal); }
