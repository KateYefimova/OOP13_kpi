#include "userInterface.h"
#include <iostream>
#include <regex>

UserInterface::UserInterface(Airport& airport, FileManager& file)
    : airport(airport), file(file) {}  
void UserInterface::addFlightsFromUser() {
    std::string type, city, time, licenseDate;

    while (true) {
        std::cout << "Enter flight type (General/Charter): ";
        std::cin >> type;

        if (type == "General" || type == "Charter") {
            break;
        }
        else {
            std::cout << "Invalid flight type, please enter 'General' or 'Charter'." << std::endl;
        }
    }

    while (true) {
        std::cout << "Enter destination city: ";
        std::cin >> city;

        if (!city.empty()) {
            break;
        }
        else {
            std::cout << "City cannot be empty, please enter a valid city." << std::endl;
        }
    }

    std::cout << "Enter departure time (HH:MM): ";
    std::cin >> time;

    Flight* flight = nullptr; 

    if (type == "General") {
        flight = new GeneralFlight(city, time); 
    }
    else if (type == "Charter") {
        while (true) {
            std::cout << "Enter license expiration date (YYYY-MM-DD): ";
            std::cin >> licenseDate;

            if (std::regex_match(licenseDate, std::regex("\\d{4}-\\d{2}-\\d{2}"))) {
                flight = new CharterFlight(city, time, licenseDate); 
                break;
            }
            else {
                std::cout << "Invalid date format. Please enter date in YYYY-MM-DD format." << std::endl;
            }
        }
    }

    airport.addFlight(std::unique_ptr<Flight>(flight));
    file.saveFlightsToFile(*flight, "flights4.txt");

    std::cout << "Flight added successfully!" << std::endl;
}


void UserInterface::askCity() const {
    std::string city;

    std::cout << "Enter city : ";
    std::getline(std::cin >> std::ws, city);
    unique_ptr<Flight> earliest = airport.getEarliestFlight(city);
    unique_ptr<Flight> latest =airport.getLatestFlight(city);

    if (!earliest || !latest) {
        std::cout << "No flights to the city " << city << " were found." << std::endl;
    }
    else {
        std::cout << "The earliest flight to ";
        earliest->getInfo();
        std::cout << std::endl;
        std::cout << "The latest flight to " ;
        latest->getInfo();
        std::cout << std::endl;
    }
}

