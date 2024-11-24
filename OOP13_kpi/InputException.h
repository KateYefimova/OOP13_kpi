#pragma once
#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H
#include "baseException.h"
#include <string>

class InputException : public MyBaseException {
private:
    std::string message;
public:
    explicit InputException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override;
};

#endif