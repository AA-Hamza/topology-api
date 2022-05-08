testexe = executable('Test Topology API', 
                     'test.cpp',
                     dependencies: json,
                     include_directories: inc,
                     link_with: topologylib)

test('test with stdin', testexe, workdir : meson.current_source_dir())
                    
