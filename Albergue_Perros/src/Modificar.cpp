#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

void SUCURSAL::MODIFICAR_PERRITO() {
  PERRERA* PE;
  PERROS* P;
  char choice;
  string perrera, perrito, nombre_perrito;
  int flag1 = 0, flag2 = 0, edad, altura;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perrera ingresada donde buscar perrito alguno, favor de crear al menos una perrera con un perrito dentro." << endl;
    return;
  }

  cout << "\t\tSegun la siguiente lista de perreras:" << endl;
  MOSTRAR_PERRERAS();
  cout << "\t\tCual es la perrera donde se encuentra su perrito: ";
  getline(cin, perrera);

  PE = INICIO;

  while (PE) {
    if (PE->getNombre() == perrera) {
      flag1 = 1;

      if (PE->getINIP() == NULL) {
        cout << "\t\tLa perrera no cuenta con ningun perrito, favor de al menos ingresar uno." << endl;
        return;
      }

      cout << "\t\tSegun la siguiente lista de perritos ingresados:" << endl;
      MOSTRAR_PERRITOS(perrera);
      cout << "\t\tCual desea modificar: ";
      getline(cin, perrito);

      P = PE->getINIP();

      while (P) {
        if (P->getNombre() == perrito) {
          flag2 = 1;
          do {
            cout << "\t\tDesea modificar el nombre? S(Si) N(No): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
          } while (choice != 'S' && choice != 'N');

          if (choice == 'S') {
            cout << "\t\tCual es el nuevo nombre para " << P->getNombre() << ": ";
            getline(cin, nombre_perrito);
            P->setNombre(nombre_perrito);
          }

          do {
            cout << "\t\tDesea modificar la edad? S(Si) N(No): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
          } while (choice != 'S' && choice != 'N');

          if (choice == 'S') {
            cout << "\t\tCual es la nueva edad para " << P->getNombre() << ": ";
            cin >> edad;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            P->setEdad(edad);
          }

          break;
        }

        P = P->getSIG();
      }

      if (flag2 == 0) {
        cout << "\t\tLa perrera se encontro pero no el perro correspondiente :(" << endl;
      }

      break;
    }

    PE = PE->getSIG();
  }

  if (flag1 == 0) {
    cout << "\t\tNo se encontro la perrera pertinente." << endl;
  }

  return;
}

void SUCURSAL::MODIFICAR_PERRERA() {
  PERRERA* PE;
  char choice;
  string perrera, nombre, pais, provincia, partido, localidad, direccion;
  int flag = 0, altura = 0;

  if (INICIO == NULL) {
    cout << "\t\tNo hay perrera alguna para modificar, cree al menos una para usar esta funcion." << endl;
    return;
  }

  cout << "\t\tEn funcion de las siguientes perreras disponibles:" << endl;
  MOSTRAR_PERRERAS();
  cout << "\t\tIngrese el nombre de la que desea modificar sus datos: ";
  getline(cin, perrera);

  PE = INICIO;

  while (PE) {
    if (PE->getNombre() == perrera) {
      do {
        cout << "\t\tDesea modificar el Nombre? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese el nuevo Nombre: ";
        getline(cin, nombre);
        PE->setNombre(nombre);
      }

      do {
        cout << "\t\tDesea modificar el Pais? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese el nuevo Pais: ";
        getline(cin, pais);
        PE->setPais(pais);
      }

      do {
        cout << "\t\tDesea modificar la Provincia? S(Si) N(No)";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese la nueva Provincia: ";
        getline(cin, provincia);
        PE->setProvincia(provincia);
      }

      do {
        cout << "\t\tDesea modificar el Partido? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese el nuevo Partido: ";
        getline(cin, partido);
        PE->setPartido(partido);
      }

      do {
        cout << "\t\tDesea modificar la Localidad? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese la nueva Localidad: ";
        getline(cin, localidad);
        PE->setLocalidad(localidad);
      }

      do {
        cout << "\t\tDesea modificar la Direccion? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese la nueva Direccion: ";
        getline(cin, direccion);
        PE->setDireccion(direccion);
      }

      do {
        cout << "\t\tDesea modificar la Altura? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        while (altura <= 0) {
          cout << "\t\tIngrese la nueva Altura: ";
          cin >> altura;
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
          PE->setAltura(altura);
        }
      }

      flag = 1;
      break;
    }

    PE = PE->getSIG();
  }

  if (flag == 0) {
    cout << "\t\tNo se encontro la perrera especificada. Se lo retorna al Menu Principal." << endl;
  }

  return;
}
