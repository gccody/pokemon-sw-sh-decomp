// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ace18 {
public:
    virtual ~Unk_23ace18();
};

// 0x710082d5d0, 0x710082d5e0
Unk_23ace18::~Unk_23ace18() {}
