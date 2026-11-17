// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23b8260 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100899e50
void Unk_23b8260::vf0() {}
