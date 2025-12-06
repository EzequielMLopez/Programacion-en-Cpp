#include "Funciones_Main.h"
#include "Clases.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

string nuevaPerrera() {
  string perrera;

  cout << "\tEscoge el nombre de tu perrera: ";
  getline(std::cin, perrera);

  return perrera;
};

string pedirNombrePerrera() {
  string perrera;

  cout << "\tIngrese el nombre de la perrera en donde desea efectuar la accion: ";
  getline(cin, perrera);

  return perrera;
}

void listarPerreras(SUCURSAL& system) {
  string perrera;

  cout << "\tSegun el siguiente listado que contamos en nuestra base de datos:" << endl;
  system.MOSTRAR_PERRERAS();

  return;
}
