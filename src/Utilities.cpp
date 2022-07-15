#include "Utilities.h"

bool Utilities::DoesPathExist(const std::string &s) {
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}