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


Topology TopologyList::operator[](std::string topologyID) {
  if (m_topologies.find(topologyID) != m_topologies.end()) {
    return m_topologies[topologyID];
  }
  else {
    throw std::invalid_argument("Topology ID not found");
  }
}

bool TopologyList::add(const Topology &topology) {
  if (m_topologies.find(topology.m_topologyID) == m_topologies.end()) {
    m_topologies[topology.m_topologyID] = topology;
    return true;
  }
  else {
    throw std::invalid_argument("Topology already exists");
  }
  return false;
}

bool TopologyList::erase(const std::string topologyID) {
  auto it = m_topologies.find(topologyID);
  if (it != m_topologies.end()) {
    m_topologies.erase(it);
    return true;
  }
  else {
    throw std::invalid_argument("Topology ID was not found");
  }
  return false;
}

size_t TopologyList::size() const {
  return m_topologies.size();
}

std::map<std::string, Topology>::const_iterator TopologyList::cbegin() const {
  return m_topologies.cbegin();
}

std::map<std::string, Topology>::const_iterator TopologyList::cend() const {
  return m_topologies.cend();
}
