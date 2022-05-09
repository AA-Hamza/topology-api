#include <device.hpp>
#include "devices/resistor.hpp"
#include <exception>
#include <sstream>
#include <topology.hpp>
#include <topologyIO.hpp>
#include <topologyList.hpp>
#include <iostream>
#include <vector>
//#include <filesystem>

#define FILES_COUNT 5
int main()
{
    topology::TopologyList topolgoyListTest;
    
    /****************************
     * Testing the add function *
     ****************************
     */
    for (int i = 1; i <= FILES_COUNT; ++i) {
        // Preparing the file
        std::stringstream exFileName;
        exFileName << "topologies/ex" << i << ".json";

        // Opening the file
        //std::filesystem::path exFile = exFileName.str();
        //std::string fileFullPath = std::string(std::filesystem::absolute(exFile));

        // Making a topology & adding it to the topologyList
        //assert(topolgoyListTest.add(topology::readJSON(fileFullPath)) == true);
        assert(topolgoyListTest.add(topology::readJSON(exFileName.str())) == true);
    }

    // adding an already existing topology
    try {
        std::string exFile = "topologies/ex1.json";
        //std::filesystem::path exFile = "topologies/ex1.json";
        //std::string fileFullPath = std::string(std::filesystem::absolute(exFile));

        // Making a topology & adding it to the topologyList
        assert(topolgoyListTest.add(topology::readJSON(exFile)) == true);

    }
    catch (std::exception &e) {
        assert(e.what() == std::string("Topology already exists"));
    }

    // Asserting topologyListTest contains FILES_COUNT topologies
    assert(topolgoyListTest.size() == FILES_COUNT);


    /******************************
     * Testing the erase function *
     ******************************
     */
    topology::Topology eraseThisTopology = topolgoyListTest.cbegin()->second;
    // Asserting that the size of topologyListTest went down by 1
    topolgoyListTest.erase(eraseThisTopology.getID());
    assert(topolgoyListTest.size() == FILES_COUNT-1);
    // Try acessing the deleted topology ID
    try {
        topolgoyListTest[eraseThisTopology.getID()];
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        assert(e.what() == std::string("topologyID not found")); 
    }

}
