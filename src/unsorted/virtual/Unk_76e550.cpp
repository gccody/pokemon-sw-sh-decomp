// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a7a28 {
public:
    virtual ~Unk_23a7a28();
};

// 0x710076e550, 0x710076e560
Unk_23a7a28::~Unk_23a7a28() {}

class Unk_23a7b18 {
public:
    virtual ~Unk_23a7b18();
};

// 0x7100770c30, 0x7100770c40
Unk_23a7b18::~Unk_23a7b18() {}
