#include "flight5.h"
#include <algorithm>
#include <vector>
using namespace std;

Flight::Flight(const std::string& city, const std::string& time, const std::string& type)
    : city(city), time(time), flightType(type) {}



string Flight::getCity() const {
    return city;
}

string Flight::getTime() const {
    return time;
}

string Flight::getFlightType() const {
    return flightType;
}
void Flight::getInfo() const {
    std::cout << city << ": " << time << " (" << flightType << ")";
}

void Flight::saveToFile(std::ofstream& outfile) const {
    outfile << flightType << " " << city << " " << time;
}


