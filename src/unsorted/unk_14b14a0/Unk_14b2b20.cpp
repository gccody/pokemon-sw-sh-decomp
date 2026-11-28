// Scope: common
//
// Slots of the League Card view with vtable 0x71024422d8 (its class,
// Unk_24422d8, is declared by src/unsorted/virtual/Unk_14b2cc0.cpp, where
// its one-call forwarders are). They work on the view's parts (+0x58,
// src/contents/trainer_license/state/Unk_14aae90.h): positions, attaching
// parts, and finding a part's named descendants. Written as free functions
// over the view's layout, with placeholder names: rename them once the class
// is known. The positions the slots take and give are 16-byte vectors whose
// first two lanes are a part's 2D position.
//
// The view is on gflib3's Unk_239a4c0 (src/gflib3/Unk_239a4c0.h): its
// constructor (0x71014b2b20) and destructors (0x71014b3060, 0x71014b30b0 and
// the +0x48 thunks 0x71014b3100, 0x71014b3150) need the class declared with
// its bases, and drop the parts' reference at +0x58. They aren't written yet.
#include <arm_neon.h>
#include <cstring>

#include <types.h>

#include "contents/trainer_license/state/Unk_14aae90.h"

// A part as these slots see it (Unk_14aaec0_Part): slot 5 sets one of four
// values, +0x58 holds its flags (bit 0 tested when looking for a cursor) and
// +0xb0 its name (searched with strstr).
class Unk_14b2b20_Part {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u32 index, u64 value);

    u8 _8[0x58 - 0x8];
    u8 field_58;
    u8 _59[0xb0 - 0x59];
    char field_b0[0x18];
};
PKMN_OFFSET_ASSERT(Unk_14b2b20_Part, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_14b2b20_Part, field_b0, 0xb0);

// What 0x71017ac790 finds by name: +0x4 is the offset of its data from it.
struct Unk_17ac790_Entry {
    u32 field_0;
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_17ac790_Entry, field_4, 0x4);

// The view (Unk_24422d8): its parts at +0x58.
struct Unk_14b2b20_View {
    u8 _0[0x58];
    Unk_14aaec0_Parts* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14b2b20_View, field_58, 0x58);

// Defined in src/contents/trainer_license/state/Unk_14aae90.cpp.
struct Unk_14aae90_Node;
Unk_14aae90_Vec2 Unk_14aae90(const Unk_14aae90_Node* node);
void Unk_14aaec0(Unk_14aaec0_Parts* self, const u64& key, const Unk_14aae90_Vec2& value);
void Unk_14aaf40(const Unk_14aaec0_Parts* self, const u64& key, Unk_14aae90_Vec2* out);
void Unk_14aafc0(Unk_14aaec0_Parts* self, const u64& key, const Unk_14aae90_Vec2& value);
void Unk_14ab440(u64 self, u64 key, f32 frame);
f32 Unk_14ab5c0(Unk_14aaec0_Parts* self, const u64& key);
// Defined in src/contents/trainer_license/state/Unk_14ab670.cpp.
void Unk_14ab670(const Unk_14aaec0_Parts* self, const u64& key, const u64& other);
void Unk_14ab810(const Unk_14aaec0_Parts* self, const u64& key, const u64& other);
void Unk_14ab8e0(const Unk_14aaec0_Parts* self, const u64& key);

// The parts' lookups (placeholders: the signatures are what the calls pass).
// 0x71014aad40 gives the part with the key (null when there's none),
// 0x71014aadb0 and 0x71014aacc0 get and set its +0x30 position.
Unk_14b2b20_Part* Unk_14aad40(const Unk_14aaec0_Parts* self, const u64& key);
Unk_14aae90_Vec2 Unk_14aadb0(const Unk_14aaec0_Parts* self, const u64& key);
void Unk_14aacc0(Unk_14aaec0_Parts* self, const u64& key, const Unk_14aae90_Vec2& value);
// The part with the key as another kind of part (0x71014aad40, then a type
// check).
Unk_14b2b20_Part* Unk_7a3a10(const Unk_14aaec0_Parts* self, const u64& key);
void Unk_130b590(void* target, Unk_14b2b20_Part* part, u32 arg);
// The part's entry with the name, or null.
const Unk_17ac790_Entry* Unk_17ac790(Unk_14b2b20_Part* part, const char* name);
// The next part to search after this one (null at the end).
Unk_14b2b20_Part* Unk_17b9140(Unk_14b2b20_Part* part);

// A position as the view gives it.
inline float32x4_t Unk_14b2b20_ToVector(const Unk_14aae90_Vec2& pos) {
    return float32x4_t{pos.x, pos.y, 0.0f, 0.0f};
}

// Sets the +0x30 position of the part with the key.
inline void Unk_14b2b20_SetPosition(Unk_14b2b20_View* self,
                                    const u64& key,
                                    const float32x4_t& pos) {
    Unk_14aacc0(self->field_58, key, Unk_14aae90_Vec2{pos[0], pos[1]});
}

