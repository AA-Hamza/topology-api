#ifndef topologyAPI_H
#define topologyAPI_H

#include <string>

#include "topologyList.hpp"
#include "topology.hpp"
#include "device.hpp"

namespace topology {
  /**
  * Read a topology Json file. If none is provided it reads from stdin
  * @param fileName the file name of the json file containing a topology
  * @return topology::Topology a Topology Object
  */
  Topology readJSON(const std::string fileName = "");

  /**
  * Writes a topology from a topologyList object on the hard disk
  * @param topologyList a topologyList object
  * @param topologyID the id of the topology
  * @param filename an optional file name, defaults to topology ID
  * @return topology::Topology a Topology Object
  */
  void writeJSON(const topology::TopologyList &topologyList, const std::string topolgoyID, const std::string fileName = "");
  //bool deleteTopology(const topology::TopologyList &, const std::string topologyID);
  //vector<Device> &queryDevices(const topology::TopologyList &, const std::string TopologyID);
  //vector<Device> &queryDevicesWithNetlistNode(const topology::TopologyList &, const std::string TopologyID, const std::string netlistNodeID);

}
#endif