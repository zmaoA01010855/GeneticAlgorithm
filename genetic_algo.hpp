#ifndef GENETICALGORITHM_GENETIC_ALGO_HPP
#define GENETICALGORITHM_GENETIC_ALGO_HPP

#include <map>
#include "tour.hpp"



const int POPULATION_SIZE = 32;
const int SHUFFLES = 64;
const int ITERATIONS = 1000;
const int PARENT_POOL_SIZE = 5;
const int NUM_PARENTS = 2;
const int NUM_ELITE = 1;

class genetic_algo {
private:
    map<tour, double> population_list;
    tour elite;
    vector<tour> parent;

public:
    genetic_algo(vector<tour>);
    inline tour get_best_elite();
    inline void set_elite(tour elite) {this->elite = elite;}
    void selection();
    void crossover(vector<tour>);
//    void mutation(tour);
};


#endif //GENETICALGORITHM_GENETIC_ALGO_HPP
