#include "device.hpp"
#include <devices/nmos.hpp>
#include <devices/resistor.hpp>
#include <topology.hpp>

using namespace topology;

Topology::Topology(const json &topologyJson) {
  try {
    m_topologyID = topologyJson.at("id");
    json::array_t componentsJson = topologyJson.at("components");

    // Populate m_components with topology components
    for (size_t i = 0; i < componentsJson.size(); ++i) {
      if (componentsJson[i].at("type") == "resistor") {
        m_devices.push_back(Resistor(componentsJson[i]));
      }
      else if (componentsJson[i].at("type") == "nmos") {
        m_devices.push_back(Nmos(componentsJson[i]));
      }
    }
  }
  catch (const json::exception &e) {
    std::cerr << "Couldn't create a component" << std::endl;
    throw e;
  }
}

const std::string Topology::getID() const {
  return m_topologyID;
}

const std::vector<Device> Topology::getDevices() const {
  return m_devices;
}

json Topology::toJson() const {
  json jsonRepresentation;
  jsonRepresentation["id"] = m_topologyID;
  json::array_t components;
  for (size_t i = 0; i < m_devices.size(); ++i) {
    components.push_back(m_devices[i].toJson());
  }
  jsonRepresentation["components"] = std::move(components);
  return jsonRepresentation;
}