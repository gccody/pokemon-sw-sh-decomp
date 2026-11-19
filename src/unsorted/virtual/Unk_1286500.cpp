// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// Lifted through their own placeholder structs (cast_member).
struct Unk_1286500 {
    u8 _0[0x78];
    Unk_239a418* field_78;
};
PKMN_OFFSET_ASSERT(Unk_1286500, field_78, 0x78);

struct Unk_128da20 {
    u8 _0[0x78];
    Unk_239a418* field_78;
};
PKMN_OFFSET_ASSERT(Unk_128da20, field_78, 0x78);

struct Unk_128da40 {
    u8 _0[0x78];
    Unk_239a418* field_78;
};
PKMN_OFFSET_ASSERT(Unk_128da40, field_78, 0x78);

struct Unk_12903f0 {
    u8 _0[0x78];
    Unk_239a418* field_78;
};
PKMN_OFFSET_ASSERT(Unk_12903f0, field_78, 0x78);

struct Unk_1290410 {
    u8 _0[0x78];
    Unk_239a418* field_78;
};
PKMN_OFFSET_ASSERT(Unk_1290410, field_78, 0x78);

class Unk_242a258 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};

// 0x7101286500
void Unk_242a258::vf11() {
    Unk_1286500* self = reinterpret_cast<Unk_1286500*>(this);
    Unk_239a418* v0 = self->field_78;
    self->field_78 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

class Unk_242a348 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};

// 0x7101286cf0
void Unk_242a348::vf11() {}

// 0x7101286d00
void Unk_242a348::vf12() {}

// 0x7101286d10
void Unk_242a348::vf13() {}

class Unk_242a9d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};

// 0x710128da20
void Unk_242a9d8::vf12() {
    Unk_128da20* self = reinterpret_cast<Unk_128da20*>(this);
    Unk_239a418* v0 = self->field_78;
    self->field_78 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

// 0x710128da40
void Unk_242a9d8::vf13() {
    Unk_128da40* self = reinterpret_cast<Unk_128da40*>(this);
    Unk_239a418* v0 = self->field_78;
    self->field_78 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

class Unk_242aca8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};

// 0x71012903f0
void Unk_242aca8::vf12() {
    Unk_12903f0* self = reinterpret_cast<Unk_12903f0*>(this);
    Unk_239a418* v0 = self->field_78;
    self->field_78 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

// 0x7101290410
void Unk_242aca8::vf13() {
    Unk_1290410* self = reinterpret_cast<Unk_1290410*>(this);
    Unk_239a418* v0 = self->field_78;
    self->field_78 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}
