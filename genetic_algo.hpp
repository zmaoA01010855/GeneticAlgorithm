#ifndef GENETICALGORITHM_GENETIC_ALGO_HPP
#define GENETICALGORITHM_GENETIC_ALGO_HPP

#include <map>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include "tour.hpp"

const int NUM_PARENTS = 2;
const int NUM_ELITE = 1;
const int POPULATION_SIZE = 32;

using namespace std;

class genetic_algo {
private:
    vector<tour> population_list;
    multimap<double, tour> order_map;
    multimap<double, tour> elite;
    double fitness;


public:
    genetic_algo(){};
    void add_tour(tour);
    tour get_fittest_tour();
    tour merge(vector<tour>);
    multimap<double, tour> generate_tour_order(vector<tour> t);
    bool tour_exist(tour);
    void selection();
    void crossover();
    void mutation();
    double evaluation();
    void report();

};


#endif //GENETICALGORITHM_GENETIC_ALGO_HPP
