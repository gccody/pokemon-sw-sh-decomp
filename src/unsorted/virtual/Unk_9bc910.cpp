// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23c4e30 {
public:
    virtual ~Unk_23c4e30();
};

// 0x71009bc910, 0x71009bc920
Unk_23c4e30::~Unk_23c4e30() {}
