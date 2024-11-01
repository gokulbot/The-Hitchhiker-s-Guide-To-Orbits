//
// Created by gsanthosh on 1/11/24.
//
#include "../include/primitives.hpp"
Edges::Edges() { last_edge_idx = 0; }

int Edges::set_edge(int id_1, int id_2) {
  Edge e{};
  e.edge_index = last_edge_idx++;
  e.id_1 = id_1;
  e.id_2 = id_2;

  edge_list.insert(std::pair<int, Edge>(e.edge_index, e));

  return e.edge_index;
}

void Edges::change_id(int new_id, int id_2) {
  std::map<int, Edge>::iterator it;

  for (it = edge_list.begin(); it != edge_list.end(); it++) {
    if (it->second.id_2 == id_2) {
      it->second.id_1 = new_id;
    }
  }
}

void Edges::print_edges() {
  std::map<int, Edge>::iterator it;
  for (it = edge_list.begin(); it != edge_list.end(); it++) {
    std::cout << it->second.edge_index << "; " << it->second.id_1 << "; "
              << it->second.id_2 << std::endl;
  }
}
