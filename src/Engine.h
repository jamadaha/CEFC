#ifndef ENGINE
#define ENGINE

#include <climits>
#include <bits/stdc++.h>
#include <unordered_map>


#include "string"

class Engine {
    public:
    Engine(unsigned long int id, std::string path);

    unsigned long int GetId();
    std::string GetName();
    std::string GetMove(std::string moves);
    void AddWin(unsigned long int opponent);
    double GetWinrate(Engine* engine);
    int GetWinCount(unsigned long int opponent);

    private:
    unsigned long int id;
    std::string path;
    std::unordered_map<unsigned long int, unsigned int> wins;
    
};

#endif