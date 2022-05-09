topologySource = ['topology.cpp', 'topologyIO.cpp', 'topologyList.cpp']
devicesSource  = ['device.cpp', 'devices/resistor.cpp', 'devices/nmos.cpp'] 
sources = devicesSource+topologySource
topologylib = shared_library('topologylib',
                     sources,
                     include_directories: inc,
                     dependencies: json,
                     install: true)

