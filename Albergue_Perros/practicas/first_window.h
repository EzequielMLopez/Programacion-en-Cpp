#ifndef GTKMM_EXAMPLE_BUTTONS_H
#define GTKMM_EXAMPLE_BUTTONS_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/window.h>

class ExampleWindow : public Gtk::Window {
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  // Signal handlers:
  void on_button_toggled();

  // Child widgets:
  Gtk::CheckButton m_button;
};

#endif // GTKMM_EXAMPLE_BUTTONS_H
