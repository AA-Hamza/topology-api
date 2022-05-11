#include <exception>
#include <stdexcept>
#include <topologyList.hpp>
#include <topology.hpp>

using namespace topology;

TopologyList::TopologyList(const std::vector<Topology> &m_topologiesSrc) {
  for (size_t i = 0; i < m_topologiesSrc.size(); ++i) {
    Topology tmp = m_topologiesSrc[i];
    m_topologies.insert(make_pair(tmp.m_topologyID, tmp));
  }
}


const Topology &TopologyList::operator[](const std::string topologyID) const {
  if (m_topologies.find(topologyID) != m_topologies.end()) {
    return m_topologies.at(topologyID);
  }
  else {
    std::string err("topologyID: "+topologyID+" not found");
    throw std::invalid_argument(err);
  }
}

void TopologyList::add(const Topology &topology) {
  if (m_topologies.find(topology.m_topologyID) == m_topologies.end()) {
    m_topologies[topology.m_topologyID] = topology;
  }
  else {
    std::string err("topologyID: "+topology.m_topologyID+" already exists");
    throw std::invalid_argument(err);
  }
}

void TopologyList::erase(const std::string topologyID) {
  auto it = m_topologies.find(topologyID);
  if (it != m_topologies.end()) {
    m_topologies.erase(it);
  }
  else {
    std::string err("topologyID: "+topologyID+" not found");
    throw std::invalid_argument(err);
  }
}

size_t TopologyList::size() const {
  return m_topologies.size();
}

std::vector<std::string> TopologyList::getIDs() const {
  // reserve m_topologies size of string objects
  std::vector<std::string> topologyIDsVector(m_topologies.size());
  size_t index = 0;
  for (const auto &it : m_topologies) {
    topologyIDsVector[index++] = (it.first);
  }
  return topologyIDsVector;
}