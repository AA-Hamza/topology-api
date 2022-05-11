#include "devices/resistor.hpp"
#include <exception>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <topologyIO.hpp>
#include <topology.hpp>
#include <device.hpp>
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include "test.h"


int main()
{
  std::vector<std::string> fileNamesVector(fileNamesArray, std::end(fileNamesArray));

  // Will only use the first file
  std::ifstream file(fileNamesVector[0]);
  nlohmann::json topologyJson;
  file >> topologyJson;
  file.close();
  file.clear();

  topology::Topology ex1Topology = topology::readJSON(fileNamesVector[0]);
  
  // Assert that ex1 topology is read correctly
  assert(ex1Topology.toJson() == topologyJson);

  // write it out to dummy file
  const std::string testOutputFile = "topologies/testTopologyIO_output.json"; 
  topology::writeJSON(ex1Topology, testOutputFile);

  //// Test the outputed file with the original topology object
  //file.open(testOutputFile);
  //topologyJson.clear();
  //file >> topologyJson;
  //assert(ex1Topology.toJson() == topologyJson);
}
