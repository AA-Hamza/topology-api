#include <device.hpp>
#include <exception>
#include <iostream>

using namespace topology;

std::string Device::getID() const
{
    return m_deviceID;
}

std::string Device::getType() const
{
    return m_deviceType;
}

const std::map<std::string, std::string> &Device::getNetList() const
{
    return m_netList;
}

const std::map<std::string, double> &Device::getProperties() const
{
    return m_deviceProperties;
}