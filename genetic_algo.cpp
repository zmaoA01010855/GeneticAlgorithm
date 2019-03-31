//
// Created by Bruce Dayton on 2019-03-22.
//

#include "genetic_algo.hpp"

genetic_algo::genetic_algo(vector<tour> tourlist) {
    for(auto it = tourlist.begin(); it != tourlist.end(); ++it) {
        population_list.insert(make_pair((*it), it->get_fitness()));
    }
    elite = get_best_elite();

}

tour genetic_algo::get_best_elite() {
    double fitness = INT8_MAX;
    tour fittest = population_list.begin()->first;
    for(auto it = population_list.begin(); it != population_list.end(); ++it) {
        if(it->second < fitness) {
            fitness = it->second;
            fittest = it->first;
        }
    }
}

void genetic_algo::selection() {
    double fitness = INT8_MAX;
    tour fittest = population_list.begin()->first;
    for(auto it = population_list.begin(); it != population_list.end(); ++it) {
        if(it->second < fitness) {
            fitness = it->second;
            fittest = it->first;
        }
    }
    this->set_elite(fittest);
}

void genetic_algo::crossover(vector<tour> parent) {
    for()
}


