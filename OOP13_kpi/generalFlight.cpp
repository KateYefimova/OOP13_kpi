#include "generalFlight.h"

GeneralFlight::GeneralFlight(const std::string& city, const std::string& time)
    : Flight(city, time, "General") {}

std::string GeneralFlight::getLicenseExpirationDate() const {
    return ""; 
}

void GeneralFlight::getInfo() const {
    Flight::getInfo();
}
std::unique_ptr<Flight> GeneralFlight::clone() const {
    return std::make_unique<GeneralFlight>(*this);
}

