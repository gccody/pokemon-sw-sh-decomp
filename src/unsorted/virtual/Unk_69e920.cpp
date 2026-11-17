// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a2380 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710069e920
void Unk_23a2380::vf2() {}

class Unk_23a23b0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710069e9a0
void Unk_23a23b0::vf0() {}

class Unk_23a23d0 {
public:
    virtual ~Unk_23a23d0();
    virtual void vf2();
    virtual void vf3();
    u8 _8[0x260];
    u32 field_268;
};
PKMN_OFFSET_ASSERT(Unk_23a23d0, field_268, 0x268);

// 0x710069f060
void Unk_23a23d0::vf3() {
    field_268 = 3;
}
