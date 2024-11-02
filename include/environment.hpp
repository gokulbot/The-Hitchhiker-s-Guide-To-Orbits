#ifndef THE_HITCHHIKER_S_GUIDE_TO_ORBITS_ENVIRONMENT_HPP
#define THE_HITCHHIKER_S_GUIDE_TO_ORBITS_ENVIRONMENT_HPP

#include <iostream>
#include <vector>

class Environment {
  private:
    std::vector<std::pair<float, float>> planets;

  public:
    Environment();
    
    void add_planet(float x, float y);
    void print_environment() const;
    const std::vector<std::pair<float, float>>& get_planets() const;
    float distance(const std::pair<float, float>& p1, const std::pair<float, float>& p2) const;
    const std::pair<float, float>& sample_next_planet(const std::pair<float, float>& current, const std::pair<float, float>& goal) const;
};

#endif // THE_HITCHHIKER_S_GUIDE_TO_ORBITS_ENVIRONMENT_HPP