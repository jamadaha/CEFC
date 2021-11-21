#ifndef FIGHT
#define FIGHT

#include <string>

#include "EnginePair.h"

class Fight {
    public:
    enum class Result {
        unfinished = 0,
        draw = 1,
        checkmate = 2
    };
    Result result = Result::unfinished;
    std::string moves;
    
    
    Fight(EnginePair *enginePair);

    unsigned long int GetHash();
    Engine* GetWinner();
    Engine* GetLoser();

    void Begin();

    private:
    EnginePair *engines;
    unsigned long int winner;

    };

#endif