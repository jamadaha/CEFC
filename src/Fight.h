#ifndef FIGHT
#define FIGHT

#include "EnginePair.h"

class Fight {
    public:
    Fight(EnginePair *enginePair);

    unsigned long int GetHash();

    private:
    EnginePair *engines;
};

#endif