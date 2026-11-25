// Scope: common
// Readers of the two blocks of data the object with vtable 0x71023bc560
// holds (Unk_8e0670.h): their checks against their stored values, flags,
// bits, a date range, and their strings (one per language) made into string
// objects. Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_New.h"
#include "unsorted/unk_8bf520/Unk_8e0670.h"

// A reference to an object on Unk_239a4c0: added and dropped through its
// +0x48 interface.
template <class T>
class Unk_8e0670_Ref {
public:
    explicit Unk_8e0670_Ref(T* ptr) : m_ptr(ptr) {
        if (m_ptr)
            static_cast<Unk_239a4f8*>(m_ptr)->vf3();
    }
    Unk_8e0670_Ref(const Unk_8e0670_Ref& other) : m_ptr(other.m_ptr) {
        if (m_ptr)
            static_cast<Unk_239a4f8*>(m_ptr)->vf3();
    }
    // Takes over the other's reference (Unk_8e0960 returns its string by
    // moving it, not by copy elision).
    Unk_8e0670_Ref(Unk_8e0670_Ref&& other) : m_ptr(other.m_ptr) { other.m_ptr = nullptr; }
    ~Unk_8e0670_Ref() {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
    }

    T* m_ptr;
};

// A string of 16-bit characters with a fixed capacity, on Unk_239a4c0
// (0x710067b990 constructs one, the leaf Unk_67be60_call copies into it).
// The constructor takes the capacity as 32 bits: its caller's switch gives
// it from a table of words, and the constructor masks it.
class Unk_67be60 : public Unk_239a4c0 {
public:
    explicit Unk_67be60(u32 capacity);
    ~Unk_67be60() override;

    u16* field_58;
    u8 _60[0x18];
    u16 field_78;  // the capacity
    u16 field_7a;
    u8 field_7c;
};
PKMN_SIZE_ASSERT(Unk_67be60, 0x80);
PKMN_OFFSET_ASSERT(Unk_67be60, field_78, 0x78);

// Copies a string into it. Its name takes the characters' address as an
// integer.
u32 Unk_67be60_call(Unk_67be60* self, u64 value);

// 0x71008e0670
bool Unk_8e0670(void* object) {
    Unk_8e0670_Owner* self = static_cast<Unk_8e0670_Owner*>(object);
    Unk_8e0670_Block1* block = self->field_180;
    if (block == nullptr)
        return false;
    u16 stored = block->field_235c;
    return Unk_65c7c0(&block->field_60, 0x22fc) == stored;
}

// 0x71008e06c0
bool Unk_8e06c0(Unk_8e0670_Owner* self) {
    Unk_8e0670_Block2* block = self->field_188;
    if (block == nullptr)
        return false;
    u16 stored = block->field_6a0;
    return Unk_65c7c0(&block->_60, 0x640) == stored;
}

// 0x71008e0ae0
u8 Unk_8e0ae0(Unk_8e0670_Owner* self) {
    if (self->field_180 == nullptr)
        return 0;
    return self->field_180->field_2345;
}

// 0x71008e0b00
u8 Unk_8e0b00(Unk_8e0670_Owner* self) {
    if (self->field_180 == nullptr)
        return 0;
    return self->field_180->field_234c;
}

// 0x71008e0b20
u32 Unk_8e0b20(Unk_8e0670_Owner* self) {
    if (self->field_180 == nullptr)
        return 0;
    if (self->field_188 != nullptr && self->field_188->field_5a1 == 8)
        return self->field_188->field_614;
    return self->field_180->field_2354;
}

// 0x71008e0b60
u8 Unk_8e0b60(Unk_8e0670_Owner* self) {
    if (self->field_180 == nullptr)
        return 0;
    return self->field_180->field_2359;
}

// 0x71008e0b80
u8 Unk_8e0b80(Unk_8e0670_Owner* self) {
    if (self->field_180 == nullptr)
        return 0;
    return self->field_180->field_2343;
}

static inline bool Unk_8e0ba0_NotAfter(const Unk_8e0670_Date& a, const Unk_8e0670_Date& b) {
    if (a.field_0 < b.field_0)
        return true;
    if (a.field_0 != b.field_0)
        return false;
    if (a.field_4 < b.field_4)
        return true;
    if (a.field_4 != b.field_4)
        return false;
    return a.field_8 <= b.field_8;
}

// 0x71008e0ba0
bool Unk_8e0ba0(Unk_8e0670_Owner* self, const Unk_8e0670_Date* date) {
    Unk_8e0670_Block2* block = self->field_188;
    if (block == nullptr)
        return false;
    const Unk_8e0670_Date& from = block->field_5d8;
    const Unk_8e0670_Date& to = block->field_5e4;
    // Neither set: no range.
    u32 set = from.field_0 | from.field_4 | from.field_8;
    set |= to.field_0 | to.field_4 | to.field_8;
    if (set == 0)
        return true;
    if (Unk_8e0ba0_NotAfter(from, *date) && Unk_8e0ba0_NotAfter(*date, to))
        return true;
    return false;
}

