#ifndef CHARTER_FLIGHT_H
#define CHARTER_FLIGHT_H

#include "Flight5.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

class CharterFlight : public Flight {
private:
    std::string licenseExpirationDate;

public:
    CharterFlight(const std::string& city, const std::string& time, const std::string& licenseDate);
    std::string getLicenseExpirationDate() const override;
    void getInfo() const override;
    std::unique_ptr<Flight> clone() const override;
    void saveToFile(std::ofstream& outfile) const override;
};

#endif
