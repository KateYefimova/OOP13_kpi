#pragma once
#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <memory>
#include "flight5.h"
#include "generalFlight.h"
#include "charterFlight.h"

using namespace std;

class Airport {
private:
    vector<unique_ptr<Flight>> flights;  
    
public:
    vector<unique_ptr<Flight>> getFlight();
    void addFlight(unique_ptr<Flight> flight);
    unique_ptr<Flight> getEarliestFlight(const string& city) const;
    unique_ptr<Flight> getLatestFlight(const string& city) const;
};

#endif 
