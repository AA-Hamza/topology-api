#include "device.hpp"
#include "test.h"
#include "topology.hpp"
#include "topologyIO.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>
#include <vector>

void testTopologyGetID(const std::string fileName)
{
    topology::Topology exTopology = topology::readJSON(fileName);

    nlohmann::json jsonRepresentation;
    std::ifstream topologyFile(fileName);
    topologyFile >> jsonRepresentation;

    assert(jsonRepresentation.at("id") == exTopology.getID());
}

void testTopologyGetDevices(const std::string fileName)
{
    topology::Topology exTopology = topology::readJSON(fileName);
    const std::vector<std::shared_ptr<const topology::Device>> &connectedDevices = exTopology.getDevices();

    nlohmann::json jsonRepresentation;
    std::ifstream topologyFile(fileName);
    topologyFile >> jsonRepresentation;

    for (size_t i = 0; i < connectedDevices.size(); ++i)
    {
        assert(connectedDevices[i]->getID() == jsonRepresentation.at("components")[i].at("id"));
    }
}

void testTopologyToJson(const std::string fileName)
{
    topology::Topology exTopology = topology::readJSON(fileName);

    std::ifstream exFile(fileName);
    nlohmann::json jsonRepresentation;
    exFile >> jsonRepresentation;
    assert(jsonRepresentation == exTopology.toJson());
}

void testTopologyGetDevicesConnectedTo(const std::string fileName, const std::string netListNode)
{
    topology::Topology exTopology = topology::readJSON(fileName);
    const auto &connectedDevices = exTopology.getDevicesConnectedTo(netListNode);

    std::ifstream exFile(fileName);
    nlohmann::json jsonRepresentation;
    exFile >> jsonRepresentation;

    size_t index = 0;
    const nlohmann::json &components = jsonRepresentation.at("components");
    for (size_t i = 0; i < components.size(); ++i)
    {
        const nlohmann::json netList = components[i].at("netlist");
        for (const auto &it : netList.items())
        {
            if (it.value() == netListNode)
            {
                assert(connectedDevices[index++]->getID() == components[i].at("id"));
            }
        }
    }
}

int main()
{
    std::vector<std::string> fileNamesVector(fileNamesArray, std::end(fileNamesArray));

    /******************
     * Testing getID *
     *****************
     */
    for (const auto &fileName : fileNamesVector)
    {
        testTopologyGetID(fileName);
    }

    /*****************************
     * Testing getDevices       *
     ****************************
     */
    for (const auto &fileName : fileNamesVector)
    {
        testTopologyGetDevices(fileName);
    }

    /*****************************
     * Testing toJson           *
     ****************************
     */
    for (const auto &fileName : fileNamesVector)
    {
        testTopologyToJson(fileName);
    }

    /**********************************
     * Testing getDevicesConnectedTo *
     *********************************
     */
    const std::vector<std::string> netListNodes = {"vss", "n1", "vin", "vdd", "non-existing", ""};
    for (const auto &fileName : fileNamesVector)
    {
        for (const auto &node : netListNodes)
        {
            testTopologyGetDevicesConnectedTo(fileName, node);
        }
    }
}
