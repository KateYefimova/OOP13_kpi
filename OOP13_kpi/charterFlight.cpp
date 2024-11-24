#include "CharterFlight.h"
#include <iostream>

CharterFlight::CharterFlight(const std::string& city, const std::string& time, const std::string& licenseDate)
    : Flight(city, time, "Charter"), licenseExpirationDate(licenseDate) {}

std::string CharterFlight::getLicenseExpirationDate() const  {
    return licenseExpirationDate;
}
void CharterFlight::getInfo() const{
    std::cout << city << ": " << time << " (" << flightType << ")" << ": " << licenseExpirationDate;
}

std::unique_ptr<Flight> CharterFlight::clone() const {
    return std::make_unique<CharterFlight>(*this);
}
void CharterFlight::saveToFile(std::ofstream& outfile) const {
    outfile << flightType << " " << city << " " << time << " " << licenseExpirationDate;
}

