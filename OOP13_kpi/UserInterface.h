#pragma once
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include "airport4.h"
#include "FileManager.h"

class UserInterface {
public:
    UserInterface(Airport& airport, FileManager& file);
    void addFlightsFromUser();
    void askCity() const;

private:
    Airport& airport;
    FileManager& file; 
};

#endif 
