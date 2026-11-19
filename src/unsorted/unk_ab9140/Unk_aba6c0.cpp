// Scope: common
// Optional values of the TU(s) of 0x7100ab9140-0x7100abed80 (see
// Unk_ab95a0.cpp): a flag and the value. The getters return them through
// x8, so the type isn't trivially copyable (its destructor is user-provided
// here). Placeholder names; each function takes a placeholder type of its own.
// The setter of 0x18f8, 0x7100aba680, isn't matched yet (the original stores
// the value on both paths, separately).
#include <types.h>

template <class T>
class Unk_aba680_Optional {
public:
    Unk_aba680_Optional() : m_has(false) {}
    ~Unk_aba680_Optional() {}

    void Emplace(const T& value) {
        m_value = value;
        m_has = true;
    }

    bool m_has;
    T m_value;
};

struct Unk_aba680_Value {
    u16 field_0[4];
};
struct Unk_abaf40_Value {
    u32 field_0[2];
};
struct Unk_ab9ec0_Value {
    u64 field_0[4];
};

struct Unk_aba680 {
    u8 _0[0x18f8];
    Unk_aba680_Optional<Unk_aba680_Value> field_18f8;
};
PKMN_OFFSET_ASSERT(Unk_aba680, field_18f8, 0x18f8);

// 0x7100aba6c0
Unk_aba680_Optional<Unk_aba680_Value> Unk_aba6c0_get(const Unk_aba680* self) {
    Unk_aba680_Optional<Unk_aba680_Value> result;
    if (self->field_18f8.m_has)
        result.Emplace(self->field_18f8.m_value);
    return result;
}

struct Unk_abaf40 {
    u8 _0[0x1900];
    Unk_aba680_Optional<Unk_abaf40_Value> field_1900;
};
PKMN_OFFSET_ASSERT(Unk_abaf40, field_1900, 0x1900);

// 0x7100abaf40
Unk_aba680_Optional<Unk_abaf40_Value> Unk_abaf40_get(const Unk_abaf40* self) {
    Unk_aba680_Optional<Unk_abaf40_Value> result;
    if (self->field_1900.m_has)
        result.Emplace(self->field_1900.m_value);
    return result;
}

struct Unk_aba770 {
    u8 _0[0x1910];
    Unk_aba680_Optional<u64> field_1910;
};
PKMN_OFFSET_ASSERT(Unk_aba770, field_1910, 0x1910);

// 0x7100aba770
Unk_aba680_Optional<u64> Unk_aba770_get(const Unk_aba770* self) {
    Unk_aba680_Optional<u64> result;
    if (self->field_1910.m_has)
        result.Emplace(self->field_1910.m_value);
    return result;
}

struct Unk_ab9ec0 {
    u8 _0[0x1890];
    Unk_aba680_Optional<Unk_ab9ec0_Value> field_1890;
};
PKMN_OFFSET_ASSERT(Unk_ab9ec0, field_1890, 0x1890);

// 0x7100ab9ec0
Unk_aba680_Optional<Unk_ab9ec0_Value> Unk_ab9ec0_get(const Unk_ab9ec0* self) {
    Unk_aba680_Optional<Unk_ab9ec0_Value> result;
    if (self->field_1890.m_has)
        result.Emplace(self->field_1890.m_value);
    return result;
}
