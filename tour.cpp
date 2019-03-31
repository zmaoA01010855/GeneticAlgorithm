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

void tour::remove_city(city c) {
    size_t sz = citylist.size();
    for(unsigned i = 0; i < sz; i++) {
        if(citylist[i] == c) {
            citylist.erase(citylist.begin(), citylist.begin() + (int)i);
            break;
        }
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
    for(unsigned it = 0; it < citylist.size() - 1; it++) {
        distance += citylist[it].get_distance_between_cities(citylist[it + 1]);
    }
    return distance;
}

void tour::generate_fitness() {
    fitness = 0.001 * get_distance();
}

double tour::get_fitness() const {
    return fitness;
}

void tour::shuffle_cities() {
    random_shuffle(citylist.begin(), citylist.end());
    generate_fitness();
    distance = get_distance();
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
    cout << "\n";
}