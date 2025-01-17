#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP
#include <string>
#include <math.h>
#include <utility>

using namespace std;

/**
 * Max Boundary.
 */
const double MAX_MAP_BOUNDARY = 1000;

/**
 * Min Boundary.
 */
const double MIN_MAP_BOUNDARY = 0;

/**
 * For squaring a number.
 */
const int SQUARE = 2;

class city {
private:
    string name;
    pair<double, double> coordinate;
    friend ostream& operator<<(ostream& os, const city& t) {
        os << t.name;
        return os;
    }

public:
    city(string, double, double);
    pair<double, double> get_coordinates() const;
    double get_distance_between_cities(city);

    /**
     * Override == operator.
     * @param rhs city on right hand side
     * @return bool
     */
    bool operator==(const city& rhs) {
        if(name != rhs.name) {
            return false;
        }
        if(coordinate.first != rhs.coordinate.first) {
            return false;
        }
        return (coordinate.second == rhs.coordinate.second);
    }

    /**
     * Override != operator.
     * @param rhs city on right hand side
     * @return bool
     */
    bool operator!=(const city& rhs) {
        return ((*this)==rhs);
    }
};


#endif //GENETICALGORITHM_CITY_HPP
