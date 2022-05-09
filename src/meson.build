topologySource = ['device.cpp', 'topology.cpp', 'topologyIO.cpp', 'topologyList.cpp']
devicesSource  = ['devices/resistor.cpp', 'devices/nmos.cpp'] 
sources = topologySource+devicesSource
topologylib = library('topologylib',
                     sources,
                     include_directories: inc,
                     dependencies: json)