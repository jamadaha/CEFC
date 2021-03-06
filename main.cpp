#include <iostream>
#include <vector>

#include "src/ConfigReader.h"
#include "src/Engine.h"
#include "src/FightOrganizer.h"

int main(int, char**) {
    ConfigReader configReader = ConfigReader("config.txt");
    configReader.Read();
    FightOrganizer fightOrganizer = FightOrganizer();
    if (fightOrganizer.GatherEngines(configReader.GetString("EnginePath"))) {
        fightOrganizer.BeginTournament(std::stoi(configReader.GetString("FightCount")));
        if (configReader.GetBool("PrintResults"))
            fightOrganizer.PrintTournamentResults();
        printf("Done\n");
    }
}