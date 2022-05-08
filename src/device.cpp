#include <device.hpp>

using namespace topology;

// Constructor
Device::Device(const json &deviceJson) {
  try {
    m_deviceID = deviceJson.at("id");
    m_type = deviceJson.at("type");
  }
  catch (const json::exception &e){
    throw e;
  }
}