#include <iostream>
#include <fstream>

#include "FightHistory.h"

void FightHistory::AddFight(Fight* fight) {
    if (!EnginesHaveHistory(fight->GetHash()))
        fights.emplace(fight->GetHash(), std::vector<Fight*>());
    fights[fight->GetHash()].push_back(fight);
};

bool FightHistory::EnginesHaveHistory(unsigned long int hash) {
    return fights.find(hash) != fights.end();
}

void FightHistory::ExportToCSV() {
    std::ofstream outputFile;
    outputFile.open("log.csv");
}