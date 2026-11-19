// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_857650_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_857650_arg1, field_0, 0x0);

struct Unk_857650_arg2 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_857650_arg2, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_857650_arg2, field_4, 0x4);

u32 Unk_7ef2b0();
u64 Unk_82ab10(void*, u8);
void Unk_7f1a20(u64, u32);

// 0x7100857650
void Unk_857650_call(void* self, Unk_857650_arg1* value, const Unk_857650_arg2* arg2) {
    value->field_0 = 0;
    u64 r0 = Unk_82ab10(self, arg2->field_0);
    u32 r1 = Unk_7ef2b0();
    if ((r1 & 1) == 0) {
        Unk_7f1a20(r0, arg2->field_4);
        value->field_0 = 1;
    }
}
