// Scope: common
// Functions that move a nest hole object's state on (the value at +0x7c),
// clearing its two flags at +0x385. Placeholder types: rename and move once
// the owning classes are known.
#include <types.h>

struct Unk_fa87e0_0 {
    u8 _0[0x78];
    u32 field_78;
    u32 field_7c;
    u8 _80[0x340 - 0x80];
    void* field_340;
    u8 _348[0x385 - 0x348];
    bool field_385;
    bool field_386;
};
PKMN_OFFSET_ASSERT(Unk_fa87e0_0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_fa87e0_0, field_7c, 0x7c);
PKMN_OFFSET_ASSERT(Unk_fa87e0_0, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_fa87e0_0, field_385, 0x385);
PKMN_OFFSET_ASSERT(Unk_fa87e0_0, field_386, 0x386);

struct Unk_fa87e0 {
    Unk_fa87e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fa87e0, field_0, 0x0);

void Unk_fb55c0(void*);

// 0x7100fa87e0
void Unk_fa87e0_reset(const Unk_fa87e0* self) {
    Unk_fa87e0_0* obj = self->field_0;
    obj->field_385 = false;
    obj->field_386 = false;
    obj->field_7c = 0xf;
}

// 0x7100fa8870
void Unk_fa8870_reset(const Unk_fa87e0* self) {
    Unk_fa87e0_0* obj = self->field_0;
    obj->field_385 = false;
    obj->field_386 = false;
    obj->field_7c = 0xf;
}

// 0x7100fa88c0
void Unk_fa88c0_reset(const Unk_fa87e0* self) {
    Unk_fa87e0_0* obj = self->field_0;
    obj->field_78 = 0;
    Unk_fb55c0(obj->field_340);
    obj->field_385 = false;
    obj->field_386 = false;
    obj->field_7c = 1;
}
