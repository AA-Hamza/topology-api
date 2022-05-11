#ifndef TOPOLOGY_LIST_h
#define TOPOLOGY_LIST_h

#include <string>
#include <map>
#include <vector>
#include <nlohmann/json.hpp>
#include <topology.hpp>

using json = nlohmann::json;


namespace topology {
  /**
  * @brief class containing other Topology objects
  */
  class TopologyList {
    public:
      // Empty constructor, makes the compiler happy
      TopologyList() {};

      /**
      * TopologyList constructor from a vector of Topology
      * @param topologiesSrc a vector of Topology objects
      */
      TopologyList(const std::vector<Topology> &topologiesSrc);

      /**
      * @brief get the topolgoy holding topologyID
      * @throw std::invalid_argument("Topology ID was not found")
      * @param topologyID a topology object ID
      * @return returns a copy to the topology with topologyID
      */
      const Topology &operator[](const std::string topologyID) const;

      /**
      * @brief Add a new Topology to the TopologyList, throws an exception if topology already exists
      * @throw std::invalid_argument("Topology already exists")
      * @param topology a topology Object
      */
      void add(const Topology &topology);

      /**
      * @brief remove a Topology from the TopologyList, throws an exception if topologyID wasn't found
      * @throw std::invalid_argument("topologyID not found")
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
}
#endif