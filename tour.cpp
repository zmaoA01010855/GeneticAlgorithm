#include "tour.hpp"

void tour::add_tour(city c) {
    citylist.push_back(c);
}

double tour::get_tour_distance() {
    double distance = 0;
    for(auto it = citylist.begin(); it != citylist.end() - 1; ++it) {
        distance += it->get_distance_between_cities(*(it + 1));
    }
    return distance;
}

void tour::shuffle_cities() {
    auto ran_gen = default_random_engine{};
    shuffle(citylist.begin(), citylist.end(), ran_gen);
}

void tour::mutation() {
    auto it = citylist.begin();
    for(; it != citylist.end() - 1; ++it) {
        int num = rand() % TOTAL_RATE;
        if(num < MUTATION_RATE) {
            city temp = *(it + 1);
            *(it + 1) = *it;
            *it = temp;
        }
    }

    int num = rand() % TOTAL_RATE;
    if(num < MUTATION_RATE) {
        city temp = *(citylist.begin());
        *(citylist.begin()) = *it;
        *it = temp;
    }
}