#include "fileException.h"

const char* FileException::what() const noexcept {
    return "FileException occurred";
}
