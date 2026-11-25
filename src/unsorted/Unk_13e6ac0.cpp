// Scope: common
//
// Script commands of game/unk_133d350 (0x71013e6ac0-0x71013e7230), entries of
// a command table that take the script's context and its arguments (as
// src/field/content/Unk_13f1360.h): calls of the objects the global
// Unk_24ba4e0 holds at +0x1d8, +0x1e8 and +0x208, and of the objects the
// manager Unk_24ba5a8 holds at +0x90 reaches. Each is held by a reference for
// the call (as src/unsorted/unk_133d350/Unk_13b0640.cpp). Placeholder names:
// rename once the classes are known.
#include <types.h>

#include "field/content/Unk_13f1360.h"
#include "gflib3/Unk_239a418.h"

// What Unk_24ba4e0 holds at +0x1e8 (as src/battle/battle_engine/Unk_137c470.cpp).
class Unk_136b580 : public Unk_239a418 {};

// The owner of the block stores (as src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type {
    u8 _0[0x1d8];
    Unk_239a418_Ref2<Unk_239a418> field_1d8;
    u8 _1e0[0x1e8 - 0x1e0];
    Unk_239a418_Ref2<Unk_136b580> field_1e8;
    u8 _1f0[0x208 - 0x1f0];
    Unk_239a418_Ref2<Unk_239a418> field_208;
};
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_1d8, 0x1d8);
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_1e8, 0x1e8);
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_208, 0x208);

extern Unk_24ba4e0_Type* Unk_24ba4e0;

// The object at +0x1d8 (src/unsorted/Unk_13e6430.cpp).
bool Unk_1368ae0(Unk_239a418* self, s32 value);

// The object at +0x1e8: a counter at +0x130 that 0x710136b7c0 adds to (with a
// 9,999,999 limit) and 0x710136b820 takes from.
struct Unk_136b790;
struct Unk_136b820;
u32 Unk_136b790_getField130(const Unk_136b790* self);
u32 Unk_136b7c0(Unk_136b580* self, u32 value);
u32 Unk_136b820_update(Unk_136b820* self, u32 value);

// The object at +0x208: a counter at +0x64 that 0x710137b8e0 adds to (with a
// 9,999,999 limit) and 0x710137b940 takes from.
struct Unk_137b8b0;
struct Unk_137b940;
u32 Unk_137b8b0_getField64(const Unk_137b8b0* self);
u32 Unk_137b8e0(Unk_239a418* self, u32 value);
u32 Unk_137b940_update(Unk_137b940* self, u32 value);

// What the manager's inner object holds at +0x630: its functions are at
// 0x71014dfc70-0x71014dfe50.
class Unk_14dfe50_Object;
bool Unk_14dfe50(Unk_14dfe50_Object* self);
void Unk_14dfd60(Unk_14dfe50_Object* self);
void Unk_14dfc70(Unk_14dfe50_Object* self, u16 value);

// What the object the manager's inner object holds at +0x610 holds at +0x120:
// its functions are at 0x7100e3cdd0-0x7100e3d020.
class Unk_e3ce60_Object : public Unk_239a418 {};
void Unk_e3cdd0(Unk_e3ce60_Object* self, bool value);
void Unk_e3ce60(Unk_e3ce60_Object* self);
void Unk_e3cee0(Unk_e3ce60_Object* self, bool value);
void Unk_e3d020(Unk_e3ce60_Object* self);

class Unk_13e6e50_Holder : public Unk_239a418 {
public:
    u8 _60[0x120 - 0x60];
    Unk_239a418_Ref2<Unk_e3ce60_Object> field_120;
};
PKMN_OFFSET_ASSERT(Unk_13e6e50_Holder, field_120, 0x120);

// The manager's inner object (src/unsorted/unk_133d350/Unk_13b0640.h's
// Unk_13b0640_Inner, which this file can't include: its Unk_24ba4e0_Type
// has none of the fields above).
struct Unk_13e6ac0_Inner {
    u8 _0[0x610];
    Unk_239a418_Ref2<Unk_13e6e50_Holder> field_610;
    u8 _618[0x630 - 0x618];
    Unk_14dfe50_Object* field_630;
};
PKMN_OFFSET_ASSERT(Unk_13e6ac0_Inner, field_610, 0x610);
PKMN_OFFSET_ASSERT(Unk_13e6ac0_Inner, field_630, 0x630);

// What Unk_24ba5a8 holds at +0x90 (Unk_13b0640.h's Unk_13b0640_Manager).
class Unk_13e6ac0_Manager : public Unk_239a418 {
public:
    Unk_13e6ac0_Inner* field_60;
};
PKMN_OFFSET_ASSERT(Unk_13e6ac0_Manager, field_60, 0x60);

