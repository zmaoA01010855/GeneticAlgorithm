#include "genetic_algo.hpp"

void genetic_algo::add_tour(tour t) {
    population_list.push_back(t);
    order_map = generate_tour_order(population_list);
}

multimap<double, tour> genetic_algo::generate_tour_order(vector<tour> t) {
    multimap<double, tour> map;
    for(auto it = t.begin(); it != t.end(); ++it) {
        map.insert(make_pair(it->get_fitness(), (*it)));
    }
}

tour genetic_algo::get_fittest_tour() {
    double fitness = population_list.begin()->get_fitness();
    tour best_tour;
    for(auto it = population_list.begin(); it != population_list.end(); ++it) {
        if(fitness < it->get_fitness()) {
            fitness = it->get_fitness();
            best_tour = (*it);
        }
    }
    return best_tour;
}

bool genetic_algo::tour_exist(tour t) {
    for(auto it = population_list.begin(); it != population_list.end(); ++it) {
        if(t == *it) {
            return true;
        }
    }
    return false;
}

void genetic_algo::selection() {
    tour fittest = order_map.begin()->second;
    if(elite.empty()) {
        int i = 0;
        for(auto it = order_map.begin(); it != order_map.end() || i < NUM_ELITE; ++it) {
            elite.insert(make_pair(it->first, it->second));
            order_map.erase(order_map.find(it->first));
            i++;
        }
    } else {
        int i = 0;
        for(auto it = elite.begin(); it != elite.end(); ++it) {
            for(auto it1 = order_map.begin(); it1 != order_map.end() || i < NUM_ELITE; ++it) {
                if(it->first > it1->first) {
                    elite.erase(elite.find(it->first));
                    order_map.erase(order_map.find(it1->first));
                    elite.insert(make_pair(it1->first, it1->second));
                }
                i++;
            }
        }
    }
}

void genetic_algo::crossover() {
    vector<tour> city_list;
    vector<tour> rest_city_list;
    for(auto it = elite.begin(); it != elite.end(); it++) {
        city_list.push_back(it->second);
    }
    for(auto it = order_map.begin(); it != order_map.end(); it++) {
        rest_city_list.push_back(it->second);
    }
    int size = 0;
    while(size < order_map.size()) {
        int random = 0;
        int time = 0;
        vector<tour> cross_parent;
        auto it = rest_city_list.begin();
        while(time < NUM_PARENTS) {
            random = rand() % cross_parent.size();
            cross_parent.push_back(*(random + it));
            time++;
        }
        city_list.push_back(cross_parent.front().merge(cross_parent));
        size++;
    }
    population_list.clear();
    for(auto it = city_list.begin(); it != city_list.end(); ++it) {
        population_list.push_back((*it));
    }
}

void genetic_algo::mutation() {
    vector<tour> population_list1;
    multimap<double, tour> flip = generate_tour_order(population_list);
    for(auto it = flip.begin(); it != flip.end(); ++it) {
        it->second.mutation();
        population_list1.push_back(it->second);
    }
    population_list.clear();
    for(auto it = population_list1.begin(); it != population_list1.end(); ++it) {
        population_list.push_back(*it);
    }
}

double genetic_algo::evaluation() {
    order_map = generate_tour_order(population_list);
    return (abs(order_map.begin()->first - elite.begin()->first));
}

void genetic_algo::report() {
    cout << "Best tour list: ";
    get_fittest_tour().print_city();
    cout << "" << endl;
    cout << "The distance: " << get_fittest_tour().get_distance() << endl;
}


