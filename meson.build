project('Topology API', 'cpp', default_options: ['cpp_std=c++17'])
subproject('nlohmann_json', required: true)
json = dependency('nlohmann_json', required: true)

inc = include_directories('include')

subdir('include')
subdir('src')
subdir('test')

example = executable('example',
                     'example.cpp',
                     dependencies: json,
                     include_directories: inc,
                     link_with: topologylib)