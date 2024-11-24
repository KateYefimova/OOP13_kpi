#include "userInterface.h"
#include "InputException.h"
#include <iostream>
#include <regex>

UserInterface::UserInterface(Airport& airport, FileManager& file)
    : airport(airport), file(file) {}  

void UserInterface::addFlightsFromUser() {
    std::string type, city, time, licenseDate;

    std::cout << "Enter flight type (General/Charter): ";
    std::cin >> type;

    if (type != "General" && type != "Charter") {
        throw InputException("Invalid flight type. Please enter 'General' or 'Charter'.");
    }

    std::cout << "Enter destination city: ";
    std::cin >> city;

    if (city.empty()) {
        throw InputException("City cannot be empty. Please enter a valid city.");
    }

    std::cout << "Enter departure time (HH:MM): ";
    std::cin >> time;
    if (!std::regex_match(time, std::regex("^([01]\\d|2[0-3]):([0-5]\\d)$"))) {
        throw InputException("Invalid time format. Please enter time in HH:MM format.");
    }

    Flight* flight = nullptr;

    if (type == "General") {
        flight = new GeneralFlight(city, time);
    }
    else if (type == "Charter") {
        while (true) {
            std::cout << "Enter license expiration date (YYYY-MM-DD): ";
            std::cin >> licenseDate;

            if (!std::regex_match(licenseDate, std::regex("\\d{4}-\\d{2}-\\d{2}"))) {
                throw InputException("Invalid date format. Please enter date in YYYY-MM-DD format.");
            }
            flight = new CharterFlight(city, time, licenseDate);
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
    if (city.empty()) {
        throw InputException("City name cannot be empty. Please enter a valid city.");
    }
    if (!std::regex_match(city, std::regex("^[a-zA-Z\\s]+$"))) {
        throw InputException("Invalid city name. Only alphabetic characters and spaces are allowed.");
    }
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

