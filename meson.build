project('Topology API', 'cpp', default_options: ['cpp_std=c++11'])
subproject('nlohmann_json', required: true)
json = dependency('nlohmann_json', required: true)

inc = include_directories('include')

subdir('include')
subdir('src')
subdir('test')

cppcheck = find_program('cppcheck', required: false)
if cppcheck.found()
  run_target('cppcheck', command : ['cppcheck', '--project=' + 
    join_paths(meson.build_root(), 'compile_commands.json')]) 
endif

example = executable('example',
                     'example.cpp',
                     dependencies: json,
                     include_directories: inc,
                     link_with: topologylib)

