#ifndef ALBERGUE_WINDOW_H
#define ALBERGUE_WINDOW_H

#include "AgregarPerrera.h"
#include "AgregarPerrito.h"
#include "Clases.h"
#include "gtkmm/button.h"
#include "gtkmm/entry.h"
#include <gtkmm.h>

class AlbergueWindow : public Gtk::Window {
public:
  AlbergueWindow(SUCURSAL& back_agr_perre);

private:
  SUCURSAL& m_back_agr_perre; // Referencia para usar mi logica

  Gtk::Box m_box_main;
  Gtk::Button m_btn_agregar_perrera;
  Gtk::Button m_btn_agregar_perrito;
  Gtk::Button m_btn_mostrar_perreras;
  Gtk::Button m_btn_mostrar_perritos;

protected:
  // Callback del botón
  void on_boton_agregar_perrera_clicked();
  void on_boton_agregar_perrito_clicked();
  void on_boton_mostrar_perreras_clicked();
  void on_boton_mostrar_perritos_clicked();
};

#endif // ALBERGUE_WINDOW_H
