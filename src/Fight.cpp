#include "Fight.h"

Fight::Fight(EnginePair *enginePair) {
    engines = enginePair;
};

unsigned long int Fight::GetHash() {
    return engines->GetHash();
}

void Fight::Begin() {
    std::string moves = "";
    while (true) {
        for (int i = 0; i < 2; i++) {
            std::string move = engines->GetEngine(i)->GetMove("\'" + moves + "\'");
            moves += move + " ";
            if (move == "draw") {
                result = Result::draw;
                return;
            }
        }
    }
}