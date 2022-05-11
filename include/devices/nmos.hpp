#ifndef NMOS_DEVICE_H
#define NMOS_DEVICE_H

#include "device.hpp"
#include <nlohmann/json.hpp>
#include <string>

namespace topology
{
/**
 * @brief Nmos (N-type metal-oxide-semiconductor) device
 */
class Nmos : public Device
{
  public:
    /**
     * @brief Construct a N-type metal-oxide-semiconductor from the json representation
     * @param deviceJson A json object representing the nmos
     */
    Nmos(const nlohmann::json &deviceJson);

    // Override Device toJson
    nlohmann::json toJson() const override;
};
} // namespace topology
#endif