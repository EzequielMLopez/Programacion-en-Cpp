#ifndef GTKMM_EXAMPLE_BUTTONS_H
#define GTKMM_EXAMPLE_BUTTONS_H

#include <gtkmm-4.0/gtkmm/togglebutton.h>
#include <gtkmm-4.0/gtkmm/window.h>
#include <gtkmm/button.h>

class Buttons : public Gtk::Window {
public:
  Buttons();
  virtual ~Buttons();

protected:
  // Signal handlers:
  void on_button_clicked();

  // Child widgets:
  Gtk::Button m_button;
};

class ToggleButton : public Gtk::Window {
public:
  ToggleButton();
  virtual ~ToggleButton();

protected:
  // Signal handlers:
  void on_button_clicked();
  void on_button_clicked2();

  // Child widgets:
  Gtk::ToggleButton t_button;
  Gtk::ToggleButton t_button2;
};

#endif // GTKMM_EXAMPLE_BUTTONS_H
