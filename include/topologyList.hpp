#ifndef TOPOLOGY_LIST_h
#define TOPOLOGY_LIST_h

#include "topology.hpp"
#include <map>
#include <string>
#include <vector>

namespace topology
{
/**
 * @brief class containing other Topology objects
 */
class TopologyList
{
  public:
    // Empty constructor, for basic construction.
    TopologyList(){};

    /**
     * @brief TopologyList constructor from a vector of Topology
     * @param topologiesSrc a vector of Topology objects
     */
    TopologyList(const std::vector<Topology> &topologiesSrc);

    /**
     * @brief get the topolgoy holding topologyID
     * @throw std::invalid_argument if topologyID doesn't exist
     * @param topologyID a topology object ID
     * @return returns a const reference to the topology with topologyID
     */
    const Topology &operator[](const std::string topologyID) const;

    /**
     * @brief Add a new Topology to the TopologyList
     * @throw std::invalid_argument if topology already exists
     * @param topology a topology Object
     */
    void add(const Topology topology);

    /**
     * @brief remove a Topology from the TopologyList
     * @throw std::invalid_argument if topologyID wasn't found
     * @param topologyID a topology Object ID
     */
    void erase(const std::string topologyID);

    /**
     * @brief Get how many topologies are in the TopologyList
     * @return get the size of the TopologyList
     */
    size_t size() const;

    /**
     * @brief get a vector of IDs of the topologies existing in the TopologyList
     * @return a vector of strings
     */
    std::vector<std::string> getIDs() const;

  private:
    std::map<std::string, Topology> m_topologies;
};
} // namespace topology
#endif