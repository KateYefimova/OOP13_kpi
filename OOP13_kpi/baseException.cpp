#include "baseException.h"

const char* MyBaseException::what() const noexcept {
    return "MyBaseException occurred";
}
