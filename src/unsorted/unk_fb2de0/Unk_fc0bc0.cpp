// Scope: common
//
// A class on Unk_23f4e40 (vtable 0x7102402dc8): references, a member with a
// destructor of its own (0x7100fc25f0), three optional values and a vector.
// Its destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the classes are known.
#include <vector>

#include "unsorted/Unk_23f4e40.h"

// A value that may be there: a flag, then the value. Going, it destroys the
// value if there is one and clears the flag.
template <class T>
struct Unk_2402dc8_Optional {
    ~Unk_2402dc8_Optional() {
        if (m_has) {
            m_value.~T();
            m_has = false;
        }
    }

    bool m_has;
    union {
        T m_value;
    };
};

// What field_90 holds a reference to: gflib3's reference-counted interface
// at +0x50.
class Unk_2402dc8_90_Base {
public:
    virtual void vf0();

    u8 _8[0x48];
};

class Unk_2402dc8_90 : public Unk_2402dc8_90_Base, public Unk_239a458 {};

// A member with an out-of-line destructor (0x7100fc25f0), not decompiled
// yet.
struct Unk_fc25f0 {
    ~Unk_fc25f0();

    u8 _0[0xa0];
};

struct Unk_2402dc8_Entry {
    Unk_239a418_Ref<Unk_239a418> field_0;
    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
};

struct Unk_2402dc8_Value30 {
    u32 field_0[12];
};

struct Unk_2402dc8_Value8 {
    u32 field_0[2];
};

class Unk_2402dc8 : public Unk_23f4e40 {
public:
    ~Unk_2402dc8() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;

    u64 field_88;
    Unk_239a418_Ref<Unk_2402dc8_90> field_90;
    Unk_fc25f0 field_98;
    Unk_239a418_Ref<Unk_239a418> field_138;
    Unk_2402dc8_Optional<
        std::vector<Unk_2402dc8_Entry, Unk_239a418_StdAllocator<Unk_2402dc8_Entry>>>
        field_140;
    u64 field_168;
    u64 field_170;
    Unk_2402dc8_Optional<Unk_2402dc8_Value30> field_178;
    Unk_2402dc8_Optional<Unk_2402dc8_Value8> field_1ac;
    Unk_239a418_Ref<Unk_239a418> field_1b8;
    u64 field_1c0;
    u64 field_1c8;
    u64 field_1d0;
    u64 field_1d8;
    Unk_239a418_Ref<Unk_239a418> field_1e0;
    Unk_239a418_Ref<Unk_239a418> field_1e8;
    u64 field_1f0;
    u64 field_1f8;
    u64 field_200;
    Unk_239a418_Ref<Unk_239a418> field_208;
    Unk_239a418_Ref<Unk_239a418> field_210;
    u64 field_218;
    u64 field_220;
    u64 field_228;
    Unk_239a418_Ref<Unk_239a418> field_230;
    u64 field_238;
    std::vector<u32, Unk_239a418_StdAllocator<u32>> field_240;
    u64 field_260;
    u64 field_268;
    u64 field_270;
    Unk_239a418_Ref<Unk_239a418> field_278;
};
static_assert(sizeof(Unk_2402dc8) == 0x280, "Unk_2402dc8");
static_assert(__builtin_offsetof(Unk_2402dc8, field_140) == 0x140, "Unk_2402dc8::field_140");
static_assert(__builtin_offsetof(Unk_2402dc8, field_178) == 0x178, "Unk_2402dc8::field_178");
static_assert(__builtin_offsetof(Unk_2402dc8, field_1ac) == 0x1ac, "Unk_2402dc8::field_1ac");
static_assert(__builtin_offsetof(Unk_2402dc8, field_240) == 0x240, "Unk_2402dc8::field_240");

// 0x7100fc0bc0 (its D0 and thunks tail-call it)
Unk_2402dc8::~Unk_2402dc8() {}
