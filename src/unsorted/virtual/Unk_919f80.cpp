// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23be2d8 {
public:
    virtual ~Unk_23be2d8();
    virtual void vf2();
};

// 0x7100919f80
void Unk_23be2d8::vf2() {}
