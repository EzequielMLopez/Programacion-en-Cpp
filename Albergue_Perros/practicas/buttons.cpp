#include "buttons.h"
#include "sigc++/functors/mem_fun.h"
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <iostream>

/*
Buttons::Buttons() {
  // This corresponds to Gtk::Bin::add_pixlabel("info.xpm", "cool button") in
  // gtkmm3.
  // Create Image and Label widgets:
  auto pmap = Gtk::make_managed<Gtk::Image>(
      "/home/eml/Escritorio/Albergue_Perros/info.jpg");
  auto label = Gtk::make_managed<Gtk::Label>("Miren que botonazo");
  label->set_expand(true);

  // Put them in a Box:
  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(*pmap);
  hbox->append(*label);

  // And put that Box in the button:
  m_button.set_child(*hbox);

  set_title("Pixmap'd buttons!");

  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &Buttons::on_button_clicked));

  m_button.set_margin(10);
  set_child(m_button);
}

Buttons::~Buttons() {}

void Buttons::on_button_clicked() {
  std::cout << "The Button was clicked." << std::endl;
}
*/
ToggleButton::ToggleButton() {
  // This corresponds to Gtk::Bin::add_pixlabel("info.xpm", "cool button") in
  // gtkmm3.
  // Create Image and Label widgets:
  /*
  auto pmap = Gtk::make_managed<Gtk::Image>(
      "/home/eml/Escritorio/Albergue_Perros/info.jpg");
  auto label = Gtk::make_managed<Gtk::Label>("Miren que botonazo");
  label->set_expand(true);

  // Put them in a Box:
  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(*pmap);
  hbox->append(*label);
  // And put that Box in the button:
  t_button.set_child(*hbox);
  */

  t_button.toggled();
  t_button2.toggled();

  set_title("Pixmap'd ToggleButton!");
  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(t_button);
  hbox->append(t_button2);

  t_button.signal_clicked().connect(
      sigc::mem_fun(*this, &ToggleButton::on_button_clicked));
  t_button2.signal_clicked().connect(
      sigc::mem_fun(*this, &ToggleButton::on_button_clicked2));

  t_button.set_margin(10);
  t_button2.set_margin(10);

  set_child(*hbox);
}

ToggleButton::~ToggleButton() {}

void ToggleButton::on_button_clicked() {
  std::cout << "The Button Toggle was clicked." << std::endl;
}

void ToggleButton::on_button_clicked2() {
  std::cout << "I am the second Toggle Button!!!" << std::endl;
}
