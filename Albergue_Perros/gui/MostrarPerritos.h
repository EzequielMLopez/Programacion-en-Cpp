#ifndef GTKMM_MOSTRARPERRITOS_H
#define GTKMM_MOSTRARPERRITOS_H

#include "Clases.h"
#include "glibmm/refptr.h"
#include "gtkmm.h"
#include "gtkmm/singleselection.h"
#include "gtkmm/stringlist.h"
#include <vector>

using namespace std;

class Mostrar_Perritos : public Gtk::Dialog {
private:
  Gtk::ScrolledWindow scrolled_window;
  Gtk::ListView list_view;
  Glib::RefPtr<Gtk::StringList> m_string_list;
  Glib::RefPtr<Gtk::SignalListItemFactory> m_factory;
  Glib::RefPtr<Gtk::SingleSelection> m_selection_model;

public:
  Mostrar_Perritos(Gtk::Window& parent, const std::vector<std::string>& detalles_perritos);
  ~Mostrar_Perritos();
};

#endif // GTKMM_MOSTRARPERRITOS_H
