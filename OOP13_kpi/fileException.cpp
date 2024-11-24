#include "fileException.h"

const char* FileException::what() const noexcept {
    return message.c_str();
}
