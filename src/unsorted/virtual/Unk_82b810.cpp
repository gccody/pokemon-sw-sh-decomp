// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23accf8 {
public:
    virtual ~Unk_23accf8();
};

// 0x710082b810, 0x710082b820
Unk_23accf8::~Unk_23accf8() {}
