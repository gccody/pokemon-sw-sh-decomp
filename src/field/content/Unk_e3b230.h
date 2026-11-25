#pragma once
// What the three nest hole table resources (bin/test/nest_hole/*.bin, classes
// Unk_23f1508, Unk_23f1578 and Unk_23f15e8 on Unk_23f5d00) share: their file
// name, a static their vf5 returns, and the FlatBuffers tables
// (unsorted/Unk_Table.h) of the loaded file, read in place. Placeholder
// names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f5d00.h"
#include "unsorted/Unk_Table.h"

// A file name: its hash (64-bit FNV-1a), the string, its length and a
// reference (dropped by Unk_611220_call, its destructor).
struct Unk_e3b230_Name {
    u64 field_0;
    const char* field_8;
    u64 field_10;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_e3b230_Name, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_e3b230_Name, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_e3b230_Name, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_e3b230_Name, 0x20);

struct Unk_611220;
void Unk_611220_call(Unk_611220* self);

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// The loaded file of the resource (a member of Unk_23f5d00), null while
// there is none.
const u8* Unk_ead710(void* self);

// A vector of tables in a table: its length, then the offset of each, from
// where the offset is.
struct Unk_e3b230_Tables {
    class Iterator {
    public:
        explicit Iterator(const u8* p) : m_p(p) {}
        const Unk_Table* operator*() const {
            return reinterpret_cast<const Unk_Table*>(m_p + *reinterpret_cast<const u32*>(m_p));
        }
        Iterator& operator++() {
            m_p += sizeof(u32);
            return *this;
        }
        bool operator==(const Iterator& other) const { return m_p == other.m_p; }
        bool operator!=(const Iterator& other) const { return m_p != other.m_p; }

    private:
        const u8* m_p;
    };

    const u8* Data() const { return reinterpret_cast<const u8*>(&m_size + 1); }
    Iterator begin() const { return Iterator(Data()); }
    Iterator end() const { return Iterator(Data() + m_size * sizeof(u32)); }

    const Unk_Table* Get(u32 index) const { return *Iterator(Data() + index * sizeof(u32)); }

    u32 m_size;
};

// A field stored out of line that the code takes as always there: read
// without the vtable's size or a zero offset checked.
template <class T>
const T* Unk_e3b230_GetRequired(const Unk_Table* table, u16 field) {
    const u8* vtable = reinterpret_cast<const u8*>(table) - *reinterpret_cast<const s32*>(table);
    const u8* p =
        reinterpret_cast<const u8*>(table) + *reinterpret_cast<const u16*>(vtable + field);
    return reinterpret_cast<const T*>(p + *reinterpret_cast<const u32*>(p));
}

// The root table of a file.
inline const Unk_Table* Unk_e3b230_Root(const u8* buffer) {
    return reinterpret_cast<const Unk_Table*>(buffer + *reinterpret_cast<const u32*>(buffer));
}

// The table of a vector field at `index`, null past its end.
inline const Unk_Table* Unk_e3b230_GetAt(const Unk_Table* table, u16 field, u32 index) {
    const Unk_e3b230_Tables* tables = Unk_e3b230_GetRequired<Unk_e3b230_Tables>(table, field);
    if (index < tables->m_size) {
        return tables->Get(index);
    }
    return nullptr;
}
