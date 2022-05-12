#include "topology.hpp"
#include "topologyIO.hpp"
#include "topologyList.hpp"
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace topology;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Invalid arguments" << endl;
        cerr << "Usage: " << argv[0] << " path/to/file1 path/to/file2" << endl;
        exit(-1);
    }
    TopologyList myTopologyList;

    Topology Topology1 = readJSON(argv[1]);
    cout << Topology1.getID() << endl;

    Topology Topology2 = readJSON(argv[2]);
    cout << Topology2.toJson().dump(2) << endl; // Will print Topology2 in json format on screen

    myTopologyList.add(Topology1);
    myTopologyList.add(Topology2);

    cout << myTopologyList.size() << endl; // Will print 2 on screen
    myTopologyList.erase(Topology2.getID());
    cout << myTopologyList.size() << endl; // Will print 1 on screen

    auto connectedDevices = Topology1.getDevicesConnectedTo("n1");
    for (auto device : connectedDevices)
    {
        cout << device->getID() << endl;
    }

    for (auto device : Topology2.getDevices())
    {
        cout << device->getID() << endl;
    }

    return 0;
}