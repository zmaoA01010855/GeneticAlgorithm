#include "genetic_algo.hpp"

bool compare_tour(tour t1, tour t2) {
    return (t1.get_fitness() < t2.get_fitness());
}

void genetic_algo::add_tour(tour t) {
    population_list.push_back(t);
    order_map = generate_tour_order(population_list);
}

multimap<double, tour> genetic_algo::generate_tour_order(vector<tour> t) {
    multimap<double, tour> map;
    for(auto it = t.begin(); it != t.end(); ++it) {
        tour v = (*it);
        v.generate_fitness();
        v.generate_distance();
        map.insert(make_pair(v.get_fitness(), v));
    }
    return map;
}

tour genetic_algo::get_fittest_tour() {
    double fitness = population_list.begin()->get_distance();
    tour best_tour = elite.begin()->second;
    for(auto it = population_list.begin(); it != population_list.end(); ++it) {
        if(fitness > it->get_distance()) {
            fitness = it->get_distance();
            best_tour = (*it);
        }
    }
    return best_tour;
}

tour genetic_algo::merge(vector<tour> merge_list) {
    tour iterative;
    vector<tour> copy = merge_list;

    size_t sz1 = copy.size() - 1;
    for(unsigned i = 0; i < sz1; i++) {
        size_t sz2 = copy[i].get_city_list().size();
        for(unsigned j = 0; j < sz2; j += sz1) {
            if(!iterative.city_exist(copy[i].get_city_list()[j]))
                iterative.add_tour(copy[i].get_city_list()[j]);

        }

    }

    size_t sz3 = copy[sz1].get_city_list().size();
    for(unsigned j = 0; j < sz3; j++) {
        if(iterative.get_city_list().size() != copy[sz1].get_city_list().size()) {
            if(!iterative.city_exist(copy[sz1].get_city_list()[j]))
                iterative.add_tour(copy[sz1].get_city_list()[j]);
        }
    }
    iterative.generate_fitness();
    iterative.generate_distance();
    return iterative;
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
    multimap<double, tour> elite_copy;
    multimap<double, tour> copy;
    if(elite.empty()) {
        int i = 0;
        for(auto it = order_map.begin(); it != order_map.end(); ++it) {
            if(i < NUM_ELITE) {
                elite.insert(make_pair(it->first, it->second));
            } else {
                copy.insert(make_pair(it->first, it->second));
            }
            i++;
        }
        order_map = copy;
    } else {
        int i = 0;
        for(auto it1 = order_map.begin(); it1 != order_map.end(); ++it1) {
            if(i < NUM_ELITE){
                for(auto it = elite.begin(); it != elite.end(); ++it) {
                    if(it->first > it1->first) {
                        elite_copy.insert(make_pair(it1->first, it1->second));
                    } else {
                        elite_copy.insert(make_pair(it->first, it->second));
                        copy.insert(make_pair(it1->first, it1->second));
                    }
                }
            } else {
                copy.insert(make_pair(it1->first, it1->second));
            }
            i++;
        }
        elite = elite_copy;
        order_map = copy;
    }
    base_tour = order_map.begin()->second;
    base_tour.generate_distance();
    base_tour.generate_fitness();
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
    while(size < (POPULATION_SIZE - NUM_ELITE)) {
        int random = 0;
        int time = 0;
        vector<tour> cross_parent;

        while(time < NUM_PARENTS) {
            auto it = rest_city_list.begin();
            random = rand() % (POPULATION_SIZE - NUM_ELITE);
            cross_parent.push_back(*(random + it));
            time++;
        }
        city_list.push_back(merge(cross_parent));
        size++;
    }
    population_list.clear();
    for(auto it = city_list.begin(); it != city_list.end(); ++it) {
        it->generate_distance();
        it->generate_fitness();
        population_list.push_back((*it));
    }
}

void genetic_algo::mutation() {
    vector<tour> population_list1;
    multimap<double, tour> flip = generate_tour_order(population_list);
    for(auto it = flip.begin(); it != flip.end(); ++it) {
        it->second.mutation();
        it->second.generate_distance();
        it->second.generate_fitness();
        population_list1.push_back(it->second);
    }
    population_list.clear();
    for(auto it = population_list1.begin(); it != population_list1.end(); ++it) {
        population_list.push_back(*it);
    }
}

double genetic_algo::evaluation() {
    order_map = generate_tour_order(population_list);
    return (order_map.begin()->first - elite.begin()->first);
}

void genetic_algo::report() {
    cout << "Base tour list: ";
    base_tour.print_city();
    cout << "Best tour list: ";
    get_fittest_tour().print_city();
    cout << "The shortest distance: " << get_fittest_tour().get_distance() << endl;
}


