#ifndef GTKMM_AGREGAR_PERRITO_H
#define GTKMM_AGREGAR_PERRITO_H

#include "glibmm/refptr.h"
#include "gtkmm.h"
#include "gtkmm/button.h"
#include "gtkmm/dropdown.h"
#include "gtkmm/stringlist.h"
#include <vector>

class Agregar_Perrito : public Gtk::Dialog {
private:
  Gtk::Grid grid;
  Gtk::Entry entry_nombre;
  Gtk::Entry entry_edad;
  Gtk::DropDown drop_d;

  // Model de datos para el Drop_Down
  Glib::RefPtr<Gtk::StringList> m_string_list;

  Gtk::Label lbl_nombre;
  Gtk::Label lbl_edad;
  Gtk::Label lbl_perrera;

public:
  Agregar_Perrito(Gtk::Window& parent, const std::vector<std::string>& nombres_perreras);
  ~Agregar_Perrito();

  std::string get_nombre() const;
  std::string get_perrera() const;
  int get_edad() const;
};

#endif // GTKMM_AGREGAR_PERRITO_H
