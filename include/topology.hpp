#ifndef TOPOLOGY_H 
#define TOPOLOGY_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "device.hpp"

using json = nlohmann::json;

namespace topology {
  class Topology {
  public:
    Topology() = default;
    /**
    * Construct Topology from the Json object
    * @param topologyJson the topology json object 
    */
    Topology(const json &topologyJson);

    /**
    * @return Topology ID
    */
    const std::string getID() const;

    /**
    * @return A c++ vector to topology devices
    */
    const std::vector<Device> getDevices() const;

    /**
    * @return Devices connected to a net list node
    */
    std::vector<Device> getDevicesConnectedTo(std::string netListNode) const;

    /**
    * @return json representation of topology
    */
    json toJson() const;

    ~Topology() {}

  private:
    std::string m_topologyID;
    std::vector<Device> m_devices;

    friend class TopologyList;
  };
}

#endif