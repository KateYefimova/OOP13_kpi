#include "airport4.h"
#include "generalFlight.h"
#include "charterFlight.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <regex> 

using namespace std;

vector<unique_ptr<Flight>> Airport::getFlight() {
    return std::move(flights);
}

void Airport::addFlight(unique_ptr<Flight> flight) {
    flights.push_back(std::move(flight));
}

unique_ptr<Flight> Airport::getEarliestFlight(const std::string& city) const {
    unique_ptr<Flight> earliest = nullptr;
    for (const auto& flight : flights) {
        if (flight->getCity() == city && (!earliest || flight->getTime() < earliest->getTime())) {
            earliest = flight->clone();
        }
    }
    return earliest;
}

unique_ptr<Flight> Airport::getLatestFlight(const std::string& city) const {
    unique_ptr<Flight> latest = nullptr;
    for (const auto& flight : flights) {
        if (flight->getCity() == city && (!latest || flight->getTime() > latest->getTime())) {
            latest = flight->clone();
        }
    }
    return latest;
}





