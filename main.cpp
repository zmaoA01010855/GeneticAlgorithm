#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include <stdlib.h>
#include "genetic_algo.hpp"
const int CITIE_IN_TOUR = 32;

using namespace std;

int main() {

    int x, y;

    for(int i = 0; i <CITIE_IN_TOUR; i++) {
        x = rand() % 1000 + 1;
        y = rand() % 1000 + 1;
        cout << x << " - " << y << endl;
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}