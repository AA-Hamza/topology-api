#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <ostream>
#include <topologyAPI.hpp>

// for convenience
using json = nlohmann::json;
using namespace std;
//using namespace topology;

topology::Topology topology::readJSON(const std::string fileName) {
    json fileJson;
    ifstream file(fileName);
    try {
        file >> fileJson;
    }
    catch (json::exception &e) {
        std::cerr << "Error reading from " << fileName << std::endl;
        throw e;
    }
    return Topology(fileJson);
}

void topology::writeJSON(const topology::TopologyList &topologyList, const std::string topolgoyID, std::string fileName) {
    if (fileName.empty()) {
        fileName = topolgoyID;
    }

    ofstream file(fileName);
    //Toplogy fileJson = topologyList[topolgoyID];
}
