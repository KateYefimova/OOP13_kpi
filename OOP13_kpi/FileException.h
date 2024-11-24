#pragma once
#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H
#include "baseException.h"

class FileException : public MyBaseException {
public:
    const char* what() const noexcept override;
};
#endif