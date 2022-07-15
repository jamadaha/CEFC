#ifndef FIGHT_ORGANIZER
#define FIGHT_ORGANIZER

#include <string>
#include <vector>
#include <filesystem>
#include <random>
#include <climits>
#include <stdio.h>

#include "Engine.h"
#include "EnginePair.h"
#include "FightHistory.h"
#include "Utilities.h"

class FightOrganizer {
    public:
    FightOrganizer();
    bool GatherEngines(std::string path);
    void BeginTournament(int fightCount);
    void PrintTournamentResults();

    private:
    std::vector<Engine*> engines;
    FightHistory fightHistory = FightHistory();
    
};
#endif