// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_242d1e8 {
public:
    virtual ~Unk_242d1e8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x90];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_242d1e8, field_98, 0x98);

// 0x71012cdc10
u64 Unk_242d1e8::vf3() {
    return field_98;
}

class Unk_242d228 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71012cdda0
u32 Unk_242d228::vf0() {
    return 3;
}
