#include "../include/state.hpp"

State::State() {
  state_id = 0;
  x = 0;
  y = 0;
  alpha = 0;
  e = 0;
  p = 0;
  omega = 0;
}

State::State(int state_id, float x, float y, float alpha, float e, float p, float omega) {
  this->state_id = state_id;
  this->x = x;
  this->y = y;
  this->alpha = alpha;
  this->e = e;
  this->p = p;
  this->omega = omega;
}

void State::set_state(int state_id, float x, float y, float alpha, float e, float p, float omega) {
  this->state_id = state_id;
  this->x = x;
  this->y = y;
  this->alpha = alpha;
  this->e = e;
  this->p = p;
  this->omega = omega;
}

void State::print_state() const {
  std::cout << state_id << "; " << x << "; " << y << "; " << alpha << "; " << e << "; " << p << "; " << omega << std::endl;
}

void State::sample_next(State &next_state) const {
  next_state.state_id = state_id + 1;
  next_state.x = x + 1;
  next_state.y = y + 1;
  next_state.alpha = alpha + 1;
  next_state.e = e + 1;
  next_state.p = p + 1;
  next_state.omega = omega + 1;
}

float State::transition_cost(const State &next_state) const {
  return 0;
}

bool State::feasibility_check(const State &next_state) const {
  return true;
}