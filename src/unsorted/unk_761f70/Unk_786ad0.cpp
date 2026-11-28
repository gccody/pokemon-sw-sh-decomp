// Scope: common
//
// Queries of the 0x30-byte entries that Unk_785ce0 finds by id in the object
// the global Unk_27cecf0 points to (the same object as Unk_785fe0_get's,
// src/unsorted/leaf/Unk_782c90.cpp). Each one aborts when the global is
// null. Placeholder names: rename once the classes are known.
#include <nn/os.h>
#include <types.h>

struct Unk_785fe0_160;

struct Unk_785fe0 {
    u8 _0[0x160];
    Unk_785fe0_160* field_160;
};
PKMN_OFFSET_ASSERT(Unk_785fe0, field_160, 0x160);

// An entry Unk_785ce0 returns.
struct Unk_785ce0_Entry {
    u8 _0[0x10];
    u8 field_10;
    u8 _11[0x5];
    u8 field_16;
    u8 _17[0x5];
    u8 field_1c;
    u8 field_1d;
    u8 _1e[0x12];
};
PKMN_SIZE_ASSERT(Unk_785ce0_Entry, 0x30);
PKMN_OFFSET_ASSERT(Unk_785ce0_Entry, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_785ce0_Entry, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_785ce0_Entry, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_785ce0_Entry, field_1d, 0x1d);

struct Unk_786ca0 {
    const Unk_785ce0_Entry* field_0;
};
PKMN_OFFSET_ASSERT(Unk_786ca0, field_0, 0x0);

struct Unk_786c30 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_786c30, field_8, 0x8);

// A Unk_785fe0*, declared as its callers elsewhere declare it.
extern u64 Unk_27cecf0;

const Unk_785ce0_Entry* Unk_785ce0(u64 self, u16 id);
u16 Unk_785ee0(u64 self, u32 value);
u16 Unk_785fe0_get(const Unk_785fe0* self);

namespace {

const Unk_785ce0_Entry* FindEntry(u16 id) {
    if (Unk_27cecf0 == 0)
        nn::diag::detail::AbortImpl("", "", "", 0);
    return Unk_785ce0(Unk_27cecf0, id);
}

// As Unk_786c10_call (src/unsorted/leaf/Unk_782c90.cpp) does.
u16 Lookup(u32 value) {
    return Unk_785ee0(Unk_27cecf0, value);
}

}  // namespace

// 0x7100786ad0
bool Unk_786ad0(u32 id) {
    if (id > 0x62a)
        return false;
    return FindEntry(id)->field_16 == 9;
}

// 0x7100786b80
bool Unk_786b80(u16 id) {
    return FindEntry(id)->field_1c == 4;
}

// 0x7100786c30
u16 Unk_786c30(const Unk_786c30* self) {
    return Lookup(self->field_8);
}

// 0x7100786c50
u8 Unk_786c50(u16 id) {
    return FindEntry(id)->field_1d;
}

// 0x7100786ca0
s32 Unk_786ca0_get(const Unk_786ca0* self) {
    if (self->field_0->field_1c != 4)
        return -1;
    return self->field_0->field_1d;
}

// 0x7100786cc0
u16 Unk_786cc0() {
    return Unk_785fe0_get(reinterpret_cast<const Unk_785fe0*>(Unk_27cecf0));
}

// 0x7100786cf0
bool Unk_786cf0(u16 id) {
    const Unk_785ce0_Entry* entry = FindEntry(id);
    if (entry->field_1c != 4)
        return false;
    return (entry->field_10 & 0x20) == 0;
}

// 0x7100786d90
bool Unk_786d90(u16 id) {
    return FindEntry(id)->field_1c == 3;
}
