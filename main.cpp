#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include <stdlib.h>
#include "genetic_algo.hpp"
const int CITIE_IN_TOUR = 32;
const int POPULATION_SIZE = 32;
const int SHUFFLES = 64;
const int ITERATIONS = 1000;

using namespace std;

int main() {

    double x, y;
    char char1, char2, char3;
    tour tour;
    genetic_algo ga;

    //Generate city list
    for(int i = 0; i < CITIE_IN_TOUR; i++) {
        x = rand() % 1000 + 1;
        y = rand() % 1000 + 1;
        char1 = rand() % 26 + 65;
        char2 = rand() % 26 + 97;
        char3 = rand() % 26 + 97;
        char str[] = {char1, char2, char3};
        string s{str};
        city c{s, x, y};
        if (!tour.city_exist(c)) {
            tour.add_tour(c);
        } else {
            i--;
        }
    }

    //Generate population list
    int pop_size = 0;
    while(pop_size < POPULATION_SIZE) {
        int shuffle = 0;
        while(shuffle < SHUFFLES) {
            tour.shuffle_cities();
        }
        if(!ga.tour_exist(tour)) {
            ga.add_tour(tour);
        } else {
            pop_size--;
        }
        pop_size++;
    }

    int iteration = 0;
    while(iteration < ITERATIONS || ga.evaluation() == 0) {
        ga.selection();
        ga.crossover();
        ga.mutation();
        iteration++;
    }

    ga.report();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}