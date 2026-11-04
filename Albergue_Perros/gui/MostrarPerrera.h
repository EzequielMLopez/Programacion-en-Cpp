#ifndef GTKMM_MOSTRAR_PERRERAS_H
#define GTKMM_MOSTRAR_PERRERAS_H

#include "glibmm/refptr.h"
#include "gtkmm/dialog.h"
#include "gtkmm/listview.h"
#include "gtkmm/scrolledwindow.h"
#include "gtkmm/signallistitemfactory.h"
#include "gtkmm/stringlist.h"
#include <gtkmm.h>
#include <vector>

class Mostrar_Perreras : public Gtk::Dialog {
private:
  Gtk::ScrolledWindow scrolled_window;
  Gtk::ListView list_view;
  Glib::RefPtr<Gtk::StringList> m_string_list;
  Glib::RefPtr<Gtk::SignalListItemFactory> m_factory;
  Glib::RefPtr<Gtk::SingleSelection> m_selection_model;

public:
  Mostrar_Perreras(Gtk::Window& parent, const std::vector<std::string>& detalles_perreras);
  ~Mostrar_Perreras();
};
#endif // GTKMM_MOSTRAR_PERRERAS_H
