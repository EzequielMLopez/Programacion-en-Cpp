#include "examplewindow.h"
#include <iostream>

ExampleWindow::ExampleWindow() : m_button("Soy un botoncito nuevo xD") {
  set_title("checkbutton example");

  m_button.signal_toggled().connect(
      sigc::mem_fun(*this, &ExampleWindow::on_button_toggled));

  m_button.set_margin(10);
  set_child(m_button);
}

ExampleWindow::~ExampleWindow() {}

void ExampleWindow::on_button_toggled() {
  std::cout << "The Button was toggled: state="
            << (m_button.get_active() ? "true" : "false") << std::endl;
}
