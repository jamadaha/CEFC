#ifndef FIGHT
#define FIGHT

#include "EnginePair.h"

class Fight {
    public:
    enum class Result {
        unfinished,
        draw,
        win
    };
    Result result = Result::unfinished;
    
    Fight(EnginePair *enginePair);

    unsigned long int GetHash();

    void Begin();

    private:
    EnginePair *engines;
};

#endif