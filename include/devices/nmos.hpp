#ifndef NMOS_DEVICE_H
#define NMOS_DEVICE_H

#include <nlohmann/json.hpp>
#include <string>
#include <device.hpp>

using json = nlohmann::json;

namespace topology {
  class Nmos : public Device {
    public:
      /**
      * Construct a N-type metal-oxide-semiconductor from the json representation
      * @param deviceJson A json object representing the nmos
      */
      Nmos(const json &deviceJson);
      virtual json toJson() const override;
  };
}
#endif