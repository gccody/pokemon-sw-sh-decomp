// Scope: common
// A class of game/rental_team on gflib3's object (vtable 0x7102430808) that
// keeps five entries of 0x880 bytes, picked by index: its constructor,
// destructors and the accessors of the entries. Its destructor is its key
// function: its vtables, inline type getter and its thunks are emitted here.
// Placeholder names: rename once the class is known.
#include <cstring>

#include <types.h>

#include "gflib3/Unk_239a418.h"

// One entry. Its first word is 0 while it is empty. Its last byte is at
// 0x87e: an assignment copies 0x87f bytes (clang copies an object that may be
// a base subobject without its tail padding). Its members' initialisers make
// its default constructor non-trivial: the array of them is value-initialised
// (cleared, then constructed), and Unk_132bce0's assignment of an empty one is
// a memset that isn't a tail call (it comes from a temporary's copy).
struct Unk_24307f8_Entry {
    u64 field_0 = 0;
    u8 _8[0x862];
    u16 field_86a = 0;
    u16 field_86c = 0;
    u8 field_86e = 0;
    u8 _86f[0xf];
    u8 field_87e;
};
PKMN_SIZE_ASSERT(Unk_24307f8_Entry, 0x880);
PKMN_OFFSET_ASSERT(Unk_24307f8_Entry, field_86a, 0x86a);
PKMN_OFFSET_ASSERT(Unk_24307f8_Entry, field_86e, 0x86e);

// A value and whether it is set. The flag is tested as a byte (`and #0xff`),
// not as a bool's bit.
struct Unk_24307f8_Value {
    Unk_24307f8_Value() : m_set(false) {}
    Unk_24307f8_Value(u32 value) : m_set(true), m_value(value) {}

    u8 m_set;
    u32 m_value;
};
PKMN_SIZE_ASSERT(Unk_24307f8_Value, 0x8);

// An entry, if one is set: its storage isn't constructed until one is, and
// it is cleared when the slot goes.
struct Unk_24307f8_Slot {
    Unk_24307f8_Slot() : m_set(false) {}
    ~Unk_24307f8_Slot() {
        if (m_set) {
            m_entry.~Unk_24307f8_Entry();
            m_set = false;
        }
    }

    bool m_set;
    union {
        Unk_24307f8_Entry m_entry;
    };
};
PKMN_SIZE_ASSERT(Unk_24307f8_Slot, 0x888);

// What Unk_132bd10 returns: the first word of the current entry, if there is one.
struct Unk_24307f8_Word {
    Unk_24307f8_Word() : m_set(false) {}
    Unk_24307f8_Word(u64 value) : m_set(true), m_value(value) {}

    bool m_set;
    u64 m_value;
};

class Unk_24307f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    Unk_24307f8();
    ~Unk_24307f8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    void Unk_132bc40(u32 value);
    bool Unk_132bc60(u32 index, Unk_24307f8_Entry* out);
    void Unk_132bcb0(u32 index, const Unk_24307f8_Entry* entry);
    void Unk_132bce0(u32 index);
    Unk_24307f8_Word Unk_132bd10();

    // The index of the current entry. Returned by value: Unk_132bd10 loads it
    // as one word and splits it.
    Unk_24307f8_Value Unk_GetIndex() const { return field_78; }

    Unk_24307f8_Value field_60;
    Unk_24307f8_Value field_68;  // field_60 before Unk_132bc40 set it
    Unk_24307f8_Value field_70;
    Unk_24307f8_Value field_78;  // the index of the current entry
    Unk_24307f8_Value field_80;
    Unk_24307f8_Slot field_88;
    Unk_24307f8_Entry field_910[5];
};
PKMN_OFFSET_ASSERT(Unk_24307f8, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_24307f8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_24307f8, field_910, 0x910);
PKMN_SIZE_ASSERT(Unk_24307f8, 0x3390);

// 0x710132bb70
// NON_MATCHING: the stores of the entries' initialisers after the memset are
// scheduled in another order (the original stores each entry's +0x86e byte,
// then the next entry's first word, then its +0x86a word).
Unk_24307f8::Unk_24307f8() : field_60(0), field_910() {}

// 0x710132bd50, 0x710132bdd0 (D0), thunks 0x710132bf40/0x710132bfc0 (+0x48)
// and 0x710132c060/0x710132c0e0 (+0x50); vf_type's thunks 0x710132c040 (+0x48)
// and 0x710132c050 (+0x50)
Unk_24307f8::~Unk_24307f8() {}

// 0x710132bc40
void Unk_24307f8::Unk_132bc40(u32 value) {
    field_68 = field_60;
    field_60.m_value = value;
    field_60.m_set = true;
}

// 0x710132bc60
bool Unk_24307f8::Unk_132bc60(u32 index, Unk_24307f8_Entry* out) {
    if (index > 4 || out == nullptr)
        return false;
    memcpy(out, &field_910[index], sizeof(Unk_24307f8_Entry));
    return out->field_0 != 0;
}

// 0x710132bcb0
void Unk_24307f8::Unk_132bcb0(u32 index, const Unk_24307f8_Entry* entry) {
    if (index > 4 || entry == nullptr)
        return;
    field_910[index] = *entry;
}

// 0x710132bce0
void Unk_24307f8::Unk_132bce0(u32 index) {
    if (index > 4)
        return;
    field_910[index] = Unk_24307f8_Entry();
}

// 0x710132bd10
Unk_24307f8_Word Unk_24307f8::Unk_132bd10() {
    Unk_24307f8_Value index = Unk_GetIndex();
    u64 i = index.m_value;
    if (!index.m_set || i >= 5)
        return Unk_24307f8_Word();
    return Unk_24307f8_Word(field_910[i].field_0);
}
