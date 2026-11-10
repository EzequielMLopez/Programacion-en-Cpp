#include "MainWindow.h"
#include "AgregarPerrera.h"
#include "AgregarPerrito.h"
#include "ModificarPerrera.h"
#include "ModificarPerrito.h"
#include "MostrarPerrera.h"
#include "MostrarPerritos.h"
#include "Seleccionadores.h"
#include "Seleccionar_Perrito_Modificar_Perrito.h"
#include "giomm/asyncresult.h"
#include "glibmm/refptr.h"
#include "gtk/gtkconstraintguide.h"
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
      m_btn_agregar_perrito("2. Agregar Perrito"), m_btn_mostrar_perreras("3. Mostrar Perreras"), m_btn_mostrar_perritos("4. Mostrar Perritos"),
      m_btn_modificar_perrera("5. Modificar Perrera"), m_btn_modificar_perrito("6. Modificar Perrito"), m_btn_eliminar_perrera("6. Eliminar Perrera"),
      m_btn_eliminar_perrito("7. Eliminar Perrito") {

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
  m_box_main.append(m_btn_modificar_perrera);
  m_box_main.append(m_btn_modificar_perrito);
  m_box_main.append(m_btn_eliminar_perrera);

  // Conectar la señal del botón a nuestra función callback (equivalente a elegir la opción del menú)
  m_btn_agregar_perrera.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_agregar_perrera_clicked));
  m_btn_agregar_perrito.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_agregar_perrito_clicked));
  m_btn_mostrar_perreras.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_mostrar_perreras_clicked));
  m_btn_mostrar_perritos.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_mostrar_perritos_clicked));
  m_btn_modificar_perrera.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_modificar_perrera_clicked));
  m_btn_modificar_perrito.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_modificar_perrito_clicked));
  m_btn_eliminar_perrera.signal_clicked().connect(sigc::mem_fun(*this, &AlbergueWindow::on_boton_eliminar_perrera_clicked));

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
  std::vector<std::string> lista_perreras = m_back_agr_perre.MOSTRAR_DETALLES_PERRERAS_GUI();

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

  auto dialogo_seleccion = new Seleccionador(*this, "Seleccionador Perrera", nombres_perreras, m_back_agr_perre);

  dialogo_seleccion->signal_response().connect([this, dialogo_seleccion](int response_id) {
    if (response_id == static_cast<int>(Gtk::ResponseType::OK)) {
      std::string perrera_seleccionada = dialogo_seleccion->get_perrera_seleccionada();
      std::vector<std::string> lista_perritos = m_back_agr_perre.MOSTRAR_DETALLES_PERRITOS_GUI(perrera_seleccionada);

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

void AlbergueWindow::on_boton_modificar_perrera_clicked() {
  // Si ya hay un proceso abierto, ignoramos cualquier Enter o clic fantasma
  if (m_proceso_activo) {
    return;
  }
  m_proceso_activo = true; // Bloqueamos nuevas ejecuciones

  std::vector<std::string> nombres_perreras = m_back_agr_perre.OBTENER_NOMBRES_PERRERAS_GUI();
  if (nombres_perreras.empty()) {
    std::cout << "[GUI] No hay perreras registradas para consultar.\n";
    m_proceso_activo = false; // Liberamos el bloqueo si salimos temprano
    return;
  }

  auto dialogo_seleccion = new Seleccionador(*this, "Seleccionador Perrera", nombres_perreras, m_back_agr_perre);

  dialogo_seleccion->signal_response().connect([this, dialogo_seleccion](int response_id) {
    if (response_id == static_cast<int>(Gtk::ResponseType::OK)) {
      std::string perrera_seleccionada = dialogo_seleccion->get_perrera_seleccionada();
      dialogo_seleccion->hide();

      std::vector<std::string> det_perrera = m_back_agr_perre.OBTENER_DETALLES_PERRERA_GUI(perrera_seleccionada);

      if (!det_perrera.empty() && det_perrera.size() >= 7) {
        std::string nombre_actual = det_perrera[0];
        std::string pais_actual = det_perrera[1];
        std::string prov_actual = det_perrera[2];
        std::string part_actual = det_perrera[3];
        std::string loc_actual = det_perrera[4];
        std::string dir_actual = det_perrera[5];
        int alt_actual = std::stoi(det_perrera[6]);

        // Abrimos el formulario de modificacion
        auto dialog_mod =
            new ModificarPerrera(*dialogo_seleccion, nombre_actual, pais_actual, prov_actual, part_actual, loc_actual, dir_actual, alt_actual);

        dialog_mod->signal_response().connect([this, dialogo_seleccion, dialog_mod, perrera_seleccionada](int resp_mod) {
          dialog_mod->hide();

          if (resp_mod == static_cast<int>(Gtk::ResponseType::OK)) {
            std::string nuevo_nombre = dialog_mod->get_nombre();
            std::string nuevo_pais = dialog_mod->get_pais();
            std::string nueva_prov = dialog_mod->get_provincia();
            std::string nuevo_part = dialog_mod->get_partido();
            std::string nueva_loc = dialog_mod->get_localidad();
            std::string nueva_dir = dialog_mod->get_direccion();
            int nueva_alt = dialog_mod->get_altura();

            m_back_agr_perre.MODIFICAR_PERRERA_GUI(perrera_seleccionada, nuevo_nombre, nuevo_pais, nueva_prov, nuevo_part, nueva_loc, nueva_dir,
                                                   nueva_alt);

            std::cout << "[GUI] Perrera modificada con éxito.\n";
          }

          Glib::signal_idle().connect([dialog_mod]() {
            delete dialog_mod;
            return false;
          });
          dialogo_seleccion->actualizar_lista_perreras();
          dialogo_seleccion->present();
        });

        dialog_mod->present();
      }
    } else {
      // Si el usuario canceló el diálogo de selección de perreras:
      dialogo_seleccion->hide();
      Glib::signal_idle().connect([this, dialogo_seleccion]() {
        delete dialogo_seleccion;
        m_proceso_activo = false; // <--- LIBERAMOS EL BLOQUEO SI CANCELA
        return false;
      });
    }
  });

  dialogo_seleccion->present();
}

void AlbergueWindow::on_boton_modificar_perrito_clicked() {
  // Si ya hay un proceso abierto, ignoramos cualquier Enter o clic fantasma
  if (m_proceso_activo) {
    return;
  }

  m_proceso_activo = true; // Bloqueamos nuevas ejecuciones

  std::vector<std::string> nombres_perreras = m_back_agr_perre.OBTENER_NOMBRES_PERRERAS_GUI();
  if (nombres_perreras.empty()) {
    std::cout << "[GUI] No hay perreras registradas para consultar.\n";
    m_proceso_activo = false; // Liberamos el bloqueo si salimos temprano
    return;
  }

  auto dialogo_perrito = new SeleccionarPerritoModificar(*this, m_back_agr_perre, nombres_perreras);

  dialogo_perrito->signal_response().connect([this, dialogo_perrito](int response_id) {
    if (response_id == static_cast<int>(Gtk::ResponseType::OK)) {
      // 1. Ocultamos el selector temporalmente (NO LO BORRAMOS)

      std::string perrera_seleccionada = dialogo_perrito->get_perrera_seleccionada();
      std::string perrito_seleccionado = dialogo_perrito->get_perrito_seleccionado();

      dialogo_perrito->hide();

      std::vector<std::string> det_perrito = m_back_agr_perre.OBTENER_DETALLES_PERRITOS_GUI(perrera_seleccionada, perrito_seleccionado);
      std::string nombre_actual = det_perrito[0];
      int edad_actual = std::stoi(det_perrito[1]);

      // 2. Abrimos el formulario de modificación
      auto dialogo_mod = new ModificarPerrito(*this, nombre_actual, edad_actual);

      dialogo_mod->signal_response().connect([this, dialogo_perrito, dialogo_mod, perrera_seleccionada, perrito_seleccionado](int resp_mod) {
        dialogo_mod->hide();

        if (resp_mod == static_cast<int>(Gtk::ResponseType::OK)) {
          std::string nuevo_nombre = dialogo_mod->get_nombre();
          int nueva_edad = dialogo_mod->get_edad();

          m_back_agr_perre.MODIFICAR_PERRITO_GUI(perrera_seleccionada, perrito_seleccionado, nuevo_nombre, nueva_edad);

          std::cout << "[GUI] Perrito modificado con éxito.\n";
        }

        // 3. Borramos únicamente el formulario de modificación de forma segura
        Glib::signal_idle().connect([dialogo_mod]() {
          delete dialogo_mod;
          return false;
        });

        // 4. AQUÍ ESTÁ EL TRUCO: Volvemos a mostrar el selector de perritos en lugar de salir al menú
        dialogo_perrito->actualizar_lista_perritos(perrera_seleccionada);
        dialogo_perrito->present();
      });

      dialogo_mod->present();

    } else {
      // 5. El selector de perritos se cierra y libera todo ÚNICAMENTE si el usuario presiona Cancelar aquí
      dialogo_perrito->hide();
      Glib::signal_idle().connect([this, dialogo_perrito]() {
        delete dialogo_perrito;
        m_proceso_activo = false;
        return false;
      });
    }
  });

  dialogo_perrito->present();
}

void AlbergueWindow ::on_boton_eliminar_perrera_clicked() {
  // Si ya hay un proceso abierto, ignoramos cualquier Enter o clic fantasma
  if (m_proceso_activo) {
    return;
  }
  m_proceso_activo = true; // Bloqueamos nuevas ejecuciones

  std::vector<std::string> nombres_perreras = m_back_agr_perre.OBTENER_NOMBRES_PERRERAS_GUI();
  if (nombres_perreras.empty()) {
    std::cout << "[GUI] No hay perreras registradas para consultar.\n";
    m_proceso_activo = false; // Liberamos el bloqueo si salimos temprano
    return;
  }

  auto dialogo_seleccion = new Seleccionador(*this, "Seleccionador Perrera", nombres_perreras, m_back_agr_perre);

  dialogo_seleccion->signal_response().connect([this, dialogo_seleccion](int response_id) {
    if (response_id == static_cast<int>(Gtk::ResponseType::OK)) {
      std::string perrera_seleccionada = dialogo_seleccion->get_perrera_seleccionada();
      dialogo_seleccion->hide();
      std::string res_operacion = m_back_agr_perre.ELIMINAR_PERRERA_GUI(perrera_seleccionada);

      // 4. Creamos el AlertDialog con el mensaje recibido del backend
      auto alert = Gtk::AlertDialog::create("Resultado de la operación");
      alert->set_detail(res_operacion);
      alert->set_buttons({"Aceptar"});

      // 5. Mostramos la alerta y limpiamos el diálogo selector de forma segura
      alert->choose(*this, [this, dialogo_seleccion, alert](Glib::RefPtr<Gio::AsyncResult>& result) {
        try {
          int resp_alert = alert->choose_finish(result);
        } catch (const Glib::Error& err) {
          // Manejo estándar por si la operación se cancela por el sistema
        }

        delete dialogo_seleccion;
        m_proceso_activo = false;
      });
    } else {
      // Si cancela, simplemente cerramos y destruimos el selector
      dialogo_seleccion->hide();
      delete dialogo_seleccion;
      m_proceso_activo = false;
    };
  });

  dialogo_seleccion->show();
}
