#include <device.hpp>
#include <iostream>

//using namespace topology;

namespace topology {
  std::string Device::getID() const{
    return m_deviceID;
  }
  
  std::string Device::getType() const{
    return m_deviceType;
  }

std::map<std::string, std::string> Device::getNetList() const {
    return m_netList;
  }

  std::map<std::string, double> Device::getProperties() const {
    return m_deviceProperties;
  }
}