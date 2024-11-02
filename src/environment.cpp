#include "../include/environment.hpp"
#include <vector>
#include <cmath>
#include <random>
#include <numeric>
#include <limits>

Environment::Environment(){
    planets = std::vector<std::pair<float, float>>();
}

void Environment::add_planet(float x, float y){
    planets.push_back(std::pair<float, float>(x, y));
}

void Environment::print_environment() const {
    for (auto &planet : planets) {
        std::cout << planet.first << "; " << planet.second << std::endl;
    }
}

const std::vector<std::pair<float, float>>& Environment::get_planets() const {
    return planets;
}

float Environment::distance(const std::pair<float, float>& p1, const std::pair<float, float>& p2) const {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

const std::pair<float, float>& Environment::sample_next_planet(const std::pair<float, float>& current, const std::pair<float, float>& goal) const {
    // Step 1: Calculate combined distances
    std::vector<float> combined_distances;
    for (const auto& planet : planets) {
        float dist = distance(planet, current) + distance(planet, goal);
        // Avoid very small distances by capping at a minimum threshold
        combined_distances.push_back(dist > 0 ? 1.0f / dist : std::numeric_limits<float>::max());
    }

    // Step 2: Normalize to create probabilities
    float sum_inverse_distances = std::accumulate(combined_distances.begin(), combined_distances.end(), 0.0f);
    std::vector<float> probabilities;
    for (float inverse_distance : combined_distances) {
        probabilities.push_back(inverse_distance / sum_inverse_distances);
    }

    // Step 3: Set up random sampling with probabilities
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> dist(probabilities.begin(), probabilities.end());

    // Step 4: Sample an index based on the distribution
    int selected_index = dist(gen);
    return planets[selected_index];
}