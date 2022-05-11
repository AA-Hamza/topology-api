#ifndef topologyAPI_H
#define topologyAPI_H

#include "device.hpp"
#include "topology.hpp"
#include <string>

namespace topology
{
/**
 * @brief Read a topology Json file (if fileName is not provided, it reads from stdin) and store it in a Topology
 * object.
 * @param fileName the file name of the json file containing a topology
 * @throw json::exception on json parsing failure
 * @throw std::ios_base::failure on IO failure
 * @return topology::Topology a Topology Object
 */
Topology readJSON(const std::string fileName = "");

/**
 * @brief Writes a Topology from a TopologyList object to the hard disk
 * @brief If fileName isn't provided, it uses the topology ID as fileName
 * @param outputTopology a const reference to the Topology
 * @param fileName an optional file name, defaults to topology ID
 * @throw std::ios_base::failure on IO failure
 * @return true on success, false otherwise
 */
void writeJSON(const Topology &outputTopolgoy, const std::string fileName = "");
} // namespace topology
#endif