struct Unk_24ba5a8_Type {
    u8 _0[0x90];
    Unk_239a418_Ref2<Unk_13e6ac0_Manager> field_90;
};
PKMN_OFFSET_ASSERT(Unk_24ba5a8_Type, field_90, 0x90);

extern Unk_24ba5a8_Type* Unk_24ba5a8;

// The object at +0x120 of the inner object's +0x610 object, null when there's
// no inner object.
inline Unk_239a418_Ref2<Unk_e3ce60_Object> Unk_13e6ac0_GetObject() {
    Unk_239a418_Ref2<Unk_13e6ac0_Manager> manager = Unk_24ba5a8->field_90;
    Unk_13e6ac0_Inner* inner = manager.m_ptr->field_60;
    if (inner == nullptr)
        return Unk_239a418_Ref2<Unk_e3ce60_Object>(nullptr);
    Unk_239a418_Ref2<Unk_13e6e50_Holder> holder = inner->field_610;
    return holder.m_ptr->field_120;
}

// 0x71013e6ac0
s64 Unk_13e6ac0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s16 value = args->field_8;
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_1d8;
    return Unk_1368ae0(object.m_ptr, value);
}

// 0x71013e6b30
s64 Unk_13e6b30(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u16 value = args->field_8;
    Unk_239a418_Ref2<Unk_13e6ac0_Manager> manager = Unk_24ba5a8->field_90;
    Unk_13e6ac0_Inner* inner = manager.m_ptr->field_60;
    if (inner == nullptr)
        return 0;
    Unk_14dfe50_Object* object = inner->field_630;
    if (Unk_14dfe50(object))
        return 0;
    Unk_14dfc70(object, value);
    return 1;
}

// 0x71013e6bc0
s64 Unk_13e6bc0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13e6ac0_Manager> manager = Unk_24ba5a8->field_90;
    Unk_13e6ac0_Inner* inner = manager.m_ptr->field_60;
    if (inner == nullptr)
        return 0;
    Unk_14dfe50_Object* object = inner->field_630;
    if (!Unk_14dfe50(object))
        return 0;
    Unk_14dfd60(object);
    return 1;
}

// 0x71013e6c40
s64 Unk_13e6c40(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13e6ac0_Manager> manager = Unk_24ba5a8->field_90;
    Unk_13e6ac0_Inner* inner = manager.m_ptr->field_60;
    if (inner == nullptr)
        return false;
    return Unk_14dfe50(inner->field_630);
}

// 0x71013e6cb0
s64 Unk_13e6cb0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u32 value = args->field_8;
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_208;
    return Unk_137b8e0(object.m_ptr, value);
}

// 0x71013e6d40
s64 Unk_13e6d40(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u32 value = args->field_8;
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_208;
    return Unk_137b940_update(reinterpret_cast<Unk_137b940*>(object.m_ptr), value);
}

// 0x71013e6dd0
s64 Unk_13e6dd0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_208;
    return Unk_137b8b0_getField64(reinterpret_cast<const Unk_137b8b0*>(object.m_ptr));
}

// 0x71013e6e50
s64 Unk_13e6e50(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    bool value = args->field_8 != 0;
    Unk_239a418_Ref2<Unk_e3ce60_Object> object = Unk_13e6ac0_GetObject();
    if (object.m_ptr == nullptr)
        return 0;
    Unk_e3d020(object.m_ptr);
    Unk_e3cdd0(object.m_ptr, value);
    return 1;
}

// 0x71013e6f40
s64 Unk_13e6f40(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_e3ce60_Object> object = Unk_13e6ac0_GetObject();
    if (object.m_ptr == nullptr)
        return 0;
    Unk_e3ce60(object.m_ptr);
    return 1;
}

// 0x71013e7020
s64 Unk_13e7020(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    bool value = args->field_8 != 0;
    Unk_239a418_Ref2<Unk_e3ce60_Object> object = Unk_13e6ac0_GetObject();
    if (object.m_ptr == nullptr)
        return 0;
    Unk_e3cee0(object.m_ptr, value);
    return 1;
}

// 0x71013e7110
s64 Unk_13e7110(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u32 value = args->field_8;
    Unk_239a418_Ref2<Unk_136b580> object = Unk_24ba4e0->field_1e8;
    return Unk_136b7c0(object.m_ptr, value);
}

// 0x71013e71a0
s64 Unk_13e71a0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u32 value = args->field_8;
    Unk_239a418_Ref2<Unk_136b580> object = Unk_24ba4e0->field_1e8;
    return Unk_136b820_update(reinterpret_cast<Unk_136b820*>(object.m_ptr), value);
}

// 0x71013e7230
s64 Unk_13e7230(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_136b580> object = Unk_24ba4e0->field_1e8;
    return Unk_136b790_getField130(reinterpret_cast<const Unk_136b790*>(object.m_ptr));
}
