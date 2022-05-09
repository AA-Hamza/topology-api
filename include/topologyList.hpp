#ifndef TOPOLOGY_LIST_h
#define TOPOLOGY_LIST_h

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <nlohmann/json.hpp>
#include "topology.hpp"

using json = nlohmann::json;


namespace topology {
  class TopologyList {
    public:
      TopologyList() {};
      /**
      * @param topologiesSrc a vector of Topology objects
      */
      TopologyList(const std::vector<Topology> &topologiesSrc);

      /**
      * get the topolgoy in the topologyList by it's ID
      * @param topologyID a topology object ID
      * @return returns a copy to the topology with topologyID
      */
      Topology operator[](const std::string topologyID);

      /**
      * Add a new topology to the list, it throws an exception if the id already exists
      * @param topology a topology Object
      * @return returns true on success, false otherwise
      */
      bool add(const Topology &topology);

      /**
      * remove a topology from the TopologyList
      * @param topologyID a topology Object ID
      * @return true on success, false otherwise
      */
      bool erase(const std::string topologyID);

      /**
      * @return get the size of the topology
      */
      size_t size() const;

      /**
      * @return const_iterator to the begining of the topologyList map
      */
      std::map<std::string, Topology>::const_iterator cbegin() const;

      /**
      * @return const_iterator to the end of the topologyList map
      */
      std::map<std::string, Topology>::const_iterator cend() const;

    private:
      std::map<std::string, Topology> m_topologies;
  };
}
#endif