// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bd1f8 {
public:
    virtual ~Unk_23bd1f8();
    virtual void vf2();
};

// 0x71008ec7f0
void Unk_23bd1f8::vf2() {}
