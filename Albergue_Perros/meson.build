project('Albergue_Perros', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3']
)

# Reconoce todos los *.cpp que hay dentro de src
src_dir = 'src' 
gui_dir = 'gui'

src = files (
  join_paths(src_dir, 'main.cpp'),
  join_paths(src_dir, 'Buscar.cpp'),
  join_paths(src_dir, 'Clases.cpp'),
  join_paths(src_dir, 'Eliminar.cpp'),
  join_paths(src_dir, 'Insertar.cpp'),
  join_paths(src_dir, 'Modificar.cpp'),
  join_paths(src_dir, 'Mostrar.cpp'),
  join_paths(src_dir, 'Mover.cpp'),
  join_paths(src_dir, 'Funciones_Main.cpp'),
)

gui = files (
  join_paths(gui_dir, 'MainWindow.cpp'),
  join_paths(gui_dir, 'AddPerreraDialog.cpp'),
  join_paths(gui_dir, 'MostrarPerrera.cpp')
)

# Primero definimos la dependencia de gtkmm 4
gtkmm_dep = dependency('gtkmm-4.0', version: '>= 4.6.0')

# Mantengo los headers accesibles
inc = include_directories('src', 'gui')

# Luego creamos el ejecutable
exe = executable('Albergue_Perros', src, gui,
  include_directories: inc,
  dependencies: gtkmm_dep,
  win_subsystem: 'windows',
  install : true
)

test('basic', exe)
