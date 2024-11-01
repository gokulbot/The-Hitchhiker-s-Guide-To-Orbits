//
// Created by gsanthosh on 1/11/24.
//

#ifndef THE_HITCHHIKER_S_GUIDE_TO_ORBITS_PRIMITIVES_HPP
#define THE_HITCHHIKER_S_GUIDE_TO_ORBITS_PRIMITIVES_HPP

struct Edge {
  int id_1;
  int id_2;
  int edge_index;
};

class Edges : public Points {
private:
  int last_edge_idx;
  std::map<int, Edge> edge_list;

public:
  Edges();
  int set_edge(int id_1, int id_2);
  void change_id(int new_id, int id_2);
  void print_edges();
};

#endif // THE_HITCHHIKER_S_GUIDE_TO_ORBITS_PRIMITIVES_HPP
