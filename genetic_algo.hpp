#ifndef GENETICALGORITHM_GENETIC_ALGO_HPP
#define GENETICALGORITHM_GENETIC_ALGO_HPP

#include "tour.hpp"

const int CITIE_IN_TOUR = 32;
const int POPULATION_SIZE = 32;
const int SHUFFLES = 64;
const int ITERATIONS = 1000;
const int PARENT_POOL_SIZE = 5;
const int NUM_PARENTS = 2;
const int NUM_ELITE = 1;

class genetic_algo {
private:
    vector<tour> population_list;
    tour elite;
    vector<tour> parent;
public:
    genetic_algo();
    void add_tour(tour);
    void selection();
    void crossover(tour, tour);
    void mutation(tour);
};


#endif //GENETICALGORITHM_GENETIC_ALGO_HPP
