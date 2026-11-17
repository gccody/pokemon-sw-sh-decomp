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

class Unk_23b8280 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23b8280, field_78, 0x78);

// 0x710089b100
u64 Unk_23b8280::vf7() {
    return field_78;
}

class Unk_23b8348 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23b8348, field_78, 0x78);

// 0x710089b960
u64 Unk_23b8348::vf7() {
    return field_78;
}
