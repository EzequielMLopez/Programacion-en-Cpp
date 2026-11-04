#include "Clases.h"
#include "Funciones_Main.h"
#include "MainWindow.h"
#include <cstdlib>
#include <cstring>
#include <gtkmm.h>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  // 1. Crear la instancia de la aplicacion GTK
  auto app = Gtk::Application::create("org.gtkmm.albergue_perros");

  // Instanciamos la clase de la logica (backend)
  SUCURSAL agregar_perrera;

  // Instanciar nuestra ventana principal y ejecucion del bucle
  /* AlbergueWindow window(agregar_perrera);
  app->add_window(window);
  window.present(); */

  // return app->run(argc, argv);

  return app->make_window_and_run<AlbergueWindow>(argc, argv, agregar_perrera);
}
