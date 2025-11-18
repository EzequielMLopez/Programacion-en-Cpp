// #include "buttons.h"
// #include "examplewindow.h"
// #include "radiobuttons.h"
// #include "examplewindows.h"
#include "glibmm/date.h"
#include "widgets_label.h"
#include <gtkmm/application.h>
/*
int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example");

  // Shows the window and returns when it is closed.
  return app->make_window_and_run<ToggleButton>(argc, argv);
}

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example");

  // Shows the window and returns when it is closed.
  return app->make_window_and_run<ExampleWindow>(argc, argv);
}

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example");

  // Shows the window and returns when it is closed.
  return app->make_window_and_run<RadioButtons>(argc, argv);
}

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example");

  // Shows the window and returns when it is closed.
  return app->make_window_and_run<ExampleWindow>(argc, argv);
}
*/

class PERRO {
public:
  int edad, fecha_ingreso, fecha_egreso;
  char nombre[20];
  PERRO *SIG;
  PERRO();
  ~PERRO();
};

class PERRERA {
public:
  char nombre[20], pais[20], provincia[20], localidad[20], direccion[20];
  int dir_num;
  PERRO *INIPE;
  PERRERA *SIG;
  PERRERA();
  ~PERRERA();
};

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example");

  // Shows the window and returns when it is closed.
  return app->make_window_and_run<ExampleWindow>(argc, argv);
}
