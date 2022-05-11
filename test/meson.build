testTopologyList = executable('Test topology list', 
                     'testTopologyList.cpp',
                     dependencies: json,
                     include_directories: inc,
                     link_with: topologylib)

test('Test topology list', testTopologyList, workdir : meson.current_source_dir())

testTopology = executable('Test topology', 
                     'testTopology.cpp',
                     dependencies: json,
                     include_directories: inc,
                     link_with: topologylib)

test('Test topology', testTopology, workdir : meson.current_source_dir())

testDevice = executable('Test Device', 
                     'testDevice.cpp',
                     dependencies: json,
                     include_directories: inc,
                     link_with: topologylib)

test('Test Device', testDevice, workdir : meson.current_source_dir())

testTopologyIO = executable('Test ToplogyIO', 
                     'testTopologyIO.cpp',
                     dependencies: json,
                     include_directories: inc,
                     link_with: topologylib)

test('Test TopologyIO', testTopologyIO, workdir : meson.current_source_dir())