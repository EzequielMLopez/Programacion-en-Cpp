#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include "Clases.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class MainWindow : public Gtk::Window {

public:
  MainWindow();
  ~MainWindow() override;

protected:
  // Signal handlers:
  void On_Agregar_Perrera();
  void On_Mostrar_Perreras();
  void On_Salir();
  void On_Cancel();

  // Member widgets:
  Gtk::Box v_HBox{Gtk::Orientation::VERTICAL};
  Gtk::Button Agregar_Perrera_button;
  Gtk::Button Mostrar_Perreras_button;
  Gtk::Button Salir_button;

  SUCURSAL sistema;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H
