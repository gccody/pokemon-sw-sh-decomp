// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a3d58 {
public:
    virtual ~Unk_23a3d58();
    virtual u8* vf2();
    virtual void vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_23a3d58, field_8, 0x8);

// 0x71006c27d0
u8* Unk_23a3d58::vf2() {
    return &field_8;
}

class Unk_23a3d88 {
public:
    virtual ~Unk_23a3d88();
    virtual u64 vf2();
    virtual void vf3();
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_23a3d88, field_8, 0x8);

// 0x71006c2840
u64 Unk_23a3d88::vf2() {
    return field_8;
}
