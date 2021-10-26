#include "FightOrganizer.h"

FightOrganizer::FightOrganizer() {
    
}

void FightOrganizer::GatherEngines(std::string path) {
    std::mt19937 gen(0);
	std::uniform_int_distribution<unsigned long int> distribution(0, ULONG_MAX);
    for (const auto & entry : std::filesystem::directory_iterator(path))
        engines.push_back(new Engine(distribution(gen), entry.path()));
}

void FightOrganizer::BeginTournament(int fightCount) {
    for (int i = 0; i < engines.size(); i++) {
        for (int i2 = 1; i2 < engines.size(); i2++) {
            Fight *fight = new Fight(engines[i], engines[i2]);
            unsigned long int hash = fight->GetHash();
            if (fightHistory.EnginesHaveHistory(hash))
                continue;

            // fight the fight

            fightHistory.AddFight(fight);

            printf("%lu\n", hash);
        }
    }
}