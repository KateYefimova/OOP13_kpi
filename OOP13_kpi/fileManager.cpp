#include "fileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool FileManager::loadFlightsFromFile( const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw FileException();
    }

    string line, city, time, type, licenseDate;
    while (getline(file, line)) {
        istringstream iss(line);
        if (iss >> type >> city >> time) {
            if (type == "General") {
                airport.addFlight(make_unique<GeneralFlight>(city, time));
            }
            else if (type == "Charter") {
                iss >> licenseDate;
                airport.addFlight(make_unique<CharterFlight>(city, time, licenseDate));
            }
        }
    }

    file.close();
    return true;
}


void FileManager::saveFlightsToFile(const Flight& flight, const std::string& filename) {
    std::ofstream outfile(filename, std::ios::app); 
    if (!outfile.is_open()) {
        std::cout << "Error opening file for writing." << std::endl;
        return;
    }

    flight.saveToFile(outfile);
    outfile << std::endl;

    outfile.close();
}
