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
    private:
      std::string m_deviceID;
      std::string m_type;
  };
}
#endif