// Scope: common
// The battle scene's view system's scene (unsorted/Unk_98a420.h,
// Unk_23c4ef0_Scene): what it does with the objects it holds at +0x38 and
// +0x58, and functions that forward to what they lead to. Its headers
// declare the class without these functions, so they are free functions
// over a view of its fields. Placeholder names and types: rename and move
// once the classes are known. The callees of 0x71008ec... were matched first
// as tools/leafgen.py's placeholders, each with its own type: the objects are
// passed as those.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_23c4ef0_Scene;

// What the scene's +0x18 points to: two objects it sets flags on.
struct Unk_989900_Owner {
    u8 _0[0x3f8];
    Unk_239a418* field_3f8;
    Unk_239a418* field_400;
};
PKMN_OFFSET_ASSERT(Unk_989900_Owner, field_3f8, 0x3f8);
PKMN_OFFSET_ASSERT(Unk_989900_Owner, field_400, 0x400);

// The scene's fields (as in unsorted/Unk_98a420.h).
struct Unk_989900_Scene {
    u8 _0[0x18];
    Unk_989900_Owner* field_18;
    u8 _20[0x38 - 0x20];
    u64 field_38;
    u8 _40[0x58 - 0x40];
    u64 field_58;
    u8 _60[0x78 - 0x60];
    bool field_78;
    bool field_79;
};
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_989900_Scene, field_79, 0x79);

inline Unk_989900_Scene* Unk_989900_View(Unk_23c4ef0_Scene* scene) {
    return reinterpret_cast<Unk_989900_Scene*>(scene);
}

// What the +0x38 and +0x58 objects are asked (0x71014d...).
bool Unk_14dd320(u64 object);
bool Unk_14dc210(u64 object);
bool Unk_14dd5e0(u64 object);
bool Unk_14dc4d0(u64 object);
bool Unk_14dd2b0(u64 object);
void Unk_14dbf60(u64 object);
void Unk_14dbff0(u64 object);
void Unk_14dc050(u64 object);

// Sets or clears the flag `bit` of an object.
void Unk_601140(Unk_239a418* object, bool value, u32 bit);

// Sets or clears the flag 6 of the +0x18 object's two objects.
inline void Unk_989900_SetFlag6(Unk_989900_Owner* owner, bool value) {
    Unk_239a418_Ref<Unk_239a418> first(owner->field_3f8);
    Unk_239a418_Ref<Unk_239a418> second(owner->field_400);
    if (first.m_ptr)
        Unk_601140(first.m_ptr, value, 6);
    if (second.m_ptr)
        Unk_601140(second.m_ptr, value, 6);
}

// 0x7100989d20
bool Unk_989d20(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    bool done = Unk_14dd320(self->field_58);
    if (!done)
        Unk_14dbff0(self->field_58);
    self->field_78 = done;
    return done;
}

// 0x7100989d60
bool Unk_989d60(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    bool done = Unk_14dc210(self->field_38);
    if (!done)
        Unk_14dbff0(self->field_38);
    self->field_79 = done;
    return done;
}

// 0x7100989da0
bool Unk_989da0(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    bool done = Unk_14dd5e0(self->field_58);
    if (!done)
        Unk_14dbff0(self->field_58);
    self->field_78 = false;
    return done;
}

// 0x7100989de0
bool Unk_989de0(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    bool done = Unk_14dc4d0(self->field_38);
    if (done) {
        if (Unk_989900_Owner* owner = self->field_18)
            Unk_989900_SetFlag6(owner, true);
    } else {
        Unk_14dbff0(self->field_38);
    }
    self->field_79 = false;
    return done;
}

// 0x7100989eb0
void Unk_989eb0(Unk_23c4ef0_Scene* scene) {
    Unk_989900_Scene* self = Unk_989900_View(scene);
    if (self->field_78) {
        Unk_14dbf60(self->field_58);
        Unk_14dbff0(self->field_58);
        Unk_14dc050(self->field_58);
    }
    if (self->field_79) {
        Unk_14dbf60(self->field_38);
        Unk_14dbff0(self->field_38);
        Unk_14dc050(self->field_38);
    }
    Unk_989900_Owner* owner = self->field_18;
    bool value = self->field_79 ? !Unk_14dd2b0(self->field_38) : true;
    if (owner)
        Unk_989900_SetFlag6(owner, value);
}

// The +0x38 object's Unk_23bdd98 (its +0x638).
u8* Unk_98ab90(u64 object);

// What the +0x38 object leads to, at `offset`.
inline u8* Unk_989900_Sub38(Unk_23c4ef0_Scene* scene, u64 offset) {
    return Unk_98ab90(Unk_989900_View(scene)->field_38) + offset;
}

struct Unk_8ec490;
struct Unk_8ec4c0;
struct Unk_8ec510;
struct Unk_8ec540;
void Unk_8ec490_set(Unk_8ec490* self, u64 value, u64 arg2, u32 arg3, bool arg4, u64 arg5);
u8 Unk_8ec4c0_getField42(const Unk_8ec4c0* self);
void Unk_8ec510_set(Unk_8ec510* self, u64 value, u32 arg2, bool arg3, u64 arg4);
u8 Unk_8ec540_getField3a(const Unk_8ec540* self);
void Unk_8ec910(u64 self, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5);

// 0x7100989fd0
void Unk_989fd0(Unk_23c4ef0_Scene* scene, u64 arg1, u64 arg2, u32 arg3, bool arg4, u64 arg5) {
    Unk_8ec490_set(reinterpret_cast<Unk_8ec490*>(Unk_989900_Sub38(scene, 0x3e8)), arg1, arg2, arg3,
                   arg4, arg5);
}

// 0x710098a030
u8 Unk_98a030(Unk_23c4ef0_Scene* scene) {
    return Unk_8ec4c0_getField42(
        reinterpret_cast<const Unk_8ec4c0*>(Unk_989900_Sub38(scene, 0x3e8)));
}

// 0x710098a050
void Unk_98a050(Unk_23c4ef0_Scene* scene, u64 arg1, u32 arg2, bool arg3, u64 arg4) {
    Unk_8ec510_set(reinterpret_cast<Unk_8ec510*>(Unk_989900_Sub38(scene, 0x430)), arg1, arg2, arg3,
                   arg4);
}

// 0x710098a0a0
u8 Unk_98a0a0(Unk_23c4ef0_Scene* scene) {
    return Unk_8ec540_getField3a(
        reinterpret_cast<const Unk_8ec540*>(Unk_989900_Sub38(scene, 0x430)));
}

// NON_MATCHING: 0x71008ec910 takes the five bytes as bytes, which its name
// (_Z10Unk_8ec910mmmmmm) gives as u64: clang extends them. With the bytes
// passed as they are this matches. See the unit's report.
// 0x710098a0c0
void Unk_98a0c0(Unk_23c4ef0_Scene* scene, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    Unk_8ec910(reinterpret_cast<u64>(Unk_989900_Sub38(scene, 0xe0)), arg1, arg2, arg3, arg4, arg5);
}
