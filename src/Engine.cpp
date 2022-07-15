#include "Engine.h"

Engine::Engine(unsigned long int id, std::string path) {
        this->id = id;
        this->path = path;
    };

unsigned long int Engine::GetId() { 
    return id; 
};

std::string Engine::GetName() {
    std::vector<std::string> elements;
    std::stringstream streamData(path);
    std::string na;
    while (std::getline(streamData, na, '/')) {
        elements.push_back(na);
    }
    return elements[elements.size() - 1];
}

std::string Engine::GetMove(std::string moves) {
    auto command = (this->path + ' ' + moves);
    FILE *handle = popen(command.c_str(), "r");

    if (handle == NULL) {
            return "";
    }

    // Perhaps look at using the excess output lines
    char buf[64];
    std::vector<std::string> lines;
    while (std::fgets(buf, 64, handle))
    {
        std::string tempString = buf;
        tempString = tempString.substr(0, tempString.size() - 1);
        lines.push_back(tempString);
    }
    pclose(handle);

    return lines[0];
}

void Engine::AddWin(unsigned long int opponent) {
    if (wins.find(opponent) != wins.end())
        wins.emplace(opponent, 0);
    wins[opponent] += 1;
}

double Engine::GetWinrate(Engine* engine) {
    int thisWins = GetWinCount(engine->GetId());
    int opponentWins = engine->GetWinCount(GetId());

    return (double)thisWins / (thisWins + opponentWins);
}

int Engine::GetWinCount(unsigned long int opponent) {
    return wins[opponent];
}