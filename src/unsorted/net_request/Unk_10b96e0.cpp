// Scope: common
// A request step derived from Unk_240ce88 (Unk_10b96e0.h), vtable
// 0x71024128d8: its D0 and vf2. Its vf3 is in
// src/unsorted/virtual/Unk_10b9750.cpp. Placeholder types: rename and move
// once the classes are known.
#include "unsorted/net_request/Unk_10b96e0.h"

struct Unk_104e040;
void Unk_104e040_set(Unk_104e040* self);

extern Unk_104e040* Unk_24ba598;

class Unk_24128c8 final : public Unk_240ce88 {
public:
    ~Unk_24128c8() override;
    bool vf2() override;
    u32 vf3() override;
    Unk_10b96e0_Callable* vf11() override {
        Unk_10b96e0_Callable* target = Unk_240ce88::vf11();
        return target != nullptr ? target : &field_30;
    }

    u32 field_28;
    Unk_10b96e0_Callable field_30;
};
PKMN_OFFSET_ASSERT(Unk_24128c8, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_24128c8, field_30, 0x30);
static_assert(sizeof(Unk_24128c8) == 0x38, "Unk_24128c8");

// 0x71010b9760 (D0; its D1 is folded into Unk_240ce88's, 0x7101079c30)
Unk_24128c8::~Unk_24128c8() = default;

// 0x71010b96e0
bool Unk_24128c8::vf2() {
    Unk_10b96e0_Callable* target = vf11();
    Unk_104e040_set(Unk_24ba598);
    target->vf0();
    return true;
}
