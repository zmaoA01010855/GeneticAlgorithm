#ifndef GENETICALGORITHM_GENETIC_ALGO_HPP
#define GENETICALGORITHM_GENETIC_ALGO_HPP

#include <map>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include "tour.hpp"

/**
 * Number of parents to cross over.
 */
const int NUM_PARENTS = 2;

/**
 * Number of elite tours.
 */
const int NUM_ELITE = 1;

/**
 * Total amount of tours.
 */
const int POPULATION_SIZE = 32;

using namespace std;

class genetic_algo {
private:
    /**
     * Store the base tour.
     */
    tour base_tour;

    /**
     * Store all tours.
     */
    vector<tour> population_list;

    /**
     * Store all tours except for elite tour.
     */
    multimap<double, tour> order_map;

    /**
     * Store all elite tours.
     */
    multimap<double, tour> elite;


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
