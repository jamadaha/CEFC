#ifndef FIGHT
#define FIGHT

#include "EnginePair.h"

class Fight {
    public:
    enum class Result {
        unfinished = 0,
        draw = 1,
        win = 2
    };
    Result result = Result::unfinished;
    
    Fight(EnginePair *enginePair);

    unsigned long int GetHash();

    void Begin();

    private:
    EnginePair *engines;
};

#endif