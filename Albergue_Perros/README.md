Bienvenidos a mi Gestionador de Albergues de Perros

# 🐾 Sistema de Gestión de Albergue de Perros

Aplicación de escritorio desarrollada en **C++** y **GTKmm 4** que implementa un sistema completo de gestión para un albergue de animales. El proyecto separa estrictamente la lógica de negocio (Backend con estructuras de datos dinámicas y punteros) de la interfaz gráfica (Frontend nativo), utilizando **Meson** como sistema de compilación.

---

## 📸 Vista Previa

<p align="center">
<img width="398" height="544" alt="imagen" src="https://github.com/user-attachments/assets/090ec677-910f-47f4-bc83-c8285bde86ee" />

<img width="325" height="359" alt="imagen" src="https://github.com/user-attachments/assets/e604418e-b150-4ce9-bcd6-a717c4e10b88" />

<img width="549" height="356" alt="imagen" src="https://github.com/user-attachments/assets/07dca41a-da0a-48f4-819f-912c6bbd31ad" />
</p>

---

## ✨ Características Principales

El sistema cubre todo el ciclo de operaciones esenciales para la administración del albergue:

* **Gestión de Perreras:** Altas, modificaciones, listados y bajas de instalaciones.
* **Gestión de Perritos:** Registro de canes, actualización de datos y control de bajas.
* **Movilidad Avanzada:** 
  * Reubicación individual de un perrito entre perreras.
  * **Movilidad Total:** Traslado masivo de todos los perritos de una perrera a otra de manera automatizada.
* **Interfaz Gráfica Nativa:** Construida con GTKmm 4, utilizando diálogos modales y componentes dinámicos fluidos.

---

## 🛠️ Tecnologías y Herramientas

* **Lenguaje:** C++ (Programación Orientada a Objetos, Punteros y Estructuras Dinámicas).
* **Interfaz Gráfica:** GTKmm 4 / Gtk::Window / Gtk::AlertDialog.
* **Sistema de Compilación:** Meson & Ninja.
* **Control de Versiones:** Git y GitHub.

---

## ⚙️ Requisitos Previos

Para compilar y ejecutar este proyecto en sistemas Linux (Ubuntu/Debian), asegúrate de tener instaladas las siguientes herramientas y dependencias:

```bash
sudo apt update
sudo apt install build-essential meson ninja-build libgtkmm-4.0-dev


# Luego Clone el repositorio para poder compilar el proyecto con la herramienta Meson
  # 1. Clonar tu repositorio (reemplaza con tu URL)
       git clone https://github.com/tu-usuario/Albergue-Perros.git
       cd Albergue-Perros

  # 2. Configurar el directorio de compilación con Meson
       meson setup builddir

   # 3. Compilar el proyecto
       meson compile -C builddir

   # 4. (Opcional) Ejecutar la aplicación directamente
       ./builddir/Albergue_Perros
