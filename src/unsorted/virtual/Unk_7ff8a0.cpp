// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ac938 {
public:
    virtual ~Unk_23ac938();
};

// 0x71007ff8a0, 0x71007ff8b0
Unk_23ac938::~Unk_23ac938() {}
