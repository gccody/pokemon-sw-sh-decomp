#pragma once
// The objects the script commands of 0x71013b0640-0x71013b1150 call through
// (src/unsorted/unk_133d350/Unk_13b0640.cpp, Unk_13b0e80.cpp): what the
// globals Unk_24ba5a8, Unk_24ba4e0 and Unk_24ba560 hold. Placeholder names:
// rename once the classes are known.
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

// The manager's inner object, through a reference held while it's read.
inline Unk_13b0640_Inner* Unk_13b0640_GetInner() {
    Unk_239a418_Ref2<Unk_13b0640_Manager> manager = Unk_24ba5a8->field_90;
    return manager.m_ptr->field_60;
}
