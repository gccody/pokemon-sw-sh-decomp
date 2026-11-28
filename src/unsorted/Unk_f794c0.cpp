// Scope: common
// Unk_2400128, a view of the mystery gift app (src/unsorted/Unk_f794c0.h): the
// slots that forward its states to the object at +0x5f0, and its destructor.
#include "unsorted/Unk_f794c0.h"

// What slot 12 hands the object at +0x5f0: five kinds and objects, the
// unused ones of kind 8.
struct Unk_f79530_Entry {
    Unk_f79530_Entry() : field_0(8), field_8(nullptr) {}

    u32 field_0;
    Unk_239a418* field_8;
};
static_assert(sizeof(Unk_f79530_Entry) == 0x10, "Unk_f79530_Entry");

// 0x7100f794c0
void Unk_f794c0(Unk_2400128* self, u32 state) {
    Unk_eb5f70(self, state);
    if (state == 3 && self->field_5f0)
        self->field_5f0->vf1();
}

// 0x7100f79530
void Unk_f79530(Unk_2400128* self, u32 state) {
    Unk_eb5f90(self, state);
    if (state == 2) {
        Unk_f79530_Entry entries[5];
        entries[0].field_0 = 0;
        entries[0].field_8 = self->field_5f8[39].m_ptr;
        entries[1].field_0 = 1;
        entries[1].field_8 = self->field_5f8[40].m_ptr;
        if (self->field_5f0)
            self->field_5f0->vf0(entries);
    }
}

// 0x7100f797d0 (D1), its D0 (0x7100f79850) and thunks for +0x48
// (0x7100f79980, 0x7100f79a00), +0x50 (0x7100f79b60, 0x7100f79be0) and
// +0x5e8 (0x7100f79ce0, 0x7100f79d70)
Unk_2400128::~Unk_2400128() {}

// The parts the view's layout member (field_100) keeps at its +0x1b0.
class Unk_f795e0_Parts : public Unk_239a418 {
public:
    u8 _60[0x2e0 - 0x60];
    Unk_239a418_Ref<Unk_239a418> field_2e0;
    Unk_239a418_Ref<Unk_239a418> field_2e8;
};
PKMN_OFFSET_ASSERT(Unk_f795e0_Parts, field_2e0, 0x2e0);
PKMN_OFFSET_ASSERT(Unk_f795e0_Parts, field_2e8, 0x2e8);

// The fields of a packed date and time (lib/nx_middleware/leaf/Unk_15b79f0.cpp):
// its year, month, day, hour and minute.
struct Unk_15b80a0;
struct Unk_15b80b0;
struct Unk_15b80c0;
struct Unk_15b80d0;
struct Unk_15b80e0;
u16 Unk_15b80a0_get(const Unk_15b80a0* self);
u8 Unk_15b80b0_get(const Unk_15b80b0* self);
u8 Unk_15b80c0_get(const Unk_15b80c0* self);
u8 Unk_15b80d0_get(const Unk_15b80d0* self);
u8 Unk_15b80e0_get(const Unk_15b80e0* self);

void Unk_1315b90(void* self, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5);
struct Unk_1311c60;
void Unk_1311c60_call(Unk_1311c60* self, void* value, void* arg2);

// 0x7100f795e0
void Unk_2400128::Unk_f795e0(u32 index) {
    Unk_eb5fb0_Params params;
    if (!field_740) {
        params.field_8 = field_5f8[index].m_ptr;
        params.field_0 = 0;
        Unk_eb5fb0(params);
        return;
    }
    u64 date = field_748;
    Unk_239a418_Ref<Unk_f795e0_Parts> parts =
        *reinterpret_cast<Unk_239a418_Ref<Unk_f795e0_Parts>*>(field_100._8 + 0x1a8);
    Unk_239a418_Ref<Unk_239a418> text = parts.m_ptr->field_2e0;
    Unk_1315b90(text.m_ptr, 0, Unk_15b80a0_get(reinterpret_cast<const Unk_15b80a0*>(&date)) - 2000,
                2, 2, 1);
    Unk_1315b90(text.m_ptr, 1, Unk_15b80b0_get(reinterpret_cast<const Unk_15b80b0*>(&date)), 2, 2,
                1);
    Unk_1315b90(text.m_ptr, 2, Unk_15b80c0_get(reinterpret_cast<const Unk_15b80c0*>(&date)), 2, 2,
                1);
    Unk_1315b90(text.m_ptr, 3, Unk_15b80d0_get(reinterpret_cast<const Unk_15b80d0*>(&date)), 2, 2,
                1);
    Unk_1315b90(text.m_ptr, 4, Unk_15b80e0_get(reinterpret_cast<const Unk_15b80e0*>(&date)), 2, 2,
                1);
    Unk_239a418_Ref<Unk_239a418> object = parts.m_ptr->field_2e8;
    Unk_1311c60_call(reinterpret_cast<Unk_1311c60*>(text.m_ptr), object.m_ptr,
                     field_5f8[index].m_ptr);
    params.field_8 = object.m_ptr;
    field_740 = false;
}
