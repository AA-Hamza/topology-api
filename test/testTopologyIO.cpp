#include "devices/resistor.hpp"
#include "test.h"
#include <device.hpp>
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>
#include <topology.hpp>
#include <topologyIO.hpp>
#include <vector>

int main()
{
    std::vector<std::string> fileNamesVector(fileNamesArray, std::end(fileNamesArray));

    // Will only use the first file
    topology::Topology ex1Topology = topology::readJSON(fileNamesVector[0]);
    std::ifstream file(fileNamesVector[0]);
    nlohmann::json ex1TopologyJson;
    file >> ex1TopologyJson;

    file.close(); // Close file
    file.clear(); // to clear IO flags

    // Assert that ex1 topology is read correctly
    assert(ex1Topology.toJson() == ex1TopologyJson);

    // write it out to a test file
    const std::string testOutputFile = "topologies/testTopologyIO_output.json";
    topology::writeJSON(ex1Topology, testOutputFile);

    // Test the outputed file with the original topology object
    file.open(testOutputFile);
    ex1TopologyJson.clear();
    file >> ex1TopologyJson;
    assert(ex1Topology.toJson() == ex1TopologyJson);
}
