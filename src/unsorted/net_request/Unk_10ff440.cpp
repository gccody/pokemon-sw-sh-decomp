// Scope: common
// The request step base (Unk_10ff440.h): its destructors, vf2 and the lock of
// its weak reference. Its vf3 is in src/unsorted/virtual/Unk_10ff4a0.cpp.
#include "unsorted/net_request/Unk_10ff440.h"

// A result code: success when it isn't negative. It tests as a pointer to
// an empty member function (0x71006a5220), the safe bool idiom: the original
// selects that function's address, then tests it.
struct Unk_10ff4b0_Result {
    typedef void (Unk_10ff4b0_Result::*SafeBool)() const;
    void Unk_6a5220() const;
    operator SafeBool() const { return field_0 >= 0 ? &Unk_10ff4b0_Result::Unk_6a5220 : nullptr; }

    s32 field_0;
};

struct Unk_10ff4b0_Arg {
    u8 _0[0x14];
    s32 field_14;
    u8 _18[0x40];
    Unk_10ff4b0_Result field_58;
};
PKMN_OFFSET_ASSERT(Unk_10ff4b0_Arg, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_10ff4b0_Arg, field_58, 0x58);

// 0x71010ff440
void Unk_2418090::vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) {
    field_8 = value;
    if (object.m_ptr != nullptr) {
        Unk_239a418_Ref<Unk_239a418_Handle> handle = object.m_ptr->vf2();
        if (field_10.m_ptr != nullptr) {
            static_cast<Unk_239a458*>(field_10.m_ptr)->vf5();
            field_10.m_ptr = nullptr;
        }
        field_10.m_ptr = handle.Release();
    }
}

// 0x71010ff4b0
void Unk_2418090::Unk_10ff4b0(const Unk_10ff4b0_Arg* arg) {
    if (arg->field_14 != 4) {
        if (arg->field_58)
            vf4(true);
    }
    vf3();
}

// 0x71010ff530
Unk_239a418_Ref<Unk_2417c28> Unk_2418090::Unk_10ff530() const {
    if (field_10.m_ptr != nullptr)
        return Unk_Lock<Unk_2417c28>(field_10.m_ptr);
    return Unk_239a418_Ref<Unk_2417c28>();
}
