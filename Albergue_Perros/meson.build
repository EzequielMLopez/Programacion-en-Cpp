project('Albergue_Perros', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3'])

gtkmm_dep = dependency('gtkmm-4.0', version: '>= 4.6.0')

exe = executable('Albergue_Perros', 'main.cpp', 'widgets_label.cpp',
  dependencies: gtkmm_dep,
  win_subsystem: 'windows',
  install : true)
