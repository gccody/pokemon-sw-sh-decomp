// Scope: common
// A request step derived from Unk_240ce88 (Unk_10b96e0.h), vtable
// 0x7102412948: its D0 and vf2. Its vf3 is in
// src/unsorted/virtual/Unk_10b98a0.cpp. Placeholder types: rename and move
// once the classes are known.
#include "unsorted/net_request/Unk_10b96e0.h"

void Unk_104e050(void* object);

extern void* Unk_24ba598;

class Unk_2412938 final : public Unk_240ce88 {
public:
    ~Unk_2412938() override;
    bool vf2() override;
    u32 vf3() override;
    Unk_10b96e0_Callable* vf11() override {
        Unk_10b96e0_Callable* target = Unk_240ce88::vf11();
        return target != nullptr ? target : &field_30;
    }

    u32 field_28;
    Unk_10b96e0_Callable field_30;
};
PKMN_OFFSET_ASSERT(Unk_2412938, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_2412938, field_30, 0x30);
static_assert(sizeof(Unk_2412938) == 0x38, "Unk_2412938");

// 0x71010b98b0 (D0; its D1 is folded into Unk_240ce88's, 0x7101079c30)
Unk_2412938::~Unk_2412938() = default;

// 0x71010b9830
bool Unk_2412938::vf2() {
    Unk_10b96e0_Callable* target = vf11();
    Unk_104e050(Unk_24ba598);
    target->vf0();
    return true;
}
