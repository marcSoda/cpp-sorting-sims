project('sorting_visualization', 'cpp', version: '1.0', default_options: ['cpp_std=c++20'])

# Include directories
inc = include_directories('include')

# Source files
src_files = files(
  'src/main.cpp',
  'src/common.cpp',
  'src/merge.cpp',
  'src/heap.cpp',
  'src/quick.cpp'
)

# Dependency on raylib
raylib_dep = dependency('raylib', required: true)

# Build the executable
executable(
  'sorter',
  src_files,
  include_directories: inc,
  dependencies: [raylib_dep],
  install: false,
)
