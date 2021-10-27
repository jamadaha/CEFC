#include "Fight.h"

Fight::Fight(EnginePair *enginePair) {
    engines = enginePair;
};

unsigned long int Fight::GetHash() {
    return engines->GetHash();
}
