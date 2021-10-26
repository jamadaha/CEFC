#ifndef FIGHT
#define FIGHT

#include "Engine.h"

class Fight {
    public:
    Fight(Engine *engine1, Engine *engine2) {
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