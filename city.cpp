#include <iostream>
#include "city.hpp"

using namespace std;

city::city(string name, long x, long y) {
    this->name = name;
    try {
        if(x < 0 || x > 1000 || y < 0 || y > 1000) {
            throw "Invalid coordinates input.";
        } else {
            this.x = x;
            this.y = y;
        }
    } catch (const char* e) {
        cerr << e << endl;
    }
}