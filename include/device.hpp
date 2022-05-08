#ifndef DEVICE_H
#define DEVICE_H

#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

namespace topology {
  class Device {
    public:
      /**
      * @param deviceJson A json object representing the device
      */
      Device(const json &deviceJson);

      /**
      * @return returns the type of the Device
      */
      std::string getType() const;

      /**
      * @return returns a map<string, double> representing a copy of device properites
      */
      std::map<std::string, double> getProperties() const;

    private:
      std::string m_deviceID;
      std::string m_deviceType;
      std::map<std::string, double> m_deviceProperties;
      std::vector<std::map<std::string, std::string>> m_netList;
  };
}
#endif