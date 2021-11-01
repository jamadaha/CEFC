#ifndef ENGINE_PAIR
#define ENGINE_PAIR

#include "Engine.h"

class EnginePair {
    public:
    EnginePair(Engine *engine1, Engine *engine2);

    Engine *GetEngine(int index);

    unsigned long int GetHash();

    private:
    Engine *engines[2];
};

#endif