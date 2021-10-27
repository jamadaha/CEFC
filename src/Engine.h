#ifndef ENGINE
#define ENGINE

#include <climits>

#include "string"

class Engine {
    public:
    Engine(unsigned long int id, std::string path);

    unsigned long int GetId();

    private:
    unsigned long int id;
    std::string path;
};

#endif