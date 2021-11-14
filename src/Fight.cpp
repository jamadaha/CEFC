#include "Fight.h"

Fight::Fight(EnginePair *enginePair) {
    engines = enginePair;
};

unsigned long int Fight::GetHash() {
    return engines->GetHash();
}

Engine* Fight::GetWinner() {
    if (engines->GetEngine(0)->GetId() == winner)
        return engines->GetEngine(0);
    else
        return engines->GetEngine(1);
}

void Fight::Begin() {
    std::string moves = "";
    while (true) {
        for (int i = 0; i < 2; i++) {
            std::string move = engines->GetEngine(i)->GetMove("\'" + moves + "\'");
            moves += move + " ";
            if (move == "draw") {
                result = Result::draw;
                this->moves = moves;
                return;
            } else if (move == "loss") {
                result = Result::checkmate;
                this->moves = moves;
                this->winner = engines->GetEngine(1 - i)->GetId();
                return;
            } else if (move == "win") {
                result = Result::checkmate;
                this->moves = moves;
                this->winner = engines->GetEngine(i)->GetId();
                return;
            }
        }
    }
}