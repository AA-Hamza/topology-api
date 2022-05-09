testTopologyList = executable('Test topology list', 
                     'testTopologyList.cpp',
                     dependencies: json,
                     include_directories: inc,
                     link_with: topologylib)

test('Test topology list', testTopologyList, workdir : meson.current_source_dir())