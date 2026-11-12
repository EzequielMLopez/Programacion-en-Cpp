Buenas dias, Buenas tardes y Buenas noches.

Por el presente, quisiera instruirlos en como poder descargar la aplicacion y probarlas de manera nativa en su computador. Fue realizado sobre Ubuntu 24.04 LTS y se hizo uso de GTKM4 para todo el FrontEnd.

# Primer Paso: Instalamos las dependencias con los siguientes comandos "sudo apt update; sudo apt install build-essential meson ninja-build libgtkmm-4.0-dev"
# Segundo Paso: Clonar el repositorio para luego poder compilar el proyecto con la herramienta Meson
  # 1. Clonar tu repositorio (reemplaza con tu URL)
       git clone https://github.com/tu-usuario/Albergue-Perros.git
       cd Albergue-Perros

  # 2. Configurar el directorio de compilación con Meson
       meson setup builddir

   # 3. Compilar el proyecto
       meson compile -C builddir

   # 4. (Opcional) Ejecutar la aplicación directamente
       ./builddir/Albergue_Perros

Capturas de la Interfaz:

<img width="398" height="544" alt="imagen" src="https://github.com/user-attachments/assets/090ec677-910f-47f4-bc83-c8285bde86ee" />

<img width="325" height="359" alt="imagen" src="https://github.com/user-attachments/assets/e604418e-b150-4ce9-bcd6-a717c4e10b88" />

<img width="549" height="356" alt="imagen" src="https://github.com/user-attachments/assets/07dca41a-da0a-48f4-819f-912c6bbd31ad" />



