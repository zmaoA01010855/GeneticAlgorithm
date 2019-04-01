#include <iostream>
#include "city.hpp"

using namespace std;

/**
 * Constructor of city.
 * @param name  name of city.
 * @param x longitude
 * @param y latitude
 */
city::city(string name, double x, double y) {
    this->name = name;
    try {
        if(x < MIN_MAP_BOUNDARY || x > MAX_MAP_BOUNDARY || y < MIN_MAP_BOUNDARY || y > MAX_MAP_BOUNDARY) {
            throw "Invalid coordinates input.";
        } else {
            coordinate = make_pair(x, y);
        }
    } catch (const char* e) {
        cerr << e << endl;
    }
}

/**
 * Gte the coordinate pair of this city.
 * @return pair<longitude, latitude>
 */
pair<double, double> city::get_coordinates() const {
    return coordinate;
}

/**
 * Get the distance from this city to another city.
 * @param other another city
 * @return double distance
 */
double city::get_distance_between_cities(city other) {
    double distance = sqrt(pow(this->get_coordinates().first - other.get_coordinates().first, SQUARE)
            + pow(this->get_coordinates().second - other.get_coordinates().second, SQUARE));
    return distance;
}