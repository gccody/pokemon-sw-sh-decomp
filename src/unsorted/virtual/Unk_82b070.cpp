// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23accb8 {
public:
    virtual ~Unk_23accb8();
};

// 0x710082b070, 0x710082b080
Unk_23accb8::~Unk_23accb8() {}
