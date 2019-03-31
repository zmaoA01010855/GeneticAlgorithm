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
    tour() {};
    tour(vector<city> a) : citylist(a), fitness(0) {};
    void add_tour(city);
    double get_tour_distance();
    inline double get_fitness() {return fitness;}
    void shuffle_cities();
    void mutation();
    bool operator==(tour& rhs) {
        for(auto it1 = citylist.begin(); it1 != citylist.end(); ++it1) {
            for(auto it2 = rhs.citylist.begin(); it2 != rhs.citylist.end(); ++it2) {
                if(it1->get_coordinates() != it2->get_coordinates()) {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator!=(tour& rhs) {
        return ((*this)==rhs);
    }
};



#endif //GENETICALGORITHM_TOUR_HPP
