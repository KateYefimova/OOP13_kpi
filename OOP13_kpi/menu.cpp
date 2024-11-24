#include "menu.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>

void Menu::mainMenu() {
    std::cout << "===== Main Menu =====" << std::endl;
    std::cout << "1. Find the earliest and the latest flight by the city" << std::endl;
    std::cout << "2. Add flight" << std::endl;
    std::cout << "3. Exit" << std::endl;
    while (true) {
        string command;
        cout << "Enter the command:";
        cin >> command;
        if (command == "1") {
            try {
                if (fileManager.loadFlightsFromFile("fli.txt")) {
                    user.askCity();
                }
            }
            catch (const MyBaseException& e){
                std::cerr << "Error: " << e.what() << std::endl;
            }
        
        }
        else if (command == "2") {
            try {
                if (fileManager.loadFlightsFromFile("flights4.txt")) {
                    user.addFlightsFromUser();
                }
            }
            catch (const MyBaseException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else if (command == "3") {
            break;
        }

    }
    
}