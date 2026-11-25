// Scope: common
// The conditions' context (src/unsorted/unk_8bf520/Unk_8c26c0.cpp), from the
// TU of 0x71008c18d0-0x71008c26c0: what it holds (its leaf accessors are
// 0x71008c1ee0-0x71008c2060) and how it finds the battlers the conditions
// name by index. Placeholder names.
#include <types.h>

struct Unk_7ee6b0;
struct Unk_7efe00;
struct Unk_7f2520;
struct Unk_7fe1d0;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u8 Unk_7efe00_getField33c(const Unk_7efe00* self);
u32 Unk_7f2520_getField34c(const Unk_7f2520* self);
void* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
u32 Unk_7efef0(void* object, u32 index);
u16 Unk_8a86e0(void* self, u8 id1, u8 id2, u32 id, u32 arg4, bool flag);
struct Unk_7c2d80_Main;
struct Unk_7ecc90_Con;
u32 Unk_7cb420(const Unk_7c2d80_Main* self, Unk_7ecc90_Con* arg, u8 id);
u8 Unk_7cb660(void* self, u8 value);
void* Unk_7ed5e0(Unk_7ecc90_Con* self, u8 slot);
u32 Unk_8c20f0(void* self, u32 index);

// What 0x71008c1eb0 copies in: the battlers and the move being looked at.
struct Unk_8c1eb0_Word {
    u64 field_0;
};
struct Unk_8c1eb0_Info {
    Unk_8c1eb0_Info();

    u64 field_0;
    void* field_8;
    void* field_10;
    Unk_8c1eb0_Word field_18;
    Unk_8c1eb0_Word field_20;
    void* field_28;
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8c1eb0_Info, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8c1eb0_Info, field_30, 0x30);

// The moves each battler was seen using (0x71008c24e0 adds one,
// 0x71008c2580 looks one up; neither is matched yet: the original adds the
// array's offset in each load).
struct Unk_8c24e0_Moves {
    u32 field_0[4];
};
PKMN_SIZE_ASSERT(Unk_8c24e0_Moves, 0x10);

struct Unk_8c18d0_Context {
    u8 _0[0x58];
    void* field_58;
    Unk_7fe1d0* field_60;
    void* field_68;
    Unk_8c1eb0_Info field_70;
    Unk_8c24e0_Moves field_a8[1];
};
PKMN_OFFSET_ASSERT(Unk_8c18d0_Context, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_8c18d0_Context, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_8c18d0_Context, field_a8, 0xa8);

// 0x71008c1eb0
void Unk_8c1eb0(Unk_8c18d0_Context* self, const Unk_8c1eb0_Info* info) {
    self->field_70 = *info;
}

// 0x71008c1f60
u32 Unk_8c1f60(void* self) {
    Unk_8c18d0_Context* context = static_cast<Unk_8c18d0_Context*>(self);
    void* object = context->field_70.field_8;
    if (!object)
        return 5;
    void* arg = Unk_7fe1d0_getField8(context->field_60);
    return Unk_7cb420(static_cast<const Unk_7c2d80_Main*>(context->field_58),
                      static_cast<Unk_7ecc90_Con*>(arg),
                      Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object)));
}

// 0x71008c1fd0
u32 Unk_8c1fd0(void* self) {
    Unk_8c18d0_Context* context = static_cast<Unk_8c18d0_Context*>(self);
    void* object = context->field_70.field_10;
    if (!object)
        return 5;
    void* arg = Unk_7fe1d0_getField8(context->field_60);
    return Unk_7cb420(static_cast<const Unk_7c2d80_Main*>(context->field_58),
                      static_cast<Unk_7ecc90_Con*>(arg),
                      Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object)));
}

// 0x71008c2070
void* Unk_8c2070(void* self, u32 slot) {
    Unk_8c18d0_Context* context = static_cast<Unk_8c18d0_Context*>(self);
    return Unk_7ed5e0(static_cast<Unk_7ecc90_Con*>(Unk_7fe1d0_getField8(context->field_60)), slot);
}

// 0x71008c20a0
void* Unk_8c20a0(void* self, u32 index) {
    Unk_8c18d0_Context* context = static_cast<Unk_8c18d0_Context*>(self);
    if (index == 4)
        return context->field_70.field_28;
    u32 slot = Unk_8c20f0(self, index);
    return Unk_7ed5e0(static_cast<Unk_7ecc90_Con*>(Unk_7fe1d0_getField8(context->field_60)), slot);
}

// 0x71008c2270
u8 Unk_8c2270(void* self, u32 index) {
    Unk_8c18d0_Context* context = static_cast<Unk_8c18d0_Context*>(self);
    u32 slot = Unk_8c20f0(self, index == 4 ? 1 : index);
    return Unk_7cb660(context->field_58, slot);
}

// 0x71008c2420
u32 Unk_8c2420(void* self, void* object1, void* object2, bool flag) {
    Unk_8c18d0_Context* context = static_cast<Unk_8c18d0_Context*>(self);
    u8 id1 = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object1));
    u8 id2 = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2));
    u32 best = 0;
    u8 n = Unk_7efe00_getField33c(static_cast<const Unk_7efe00*>(object1));
    for (u32 i = 0; i < n; i++) {
        u32 id = Unk_7efef0(object1, i);
        u16 value = Unk_8a86e0(context->field_68, id1, id2, id, 1, flag);
        if (best < value)
            best = value;
    }
    return best;
}
