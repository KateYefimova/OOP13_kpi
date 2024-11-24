#include "InputException.h"

const char* InputException::what() const noexcept {
    return message.c_str();
}
