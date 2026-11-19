#pragma once
// A node of Game Freak's data documents (tables read from FlatBuffers data:
// the Poke Job table, the summary's ribbon table, ...): the root and the index
// of an object in it. Its functions (0x7101106320-0x71011069b0) return nodes
// by value, through the result pointer, so it isn't trivially copyable.
// Placeholder names: rename once the class is known.
#include <cstddef>

#include <types.h>

#include "unsorted/Unk_112dd40.h"

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

    const void* field_0;
    s32 field_8;
};
PKMN_SIZE_ASSERT(Unk_1106320_Node, 0x10);
