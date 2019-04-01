#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include <stdlib.h>
#include "genetic_algo.hpp"

/**
 * Number of cities in the tour.
 */
const int CITIE_IN_TOUR = 32;

/**
 * Times to shuffle the city list inside of tour.
 */
const int SHUFFLES = 64;

/**
 * Iteration time.
 */
const int ITERATIONS = 1000;

/**
 * Value the fitness to decide iteration should stop or not.
 */
const double IMPROVEMENT = 0;

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
            tour.add_city(c);
        } else {
            i--;
        }
    }

    tour.print_city();
    cout << "Last input tour: " << tour.get_distance() << endl;

    //Generate population list
    int pop_size = 0;
    while(pop_size < POPULATION_SIZE) {
        int shuffle = 0;
        while(shuffle < SHUFFLES) {
            tour.shuffle_cities();
            shuffle++;
        }
        if(!ga.tour_exist(tour)) {
            ga.add_tour(tour);
            pop_size++;
        }
    }

    int iteration = 0;
    double fitness = ga.evaluation();

    //Iteration of algorithm.
    while(iteration < ITERATIONS || fitness < IMPROVEMENT) {
        cout << "\n";
        cout << "Iteration " << iteration << endl;
        ga.selection();
        ga.crossover();
        ga.mutation();
        fitness = ga.evaluation();
        ga.report();
        iteration++;
    }
    cout << "Program end." << endl;

    return 0;
}