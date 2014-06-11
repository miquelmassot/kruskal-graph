/// Copyright 2014 Miquel Massot Campos
/// Systems, Robotics and Vision Group
/// University of the Balearican Islands
/// All rights reserved.

#include "kruskal/graph.h"

#include <functional>
#include <iostream>
#include <algorithm>

template<class T>
struct less_second
: std::binary_function<T, T, bool> {
  inline bool operator()(const T& lhs, const T& rhs) {
    return lhs.second < rhs.second;
  }
};

Graph::Graph(const int& nodes, const bool& directed) {
    nNodes = nodes;
    nEdges = 0;
    isDirected = directed;
}

Graph::~Graph() {}

clm_it Graph::getEdge(const int& s, const int&t) {
    std::pair<int, int> p(s, t);
    clm_it mit = link_map.find(p);
    return mit;
}

// Check if link exists between end nodes
bool Graph::edge(const int& s, const int& t) {
    return getEdge(s, t) != link_map.end();
}

// Add a link: map node pair with weight
void Graph::insert(const int& s, const int& t, const double& weight) {
    std::pair<int, int> p1(s, t);
    std::pair<int, int> p2(t, s);
    link_map[ p1 ] = weight;

    if (!isDirected) {
        link_map[ p2 ] = weight;
    }

    nEdges++;
}

// Remove selected link - remove both directions
// if graph is not directed
void Graph::remove(const int& s, const int& t) {
    std::pair<int, int> p1(s, t);
    std::map<std::pair<int, int>, double>::iterator mit = link_map.find(p1);
    link_map.erase(mit);

    if (!isDirected) {
    std::pair<int, int> p2(t, s);
        mit = link_map.find(p2);
        link_map.erase(mit);
    }

    nEdges--;
}

// Print the network topology
void Graph::show() const {
  clm_it mit = link_map.begin();

  for ( ; mit != link_map.end(); ++mit) {
    std::pair<int, int> p = (*mit).first;
    std::cout << p.first  << " " <<
            p.second << " " <<
            (*mit).second << std::endl;
  }
}

// Return true if graph is directed; false otherwose
bool Graph::directed() const {
    return isDirected;
}

// Return number of network nodes
int Graph::V() const {
    return nNodes;
}

// Return number of edges
int Graph::E() const {
    return nEdges;
}

// Sort the weighted edges
std::vector<data_t> Graph::sortedEdges() {
  std::vector<data_t> vec(link_map.begin(), link_map.end());
  std::sort(vec.begin(), vec.end(), less_second<data_t>());
  return vec;
}

std::vector<data_t> Graph::kruskal() {
  int number;
  std::vector<data_t> mst;
  mst.clear();

  const int kNodes = nNodes;
  int cicles[kNodes];

  std::vector<data_t> edges = sortedEdges();

  for (int i = 0; i < kNodes; i++) cicles[ i ] = i;

  while (static_cast<int>(mst.size()) < (kNodes - 1) && edges.size()) {
    data_t dt = edges[ 0 ];
    std::pair<int, int> p = dt.first;
    int vi = p.first;
    int vj = p.second;

    if (cicles[ vi ] != cicles[vj]) {
      number = cicles[ vj ];
      for (int i = 0; i < kNodes; i++) {
        if (cicles[ i ] == number) {
          cicles[ i ] = cicles[ vi ];
        }
      }
      mst.push_back(dt);
    }
    edges.erase(edges.begin(), edges.begin() + 1);
  }
  return mst;
}
