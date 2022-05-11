#include <exception>
#include <sstream>
#include <topologyIO.hpp>
#include <topologyList.hpp>
#include <iostream>
#include <vector>
#include "test.h"

void testTopologyListAdd(const std::vector<std::string> &fileNamesVector) {
    topology::TopologyList exTopolgoyList;
    for (const auto &fileName : fileNamesVector) {
        topology::Topology exTopology = topology::readJSON(fileName);
        exTopolgoyList.add(exTopology);
    }

    // Asserting topologyListTest added all topologies correctly
    assert(exTopolgoyList.size() == fileNamesVector.size());
    
    // adding an already existing topology
    for (const auto &exFileName : fileNamesVector) {
        topology::Topology exTopology = topology::readJSON(exFileName);
        try {
            exTopolgoyList.add(exTopology);
        }
        catch (std::exception &e) {
            assert(e.what() == "topologyID: "+exTopology.getID()+" already exists");
        }
    }

    // Asserting topologyListTest didn't add an existing topology
    assert(exTopolgoyList.size() == fileNamesVector.size());
}

void testTopologyListErase(const std::vector<std::string> &fileNamesVector) {
    topology::TopologyList exTopolgoyList;
    for (const auto &fileName : fileNamesVector) {
        topology::Topology exTopology = topology::readJSON(fileName);
        exTopolgoyList.add(exTopology);
    }

    // Asserting topologyListTest added all topologies correctly
    assert(exTopolgoyList.size() == fileNamesVector.size());

    std::vector<std::string> IDs = exTopolgoyList.getIDs();

    // Get the first topology
    assert(IDs.size() > 0);
    const topology::Topology &eraseThisTopology = exTopolgoyList[IDs[0]];

    // Delete it
    exTopolgoyList.erase(eraseThisTopology.getID());

    // Asserting that the size of topologyListTest went down by 1
    assert(exTopolgoyList.size() == fileNamesVector.size()-1);

    // Try acessing the deleted topology ID
    try {
        exTopolgoyList[eraseThisTopology.getID()];
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        assert(e.what() == "topologyID: "+eraseThisTopology.getID()+" not found"); 
    }
    
    // Asserting topologyListTest didn't add an existing topology
    assert(exTopolgoyList.size() == fileNamesVector.size()-1);
}

int main()
{
    std::vector<std::string> fileNamesVector(fileNamesArray, std::end(fileNamesArray));
    
    /****************************
     * Testing the add function *
     ****************************
     */
    testTopologyListAdd(fileNamesVector);

    /******************************
     * Testing the erase function *
     ******************************
     */
    testTopologyListErase(fileNamesVector);
}
