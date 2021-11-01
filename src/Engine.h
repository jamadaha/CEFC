#ifndef ENGINE
#define ENGINE

#include <climits>
#include <bits/stdc++.h>

#include "string"

class Engine {
    public:
    Engine(unsigned long int id, std::string path);

    unsigned long int GetId();
    std::string GetMove(std::string moves);

    private:
    unsigned long int id;
    std::string path;
};

#endif