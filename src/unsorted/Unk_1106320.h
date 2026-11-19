#pragma once
// A node of Game Freak's data documents (tables read from FlatBuffers data:
// the Poke Job table, the summary's ribbon table, ...): the root and the index
// of an object in it. Its functions (0x7101106320-0x71011069b0) return nodes
// by value, through the result pointer, so it isn't trivially copyable.
// Placeholder names: rename once the class is known.
#include <cstddef>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_112dd40.h"

// A string value of a document: the string and its hash, and a reference
// (to what holds the string, presumably).
class Unk_11069b0_String {
public:
    template <size_t N>
    constexpr Unk_11069b0_String(const char (&str)[N])
        : hash(Unk_112dd40_Hash(str)), str(str), len(N - 1) {}

    u64 hash;
    const char* str;
    u64 len;
    Unk_239a418_Ref<Unk_239a418> field_18;
};
PKMN_SIZE_ASSERT(Unk_11069b0_String, 0x20);

class Unk_1106320_Node {
public:
    Unk_1106320_Node(const Unk_1106320_Node& other)
        : field_0(other.field_0), field_8(other.field_8) {}

    // 0x7101106320: the element of an array.
    Unk_1106320_Node Unk_1106320(size_t index) const;
    // 0x71011063e0: the member of an object.
    Unk_1106320_Node Unk_11063e0(const Unk_112dd40& name) const;
    // 0x71011065b0: the value as an integer, or `value` if it isn't one.
    s32 Unk_11065b0(s32 value) const;
    // 0x71011067c0: the value as a float, or `value` if it isn't one.
    f32 Unk_11067c0(f32 value) const;
    // 0x71011069b0: the value as a string, or `value` if it isn't one.
    Unk_11069b0_String Unk_11069b0(const Unk_11069b0_String& value) const;

    const void* field_0;
    s32 field_8;
};
PKMN_SIZE_ASSERT(Unk_1106320_Node, 0x10);
