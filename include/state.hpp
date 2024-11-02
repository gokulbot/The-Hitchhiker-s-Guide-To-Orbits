#ifndef THE_HITCHHIKER_S_GUIDE_TO_ORBITS_STATE_HPP
#define THE_HITCHHIKER_S_GUIDE_TO_ORBITS_STATE_HPP

#include <iostream>

class State {
  private:
    int state_id;
    float x;
    float y;
    float alpha;
    float e;
    float p;
    float omega;
  
  public:
    State();
    State(int state_id, float x, float y, float alpha, float e, float p, float omega);

    void set_state(int state_id, float x, float y, float alpha, float e, float p, float omega);
    void print_state() const;
    void sample_next(State &next_state) const;
    float transition_cost(const State &next_state) const;
    bool feasibility_check(const State &next_state) const;
};

#endif // THE_HITCHHIKER_S_GUIDE_TO_ORBITS_STATE_HPP