#pragma once
// A Pia object keeping a list of 0x30-byte entries (an id, a station index
// that's 0xfd when unset, another id and a flag), with a pool of free entries
// that Unk_16c1390 allocates. Its members are 0x71016c1200-0x71016c1b70
// (lib/pia/common/Unk_16c1200.cpp, lib/pia/common/Unk_16c1a70.cpp; 0x71016c1b60
// is Unk_16c1b60_set in lib/nx_middleware/leaf). No RTTI: placeholder names,
// the class after its first member.
#include "pia/common/Unk_1734ed0.h"

namespace nn {
namespace pia {
namespace common {

class Unk_16c1200 {
public:
    struct Data {
        u64 field_0;
        u8 field_8;  // 0xfd when unset
        u64 field_10;
        bool field_18;
    };

    struct Entry {
        Unk_16580b0_node node;
        Data data;
    };

    static Entry* ToEntry(Unk_16580b0_node* node) { return reinterpret_cast<Entry*>(node); }

    Unk_16c1200();
    ~Unk_16c1200();
    void Unk_16c12f0();
    Unk_165e060 Unk_16c1390(u32 capacity);
    void Unk_16c1530();
    Unk_165e060 Unk_16c15b0(u64 field_0, u8 field_8, u64 field_10);
    void Unk_16c1690(u64 field_0, bool value);
    void Unk_16c1710(u8 field_8, bool value);
    Data* Unk_16c1750(u8 field_8);
    bool Unk_16c1790(u64 field_0) const;
    Unk_165e060 Unk_16c17e0(u64 field_0);
    Unk_165e060 Unk_16c1820(Data* data);
    Data* Unk_16c18d0(u64 field_10);
    Unk_165e060 Unk_16c1910(Data* out, u8 field_8);
    Unk_165e060 Unk_16c19c0(Data* out, u64 field_0);
    Unk_165e060 Unk_16c1a70(Data* out, u64 field_10);
    u32 Unk_16c1b20() const;

    Unk_16580b0 m_List;
    Unk_16580b0 m_Pool;
    Entry* m_Entries;
    u32 m_Capacity;
    u64* m_Memory;
    u32 field_48;  // at most m_Capacity (Unk_16c1b60_set)
};
PKMN_OFFSET_ASSERT(Unk_16c1200::Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_16c1200::Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_16c1200::Data, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_16c1200::Data, 0x20);
PKMN_SIZE_ASSERT(Unk_16c1200::Entry, 0x30);
PKMN_OFFSET_ASSERT(Unk_16c1200, m_Pool, 0x18);
PKMN_OFFSET_ASSERT(Unk_16c1200, m_Entries, 0x30);
PKMN_OFFSET_ASSERT(Unk_16c1200, m_Capacity, 0x38);
PKMN_OFFSET_ASSERT(Unk_16c1200, m_Memory, 0x40);
PKMN_OFFSET_ASSERT(Unk_16c1200, field_48, 0x48);
PKMN_SIZE_ASSERT(Unk_16c1200, 0x50);

}  // namespace common
}  // namespace pia
}  // namespace nn

// What Unk_16a8390_get returns (lib/pia/common/Unk_1735510.cpp): the
// placeholder of Unk_16c16d0's object, a name kept for its callers.
struct Unk_16c16d0_arg0 : nn::pia::common::Unk_16c1200 {};

nn::pia::common::Unk_16c1200::Data* Unk_16c16d0(Unk_16c16d0_arg0* self, u64 field_0);
