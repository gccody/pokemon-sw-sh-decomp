// Scope: common
// The battle scene's view system's scene (unsorted/Unk_98a420.h,
// Unk_23c4ef0_Scene): functions that forward to what its +0x38 and +0x58
// objects lead to. battle/battle_scene/Unk_23c4ef0_Seq.h declares the class
// without its fields, unsorted/Unk_98a420.h with them: this file defines
// members of the first, so it reads the fields through a view of its own.
// Placeholder names and types: rename and move once the classes are known.
// The callees were matched first as tools/leafgen.py's placeholders, each
// with its own type: the objects are passed as those.
#include <types.h>

#include "battle/battle_scene/Unk_23c4ef0_Seq.h"

// The scene's fields (as in unsorted/Unk_98a420.h).
struct Unk_98a120_Scene {
    u8 _0[0x38];
    u64 field_38;
    u8 _40[0x58 - 0x40];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_98a120_Scene, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_98a120_Scene, field_58, 0x58);

// The +0x38 object's Unk_23bdd98 (its +0x638), and the +0x58 one's.
u8* Unk_98ab90(u64 object);
u8* Unk_98adb0(u64 object);

inline const Unk_98a120_Scene* Unk_98a120_View(const void* scene) {
    return static_cast<const Unk_98a120_Scene*>(scene);
}

// What the +0x38 object leads to, at `offset`.
inline u8* Unk_98a120_Sub38(const void* scene, u64 offset) {
    return Unk_98ab90(Unk_98a120_View(scene)->field_38) + offset;
}

// What the +0x58 object leads to: at +0x58.
inline u8* Unk_98a120_Sub58(const void* scene) {
    return Unk_98adb0(Unk_98a120_View(scene)->field_58) + 0x58;
}

struct Unk_8ec930;
struct Unk_8ec940;
struct Unk_8ec950;
struct Unk_8ec960;
u8 Unk_8ec930_getField2d(const Unk_8ec930* self);
u16 Unk_8ec940_getField26(const Unk_8ec940* self);
u8 Unk_8ec950_getField28(const Unk_8ec950* self);
u8 Unk_8ec960_getField29(const Unk_8ec960* self);
void Unk_8ec970();

// 0x710098a120
u8 Unk_98a120(const Unk_23c4ef0_Scene* scene) {
    return Unk_8ec930_getField2d(
        reinterpret_cast<const Unk_8ec930*>(Unk_98a120_Sub38(scene, 0xe0)));
}

// 0x710098a140
u16 Unk_98a140(const Unk_23c4ef0_Scene* scene) {
    return Unk_8ec940_getField26(
        reinterpret_cast<const Unk_8ec940*>(Unk_98a120_Sub38(scene, 0xe0)));
}

// 0x710098a160
u8 Unk_98a160(const Unk_23c4ef0_Scene* scene) {
    return Unk_8ec950_getField28(
        reinterpret_cast<const Unk_8ec950*>(Unk_98a120_Sub38(scene, 0xe0)));
}

// 0x710098a180
u8 Unk_98a180(const Unk_23c4ef0_Scene* scene) {
    return Unk_8ec960_getField29(
        reinterpret_cast<const Unk_8ec960*>(Unk_98a120_Sub38(scene, 0xe0)));
}

// NON_MATCHING: the original passes the +0xe0 object on to 0x71008ec970,
// whose placeholder name (_Z10Unk_8ec970v) has no parameter: see the unit's
// report.
// 0x710098a1a0
void Unk_98a1a0(const Unk_23c4ef0_Scene* scene) {
    Unk_98a120_Sub38(scene, 0xe0);
    Unk_8ec970();
}

struct Unk_8eace0;
struct Unk_8eacf0;
struct Unk_8ead00;
void Unk_8eace0_call(const Unk_8eace0* self);
void Unk_8eacf0_call(const Unk_8eacf0* self, u8 value, u8 arg2, u32 arg3);
void Unk_8ead00_call(const Unk_8ead00* self);

// 0x710098a1c0
void Unk_23c4ef0_Scene::Unk_98a1c0() {
    Unk_8eace0_call(reinterpret_cast<const Unk_8eace0*>(Unk_98a120_Sub38(this, 0x370)));
}

// 0x710098a1e0
void Unk_23c4ef0_Scene::Unk_98a1e0(u32 arg1, u32 arg2, s32 arg3) {
    Unk_8eacf0_call(reinterpret_cast<const Unk_8eacf0*>(Unk_98a120_Sub38(this, 0x370)), arg1, arg2,
                    arg3);
}

// 0x710098a230
void Unk_23c4ef0_Scene::Unk_98a230() {
    Unk_8ead00_call(reinterpret_cast<const Unk_8ead00*>(Unk_98a120_Sub38(this, 0x370)));
}

void Unk_938aa0_call(void* self, u64 arg1, bool arg2);

// 0x710098a250
void Unk_98a250(const Unk_23c4ef0_Scene* scene, u64 arg1, bool arg2) {
    Unk_938aa0_call(Unk_98a120_Sub58(scene), arg1, arg2);
}

void Unk_938c90(u64 self, u64 arg1, u64 arg2, u32 arg3);

// NON_MATCHING: the original passes its first argument on unextended and
// tests the last as a bool (0x7100938c90 takes a u8 and a bool): the
// placeholder names (this one's u32, _Z10Unk_938c90mmmj) don't have them. See
// the unit's report.
// 0x710098a290
void Unk_23c4ef0_Scene::Unk_98a290(u8 arg1, u32 arg2, u32 arg3) {
    Unk_938c90(reinterpret_cast<u64>(Unk_98a120_Sub58(this)), arg1, arg2, arg3);
}

void Unk_938d00_call(void* self, u64 arg1);

// 0x710098a2e0
void Unk_98a2e0(const Unk_23c4ef0_Scene* scene, u64 arg1) {
    Unk_938d00_call(Unk_98a120_Sub58(scene), arg1);
}

void Unk_938d10(u64 self, u64 arg1, u64 arg2);
void Unk_938d80(u64 self, u64 arg1, u64 arg2);
void Unk_938df0(u64 self, u64 arg1, u64 arg2, u32 arg3);

// 0x710098a310
void Unk_98a310(const Unk_23c4ef0_Scene* scene, u32 arg1, u64 arg2) {
    Unk_938d10(reinterpret_cast<u64>(Unk_98a120_Sub58(scene)), arg1, arg2);
}

// 0x710098a350
void Unk_98a350(const Unk_23c4ef0_Scene* scene, u32 arg1, u64 arg2) {
    Unk_938d80(reinterpret_cast<u64>(Unk_98a120_Sub58(scene)), arg1, arg2);
}

// NON_MATCHING: 0x7100938df0 takes a bool (it tests it with `and #1`),
// which its placeholder name (_Z10Unk_938df0mmmj) gives as a u32: the
// conversion is scheduled after the other arguments' moves. See the unit's
// report.
// 0x710098a390
void Unk_98a390(const Unk_23c4ef0_Scene* scene, u32 arg1, u32 arg2, bool arg3) {
    Unk_938df0(reinterpret_cast<u64>(Unk_98a120_Sub58(scene)), arg1, arg2, arg3);
}
