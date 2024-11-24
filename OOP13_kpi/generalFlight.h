#pragma once
#ifndef GENERAL_FLIGHT_H
#define GENERAL_FLIGHT_H

#include "Flight5.h"
#include <memory>

class GeneralFlight : public Flight {
public:
    GeneralFlight(const std::string& city, const std::string& time);
    std::string getLicenseExpirationDate() const override;
    void getInfo() const override;
    std::unique_ptr<Flight> clone() const override;
};

#endif