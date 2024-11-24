#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <memory>
#include "airport4.h" 
#include "FileException.h" 

class FileManager {
private:
    Airport& airport;
public:
    explicit FileManager(Airport& airportRef) : airport(airportRef) {}
    bool loadFlightsFromFile(const std::string& filename);
    void saveFlightsToFile(const Flight& flight, const std::string& filename);
};

#endif 
