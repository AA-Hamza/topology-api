#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include "device.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace topology
{
/**
 * @brief Topology class to represent the topology and parse the json object.
 */
class Topology
{
  public:
    /**
     * @brief Using compiler default constructor.
     * @brief Used while initializing different datatypes like maps and vectors.
     */
    Topology() = default;

    /**
     * @brief Construct Topology from the Json object, throws an error if toplogyJson can't be parsed
     * @throw json::exception when topologyJson parsing fails
     * @param topologyJson the topology json object
     */
    Topology(const nlohmann::json &topologyJson);

    /**
     * @return Topology ID
     */
    std::string getID() const;

    /**
     * @brief Get Topology Devices
     * @return A const refernce to a vector of pointers to const topology devices
     */
    const std::vector<std::shared_ptr<const Device>> &getDevices() const;

    /**
     * @brief Get all Devices connected to a net list node
     * @return a vector of pointers to Devices connected to a m_netList node
     */
    std::vector<std::shared_ptr<const Device>> getDevicesConnectedTo(const std::string netListNode) const;

    /**
     * @return json representation of topology
     */
    nlohmann::json toJson() const;

    ~Topology()
    {
    }

  private:
    std::string m_topologyID;
    std::vector<std::shared_ptr<const Device>> m_devices;

    /**
     * TopologyList is a friend as it needs access to m_topologyID and m_devices
     */
    friend class TopologyList;
};
} // namespace topology

#endif