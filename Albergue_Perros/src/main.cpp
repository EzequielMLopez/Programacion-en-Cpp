#include "Clases.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char** argv, char** envp) {
  SUCURSAL S;
  int choice = -1, choice1 = 0;
  char perrera[20], perrera_elegida[20], know;

  cout << "Bienvenido al Albergue de Perros simulado" << endl;

  while (choice) {
    cout << "Para facilitar la gestion de este programa usted puede escoger "
            "entre las siguientes opciones:\n"
         << "1- Agregar una perrera nueva\n"
         << "2- Agregar perritos a una perrera ya existente\n"
         << "3- Mostrar Perreras\n"
         << "4- Mostrar Perritos de una Perrera determinada\n"
         << "5- Eliminar una perrera o todas las perreras (esto incluye la "
            "perdida de los datos de los "
            "perritos)\n"
         << "6- Mover los datos de algunos u todos los perritos a otra "
            "perrera\n"
         << "7- Buscar un perro especifigo en una perrera concreta o en "
            "todas\n"
         << "8- Eliminar un perrito de alguna perrera especifica\n"
         << "9- Modificar los datos de un perro\n"
         << "10- Modificar los datos de una perrera\n"
         << "0- Salir del programa\n"
         << "Ingrese la accion que desea realizar: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

    switch (choice) {
      case 1:
        cout << "\tEscoge un nombre para la nueva perrera: ";
        cin.getline(perrera, 20);
        S.AGREGAR_PERRERA(perrera);
        break;

      case 2:
        cout << "\tSabe el nombre de la perrera en donde desea ingresar al "
                "nuevo "
                "integrante S(Si) N(No): ";
        cin >> know;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (know == 'S') {
          cout << "\tColoca por favor el nombre de la perrera a donde esta "
                  "destinado el nuevo perrito/a: ";
          cin.getline(perrera, 20);
          S.AGREGAR_PERRITO(perrera);
        } else if (know == 'N') {
          cout << "\tEste es el listado de las perreras que actualmente tenemos "
                  "en nuestra base de datos:"
               << endl;
          S.MOSTRAR_PERRERAS();
          cout << "\tLa perrera deseada se encuentra entre una de ellas? S(Si) "
                  "N(No): ";
          cin >> know;
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

          if (know == 'S') {
            cout << "\tFavor de indicar el nombre de la misma: ";
            cin.getline(perrera_elegida, 20);
            S.AGREGAR_PERRITO(perrera_elegida);
          } else if (know == 'N') {
            cout << "\tSiendo que no conoce el nombre de la perrera ni tampoco "
                    "la "
                    "supo reconocer en el listado dado, le pedimos que cree la "
                    "Perrera para poder ingresar a los perritos"
                 << endl;
          } else {
            cout << "\tNo es un valor valido, se lo devuelve al menu principal.";
          }
        }
        break;

      case 3:
        cout << "\tLas perreras con las que contamos son:" << endl;
        S.MOSTRAR_PERRERAS();
        break;

      case 4:
        cout << "\t\tSegun la siguiente lista de perreras:" << endl;
        S.MOSTRAR_PERRERAS();
        cout << "\t\tEscriba el nombre de la perrera para mostrar sus perritos: ";
        cin.getline(perrera, 20);
        S.MOSTRAR_PERRITOS(perrera);
        break;

      case 5:
        cout << "\tDesea usted:\n"
             << "\t1- Eliminar una perrera determinada\n"
             << "\t2- Eliminar todas las perreras\n"
             << "\tAccion a realizar: ";
        cin >> choice1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (choice1 == 1) {
          cout << "\tFavor de ingresar el nombre de la Perrera: ";
          cin.getline(perrera, 20);
          S.ELIMINAR_PERRERA(perrera);
        } else if (choice1 == 2) {
          cout << "\tSe van a eliminar todas las perreras" << endl;
          S.ELIMINAR_PERRERA();
        } else {
          cout << "\tNo corresponde a ninguna opcion para elegir, se devuelve "
                  "al "
                  "menu principal"
               << endl;
        }
        break;

      case 6:
        cout << "\tQue desea hacer:\n"
             << "\t1- Mover algunos perros\n"
             << "\t2- Mover todos los perros de una perrera a otra\n"
             << "\tColoque la opcion deseada: ";
        cin >> choice1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (choice1 == 1) {
          S.MOVER_PERRITOS(choice1);
        } else if (choice1 == 2) {
          S.MOVER_PERRITOS(choice1);
        }
        break;

      case 7:
        cout << "\tEntre las siguientes opciones:\n"
             << "\t1- Buscar en una perrera concreta\n"
             << "\t2- Buscar en todas las perreras\n"
             << "\tCual busqueda prefiere: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (choice == 1) {
          cout << "\tEn funcion de la siguiente lista de perreras:" << endl;
          S.MOSTRAR_PERRERAS();
          cout << "\tIndique el nombre de la perrera en la que vamos a buscar "
                  "al perrito: ";
          cin.getline(perrera, 20);
          S.BUSCAR_PERRITO(perrera);
        } else if (choice == 2) {
          S.BUSCAR_PERRITO();
        } else {
          cout << "\tNo se indico ninguna de las opciones validas, se lo "
                  "devuelve al menu principal"
               << endl;
        }
        break;

      case 8: S.ELIMINAR_PERRITO(); break;

      case 9: S.MODIFICAR_PERRITO(); break;

      case 10: S.MODIFICAR_PERRERA(); break;
    }
  }

  return 0;
}
