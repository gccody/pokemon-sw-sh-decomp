// Scope: common
//
// The League Card views' parts and their animations (Unk_14aae90.h): the
// tables' lookups.
#include "contents/trainer_license/state/Unk_14aae90.h"

// A node of a chain (+0x18: the next one) with an offset at +0x30.
struct Unk_14aae90_Node {
    u8 _0[0x18];
    Unk_14aae90_Node* next;
    u8 _20[0x30 - 0x20];
    Unk_14aae90_Vec2 offset;
};
PKMN_OFFSET_ASSERT(Unk_14aae90_Node, next, 0x18);
PKMN_OFFSET_ASSERT(Unk_14aae90_Node, offset, 0x30);

// 0x71014aae90: the sum of the offsets along the chain.
Unk_14aae90_Vec2 Unk_14aae90(const Unk_14aae90_Node* node) {
    f32 x = 0.0f;
    f32 y = 0.0f;
    for (; node != nullptr; node = node->next) {
        x += node->offset.x;
        y += node->offset.y;
    }
    return {x, y};
}

// gflib3's layout animations (placeholders: the signatures are what the calls
// pass).
bool Unk_685820(void* layout, u32 index);
void Unk_685850(void* layout, u32 index, bool arg);
void Unk_685910(void* layout, u32 index, f32 frame);
void Unk_6859b0(void* layout, u64 index);
bool Unk_685a50(void* layout, u32 index);
void Unk_685ab0(void* layout, u32 index, bool arg);
f32 Unk_685b90(void* layout, u32 index);
f32 Unk_685bf0(void* layout, u32 index);
bool Unk_685c60(u64 layout, u32 index);

// 0x71014aaec0
void Unk_14aaec0(Unk_14aaec0_Parts* self, const u64& key, const Unk_14aae90_Vec2& value) {
    Unk_14aaec0_Part* part = self->Unk_GetPart(key);
    part->field_50 = value;
    part->field_58 |= 0x10;
}

// 0x71014aaf40
void Unk_14aaf40(const Unk_14aaec0_Parts* self, const u64& key, Unk_14aae90_Vec2* out) {
    Unk_14aae90_Copy(out, self->Unk_GetPart(key)->field_50);
}

// 0x71014aafc0
void Unk_14aafc0(Unk_14aaec0_Parts* self, const u64& key, const Unk_14aae90_Vec2& value) {
    Unk_14aaec0_Part* part = self->Unk_GetPart(key);
    part->field_48 = value;
    part->field_58 |= 0x10;
}

// 0x71014ab040 to 0x71014ab440 keep the u64 placeholder signatures of their
// callers (the views' forwarders, src/unsorted/virtual/Unk_14b2cc0.cpp), with
// the key's address as a u64. The forwarders pass the key through, so all of
// them take it; the names given before without it need the second u64.

// 0x71014ab040
void Unk_14ab040(u64 self, u64 key, u32 flag) {
    Unk_14aaec0_Part* part =
        reinterpret_cast<Unk_14aaec0_Parts*>(self)->Unk_GetPart(*reinterpret_cast<const u64*>(key));
    part->field_58 = (part->field_58 & ~1) | (flag & 1);
}

// 0x71014ab080
bool Unk_14ab080(u64 self, u64 key) {
    return reinterpret_cast<Unk_14aaec0_Parts*>(self)
               ->Unk_GetPart(*reinterpret_cast<const u64*>(key))
               ->field_58 &
           1;
}

// 0x71014ab0c0
void Unk_14ab0c0(u64 self, u64 key) {
    Unk_14ab180_Anim* anim =
        reinterpret_cast<Unk_14aaec0_Parts*>(self)->Unk_14ab180(*reinterpret_cast<const u64*>(key));
    if (!Unk_685a50(anim->layout.m_ptr, anim->index))
        Unk_685850(anim->layout.m_ptr, anim->index, true);
    Unk_685ab0(anim->layout.m_ptr, anim->index, true);
    Unk_685910(anim->layout.m_ptr, anim->index, 0.0f);
}

// 0x71014ab180
Unk_14ab180_Anim* Unk_14aaec0_Parts::Unk_14ab180(const u64& key) {
    Unk_14aaec0_Iter<Unk_14ab180_Entry> it =
        Unk_FindIf(field_280.begin(), field_280.end(),
                   [key](const Unk_14ab180_Entry& e) { return e.key == key; });
    return it == field_280.end() ? nullptr : &it->anim;
}

// 0x71014ab200
void Unk_14ab200(u64 self, u64 key) {
    Unk_14ab180_Anim* anim =
        reinterpret_cast<Unk_14aaec0_Parts*>(self)->Unk_14ab180(*reinterpret_cast<const u64*>(key));
    if (Unk_685a50(anim->layout.m_ptr, anim->index))
        Unk_6859b0(anim->layout.m_ptr, anim->index);
}

// 0x71014ab2b0
bool Unk_14ab2b0(u64 self, u64 key) {
    Unk_14ab180_Anim* anim =
        reinterpret_cast<Unk_14aaec0_Parts*>(self)->Unk_14ab180(*reinterpret_cast<const u64*>(key));
    if (Unk_685820(anim->layout.m_ptr, anim->index) &&
        Unk_685a50(anim->layout.m_ptr, anim->index) &&
        !Unk_685c60(reinterpret_cast<u64>(anim->layout.m_ptr), anim->index))
        return false;
    return true;
}

// 0x71014ab380
bool Unk_14ab380(u64 self, u64 key) {
    Unk_14ab180_Anim* anim =
        reinterpret_cast<Unk_14aaec0_Parts*>(self)->Unk_14ab180(*reinterpret_cast<const u64*>(key));
    if (Unk_685820(anim->layout.m_ptr, anim->index) && Unk_685a50(anim->layout.m_ptr, anim->index))
        return true;
    return false;
}

// 0x71014ab440
void Unk_14ab440(u64 self, u64 key, f32 frame) {
    Unk_14ab180_Anim* anim =
        reinterpret_cast<Unk_14aaec0_Parts*>(self)->Unk_14ab180(*reinterpret_cast<const u64*>(key));
    if (!Unk_685a50(anim->layout.m_ptr, anim->index))
        return;
    Unk_685ab0(anim->layout.m_ptr, anim->index, false);
    Unk_685910(anim->layout.m_ptr, anim->index, frame);
}

// 0x71014ab510
f32 Unk_14ab510(Unk_14aaec0_Parts* self, const u64& key) {
    Unk_14ab180_Anim* anim = self->Unk_14ab180(key);
    if (!Unk_685a50(anim->layout.m_ptr, anim->index))
        return 0.0f;
    return Unk_685b90(anim->layout.m_ptr, anim->index);
}

// 0x71014ab5c0
f32 Unk_14ab5c0(Unk_14aaec0_Parts* self, const u64& key) {
    Unk_14ab180_Anim* anim = self->Unk_14ab180(key);
    if (!Unk_685a50(anim->layout.m_ptr, anim->index))
        return 0.0f;
    return Unk_685bf0(anim->layout.m_ptr, anim->index);
}
