#include <topology.hpp>

using namespace topology;

Topology::Topology(const json &topologyJson) {
  try {
    m_topologyID = topologyJson.at("id");
    std::vector<json::array_t> componentsJson = topologyJson.at("components");

    // Populate m_components with topology components
    for (size_t i = 0; i < componentsJson.size(); ++i) {
      m_devices.push_back(Device(componentsJson[i]));
    }
  }
  catch (const json::exception &e) {
    //std::cerr << "message: " << e.what() << '\n' << "exception id: " << e.id << std::endl;
    //exit(-1);
    //delete this;
    throw e;
  }
}

const std::string Topology::getID() const {
  return m_topologyID;
}

const std::vector<Device> Topology::getDevices() const {
  return m_devices;
}