// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Lifted through their own placeholder structs (cast_member).
struct Unk_8a73c0 {
    u8 _0[0x74];
    u8 field_74;
    u8 _75[0x1];
    u8 field_76;
};
PKMN_OFFSET_ASSERT(Unk_8a73c0, field_74, 0x74);
PKMN_OFFSET_ASSERT(Unk_8a73c0, field_76, 0x76);

struct Unk_8a73e0 {
    u8 _0[0x6c];
    u8 field_6c;
    u8 _6d[0x1];
    u8 field_6e;
};
PKMN_OFFSET_ASSERT(Unk_8a73e0, field_6c, 0x6c);
PKMN_OFFSET_ASSERT(Unk_8a73e0, field_6e, 0x6e);

class Unk_23b8ec0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71008a73c0
void Unk_23b8ec0::vf4() {
    Unk_8a73c0* self = reinterpret_cast<Unk_8a73c0*>(this);
    if (self->field_76 != 0) {
        return;
    }
    self->field_74 = 1;
}

class Unk_23b8ef8 {
public:
    virtual void vf0();
};

// 0x71008a73e0
void Unk_23b8ef8::vf0() {
    Unk_8a73e0* self = reinterpret_cast<Unk_8a73e0*>(this);
    if (self->field_6e != 0) {
        return;
    }
    self->field_6c = 1;
}
