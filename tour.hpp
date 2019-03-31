#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include "city.hpp"

const int MUTATION_RATE = 15;
const int TOTAL_RATE = 100;

using namespace std;

class tour {
private:
    vector<city> citylist;
    double fitness;
    double distance;

public:
    tour() {};
    void add_tour(city);
    void remove_city(city);
    inline vector<city> get_city_list() const {return citylist;};
    bool city_exist(city);
    double get_distance();
    void generate_fitness();
    double get_fitness() const;
    void shuffle_cities();
    void mutation();
    void print_city();

    tour& operator=(tour& rhs) {
        this->citylist = rhs.citylist;
        this->fitness = rhs.get_fitness();
        return *this;
    }
    bool operator==(const tour& rhs) {
        for(auto it1 = citylist.begin(); it1 != citylist.end(); ++it1) {
            for(auto it2 = rhs.get_city_list().begin(); it2 != rhs.get_city_list().end(); ++it2) {
                if(it1->get_coordinates() != it2->get_coordinates()) {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator!=(const tour& rhs) {
        return ((*this)==rhs);
    }
    bool operator<(const tour& rhs) {
        return (this->get_fitness() < rhs.get_fitness());
    }
};



#endif //GENETICALGORITHM_TOUR_HPP
