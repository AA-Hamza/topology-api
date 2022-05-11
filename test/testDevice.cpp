#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "test.h"
#include "topologyIO.hpp"
#include "topology.hpp"
#include "device.hpp"

inline void testDeviceGetID(const topology::Device &device, const nlohmann::json &deviceJson) {
  assert(device.getID() == deviceJson.at("id"));
}

inline void testDeviceGetType(const topology::Device &device, const nlohmann::json &deviceJson) {
  assert(device.getType() == deviceJson.at("type"));
}

inline void testDeviceGetProperties(const topology::Device &device, const nlohmann::json &deviceJson) {
  const std::string deviceType = device.getType();
  if (deviceType == "resistor") {
    assert(device.getProperties() == deviceJson.at("resistance"));
  }
  else if (deviceType == "nmos") {
    assert(device.getProperties() == deviceJson.at("m(l)"));
  }
}


inline void testDeviceGetNetList(const topology::Device &device, const nlohmann::json &deviceJson) {
  assert(device.getNetList() == deviceJson.at("netlist"));
}

inline void testDeviceToJson(const topology::Device &device, const nlohmann::json &deviceJson) {
  assert(device.toJson() == deviceJson);
}

int main()
{

  std::vector<std::string> fileNamesVector(fileNamesArray, std::end(fileNamesArray));
  for (const auto &fileName : fileNamesVector) {
    std::ifstream file(fileName);
    nlohmann::json topologyJson;
    file >> topologyJson;
    topology::Topology exTopology = topology::readJSON(fileName);
    const auto &devices = exTopology.getDevices();
    const nlohmann::json::array_t devicesFromJson = topologyJson.at("components");

    assert(devices.size() == devicesFromJson.size());

    // Json arrays order is guranteed
    for (size_t i = 0; i < devices.size(); ++i) {
      auto const &device = *devices[i];
      auto const &deviceJson = devicesFromJson[i];
      testDeviceGetID(device, deviceJson);
      testDeviceGetNetList(device, deviceJson);
      testDeviceGetProperties(device, deviceJson);
      testDeviceGetType(device, deviceJson);
      testDeviceToJson(device, deviceJson);
    }
  }
}
