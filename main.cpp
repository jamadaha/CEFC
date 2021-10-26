#include <iostream>
#include <vector>

#include "src/ConfigReader.h"
#include "src/Engine.h"
#include "src/FightOrganizer.h"

int main(int, char**) {
    ConfigReader configReader = ConfigReader("config");
    configReader.Read();
    FightOrganizer fightOrganizer = FightOrganizer();
    fightOrganizer.GatherEngines(configReader.GetValue("EnginePath"));
    fightOrganizer.BeginTournament(std::stoi(configReader.GetValue("FightCount")));
}