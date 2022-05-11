#ifndef DEVICE_H
#define DEVICE_H

#include <nlohmann/json.hpp>
#include <string>

namespace topology
{
/**
 * @brief base class containing basic functionality of every device
 */
class Device
{
  public:
    /**
     * @brief Compiler default constructor, used for initializing differnt data types
     */
    Device(){};

    /**
     * @return returns the ID of the Device
     */
    std::string getID() const;

    /**
     * @return returns the type of the Device
     */
    std::string getType() const;

    /**
     * @brief Gets Device properties
     * @return returns a const reference to Device properties
     */
    const std::map<std::string, double> &getProperties() const;

    /**
     * @brief Gets Device net list
     * @return returns a const reference to Device netList
     */
    const std::map<std::string, std::string> &getNetList() const;

    /**
     * Make a json representation of Device
     * Will get overridden by derived devices
     * @return the json object of Device
     */
    virtual nlohmann::json toJson() const = 0;

    /**
     * Virtual destructor needed as this is the base class
     */
    virtual ~Device()
    {
    }

  protected:
    std::string m_deviceID;
    std::string m_deviceType;
    std::map<std::string, double> m_deviceProperties;
    std::map<std::string, std::string> m_netList;
};
} // namespace topology
#endif