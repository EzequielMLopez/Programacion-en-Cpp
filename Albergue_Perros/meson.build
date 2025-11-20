project('Albergue_Perros', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3']
)

# Primero definimos la dependencia de gtkmm 4
gtkmm_dep = dependency('gtkmm-4.0', version: '>= 4.6.0')

# Luego creamos el ejecutable
exe = executable('Albergue_Perros', 'main.cpp',
  dependencies: gtkmm_dep,
  win_subsystem: 'windows',
  install : true
)

test('basic', exe)
