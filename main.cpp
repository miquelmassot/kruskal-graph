/// Copyright 2014 Miquel Massot Campos
/// Systems, Robotics and Vision Group
/// University of the Balearican Islands
/// All rights reserved.

#include "kruskal/graph.h"

#include <iostream>
#include <algorithm>

int main() {
  /*Graph G(11, true);

  G.insert(0, 1, 1.0);
  G.insert(0, 2, 0.6);
  G.insert(0, 3, 1.0);
  G.insert(0, 4, 1.0);
  G.insert(0, 5, 1.1);
  G.insert(1, 4, 1.8);
  G.insert(1, 10, 1.9);
  G.insert(2, 3, 2.1);
  G.insert(2, 5, 2.3);
  G.insert(2, 6, 1.7);
  G.insert(3, 4, 1.7);
  G.insert(5, 6, 0.5);
  G.insert(5, 7, 0.7);
  G.insert(5, 8, 0.9);
  G.insert(5, 9, 0.9);
  G.insert(5, 10, 1.0);
  G.insert(6, 7, 1.9);
  G.insert(7, 8, 1.7);
  G.insert(8, 9, 1.6);
  G.insert(9, 10, 2.2);*/
  Graph G(5, true);
  G.insert(0, 1, -6);
  G.insert(0, 2, -8);
  G.insert(0, 3, -1);
  G.insert(0, 4, -5);
  G.insert(1, 3, -8);
  G.insert(2, 4, -6);

  G.show();

  std::cout << std::endl;

  std::vector<data_t> vec = G.kruskal();

  for (std::vector<data_t>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::pair<int, int> p = (*it).first;
    double weight = (*it).second;
    std::cout << p.first << " " << p.second << " " << weight << std::endl;
  }
  return 0;
}
