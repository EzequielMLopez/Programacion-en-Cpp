#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include "Clases.h"
#include "glibmm/ustring.h"
#include "gtkmm/columnview.h"
#include "gtkmm/liststore.h"
#include "gtkmm/window.h"
#include <gtkmm.h>
#include <string.h>

using namespace std;

// =========================
// ColumnView personalizado
// =========================
class MostrarPerrera : public Gtk::ColumnView {
public:
  MostrarPerrera();

  void cargar_desde_sucursal(const SUCURSAL& sucursal);

private:
  // ---- Modelo de columnas ----
  class ModelColumns : public Glib::Object {
  public:
    static Glib::RefPtr<ModelColumns> create(const std::string& nombre, const std::string& pais, const std::string& provincia,
                                             const std::string& partido, const std::string& localidad, const std::string& direccion, int altura);

    std::string nombre;
    std::string pais;
    std::string provincia;
    std::string partido;
    std::string localidad;
    std::string direccion;
    int altura;

  protected:
    ModelColumns(const std::string& nombre, const std::string& pais, const std::string& provincia, const std::string& partido,
                 const std::string& localidad, const std::string& direccion, int altura);
  };

  Glib::RefPtr<Gio::ListStore<ModelColumns>> m_ListStore;
  Glib::RefPtr<Gtk::SingleSelection> m_Selection;
};

// =========================
// Ventana contenedora
// =========================
class MostrarPerreraWindow : public Gtk::Window {
public:
  MostrarPerreraWindow();

  void cargar_desde_sucursal(const SUCURSAL& sucursal);

private:
  MostrarPerrera m_column_view;
  Gtk::ScrolledWindow m_scroll;
};

#endif // GTKMM_EXAMPLEWINDOW_H
