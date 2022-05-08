#include <topology.hpp>
#include <topologyAPI.hpp>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<topology::Topology> exTopologies;
    auto myTopology = topology::readJSON("exampleTopology.json");
    //exTopologies.push_back(myTopology);
    //topology::TopologyList myList(exTopologies);
    //cout << myTopology.getID() << endl;
}
