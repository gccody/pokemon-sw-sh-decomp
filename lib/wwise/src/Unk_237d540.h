#pragma once
// A base class of some node classes (vtables at 0x710237d540): the nodes'
// base with two more words. Placeholder names.
#include "Unk_237c170.h"

// 0xf8 bytes.
class Unk_237d540 : public Unk_237c170 {
public:
    explicit Unk_237d540(u32 id);  // 0x71003150a0
    ~Unk_237d540() override;  // 0x71003150f0

    u64 field_e8;
    u64 field_f0;
};
PKMN_SIZE_ASSERT(Unk_237d540, 0xf8);
