#ifndef DEVICE_H
#define DEVICE_H

#include <nlohmann/json.hpp>
#include <string>
#include <iostream>

using json = nlohmann::json;

namespace topology {
  class Device {
    public:
      Device() {}
      /**
      * @return returns the type of the Device
      */
      std::string getType() const;

      /**
      * @return returns a map<string, double> representing a copy of device properites
      */
      std::map<std::string, double> getProperties() const;

      /**
      * @return the net list of the device
      */
      std::vector<std::pair<std::string, std::string>> getNetList() const;


      /**
      * @return the json representation of the device
      */
      virtual json toJson() const {
        return json();  // Will get overriden by devices, here for compiler errors
      };

      virtual ~Device() {}

    protected:
      std::string m_deviceID;
      std::string m_deviceType;
      std::map<std::string, double> m_deviceProperties;
      std::vector<std::pair<std::string, std::string>> m_netList;
  };
}
#endif