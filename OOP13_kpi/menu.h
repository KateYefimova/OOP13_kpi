#pragma once
#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>
#include "fileManager.h"
#include "UserInterface.h"


class Menu {
private:
    FileManager fileManager;
    Airport airport;
    UserInterface user;

public:
    Menu() : airport(), fileManager(airport), user(airport, fileManager) {}
    void mainMenu();
};

#endif 
