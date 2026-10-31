#ifndef GTKMM_MOSTRARPERRITOS_H
#define GTKMM_MOSTRARPERRITOS_H

#include "Clases.h"
#include "giomm/liststore.h"
#include "glibmm/refptr.h"
#include "gtkmm.h"
#include "gtkmm/columnview.h"
#include "gtkmm/scrolledwindow.h"
#include "gtkmm/singleselection.h"
#include "gtkmm/window.h"

using namespace std;

// =========================
// ColumnView personalizado
// =========================
class MostrarPerritos : public Gtk::ColumnView {
public:
  MostrarPerritos();

  void cargar_desde_perrera(const SUCURSAL& sucursal);

private:
  // ---- Modelo de columnas ----
  class ModelColumns : public Glib::Object {
  public:
    static Glib::RefPtr<ModelColumns> create(const std::string& nombre, int edad);

    std::string nombre;
    int edad;

  protected:
    ModelColumns(const std::string& nombre, int edad);
  };

  Glib::RefPtr<Gio::ListStore<ModelColumns>> m_ListStore;
  Glib::RefPtr<Gtk::SingleSelection> m_Selection;
};

// =========================
// Ventana contenedora
// =========================
class MostrarPerritosWindow : public Gtk::Window {
public:
  MostrarPerritosWindow();

  void cargar_desde_perrera(const SUCURSAL& sucursal);

private:
  MostrarPerritos m_column_view;
  Gtk::ScrolledWindow m_scroll;
};

#endif
