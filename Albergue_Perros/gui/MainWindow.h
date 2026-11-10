#ifndef ALBERGUE_WINDOW_H
#define ALBERGUE_WINDOW_H

#include "Clases.h"
#include "Seleccionadores.h"
#include "gtkmm/button.h"
#include <gtkmm.h>

class AlbergueWindow : public Gtk::Window {
public:
  AlbergueWindow(SUCURSAL& back_agr_perre);

private:
  SUCURSAL& m_back_agr_perre;    // Referencia para usar mi logica
  bool m_proceso_activo = false; // Bandera para evitar reentradas por Enter o clics múltiples

  Gtk::Box m_box_main;
  Gtk::Button m_btn_agregar_perrera;
  Gtk::Button m_btn_agregar_perrito;
  Gtk::Button m_btn_mostrar_perreras;
  Gtk::Button m_btn_mostrar_perritos;
  Gtk::Button m_btn_modificar_perrera;
  Gtk::Button m_btn_modificar_perrito;
  Gtk::Button m_btn_eliminar_perrera;
  Gtk::Button m_btn_eliminar_perrito;

protected:
  // Callback del botón
  void on_boton_agregar_perrera_clicked();
  void on_boton_agregar_perrito_clicked();
  void on_boton_mostrar_perreras_clicked();
  void on_boton_mostrar_perritos_clicked();
  void on_boton_modificar_perrera_clicked();
  void on_boton_modificar_perrito_clicked();
  void on_boton_eliminar_perrera_clicked();
  void on_boton_eliminar_perrito_clicked();

public:
  Seleccionador Seleccionar_Perrera();
};

#endif // ALBERGUE_WINDOW_H
