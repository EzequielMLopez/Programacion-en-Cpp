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

int main(int argc, char** argv, char** envp) {
  auto app = Gtk::Application::create("com.perrera.app");
  return app->make_window_and_run<MainWindow>(argc, argv);
}
