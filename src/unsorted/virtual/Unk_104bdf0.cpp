// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240b178 {
public:
    virtual ~Unk_240b178();
    virtual u8* vf2();
    virtual void vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_240b178, field_8, 0x8);

// 0x710104bdf0
u8* Unk_240b178::vf2() {
    return &field_8;
}

class Unk_240b1a8 {
public:
    virtual ~Unk_240b1a8();
    virtual u64 vf2();
    virtual void vf3();
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_240b1a8, field_8, 0x8);

// 0x710104be50
u64 Unk_240b1a8::vf2() {
    return field_8;
}
