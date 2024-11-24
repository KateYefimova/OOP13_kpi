#pragma once
#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H
#include "baseException.h"
#include <string>

class FileException : public MyBaseException {
private:
    std::string message;
public:
    explicit FileException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override;
};
#endif