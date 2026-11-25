// Scope: common
//
// Script commands of game/unk_133d350 (0x71013b0640-0x71013b0e70), entries of
// a command table that take the script's context and its arguments (as
// src/field/content/Unk_13f1360.h): each takes a reference to an object the
// globals Unk_24ba5a8 and Unk_24ba4e0 hold and calls one of its functions.
// Placeholder names: rename once the classes are known.
#include "field/content/Unk_13f1360.h"
#include "gflib3/Unk_239a418.h"

// The object at +0x668 of Unk_13b0640_Inner: its functions are at
// 0x7100ca42d0-0x7100ca4e20.
class Unk_13b0640_Object : public Unk_239a418 {
public:
    u8 _60[0xb0 - 0x60];
    s32 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_13b0640_Object, field_b0, 0xb0);

struct Unk_13b0640_Inner {
    u8 _0[0x668];
    Unk_239a418_Ref<Unk_13b0640_Object> field_668;
};
PKMN_OFFSET_ASSERT(Unk_13b0640_Inner, field_668, 0x668);

// What Unk_24ba5a8 holds at +0x90.
class Unk_13b0640_Manager : public Unk_239a418 {
public:
    Unk_13b0640_Inner* field_60;
};
PKMN_OFFSET_ASSERT(Unk_13b0640_Manager, field_60, 0x60);

struct Unk_24ba5a8_Type {
    u8 _0[0x90];
    Unk_239a418_Ref2<Unk_13b0640_Manager> field_90;
};
PKMN_OFFSET_ASSERT(Unk_24ba5a8_Type, field_90, 0x90);

extern Unk_24ba5a8_Type* Unk_24ba5a8;

// What Unk_24ba4e0 holds at +0x290: its functions are at
// 0x710134c550-0x710134c970.
class Unk_13b09f0_Object : public Unk_239a418 {};

struct Unk_24ba4e0_Type {
    u8 _0[0x290];
    Unk_239a418_Ref2<Unk_13b09f0_Object> field_290;
};
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_290, 0x290);

extern Unk_24ba4e0_Type* Unk_24ba4e0;

// As in src/unsorted/unk_8bf520/Unk_8e1cf0.cpp: +0x68 is an allocator.
struct Unk_24ba560_Type {
    u8 _0[0x68];
    Unk_239a418_Allocator* field_68;
};
PKMN_OFFSET_ASSERT(Unk_24ba560_Type, field_68, 0x68);

extern Unk_24ba560_Type* Unk_24ba560;

void Unk_13b19d0(Unk_13b0640_Inner* self, Unk_239a418_Allocator* allocator);

void Unk_ca42d0(Unk_13b0640_Object* self);
bool Unk_ca4370(Unk_13b0640_Object* self);
void Unk_ca43b0(Unk_13b0640_Object* self);
bool Unk_ca45b0(Unk_13b0640_Object* self);

s32 Unk_134c550(Unk_13b09f0_Object* self, s32 value);
s32 Unk_134c6e0(Unk_13b09f0_Object* self, s32 value);
void Unk_134c7a0(Unk_13b09f0_Object* self, s32 value);
s32 Unk_134c880(Unk_13b09f0_Object* self, s32 value);
s32 Unk_134c8a0(Unk_13b09f0_Object* self, s32 value);
void Unk_134c8c0(Unk_13b09f0_Object* self, s32 value);
void Unk_134c8e0(Unk_13b09f0_Object* self, s32 value);
void Unk_134c970(Unk_13b09f0_Object* self, s32 value);

// The manager's inner object, through a reference held while it's read.
static Unk_13b0640_Inner* Unk_Inner() {
    Unk_239a418_Ref2<Unk_13b0640_Manager> manager = Unk_24ba5a8->field_90;
    return manager.m_ptr->field_60;
}

// 0x71013b0640
s64 Unk_13b0640(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Allocator* allocator = Unk_24ba560->field_68;
    Unk_13b19d0(Unk_Inner(), allocator);
    return 1;
}

// 0x71013b06d0
s64 Unk_13b06d0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_Inner()->field_668;
    return Unk_ca4370(object.m_ptr);
}

// 0x71013b0790
s64 Unk_13b0790(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_13b0640_Inner* inner = Unk_Inner();
    Unk_ca42d0(inner->field_668.m_ptr);
    inner->field_668.Reset();
    return 1;
}

// 0x71013b0810
s64 Unk_13b0810(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_Inner()->field_668;
    return object.m_ptr->field_b0;
}

// 0x71013b08c0
s64 Unk_13b08c0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    return Unk_134c550(object.m_ptr, value);
}

// 0x71013b0950
s64 Unk_13b0950(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    return Unk_134c6e0(object.m_ptr, value);
}

// 0x71013b09f0
s64 Unk_13b09f0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    Unk_134c8e0(object.m_ptr, value);
    return 1;
}

// 0x71013b0a70
s64 Unk_13b0a70(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    Unk_134c970(object.m_ptr, value);
    return 1;
}

// 0x71013b0af0
s64 Unk_13b0af0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    Unk_134c7a0(object.m_ptr, value);
    return 1;
}

// 0x71013b0b70
s64 Unk_13b0b70(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    return Unk_134c880(object.m_ptr, value);
}

// 0x71013b0c00
s64 Unk_13b0c00(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    return Unk_134c8a0(object.m_ptr, value);
}

// 0x71013b0c90
s64 Unk_13b0c90(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    Unk_134c8c0(object.m_ptr, value);
    return 1;
}

// 0x71013b0d10
s64 Unk_13b0d10(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_Inner()->field_668;
    Unk_ca43b0(object.m_ptr);
    return 1;
}

// 0x71013b0dc0
s64 Unk_13b0dc0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_Inner()->field_668;
    return Unk_ca45b0(object.m_ptr);
}
