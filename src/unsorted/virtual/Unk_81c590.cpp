// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23acbb8 {
public:
    virtual ~Unk_23acbb8();
};

// 0x710081c590, 0x710081c5a0
Unk_23acbb8::~Unk_23acbb8() {}
