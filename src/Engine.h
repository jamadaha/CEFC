#ifndef ENGINE
#define ENGINE

#include <climits>

#include "string"

class Engine {
    public:
    Engine(unsigned long int id, std::string path) {
        this->id = id;
        this->path = path;
    };

    unsigned long int GetId() { return id; };

    private:
    unsigned long int id;
    std::string path;
};

#endif