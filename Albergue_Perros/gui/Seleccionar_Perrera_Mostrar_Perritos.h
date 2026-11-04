#ifndef GTKMM_SELECCIONAR_PERRERA_MOSTRAR_PERRITOS_H
#define GTKMM_SELECCIONAR_PERRERA_MOSTRAR_PERRITOS_H

#include "glibmm/refptr.h"
#include "gtkmm/dialog.h"
#include "gtkmm/dropdown.h"
#include "gtkmm/stringlist.h"
#include <gtkmm.h>
#include <string>
#include <vector>

class Seleccionar_Perrera_Mostrar_Perritos : public Gtk::Dialog {
private:
  Gtk::Grid grid;
  Gtk::Label lbl_perrera{"Seleccionar Perrera"};
  Gtk::DropDown drop_d;
  Glib::RefPtr<Gtk::StringList> m_string_list;

public:
  Seleccionar_Perrera_Mostrar_Perritos(Gtk::Window& parent, const std::vector<std::string>& nombres_perreras);
  ~Seleccionar_Perrera_Mostrar_Perritos();

  std::string get_perrera_seleccionada() const;
};

#endif // !GTKMM_SELECCIONAR_PERRERA_MOSTRAR_PERRITOS_H
