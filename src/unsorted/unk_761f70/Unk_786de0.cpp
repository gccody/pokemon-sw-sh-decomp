// Scope: common
//
// More queries of the entries Unk_785ce0 finds by id in the object the global
// Unk_27cecf0 points to (see Unk_786ad0.cpp), and lookups in the 18x18 byte
// table at 0x7101f0cc5c (0, 2, 4 or 8; index 18 is never looked up).
// Placeholder names: rename once the classes are known.
#include <nn/os.h>
#include <types.h>

// An entry Unk_785ce0 returns.
struct Unk_785ce0_Entry {
    u8 _0[0x10];
    u8 field_10;
    u8 _11[0xb];
    u8 field_1c;
    u8 _1d[0x13];
};
PKMN_SIZE_ASSERT(Unk_785ce0_Entry, 0x30);
PKMN_OFFSET_ASSERT(Unk_785ce0_Entry, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_785ce0_Entry, field_1c, 0x1c);

// A Unk_785fe0*, declared as its callers elsewhere declare it.
extern u64 Unk_27cecf0;

const Unk_785ce0_Entry* Unk_785ce0(u64 self, u16 id);
bool Unk_785df0(u64 self, u8 kind, u8 index, u16* out);

extern const u8 Unk_1f0cc5c[18][18] __attribute__((visibility("hidden")));
extern const u32 Unk_1f0cda0[] __attribute__((visibility("hidden")));

namespace {

// Index 18 is outside the table: it reads as 4, like most pairs.
u8 LookupTable(u8 a, u8 b) {
    if (a == 18 || b == 18)
        return 4;
    return Unk_1f0cc5c[a][b];
}

const Unk_785ce0_Entry* FindEntry(u16 id) {
    if (Unk_27cecf0 == 0)
        nn::diag::detail::AbortImpl("", "", "", 0);
    return Unk_785ce0(Unk_27cecf0, id);
}

// 1 + the index of the lowest bit set, 0 for none.
u32 LowestBit(u32 value) {
    for (u32 i = 0; i < 32; i++) {
        if (value & (1 << i))
            return i + 1;
    }
    return 0;
}

}  // namespace

// 0x7100786de0
u16 Unk_786de0(u8 index) {
    u16 value;
    if (!Unk_785df0(Unk_27cecf0, 3, index, &value))
        return 0;
    return value;
}

// 0x7100786e20
bool Unk_786e20(u16 id) {
    return FindEntry(id)->field_1c == 7;
}

// 0x7100786e70
bool Unk_786e70(u16 id) {
    return FindEntry(id)->field_1c == 6;
}

// 0x7100786ec0
bool Unk_786ec0(u16 id) {
    return FindEntry(id)->field_1c == 8;
}

// 0x7100786f10
bool Unk_786f10(u16 id) {
    return FindEntry(id)->field_1c == 9;
}

// 0x7100786f60
u32 Unk_786f60(u16 id) {
    return FindEntry(id)->field_10 >> 7;
}

// NON_MATCHING: only by name. This matches (checked) as
// _Z10Unk_787000hhb, but the name it has, _Z10Unk_787000Pvmh, spells
// (void*, u64, u8). The rename needs its caller Unk_7f7130_call (a generated
// leaf) retyped to (u8, u8) with the global it passes, Unk_27ced04, declared
// bool: that also matches (checked).
// 0x7100787000
u32 Unk_787000(u8 a, u8 b, bool flag) {
    if (a == 18 || b == 18)
        return 7;
    u32 result;
    switch (Unk_1f0cc5c[a][b]) {
        case 0:
            result = flag ? 8 : 0;
            break;
        case 2:
            result = flag ? 8 : 6;
            break;
        case 4:
            result = 7;
            break;
        case 8:
            result = flag ? 6 : 8;
            break;
        default:
            return 0;
    }
    return result;
}

// 0x71007870a0
u32 Unk_7870a0(s32 a, s32 b) {
    u32 value = (Unk_1f0cda0[a] * Unk_1f0cda0[b]) >> 6;
    value = value < 0x1000 ? value : 0x1000;
    if (value == 0 && a != 0 && b != 0)
        value = 1;
    u32 count = LowestBit(value);
    if (count > 12)
        count = 13;
    return count;
}

// 0x7100787110
u32 Unk_787110(s32 value) {
    if (value > 7)
        return 2;
    if (value == 7)
        return 1;
    if (value == 0)
        return 0;
    return 3;
}

// 0x7100787130
u32 Unk_787130(u8 a, u8 b, bool flag) {
    switch (LookupTable(a, b)) {
        case 0:
            if (flag)
                return 2;
            [[fallthrough]];
        default:
            return 0;
        case 2:
            if (flag)
                return 2;
            break;
        case 4:
            return 1;
        case 8:
            if (!flag)
                return 2;
            break;
    }
    return 3;
}
