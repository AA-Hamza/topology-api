#ifndef DEVICE_H
#define DEVICE_H

#include <nlohmann/json.hpp>
#include <string>
#include <iostream>

using json = nlohmann::json;

namespace topology {
  /**
  * @brief base class containing basic functionality of every device
  */
  class Device {
    public:
      /**
      * @brief Compiler default constructor, used for initializing differnt data types
      */ 
      Device() {}

      /**
      * @return returns the type of the Device
      */
      std::string getType() const;

      /**
      * Make a copy of m_deviceProperties and return it
      * @return returns a map<string, double> representing a copy of device properites
      */
      std::map<std::string, double> getProperties() const;

      /**
      * Make a copy of Device m_netList and return it
      * @return the net list of the Device
      */
      std::vector<std::pair<std::string, std::string>> getNetList() const;


      /**
      * Make a json representation of Device
      * Will get overridden by derived devices
      * @return the json object of Device
      */
      virtual json toJson() const {
        return json();  // returns empty object, here for compiler errors
      };

      /**
      * Virtual destructor needed as this is the base class
      */
      virtual ~Device() {}

    protected:
      std::string m_deviceID;
      std::string m_deviceType;
      std::map<std::string, double> m_deviceProperties;
      std::vector<std::pair<std::string, std::string>> m_netList;
  };
}
#endif