#include "MainWindow.h"
#include "AddPerreraDialog.h"
#include "Clases.h"
#include "MostrarPerrera.h"
#include "gtkmm/dialog.h"
#include "gtkmm/object.h"
#include "gtkmm/window.h"

using namespace std;

MainWindow::MainWindow()
    : Agregar_Perrera_button("Agregar Perrera"), Mostrar_Perreras_button("Mostrar Perreras"),
      Salir_button("Salir") // creates a new button with label "Hello World".
{
  // Sets the margin around the button.
  Agregar_Perrera_button.set_margin(10);
  Mostrar_Perreras_button.set_margin(10);
  Salir_button.set_margin(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  Agregar_Perrera_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::On_Agregar_Perrera));
  Mostrar_Perreras_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::On_Mostrar_Perreras));
  Salir_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::On_Salir));

  // This packs the button into the Window (a container).
  v_HBox.append(Agregar_Perrera_button);
  v_HBox.append(Mostrar_Perreras_button);
  v_HBox.append(Salir_button);
  set_child(v_HBox);
}

MainWindow::~MainWindow() {}

void MainWindow::On_Agregar_Perrera() {
  auto dialog = new AddPerreraDialog(*this);

  dialog->signal_response().connect([this, dialog](int response) {
    if (response == Gtk::ResponseType::OK) {
      string nombre = dialog->get_nombre();
      string pais = dialog->get_pais();
      string provincia = dialog->get_provincia();
      string partido = dialog->get_partido();
      string localidad = dialog->get_localidad();
      string direccion = dialog->get_direccion();
      int altura = dialog->get_altura();

      sistema.AGREGAR_PERRERA_GUI(nombre, pais, provincia, partido, localidad, direccion, altura);
    }
    dialog->hide();
    delete dialog;
  });

  dialog->show();
}

void MainWindow::On_Mostrar_Perreras() {
  auto mostrar = new MostrarPerreraWindow();
  mostrar->cargar_desde_sucursal(sistema);
  mostrar->present();
}

void MainWindow::On_Salir() { close(); }
