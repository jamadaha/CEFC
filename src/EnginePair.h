#ifndef ENGINE_PAIR
#define ENGINE_PAIR

#include "Engine.h"

class EnginePair {
    public:
    EnginePair(Engine *engine1, Engine *engine2) {
        engines[0] = engine1;
        engines[1] = engine2;
    };

    unsigned long int GetHash() {
        return (engines[0]->GetId() & engines[1]->GetId());
    };

    private:
    Engine *engines[2];
};

#endif