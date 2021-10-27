#ifndef FIGHT_HISTORY
#define FIGHT_HISTORY

#include <vector>
#include <unordered_map>

#include "Fight.h"

class FightHistory {
    public:
    FightHistory() {};
    
    void AddFight(Fight* fight);
    
    // Checks whether there already exists fight with this hash
    bool EnginesHaveHistory(unsigned long int hash);

    private:
    std::unordered_map<unsigned long int, std::vector<Fight*>> fights;

};

#endif