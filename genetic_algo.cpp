//
// Created by Bruce Dayton on 2019-03-22.
//

#include "genetic_algo.hpp"

void genetic_algo::add_tour(tour t) {
    population_list.push_back(t);
}

void genetic_algo::selection() {
    double max = 0;
    auto elite = population_list.begin();
    for(auto it = population_list.begin(); it != population_list.end(); ++it) {
        if(it->get_tour_distance() > max) {
            max = it->get_tour_distance();
            elite = it;
        }
    }
    this->elite = *elite;
}

