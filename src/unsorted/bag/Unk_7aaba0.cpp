// Scope: common
//
// A class on Unk_23f4660 (vtable 0x71023a9058, made by Unk_790260_Owner's
// creators: src/gflib3/families/Unk_790260.cpp) in the bag's code: a value
// it steps through 1..max, wrapping at both ends, and the buttons it shows
// at the ends. Placeholder names: rename once the class is known.
#include <types.h>

#include "unsorted/Unk_23f4660.h"

class alignas(16) Unk_23a9048 : public Unk_23f4660 {
public:
    ~Unk_23a9048() override;

    u8 field_5cb;
    u32 field_5cc;
    Unk_239a418_Ref<Unk_239a418> field_5d0;
    u64 field_5d8;
    u64 field_5e0;
    u64 field_5e8;
    u64 field_5f0;
    u64 field_5f8;
    u64 field_600;
    u64 field_608;
    u64 field_610;
    u64 field_618;
    u64 field_620;
    u64 field_628;
    u32 field_630;
    u32 field_634;
    u64 field_638;
    u64 field_640;
    u32 field_648;
};
static_assert(sizeof(Unk_23a9048) == 0x650, "Unk_23a9048");
static_assert(__builtin_offsetof(Unk_23a9048, field_5d0) == 0x5d0, "Unk_23a9048::field_5d0");

// 0x71007aace0, its D0 (0x71007aad40) and thunks for +0x48 (0x71007aadb0,
// 0x71007aae10) and +0x50 (0x71007aae90, 0x71007aaef0)
Unk_23a9048::~Unk_23a9048() {}

struct Unk_e83430;
u32 Unk_e83430_call(const Unk_e83430* self, void* arg);
void Unk_14e1a00(void*, u32);
void Unk_1500c40(u64);
void Unk_7aa720(void*);

// The same object, as the stepping functions see it.
struct Unk_7aaba0_Self {
    u8 _0[0x100];
    u8 field_100[0x3c0];
    u64 field_4c0;
    u8 _4c8[0x5e0 - 0x4c8];
    void* field_5e0;
    void* field_5e8;
    void* field_5f0;
    void* field_5f8;
    void* field_600;
    void* field_608;
    void* field_610;
    void* field_618;
    u8 _620[0x20];
    s32 field_640;
    s32 field_644;
};
static_assert(__builtin_offsetof(Unk_7aaba0_Self, field_4c0) == 0x4c0,
              "Unk_7aaba0_Self::field_4c0");
static_assert(__builtin_offsetof(Unk_7aaba0_Self, field_5e0) == 0x5e0,
              "Unk_7aaba0_Self::field_5e0");
static_assert(__builtin_offsetof(Unk_7aaba0_Self, field_640) == 0x640,
              "Unk_7aaba0_Self::field_640");

// 0x71007aaba0
// The step is signed: -10, -1 or 1 (the callbacks below and in Unk_7ab130.cpp).
void Unk_7aaba0(void* obj, s32 delta) {
    auto* self = static_cast<Unk_7aaba0_Self*>(obj);
    s32 value = self->field_640;
    s32 max = self->field_644;
    if (delta > 0 && value == max) {
        value = 1;
    } else if (delta < 0 && value == 1) {
        value = max;
    } else {
        value += delta;
        if (value > max)
            value = max;
        if (value < 1)
            value = 1;
    }
    self->field_640 = value;
    Unk_7aa720(self);

    bool atMax = self->field_640 == self->field_644;
    bool atMin = self->field_640 == 1;
    Unk_14e1a00(self->field_5e0, !atMax);
    Unk_14e1a00(self->field_600, atMax);
    Unk_14e1a00(self->field_5e8, !atMin);
    Unk_14e1a00(self->field_608, atMin);
    Unk_14e1a00(self->field_5f8, !atMax);
    Unk_14e1a00(self->field_618, atMax);
    Unk_14e1a00(self->field_5f0, !atMin);
    Unk_14e1a00(self->field_610, atMin);

    const auto* sound = reinterpret_cast<const Unk_e83430*>(self->field_100);
    if (delta > 0) {
        u64 hash = 0x21c94826ad681fa5;
        Unk_e83430_call(sound, &hash);
    } else {
        u64 hash = 0x8365d102289604c8;
        Unk_e83430_call(sound, &hash);
    }
}

struct Unk_7ab080 {
    Unk_7aaba0_Self* field_0;
};

// 0x71007ab080
void Unk_7ab080_call(const Unk_7ab080* self) {
    Unk_7aaba0_Self* obj = self->field_0;
    Unk_7aaba0(obj, 1);
    if (obj->field_4c0 != 0)
        Unk_1500c40(obj->field_4c0);
}

struct Unk_7ab0f0 {
    Unk_7aaba0_Self* field_0;
};

// 0x71007ab0f0
void Unk_7ab0f0_call(const Unk_7ab0f0* self) {
    Unk_7aaba0_Self* obj = self->field_0;
    Unk_7aaba0(obj, 1);
    if (obj->field_4c0 != 0)
        Unk_1500c40(obj->field_4c0);
}
