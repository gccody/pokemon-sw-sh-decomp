// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240ca78 {
public:
    virtual ~Unk_240ca78();
    virtual u8* vf2();
    virtual void vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_240ca78, field_8, 0x8);

// 0x710106d070
u8* Unk_240ca78::vf2() {
    return &field_8;
}

class Unk_240caa8 {
public:
    virtual ~Unk_240caa8();
    virtual u64 vf2();
    virtual void vf3();
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_240caa8, field_8, 0x8);

// 0x710106d0e0
u64 Unk_240caa8::vf2() {
    return field_8;
}
