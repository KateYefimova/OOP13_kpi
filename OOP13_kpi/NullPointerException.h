#pragma once
#ifndef NULLPOINTER_EXCEPTION_H
#define NULLPOINTER_EXCEPTION_H
#include "baseException.h"
#include <string>

class NullPointerException : public MyBaseException {
private:
    std::string message;
public:
    explicit NullPointerException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override;
};

#endif