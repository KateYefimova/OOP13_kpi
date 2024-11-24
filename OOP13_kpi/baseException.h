#pragma once
#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H
#include <exception>

class MyBaseException : public std::exception {
public:
	virtual const char* what() const noexcept override;
};

#endif