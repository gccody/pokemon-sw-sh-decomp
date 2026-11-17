// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ac958 {
public:
    virtual ~Unk_23ac958();
};

// 0x71008005e0, 0x71008005f0
Unk_23ac958::~Unk_23ac958() {}
