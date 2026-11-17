// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2433448 {
public:
    virtual ~Unk_2433448();
    virtual u8* vf2();
    virtual u8* vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2433448, field_8, 0x8);

// 0x7101399690, 0x710139a8f0
Unk_2433448::~Unk_2433448() {}

// 0x710139a900
u8* Unk_2433448::vf2() {
    return &field_8;
}

// 0x710139a910
u8* Unk_2433448::vf3() {
    return &field_8;
}

class Unk_2433528 {
public:
    virtual ~Unk_2433528();
    virtual u8* vf2();
    virtual u8* vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2433528, field_8, 0x8);

// 0x7101399d20, 0x710139cf50
Unk_2433528::~Unk_2433528() {}

// 0x710139cf60
u8* Unk_2433528::vf2() {
    return &field_8;
}

// 0x710139cf70
u8* Unk_2433528::vf3() {
    return &field_8;
}

class Unk_24334b8 {
public:
    virtual ~Unk_24334b8();
    virtual u8* vf2();
    virtual u8* vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_24334b8, field_8, 0x8);

// 0x710139ad30, 0x710139c7f0
Unk_24334b8::~Unk_24334b8() {}

// 0x710139c800
u8* Unk_24334b8::vf2() {
    return &field_8;
}

// 0x710139c810
u8* Unk_24334b8::vf3() {
    return &field_8;
}
