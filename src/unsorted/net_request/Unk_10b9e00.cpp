// Scope: common
// A request step derived from Unk_240ce88 (Unk_10b96e0.h), vtable
// 0x7102412a98: its D0 and vf2. Its vf3 is in
// src/unsorted/virtual/Unk_10b9e80.cpp. Placeholder types: rename and move
// once the classes are known.
#include "unsorted/net_request/Unk_10b96e0.h"

// src/unsorted/leaf/Unk_1049aa0.cpp: it tail-calls a test, a flag.
bool Unk_1049aa0_call(u64 object);
void Unk_10499c0(void* object);

extern void* Unk_27d92e8;

class Unk_2412a88 final : public Unk_240ce88 {
public:
    ~Unk_2412a88() override;
    bool vf2() override;
    u32 vf3() override;
    Unk_10b96e0_Callable* vf11() override {
        Unk_10b96e0_Callable* target = Unk_240ce88::vf11();
        return target != nullptr ? target : &field_30;
    }

    u32 field_28;
    Unk_10b96e0_Callable field_30;
};
PKMN_OFFSET_ASSERT(Unk_2412a88, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_2412a88, field_30, 0x30);
static_assert(sizeof(Unk_2412a88) == 0x38, "Unk_2412a88");

// 0x71010b9e90 (D0; its D1 is folded into Unk_240ce88's, 0x7101079c30)
Unk_2412a88::~Unk_2412a88() = default;

// 0x71010b9e00
bool Unk_2412a88::vf2() {
    Unk_10b96e0_Callable* target = vf11();
    if (!Unk_1049aa0_call(reinterpret_cast<u64>(Unk_27d92e8)))
        Unk_10499c0(Unk_27d92e8);
    target->vf0();
    return true;
}
