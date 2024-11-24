#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

class Flight {
protected:
    std::string city;
    std::string time;
    std::string flightType;
public:
    Flight(const std::string& city, const std::string& time, const std::string& type);
    virtual ~Flight() {};
    virtual std::string getFlightType() const ; 
    virtual std::string getTime() const ;       
    virtual std::string getCity() const ;
    virtual std::string getLicenseExpirationDate() const = 0 ;
    virtual void getInfo() const;
    virtual std::unique_ptr<Flight> clone() const = 0;
    virtual void saveToFile(std::ofstream& outfile) const;
};

#endif 