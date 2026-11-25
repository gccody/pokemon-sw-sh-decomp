// Scope: common
// Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fae110_0 {
    u8 _0[0xc0];
    u8 field_c0[0x3a0 - 0xc0];
    u32 field_3a0;
    bool field_3a4;
};
PKMN_OFFSET_ASSERT(Unk_fae110_0, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_fae110_0, field_3a0, 0x3a0);
PKMN_OFFSET_ASSERT(Unk_fae110_0, field_3a4, 0x3a4);

struct Unk_fae110 {
    Unk_fae110_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae110, field_0, 0x0);

void Unk_fa98b0(void*);
void Unk_fadc00(void*, u32);

// 0x7100fae110
void Unk_fae110_call(const Unk_fae110* self, const u32* value) {
    Unk_fae110_0* obj = self->field_0;
    u32 v = *value;
    obj->field_3a0 = v;
    if (obj->field_3a4) {
        Unk_fa98b0(obj->field_c0);
        return;
    }
    Unk_fadc00(obj, v);
}
