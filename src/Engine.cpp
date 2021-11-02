#include "Engine.h"

Engine::Engine(unsigned long int id, std::string path) {
        this->id = id;
        this->path = path;
    };

unsigned long int Engine::GetId() { 
    return id; 
};

std::string Engine::GetMove(std::string moves) {
    FILE *handle = popen(this->path.c_str(), "r");

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

