// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240b078 {
public:
    virtual ~Unk_240b078();
    virtual u8* vf2();
    virtual void vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_240b078, field_8, 0x8);

// 0x710104b170
u8* Unk_240b078::vf2() {
    return &field_8;
}

class Unk_240b0a8 {
public:
    virtual ~Unk_240b0a8();
    virtual u64 vf2();
    virtual void vf3();
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_240b0a8, field_8, 0x8);

// 0x710104b1e0
u64 Unk_240b0a8::vf2() {
    return field_8;
}
