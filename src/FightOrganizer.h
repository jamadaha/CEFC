#ifndef FIGHT_ORGANIZER
#define FIGHT_ORGANIZER

#include <string>
#include <vector>
#include <filesystem>
#include <random>
#include <climits>

#include "Engine.h"
#include "FightHistory.h"

class FightOrganizer {
    public:
    FightOrganizer();
    void GatherEngines(std::string path);
    void BeginTournament(int fightCount);

    private:
    std::vector<Engine*> engines;
    FightHistory fightHistory = FightHistory();
    
};
#endif