#pragma once
// A table of a serialized buffer, read in place. By its layout it is a
// FlatBuffers table (the executable has no string that names the library): the
// table starts with a signed offset back to its vtable, the vtable with its own
// size, and from +4 it holds the offset of each field in the table, 0 for a
// field that isn't stored. A field past the vtable's size isn't stored
// either, and reads as its default. Placeholder names.
#include <types.h>

struct Unk_Table {
    // Where the field is in the table, 0 when it isn't stored.
    u16 Offset(u16 field) const {
        const u8* vtable = reinterpret_cast<const u8*>(this) - *reinterpret_cast<const s32*>(this);
        return field < *reinterpret_cast<const u16*>(vtable)
                   ? *reinterpret_cast<const u16*>(vtable + field)
                   : 0;
    }

    // A scalar field.
    template <class T>
    T Get(u16 field, T def) const {
        u16 offset = Offset(field);
        return offset ? *reinterpret_cast<const T*>(reinterpret_cast<const u8*>(this) + offset)
                      : def;
    }

    // A field stored out of line (a table, a vector, a string): the field holds
    // the offset to it.
    template <class T>
    const T* GetPointer(u16 field) const {
        u16 offset = Offset(field);
        const u8* p = reinterpret_cast<const u8*>(this) + offset;
        return offset ? reinterpret_cast<const T*>(p + *reinterpret_cast<const u32*>(p)) : nullptr;
    }
};
