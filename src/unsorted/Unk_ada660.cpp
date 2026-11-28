// Scope: common
//
// Two classes on Unk_23c9470: Unk_23c9ec8 (src/unsorted/Unk_ada660.h) and
// Unk_23c9da0 (vtable 0x71023c9da0), which derives from it. Their
// destructors are their key functions: their vtables and the destructors'
// thunks are emitted here. Unk_23c9da0's destructor is empty, so its D2 is
// Unk_23c9ec8's (both vtables' slot 0 is 0x7100ada6a0). Their type getters
// are in src/unsorted/types/Unk_ada760.cpp. Placeholder names: rename once
// the classes are known.
#include "unsorted/Unk_ada660.h"

struct Unk_14d9fe0;
void Unk_14d9fe0_call(const Unk_14d9fe0* self);

struct Unk_ace0e0;
void Unk_ace0e0_call(Unk_ace0e0* self);

u32 Unk_eb6530(void*);

class Unk_23c9da0 : public Unk_23c9ec8 {
public:
    ~Unk_23c9da0() override;
    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf15() override;
    u32 vf16() override;
    void vf17() override;
    u32 vf18() override;
    void vf19() override;

    u8 field_850;
};
static_assert(__builtin_offsetof(Unk_23c9da0, field_850) == 0x850, "Unk_23c9da0::field_850");

// 0x7100ada6a0 (D2, also Unk_23c9da0's), 0x7100adab30 (D0), thunks
// 0x7100adac00/0x7100adac70 (+0x48) and 0x7100adadc0/0x7100adae30 (+0x50)
Unk_23c9ec8::~Unk_23c9ec8() {
    if (field_848.m_ptr)
        Unk_14d9fe0_call(reinterpret_cast<const Unk_14d9fe0*>(field_848.m_ptr));
}

// 0x7100ada700 (D0), thunks 0x7100ada810/0x7100ada880 (+0x48) and
// 0x7100adaa50/0x7100adaac0 (+0x50)
Unk_23c9da0::~Unk_23c9da0() {}

// 0x7100ada660
u32 Unk_23c9da0::vf18() {
    return ~Unk_eb6530(this) & 1;
}

// 0x7100ada680
void Unk_23c9da0::vf19() {
    if (field_630->field_58 & 1) {
        field_850 = 0;
        Unk_ace0e0_call(reinterpret_cast<Unk_ace0e0*>(this));
    }
}
