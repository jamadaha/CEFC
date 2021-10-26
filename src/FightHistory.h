#ifndef FIGHT_HISTORY
#define FIGHT_HISTORY

#include <vector>
#include <unordered_map>

#include "Fight.h"

class FightHistory {
    public:
    FightHistory() {};
    void AddFight(Fight* fight) {
        if (!EnginesHaveHistory(fight->GetHash()))
            fights.emplace(fight->GetHash(), std::vector<Fight*>());
        fights[fight->GetHash()].push_back(fight);
    };
    
    // Checks whether there already exists fight with this hash
    bool EnginesHaveHistory(unsigned long int hash) {
        return fights.find(hash) != fights.end();
    }

    private:
    std::unordered_map<unsigned long int, std::vector<Fight*>> fights;

};

#endif