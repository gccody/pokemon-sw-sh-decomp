#pragma once
// A client's party in battle (0x71007fc210 to 0x71007fc6c0): its Pokemon and
// how many. Placeholder names: rename once the class is known.
#include <types.h>

struct Unk_7ee6b0;

struct Unk_7fc430_Party {
    Unk_7ee6b0* field_0[6];
    u8 field_30;
    u8 _31[0x38 - 0x31];
};
PKMN_SIZE_ASSERT(Unk_7fc430_Party, 0x38);

const Unk_7ee6b0* Unk_7fc430(const Unk_7fc430_Party* self, u8 index);
Unk_7ee6b0* Unk_7fc450(Unk_7fc430_Party* self, u8 index);
