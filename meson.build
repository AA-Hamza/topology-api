project('Topology API', 'cpp', default_options: ['cpp_std=c++11'])
subproject('nlohmann_json', required: true)
json = dependency('nlohmann_json', required: true)

inc = include_directories('include')

subdir('include')
subdir('src')
subdir('test')
