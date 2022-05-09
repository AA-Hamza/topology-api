#ifndef TOPOLOGY_H 
#define TOPOLOGY_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "device.hpp"

using json = nlohmann::json;

namespace topology {
  /**
  * @brief Topology class to represent the topology and parse the json object.
  */
  class Topology {
  public:
    /**
    * @brief Using compiler default constructor.
    * @brief Used while initializing different datatypes like maps and vectors.
    */
    Topology() = default;

    /**
    * @brief Construct Topology from the Json object
    * @param topologyJson the topology json object 
    */
    Topology(const json &topologyJson);

    /**
    * @return Topology ID
    */
    const std::string getID() const;

    /**
    * @return A vector to topology devices
    */
    const std::vector<Device> getDevices() const;

    /**
    * @return Devices connected to a m_netList node
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

    /**
    * TopologyList is a friend as it needs access to m_topologyID and m_devices
    */
    friend class TopologyList;
  };
}

#endif