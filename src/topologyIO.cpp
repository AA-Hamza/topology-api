#include <exception>
#include <ios>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "topology.hpp"
#include "topologyIO.hpp"

using json = nlohmann::json;

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
                std::ios_base::failure("Can't open file");
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

void topology::writeJSON(const topology::Topology &outputTopolgoy, std::string fileName) {
    if (fileName.empty()) {
        fileName = outputTopolgoy.getID();
    }

    std::ofstream file;

    // To delete file previous content
    file.open(fileName, std::ofstream::out | std::ofstream::trunc);

    if (file.is_open()) {
        const auto &json = outputTopolgoy.toJson();
        file << json.dump(2);
        file.close();
    }
    else {
        std::ios_base::failure("Can't open file");
    }
}
