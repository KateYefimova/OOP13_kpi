#include "NullPointerException.h"

const char* NullPointerException::what() const noexcept {
    return message.c_str();
}
