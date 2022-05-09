#include <exception>
#include <ios>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <ostream>
#include <topologyIO.hpp>

// for convenience
using json = nlohmann::json;
//using namespace std;
//using namespace topology;

topology::Topology topology::readJSON(const std::string fileName) {
    json fileJson;
    try {
        if (fileName.empty())  {
            // Use stdin if fileName is empty
            std::cin >> fileJson;
        }
        else {
            std::ifstream file(fileName);
            if (file.is_open()) {
                file >> fileJson;
            }
            else {
                std::cerr << "Couldn't Open file " << fileName << std::endl;
                exit(-1);
            }
            file.close();
        }
    }
    catch (json::exception &e) {
        std::cerr << "Error parsing json from " << fileName << std::endl;
        throw e;
    }
    return Topology(fileJson);
}

void topology::writeJSON(const topology::TopologyList &topologyList, const std::string topolgoyID, std::string fileName) {
    if (fileName.empty()) {
        fileName = topolgoyID;
    }

    std::ofstream file(fileName);
    //Toplogy fileJson = topologyList[topolgoyID];
}
