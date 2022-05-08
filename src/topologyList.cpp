#include <topologyList.hpp>
#include <topology.hpp>

using namespace topology;

TopologyList::TopologyList(const std::vector<Topology> &topologiesSrc) {
  for (size_t i = 0; i < topologiesSrc.size(); ++i) {
    Topology tmp = topologiesSrc[i];
    topologies.insert(make_pair(tmp.m_topologyID, tmp));
  }
}

const Topology &TopologyList::operator[](std::string topologyID) {
  if (topologies.find(topologyID) != topologies.end()) {
    return topologies[topologyID];
  }
  else {
    throw "Topology ID not found";
  }
}

Topology *TopologyList::add(const Topology &topology) {
  if (topologies.find(topology.m_topologyID) == topologies.end()) {
    topologies[topology.m_topologyID] = topology;
    return &topologies[topology.m_topologyID];
  }
  else {
    throw "Topology already exists";
  }
  return NULL;
}

bool TopologyList::erase(const std::string topologyID) {
  auto it = topologies.find(topologyID);
  if (it != topologies.end()) {
    topologies.erase(it);
    return true;
  }
  return false;
}