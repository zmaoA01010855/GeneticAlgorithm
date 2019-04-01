#include "tour.hpp"

/**
 * Print city vector by using copy function.
 * @param a vector of city to print.
 */
void print(vector<city> a) {
    ostream_iterator<city> it (cout, " - ");
    copy(a.begin(), a.end(), it);
}

/**
 * Add city in the tour.
 * @param c city to add.
 */
void tour::add_city(city c) {
    if(!city_exist(c)) {
        citylist.push_back(c);
        generate_fitness();
        generate_distance();
    }
}

/**
 * See if the city has already existed in the tour.
 * @param c city to check
 * @return bool
 */
bool tour::city_exist(city c) {
    for(auto it = citylist.begin(); it != citylist.end(); ++it) {
        if(c == (*it)) {
            return true;
        }
    }
    return false;
}

/**
 * Get the total distance of this tour.
 * @return double distance.
 */
double tour::get_distance() {
    double distance = 0;
    for(unsigned it = 0; it < citylist.size() - 1; it++) {
        distance += citylist[it].get_distance_between_cities(citylist[it + 1]);
    }
    return distance;
}

/**
 * Generate fitness of this tour.
 */
void tour::generate_fitness() {
    fitness = 0.001 * get_distance();
}

/**
 * Generate distance of this tour.
 */
void tour::generate_distance() {
    distance = get_distance();
}

/**
 * Get fitness of this tour.
 * @return fitness
 */
double tour::get_fitness() const {
    return fitness;
}

/**
 * shuffle cities inside of tour.
 */
void tour::shuffle_cities() {
    random_shuffle(citylist.begin(), citylist.end());
    generate_fitness();
    distance = get_distance();
}

/**
 * Mutate cities inside of this tour.
 */
void tour::mutation() {
    auto it = citylist.begin();
    for(; it != citylist.end() - 1; ++it) {
        int num = rand() % TOTAL_RATE;
        if(num < MUTATION_RATE) {
            city temp = *(it + 1);
            *(it + 1) = *it;
            *it = temp;
        }
    }

    int num = rand() % TOTAL_RATE;
    if(num < MUTATION_RATE) {
        city temp = *(citylist.begin());
        *(citylist.begin()) = *it;
        *it = temp;
    }
}

/**
 * Print the city list of this tour.
 */
void tour::print_city() {
    print(citylist);
    cout << "\n";
}