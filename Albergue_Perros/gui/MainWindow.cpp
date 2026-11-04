#include "MainWindow.h"
#include "AgregarPerrera.h"
#include "AgregarPerrito.h"
#include "MostrarPerrera.h"
#include "MostrarPerritos.h"
#include "Seleccionar_Perrera_Mostrar_Perritos.h"
#include "gtkmm/alertdialog.h"
#include "gtkmm/dialog.h"
#include "gtkmm/enums.h"
#include "gtkmm/messagedialog.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

AlbergueWindow::AlbergueWindow(SUCURSAL& back_agr_perre)
    : m_back_agr_perre(back_agr_perre), m_box_main(Gtk::Orientation::VERTICAL, 15), m_btn_agregar_perrera("1. Agregar Perrera"),
      m_btn_agregar_perrito("2. Agregar Perrito"), m_btn_mostrar_perreras("3. Mostrar Perreras"), m_btn_mostrar_perritos("4. Mostrar Perritos") {

  // Configuración básica de la ventana principal (Menú)
  set_title("Albergue de Perros - Menú Principal");
  set_default_size(400, 300);

  // Márgenes del contenedor principal tipo menú
  m_box_main.set_margin(20);

  // Añadir el botón al contenedor de la ventana
  m_box_main.append(m_btn_agregar_perrera);
  m_box_main.append(m_btn_agregar_perrito);
  m_box_main.append(m_btn_mostrar_perreras);
  m_box_main.append(m_btn_mostrar_perritos);

  // Conectar la señal del botón a nuestra función callback (equivalente a elegir la opción del menú)
  m_btn_agregar_perrera.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_agregar_perrera_clicked));
  m_btn_agregar_perrito.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_agregar_perrito_clicked));
  m_btn_mostrar_perreras.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_mostrar_perreras_clicked));
  m_btn_mostrar_perritos.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_mostrar_perritos_clicked));

  // Establecer el contenedor como hijo único de la ventana
  set_child(m_box_main);
}

void AlbergueWindow::on_boton_agregar_perrera_clicked() {
  Agregar_Perrera* dialog = new Agregar_Perrera(*this);

  dialog->signal_response().connect([this, dialog](int response_id) {
    if (response_id == static_cast<int>(Gtk::ResponseType::OK)) {

      std::string nombre = dialog->get_nombre();
      std::string pais = dialog->get_pais();
      std::string provincia = dialog->get_provincia();
      std::string partido = dialog->get_partido();
      std::string localidad = dialog->get_localidad();
      std::string direccion = dialog->get_direccion();
      int altura = dialog->get_altura();

      // Llamada al backend
      m_back_agr_perre.AGREGAR_PERRERA_GUI(nombre, pais, provincia, partido, localidad, direccion, altura);
    }

    // --- SOLUCIÓN AQUÍ ---
    // En lugar de solo hacer hide(), cerramos formalmente el diálogo
    // para que libere el bucle modal y devuelva el foco a la AlbergueWindow.
    dialog->hide();

    Glib::signal_idle().connect([dialog]() {
      delete dialog;
      return false;
    });
  });

  dialog->present();
}