// 0x71014b2bc0
void Unk_14b2bc0(Unk_14b2b20_View* self, const u64& key, const float32x4_t& pos) {
    Unk_14b2b20_SetPosition(self, key, pos);
}

// 0x71014b2bf0
float32x4_t Unk_14b2bf0(Unk_14b2b20_View* self, const u64& key) {
    return Unk_14b2b20_ToVector(Unk_14aadb0(self->field_58, key));
}

// 0x71014b2c20
void Unk_14b2c20(Unk_14b2b20_View* self, const u64& key, const float32x4_t& pos) {
    Unk_14aafc0(self->field_58, key, Unk_14aae90_Vec2{pos[0], pos[1]});
}

// 0x71014b2c50
void Unk_14b2c50(Unk_14b2b20_View* self, const u64& key, const float32x4_t& pos) {
    Unk_14aaec0(self->field_58, key, Unk_14aae90_Vec2{pos[0], pos[1]});
}

// 0x71014b2c80
float32x4_t Unk_14b2c80(Unk_14b2b20_View* self, const u64& key) {
    Unk_14aae90_Vec2 value = {0.0f, 0.0f};
    Unk_14aaf40(self->field_58, key, &value);
    return Unk_14b2b20_ToVector(value);
}

// 0x71014b2d30
void Unk_14b2d30(Unk_14b2b20_View* self, const u64& key) {
    Unk_14aaec0_Parts* parts = self->field_58;
    f32 frame = Unk_14ab5c0(parts, key);
    Unk_14ab440(reinterpret_cast<u64>(parts), reinterpret_cast<u64>(&key), frame);
}

// 0x71014b2d70
void Unk_14b2d70(Unk_14b2b20_View* self, const u64& key, const u64& other) {
    Unk_14ab810(self->field_58, key, other);
    Unk_14ab670(self->field_58, key, other);
}

// Moves the part with `key` to `part`'s position (the sum of the offsets up
// its chain).
inline void Unk_14b2b20_MoveTo(Unk_14b2b20_View* self, const u64& key, Unk_14b2b20_Part* part) {
    float32x4_t pos =
        Unk_14b2b20_ToVector(Unk_14aae90(reinterpret_cast<const Unk_14aae90_Node*>(part)));
    Unk_14b2b20_SetPosition(self, key, pos);
}

// 0x71014b2db0: moves the part with `key` to the first visible "N_cursor"
// part from the one with `from` on, or to that one when there's none.
void Unk_14b2db0(Unk_14b2b20_View* self, const u64& key, const u64& from) {
    for (Unk_14b2b20_Part* part = Unk_14aad40(self->field_58, from); part != nullptr;
         part = Unk_17b9140(part)) {
        if (strstr(part->field_b0, "N_cursor") != nullptr && (part->field_58 & 1)) {
            Unk_14b2b20_MoveTo(self, key, part);
            return;
        }
    }
    Unk_14b2b20_MoveTo(self, key, Unk_14aad40(self->field_58, from));
}

// 0x71014b2e60: the same with the first "N_context" part.
void Unk_14b2e60(Unk_14b2b20_View* self, const u64& key, const u64& from) {
    for (Unk_14b2b20_Part* part = Unk_14aad40(self->field_58, from); part != nullptr;
         part = Unk_17b9140(part)) {
        if (strstr(part->field_b0, "N_context") != nullptr) {
            Unk_14b2b20_MoveTo(self, key, part);
            return;
        }
    }
    Unk_14b2b20_MoveTo(self, key, Unk_14aad40(self->field_58, from));
}

// 0x71014b2f10
void Unk_14b2f10(Unk_14b2b20_View* self, const u64& key, void* target) {
    Unk_130b590(target, Unk_7a3a10(self->field_58, key), 0xa);
}

// 0x71014b2f40: the data of the part's entry with the name, or null.
const void* Unk_14b2f40(Unk_14b2b20_View* self, const u64& key, const char* name) {
    const Unk_17ac790_Entry* entry = Unk_17ac790(Unk_14aad40(self->field_58, key), name);
    if (entry == nullptr)
        return nullptr;
    return reinterpret_cast<const u8*>(entry) + entry->field_4;
}

// 0x71014b2f80: sets the part's four values to `value`.
void Unk_14b2f80(Unk_14b2b20_View* self, const u64& key, u64 value) {
    Unk_14b2b20_Part* part = Unk_14aad40(self->field_58, key);
    for (u32 i = 0; i < 4; i++)
        part->vf5(i, value);
}

// 0x71014b3000: detaches the part with `other` and attaches it to the one with
// `key`.
void Unk_14b3000(Unk_14b2b20_View* self, const u64& key, const u64& other) {
    Unk_14ab8e0(self->field_58, other);
    Unk_14ab670(self->field_58, key, other);
}
