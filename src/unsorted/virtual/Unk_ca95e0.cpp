// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23e0e60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ca95e0
void Unk_23e0e60::vf1() {}
