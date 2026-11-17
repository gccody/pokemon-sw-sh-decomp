// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bdd70 {
public:
    virtual ~Unk_23bdd70();
    virtual void vf2();
};

// 0x710090e2d0
void Unk_23bdd70::vf2() {}
