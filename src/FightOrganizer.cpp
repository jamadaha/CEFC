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
    printf("-------Beginning tournament-------\n");
    printf("There are %lu participating engines!\n", engines.size());
    int totalMatches = 0;
    for (int i = 0; i < engines.size(); i++)
        totalMatches += i;
    printf("With %d fights per match and %d matches, there will be %d total fights!\n", fightCount, totalMatches, fightCount * totalMatches);
    // Get first engine of match
    for (int i = 0; i < engines.size(); i++) {
        // Get second engine of match
        for (int i2 = 1; i2 < engines.size(); i2++) {
            EnginePair *enginePair = new EnginePair(engines[i], engines[i2]);
            // If same engine
            if (i == i2)
                break;
            // This is a check as to whether these engines have fought before
            // If they have then this match is skipped
            else if (fightHistory.EnginesHaveHistory(enginePair->GetHash()))
                break;

            printf("Starting the match between %s and %s!\n", engines[i]->GetName().c_str(), engines[i2]->GetName().c_str());
            
            // Get index of current fight, until it reaches fightCount
            for (int fightIndex = 0; fightIndex < fightCount; fightIndex++) {
                // fix indent on fight num/total
                printf("Fight %d/%d | ", fightIndex + 1, fightCount);
                Fight *fight = new Fight(enginePair);
                fight->Begin();

                if (fight->result == Fight::Result::draw)
                    printf("Result: Draw\n");
                else 
                    printf("Result: Checkmate | %s won\n", fight->GetWinner()->GetName().c_str());

                fightHistory.AddFight(fight);
                fight->GetWinner()->AddWin(fight->GetLoser()->GetId());
            }
        }
    }
}