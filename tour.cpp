#include "tour.hpp"


void print(vector<city> a) {
    ostream_iterator<city> it (cout, " - ");
    copy(a.begin(), a.end(), it);
}


//Add city to tour
void tour::add_tour(city c) {
    if(!city_exist(c)) {
        citylist.push_back(c);
        generate_fitness();
        distance = get_distance();
    }
}

//See if the city has already existed in the tour
bool tour::city_exist(city c) {
    for(auto it = citylist.begin(); it != citylist.end(); ++it) {
        if(c == (*it)) {
            return true;
        }
    }
    return false;
}

double tour::get_distance() {
    double distance = 0;
    for(auto it = citylist.begin(); it != citylist.end() - 1; ++it) {
        distance += it->get_distance_between_cities(*(it + 1));
    }
    return distance;
}

void tour::generate_fitness() {
    fitness = 1 / get_distance();
}

double tour::get_fitness() const {
    return fitness;
}

void tour::shuffle_cities() {
    auto ran_gen = default_random_engine{};
    shuffle(citylist.begin(), citylist.end(), ran_gen);
    generate_fitness();
    distance = get_distance();
}

tour tour::merge(vector<tour> merge_list) {
    tour iterative;
    vector<tour> copy = merge_list;
    for(auto it = copy.begin(); it != copy.end(); ++it) {
        for(auto it1 = this->citylist.begin(); it1 != this->citylist.end(); it1 += 3) {
            iterative.add_tour((*it1));
        }
        for(auto it2 = it->citylist.begin(); it2 != it->citylist.end(); ++it2) {
            if(!iterative.city_exist(*it2)) {
                iterative.add_tour((*it2));
            }
        }
        *this = iterative;
    }
    return *this;
}

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

void tour::print_city() {
    print(citylist);
}