// 0x71008e0c60
bool Unk_8e0c60(Unk_8e0670_Owner* self, u32 value) {
    Unk_8e0670_Block2* block = self->field_188;
    if (block == nullptr)
        return false;
    if (block->field_5a1 != 7)
        return true;
    if (block->field_5a8[0] == 0)
        return true;
    if (block->field_5a8[0] == 1000)
        return value != 0x188;
    for (s32 i = 0; i < 12; i++) {
        if (block->field_5a8[i] == value)
            return true;
    }
    return false;
}

// 0x71008e0d30
bool Unk_8e0d30(Unk_8e0670_Owner* self, u8 kind, u32 index) {
    Unk_8e0670_Block1* block = self->field_180;
    if (block == nullptr)
        return false;
    u32 byte = index / 8;
    u32 bit = index % 8;
    switch (kind) {
        case 0:
            if (block->field_21b7[byte] & (1 << bit))
                return true;
            break;
        case 1:
            if (block->field_2237[byte] & (1 << bit))
                return true;
            break;
    }
    return false;
}

// 0x71008e0d90
bool Unk_8e0d90(Unk_8e0670_Owner* self, s32 value) {
    Unk_8e0670_Block1* block = self->field_180;
    if (block == nullptr)
        return false;
    s32 index = value - 0x2c;
    return (block->field_233f[index / 8] & (1 << (index & 7))) != 0;
}

// 0x71008e0de0
bool Unk_8e0de0(Unk_8e0670_Owner* self) {
    Unk_8e0670_Block1* block = self->field_180;
    if (block == nullptr)
        return false;
    for (u32 i = 0; i < 0x400; i++) {
        if (block->field_60[i] != 0)
            return true;
    }
    return false;
}

// 0x71008e0730
bool Unk_8e0730(Unk_8e0670_Owner* self, u8 kind) {
    if (kind < 8) {
        if (self->field_180 == nullptr)
            return false;
    } else if (self->field_188 == nullptr) {
        return false;
    }
    Unk_8e0670_Block1* block = self->field_180;
    switch (kind) {
        case 0:
            return block->field_234d != 0;
        case 1:
            return block->field_234e != 0;
        case 2:
            return block->field_234f != 0;
        case 3:
            return block->field_2353 != 0;
        case 4:
            return block->field_2358 != 0;
        case 5:
            return block->field_235a != 0;
        case 6:
            return block->field_2350 != 0;
        case 7:
            return block->field_2351 != 0;
        case 8:
            return self->field_188->field_5a2 != 0;
        default:
            return false;
    }
}

// Where a language's strings are (none for language 6).
static inline u64 Unk_8e0840_LanguageIndex(u8 language) {
    switch (language) {
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 8;
        default:
            return 0;
    }
}

// 0x71008e0840
void Unk_8e0840(Unk_8e0670_Owner* self, u8 kind, u8 language, Unk_8e0670_Ref<Unk_67be60> out) {
    switch (kind) {
        case 0:
        case 1:
            if (self->field_180 == nullptr)
                return;
            break;
        case 2:
        case 3:
            if (self->field_188 == nullptr)
                return;
            break;
        case 4:
            if (self->field_188 == nullptr)
                return;
            break;
    }
    u64 index = Unk_8e0840_LanguageIndex(language);
    switch (kind) {
        case 0:
            Unk_67be60_call(out.m_ptr,
                            reinterpret_cast<u64>(self->field_180->field_1104[index].field_0));
            break;
        case 1:
            Unk_67be60_call(out.m_ptr,
                            reinterpret_cast<u64>(self->field_180->field_1104[index].field_4a));
            break;
        case 2:
            Unk_67be60_call(out.m_ptr,
                            reinterpret_cast<u64>(self->field_188->field_64[index].field_0));
            break;
        case 3:
            Unk_67be60_call(out.m_ptr,
                            reinterpret_cast<u64>(self->field_188->field_64[index].field_4a));
            break;
        case 4:
            Unk_67be60_call(out.m_ptr, reinterpret_cast<u64>(self->field_188->field_5f0));
            break;
    }
}

// The capacity of a kind of string.
static inline u32 Unk_8e0960_Capacity(u8 kind) {
    switch (kind) {
        case 0:
            return 37;
        case 1:
            return 199;
        case 2:
            return 37;
        case 3:
            return 37;
        case 4:
            return 13;
        default:
            return 0;
    }
}

// 0x71008e0960
Unk_8e0670_Ref<Unk_67be60> Unk_8e0960(Unk_8e0670_Owner* self, u8 kind, u8 language) {
    if (self->field_188 == nullptr)
        return Unk_8e0670_Ref<Unk_67be60>(nullptr);
    u32 capacity = Unk_8e0960_Capacity(kind);
    Unk_8e0670_Ref<Unk_67be60> string(Unk_New().Create<Unk_67be60>(self->field_60, capacity));
    Unk_8e0840(self, kind, language, string);
    return string;
}
