#include "Clases.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

using namespace std;

void SUCURSAL::MODIFICAR_PERRITO() {
  PERRERA* PE;
  PERROS* P;
  char choice;
  string perrera, perrito;
  int flag1 = 0, flag2 = 0;

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
    if (PE->nombre == perrera) {
      if (PE->INIP == NULL) {
        cout << "\t\tLa perrera no cuenta con ningun perrito, favor de al menos ingresar uno." << endl;
        return;
      }

      cout << "\t\tSegun la siguiente lista de perritos ingresados:" << endl;
      MOSTRAR_PERRITOS(perrera);
      cout << "\t\tCual desea modificar: ";
      getline(cin, perrito);

      P = PE->INIP;

      while (P) {
        if (P->nombre == perrito) {
          do {
            cout << "\t\tDesea modificar el nombre? S(Si) N(No): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
          } while (choice != 'S' && choice != 'N');

          if (choice == 'S') {
            cout << "\t\tCual es el nuevo nombre para " << P->nombre << ": ";
            getline(cin, P->nombre);
          }

          do {
            cout << "\t\tDesea modificar la edad? S(Si) N(No): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
          } while (choice != 'S' && choice != 'N');

          if (choice == 'S') {
            cout << "\t\tCual es la nueva edad para " << P->nombre << ": ";
            cin >> P->edad;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }

          flag2 = 1;
          break;
        }

        P = P->SIG;
      }

      if (flag2 == 0) {
        cout << "\t\tLa perrera se encontro pero no el perro correspondiente :(" << endl;
      }

      flag1 = 1;
      break;
    }

    PE = PE->SIG;
  }

  if (flag1 == 0) {
    cout << "\t\tNo se encontro la perrera pertinente." << endl;
  }

  return;
}

void SUCURSAL::MODIFICAR_PERRERA() {
  PERRERA* PE;
  char choice;
  string perrera;
  int flag = 0;

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
    if (PE->nombre == perrera) {
      do {
        cout << "\t\tDesea modificar el Pais? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese el nuevo Pais: ";
        cin.getline(PE->pais, 20);
      }

      do {
        cout << "\t\tDesea modificar la Provincia? S(Si) N(No)";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese la nueva Provincia: ";
        cin.getline(PE->provincia, 20);
      }

      do {
        cout << "\t\tDesea modificar el Partido? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese el nuevo Partido: ";
        cin.getline(PE->partido, 40);
      }

      do {
        cout << "\t\tDesea modificar la Localidad? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese la nueva Localidad: ";
        cin.getline(PE->localidad, 20);
      }

      do {
        cout << "\t\tDesea modificar la Direccion? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese la nueva Direccion: ";
        cin.getline(PE->direccion, 20);
      }

      do {
        cout << "\t\tDesea modificar la Altura? S(Si) N(No): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      } while (choice != 'S' && choice != 'N');

      if (choice == 'S') {
        cout << "\t\tIngrese la nueva Altura: ";
        cin >> PE->altura;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
      }

      flag = 1;
      break;
    }

    PE = PE->SIG;
  }

  if (flag == 0) {
    cout << "\t\tNo se encontro la perrera especificada. Se lo retorna al Menu Principal." << endl;
  }

  return;
}
