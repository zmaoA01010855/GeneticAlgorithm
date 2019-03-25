#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP
#include <vector>
#include <math.h>
#include <algorithm>
#include <random>
#include "city.hpp"

const int MUTATION_RATE = 15;
const int TOTAL_RATE = 100;

using namespace std;

class tour {
private:
    vector<city> citylist;
    double fitness;

public:
    tour(vector<city> a) : citylist(a), fitness(0) {};
    void add_tour(city);
    double get_tour_distance();
    void shuffle_cities();
    void mutation();
};



#endif //GENETICALGORITHM_TOUR_HPP
