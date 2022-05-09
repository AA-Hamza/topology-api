#ifndef RESISTOR_DEVICE_H
#define RESISTOR_DEVICE_H

#include <nlohmann/json.hpp>
#include <string>
#include <device.hpp>

using json = nlohmann::json;

namespace topology {
  /**
  * @brief Resistor device
  */
  class Resistor : public Device {
    public:
      /**
      * Construct a Resistor from the json representation
      * @param deviceJson A json object representing the resistor
      */
      Resistor(const json &deviceJson);
      virtual json toJson() const override;
  };
}
#endif