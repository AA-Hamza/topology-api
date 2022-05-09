#ifndef topologyAPI_H
#define topologyAPI_H

#include <string>

#include "topologyList.hpp"
#include "topology.hpp"
#include "device.hpp"

namespace topology {
  /**
  * @brief Read a topology Json file (if fileName is not provided, it reads from stdin) and store it in a Topology object. 
  * @param fileName the file name of the json file containing a topology
  * @return topology::Topology a Topology Object
  */
  Topology readJSON(const std::string fileName = "");

  /**
  * @brief Writes a topology from a topologyList object to the hard disk
  * @brief If fileName isn't provided, it uses the topology ID as fileName
  * @param topologyList a topologyList object
  * @param topologyID the id of the Topology
  * @param fileName an optional file name, defaults to topologyID
  * @throw json::exception
  * @return true on success, false otherwise
  */
  bool writeJSON(const topology::TopologyList &topologyList, const std::string topolgoyID, const std::string fileName = "");
}
#endif