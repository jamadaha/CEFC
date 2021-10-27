#include "EnginePair.h"

EnginePair::EnginePair(Engine *engine1, Engine *engine2) {
    engines[0] = engine1;
    engines[1] = engine2;
};

unsigned long int EnginePair::GetHash() {
    return (engines[0]->GetId() & engines[1]->GetId());
};