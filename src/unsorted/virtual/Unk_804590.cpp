// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23aca18 {
public:
    virtual ~Unk_23aca18();
};

// 0x7100804590, 0x71008045a0
Unk_23aca18::~Unk_23aca18() {}
