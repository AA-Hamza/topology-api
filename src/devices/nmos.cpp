#include <exception>
#include <nlohmann/json.hpp>
#include <iostream>
#include "devices/nmos.hpp"
#include "device.hpp"

using namespace topology;
using json = nlohmann::json;

// Constructor
Nmos::Nmos(const json &deviceJson) {
  try {
    m_deviceID = deviceJson.at("id");
    m_deviceType = deviceJson.at("type");
    json properites = deviceJson.at("m(l)");
    m_deviceProperties.insert(std::make_pair("default", properites.at("default")));
    m_deviceProperties.insert(std::make_pair("min", properites.at("min")));
    m_deviceProperties.insert(std::make_pair("max", properites.at("max")));
    json netList = deviceJson.at("netlist");
    for (const auto &node : netList.items()) {
      // Changing from json key value pair to ordinary cpp pair
      m_netList[node.key()] = node.value();
    }
  }
  catch (const json::exception &e){
    std::cerr << "Error parsing nmos device" << std::endl;
    throw e;
  }
}

// To json
json Nmos::toJson() const {
  json jsonRepresentation;
  jsonRepresentation["type"] = m_deviceType;
  jsonRepresentation["id"] = m_deviceID;
  jsonRepresentation["m(l)"] = m_deviceProperties;
  jsonRepresentation["netlist"] = m_netList;
  return jsonRepresentation;
}
