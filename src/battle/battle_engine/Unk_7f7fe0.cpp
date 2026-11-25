// Scope: common
// The end of the battle calculations' TU (0x71007f7fe0 to 0x71007f8670).
// Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_7ee6b0.h"
#include "battle/battle_engine/Unk_7fc210.h"
#include "gflib3/Unk_239a418.h"

struct Unk_7ecc90_Con;
struct Unk_7fc2e0;
struct Unk_7847d0;

const Unk_7fc430_Party* Unk_7ed1b0(const Unk_7ecc90_Con* self, u32 client);
u8 Unk_7fc2e0_getField30(const Unk_7fc2e0* self);
// Its byte, as this TU declares it (used unmasked).
u32 Unk_7847d0_getField88(const Unk_7847d0* self);
// 0x710137ba50, not decompiled.
u32 Unk_137ba50(Unk_239a418* object, u32 value);
// 0x7100764b40, not decompiled.
u32 Unk_764b40(Unk_239a418* object);

// 0x71007f8330
bool Unk_7f8330(s32 value) {
    return value != 0;
}

// The singleton 0x71007f8540 asks, as it uses it.
struct Unk_7f8540_Global {
    u8 _0[0x208];
    Unk_239a418_Ref2<Unk_239a418> field_208;
};
PKMN_OFFSET_ASSERT(Unk_7f8540_Global, field_208, 0x208);

extern Unk_7f8540_Global* Unk_24ba4e0;

// 0x71007f8540: the largest value 0x11 of client 0's Pokemon, through the
// singleton's object.
u32 Unk_7f8540(void*, const Unk_7ecc90_Con* con) {
    Unk_7fc430_Party* party = const_cast<Unk_7fc430_Party*>(Unk_7ed1b0(con, 0));
    u8 count = Unk_7fc2e0_getField30(reinterpret_cast<const Unk_7fc2e0*>(party));
    u32 max = 0;
    for (u32 i = 0; i != count; i++) {
        u32 value = Unk_7eef50(Unk_7fc450(party, i), 0x11);
        if (value > max)
            max = value;
    }
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_208;
    return Unk_137ba50(object.m_ptr, max);
}

// What 0x71007f8350 multiplies: a byte of the first object of a pair.
class Unk_7f8350_Owner : public Unk_239a418 {
public:
    u8 _60[0x10];
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_7f8350_Owner, field_70, 0x70);

// The second object of a pair: a list of objects, the last one asked for.
class Unk_7f8350_List : public Unk_239a418 {
public:
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual Unk_239a418* vf11(s32 index);
};

struct Unk_7f8350_Self {
    u32 field_0;
    u8 _4[0x408 - 0x4];
    Unk_239a418_Ref<Unk_7f8350_List> field_408;
    u8 _410[0x8];
    Unk_239a418_Ref<Unk_7f8350_List> field_418;
    u8 _420[0xa10 - 0x420];
    Unk_239a418_Ref<Unk_7f8350_Owner> field_a10;
    u8 _a18[0x8];
    Unk_239a418_Ref<Unk_7f8350_Owner> field_a20;
};
PKMN_OFFSET_ASSERT(Unk_7f8350_Self, field_408, 0x408);
PKMN_OFFSET_ASSERT(Unk_7f8350_Self, field_418, 0x418);
PKMN_OFFSET_ASSERT(Unk_7f8350_Self, field_a10, 0xa10);
PKMN_OFFSET_ASSERT(Unk_7f8350_Self, field_a20, 0xa20);

static u32 Unk_7f8350_Pair(Unk_239a418_Ref<Unk_7f8350_Owner> owner,
                           Unk_239a418_Ref<Unk_7f8350_List> list) {
    if (list.m_ptr == nullptr)
        return 0;
    u32 count = Unk_7847d0_getField88(reinterpret_cast<const Unk_7847d0*>(list.m_ptr));
    if (count == 0)
        return 0;
    Unk_239a418_Ref<Unk_239a418> last(list.m_ptr->vf11(count - 1));
    return owner.m_ptr->field_70 * Unk_764b40(last.m_ptr) * 4;
}

// 0x71007f8350
u32 Unk_7f8350(const Unk_7f8350_Self* self) {
    if (self->field_0 != 1)
        return 0;
    u32 total = 0;
    if (self->field_a10.m_ptr != nullptr && self->field_408.m_ptr != nullptr)
        total += Unk_7f8350_Pair(self->field_a10, self->field_408);
    if (self->field_a20.m_ptr != nullptr && self->field_418.m_ptr != nullptr)
        total += Unk_7f8350_Pair(self->field_a20, self->field_418);
    return total;
}

// 0x71007f8620: the initialiser of a guarded static (a template's or an
// inline one) whose destructor is 0x71007f8670: its constructor is constant,
// so only the destructor is registered.
struct Unk_7f8670;
void Unk_7f8670_call(Unk_7f8670* self) __attribute__((visibility("hidden")));

// Its guard (0x71027cecf8). The static itself (0x71027cecf0, a pointer the
// destructor releases) is declared in Unk_7ee6b0.h as other code reads it.
extern u64 Unk_27cecf8;

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

void Unk_7f8620_init() {
    if ((Unk_27cecf8 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_7f8670_call), &Unk_27cecf0,
                     &__dso_handle);
        Unk_27cecf8 = 1;
    }
}
