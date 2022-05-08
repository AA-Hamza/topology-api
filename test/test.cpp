#include <topology.hpp>
#include <topologyAPI.hpp>
#include <iostream>
#include <vector>
#include <filesystem>
//using namespace std;

int main()
{
    std::vector<topology::Topology> exTopologies;
    std::filesystem::path exFile = "exampleTopology.json";
    std::string fileFullPath = std::string(std::filesystem::absolute(exFile));
    auto myTopology = topology::readJSON(fileFullPath);
    //exTopologies.push_back(myTopology);
    //topology::TopologyList myList(exTopologies);
    //cout << myTopology.getID() << endl;
}
