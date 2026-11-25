#pragma once
// A Pia object keeping a list of 0x30-byte entries, one per 64-bit id, with
// their state and flags, and a pool of free entries (0x7101734e60 moves them
// all back). Its members are 0x7101734e60-0x7101735cd0
// (lib/pia/common/Unk_1734ed0.cpp, lib/pia/common/Unk_1735510.cpp). No RTTI:
// placeholder names, the class after its first member here.
#include "pia/common/Unk_165e060.h"

// The object behind the global Unk_27fc0a8 (no RTTI; its members are free
// placeholder functions, as Unk_172bd80 is).
struct Unk_172c3e0_arg0 {
    u8 _0[0x70];
    struct Unk_70 {
        u8 _0[0x90];
        s32 field_90;
    }* field_70;
    u8 _78[0xf0 - 0x78];
    u64 field_f0;
    u64 field_f8;
    u8 _100[0x15c - 0x100];
    u8 field_15c;
};
PKMN_OFFSET_ASSERT(Unk_172c3e0_arg0::Unk_70, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_172c3e0_arg0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_172c3e0_arg0, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_172c3e0_arg0, field_15c, 0x15c);

extern Unk_172c3e0_arg0* Unk_27fc0a8;

void Unk_172c3e0(Unk_172c3e0_arg0* self, u64 id);
void Unk_172c450(Unk_172c3e0_arg0* self, u64 id);

namespace nn {
namespace pia {
namespace common {

struct Unk_16580b0_node {
    Unk_16580b0_node* prev;
    Unk_16580b0_node* next;
};
PKMN_SIZE_ASSERT(Unk_16580b0_node, 0x10);

// An intrusive doubly linked list (its root node, then a count); the node
// sits m_Offset bytes into each element. Members 0x71016580b0-0x7101658230.
class Unk_16580b0 {
public:
    void Unk_16580b0_init();                                                  // 0x71016580b0
    void Unk_16580c0(Unk_16580b0_node* position, Unk_16580b0_node* node);     // inserts before
    void Unk_16580f0(Unk_16580b0_node* position, Unk_16580b0_node* node);     // inserts after
    void Unk_1658120(Unk_16580b0_node* node);                                 // unlinks
    Unk_16580b0_node* Unk_16581f0();                                          // pops the last one

    Unk_16580b0_node m_Root;
    s32 m_Count;
    s32 m_Offset;
};
PKMN_OFFSET_ASSERT(Unk_16580b0, m_Count, 0x10);
PKMN_OFFSET_ASSERT(Unk_16580b0, m_Offset, 0x14);
PKMN_SIZE_ASSERT(Unk_16580b0, 0x18);

struct Unk_1735990_arg0 {
    u64 field_0;  // an id
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1735990_arg0, field_8, 0x8);

class Unk_1734ed0 {
public:
    struct Data {
        u32 field_0;  // 0, 1 or 2
        u32 field_4;  // 0, 1 or 2
        u8 field_8;
        u8 field_9;
        u64 field_10;  // the id
        u32 field_18;
        bool field_1c;
        u8 field_1d;
        u8 field_1e;
        u8 field_1f;
    };

    struct Entry {
        Unk_16580b0_node node;
        Data data;
    };

    static Entry* ToEntry(Unk_16580b0_node* node) { return reinterpret_cast<Entry*>(node); }

    Unk_165e060 Unk_1734ed0_add(u64 id, u32 field_18, u32 field_0, bool field_9);
    Unk_165e060 Unk_1734fd0(u64 id);
    Data* Unk_17350a0(u64 id);
    void Unk_17350e0();
    void Unk_1735110(u64 id, bool value);
    u32 Unk_1735150(const u64* ids, u16 count) const;
    u32 Unk_1735220(u64 id) const;
    void Unk_1735260();
    void Unk_1735290(u64 id, bool value);
    bool Unk_17352d0(const u64* ids, u16 count) const;
    bool Unk_1735350(u64 id) const;
    bool Unk_17353a0(u64 id, bool value);
    bool Unk_17353f0(u64 id) const;
    void Unk_1735440();
    bool Unk_1735470(u64 id, bool value);
    bool Unk_17354c0(u64 id) const;
    void Unk_1735510();
    bool Unk_1735540(u64 id, bool value);
    u32 Unk_1735590(u64 id) const;
    void Unk_17355d0();
    void Unk_1735600(u64 id, bool value);
    bool Unk_1735640(u64 id) const;
    void Unk_1735690();
    void Unk_1735840();
    bool Unk_1735990(const Unk_1735990_arg0* peer) const;
    bool Unk_1735a20(u64 id, u32* out) const;
    void Unk_1735a70(u64 id, u8 value);
    bool Unk_1735ab0(u64 id, u8* out) const;
    void Unk_1735b00(u64 id, bool value);
    bool Unk_1735b40(u64 id, bool* out) const;
    s32 Unk_1735b90(u32 value) const;
    u32 Unk_1735bd0(u32 value) const;

    u8 _0[0x8];
    Unk_16580b0 m_List;
    Unk_16580b0 m_Pool;
};
PKMN_OFFSET_ASSERT(Unk_1734ed0::Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1734ed0::Data, field_1c, 0x1c);
PKMN_SIZE_ASSERT(Unk_1734ed0::Data, 0x20);
PKMN_SIZE_ASSERT(Unk_1734ed0::Entry, 0x30);
PKMN_OFFSET_ASSERT(Unk_1734ed0, m_List, 0x8);
PKMN_OFFSET_ASSERT(Unk_1734ed0, m_Pool, 0x20);

}  // namespace common
}  // namespace pia
}  // namespace nn
