#ifndef FIGHT
#define FIGHT

#include "EnginePair.h"

class Fight {
    public:
    Fight(EnginePair *enginePair) {
        engines = enginePair;
    };

    unsigned long int GetHash() {
        return engines->GetHash();
    }

    private:
    EnginePair *engines;
};

#endif