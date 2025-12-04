project('my-app', 'cpp',
  version: '0.1.0',
  default_options: ['cpp_std=c++17', 'warning_level=3']
)

gnome = import('gnome')

dependency_libadwaita = dependency('libadwaita-1')

# Include the framework source
sources = [
  'main.cpp',
  'framework/adw_simple.cpp'
]

executable('my-app',
  sources,
  include_directories: include_directories('framework'),
  dependencies: [dependency_libadwaita],
  install: true
)