void AlbergueWindow::on_boton_agregar_perrito_clicked() {
  // Obtenemos el nombre de las perreras desde el
  // std::vector<std::string> lista_perreras = m_back_agr_perre.OBTENER_NOMBRES_PERRERAS_GUI();
  std::vector<std::string> lista_perreras = m_back_agr_perre.OBTENER_NOMBRES_PERRERAS_GUI();

  // Validacion por si no hay perreras creadas
  if (lista_perreras.empty()) {
    std::cout << "[GUI] Advertencia: No hay perreras registradas.\n";
    // Opcional: podrías mostrar un Gtk::MessageDialog avisando que primero deben crear una perrera.
    auto dialogo = Gtk::AlertDialog::create("Operacion Negada!");
    dialogo->set_detail("Primero debe contar con una perrera donde asociar al canino ingresado.");
    return;
  }

  // Instanciamos el dialogo pasandole la lista para el DropDown
  Agregar_Perrito* dialog = new Agregar_Perrito(*this, lista_perreras);

  // Conectamos el callback
  dialog->signal_response().connect([this, dialog](int response_id) {
    if (response_id == static_cast<int>(Gtk::ResponseType::OK)) {
      std::string nombre = dialog->get_nombre();
      int edad = dialog->get_edad();
      std::string perrera_seleccionada = dialog->get_perrera();

      auto dialogo = Gtk::AlertDialog::create("Operacion Exitosa!");
      std::cout << "[DEBUG] Perrito: " << nombre << ", Edad: " << edad << ", Perrera: " << perrera_seleccionada << "\n";

      // Invocamos el metodo Backend para agregar al perrito
      m_back_agr_perre.AGREGAR_PERRITO_GUI(nombre, edad, perrera_seleccionada);
    }

    dialog->hide();
    Glib::signal_idle().connect([dialog]() {
      delete dialog;
      return false;
    });
  });

  dialog->present();
}

void AlbergueWindow::on_boton_mostrar_perreras_clicked() {
  std::vector<std::string> lista_perreras = m_back_agr_perre.OBTENER_DETALLES_PERRERAS_GUI();

  // Validacion por si no hay perreras creadas
  if (lista_perreras.empty()) {
    std::cout << "[GUI] Advertencia: No hay perreras registradas.\n";
    auto dialogo = Gtk::AlertDialog::create("Operacion Negada!");
    dialogo->set_detail("No hay perreras registradas para mostrar.");
    return;
  }

  // Creamos y presentamos el dialogo
  auto dialog = new Mostrar_Perreras(*this, lista_perreras);

  dialog->signal_response().connect([dialog](int /*response_id*/) {
    dialog->hide();

    Glib::signal_idle().connect([dialog]() {
      delete dialog;
      return false;
    });
  });

  dialog->present();
}

void AlbergueWindow::on_boton_mostrar_perritos_clicked() {
  std::vector<std::string> nombres_perreras = m_back_agr_perre.OBTENER_NOMBRES_PERRERAS_GUI();
  if (nombres_perreras.empty()) {
    std::cout << "[GUI] No hay perreras registradas para consultar.\n";
    return;
  }

  auto dialogo_seleccion = new Seleccionar_Perrera_Mostrar_Perritos(*this, nombres_perreras);

  dialogo_seleccion->signal_response().connect([this, dialogo_seleccion](int response_id) {
    if (response_id == static_cast<int>(Gtk::ResponseType::OK)) {
      std::string perrera_seleccionada = dialogo_seleccion->get_perrera_seleccionada();
      std::vector<std::string> lista_perritos = m_back_agr_perre.OBTENER_DETALLES_PERRITOS_GUI(perrera_seleccionada);

      // Validacion por si no hay perritos creados
      if (lista_perritos.empty()) {
        std::cout << "[GUI] Advertencia: No hay perritos registrados.\n";
        auto dialogo = Gtk::AlertDialog::create("Operacion Negada!");
        dialogo->set_detail("No hay perritos registrados para mostrar.");
        return;
      } else {

        // Creamos y presentamos el dialogo
        Mostrar_Perritos* dialog = new Mostrar_Perritos(*this, lista_perritos);

        dialog->signal_response().connect([dialog](int /*response_id*/) {
          dialog->hide();

          Glib::signal_idle().connect([dialog]() {
            delete dialog;
            return false;
          });
        });
        dialog->present();
      }
    }

    // Limpieza de memoria obligatoria para el diálogo de selección
    dialogo_seleccion->hide();
    Glib::signal_idle().connect([dialogo_seleccion]() {
      delete dialogo_seleccion;
      return false;
    });
  });

  dialogo_seleccion->present();
}
