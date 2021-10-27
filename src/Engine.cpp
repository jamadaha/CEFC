#include "Engine.h"

Engine::Engine(unsigned long int id, std::string path) {
        this->id = id;
        this->path = path;
    };

unsigned long int Engine::GetId() { 
    return id; 
};