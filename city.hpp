#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP
#include <string>
#include <math.h>
#include <utility>

using namespace std;

const double MAX_MAP_BOUNDARY = 1000;
const double MIN_MAP_BOUNDARY = 0;
const int SQUARE = 2;

class city {
private:
    string name;
    pair<double, double> coordinate;

public:
    city(string, double, double);
    pair<double, double> get_coordinates() const;
    double get_distance_between_cities(city);
    bool operator==(city& rhs) {
        if(name != rhs.name) {
            return false;
        }
        if(coordinate.first != rhs.coordinate.first) {
            return false;
        }
        return (coordinate.second == rhs.coordinate.second);
    }
    bool operator!=(city& rhs) {
        return ((*this)==rhs);
    }
};


#endif //GENETICALGORITHM_CITY_HPP
