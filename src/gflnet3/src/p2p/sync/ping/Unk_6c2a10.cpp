// Scope: common
//
// The constructor of the gflnet3 object with a thread (Unk_6c2a10.h), its
// state and its update. Part of the segment 0x71006c2a10-0x71006c3810 (one
// or more TUs). Placeholder names: rename once the classes are known.
#include "gflnet3/src/p2p/sync/ping/Unk_6c2a10.h"

#include "gflib3/Unk_New.h"
#include "unsorted/Unk_2771620.h"

using nn::pia::Unk_165e060;

// 0x71006c2a10
Unk_23a3db8::Unk_23a3db8(const u16& id, const Unk_23a3db8_Config& config)
    : field_58(id), field_f8(config) {}

// 0x71006c2b60
const u16& Unk_23a3db8::Unk_6c2b60() {
    Unk_23a3db8_Lock lock(field_60);
    return field_58;
}

// The result and the value the update hands on, taken under their mutex.
static Unk_23a3db8_Optional<Unk_165e060> Unk_6c2bb0_Result(Unk_23a3db8* self) {
    Unk_23a3db8_Lock lock(self->field_188);
    return self->field_168;
}

static Unk_23a3db8_Optional<u32> Unk_6c2bb0_Value(Unk_23a3db8* self) {
    Unk_23a3db8_Lock lock(self->field_188);
    return self->field_17c;
}

// 0x71006c2bb0
void Unk_6c2bb0(void* p) {
    Unk_23a3db8* self = static_cast<Unk_23a3db8*>(p);
    if (Unk_23a3db8_Optional<Unk_165e060> result = Unk_6c2bb0_Result(self)) {
        Unk_165e060 copy = *result;
        if (self->field_158.IsAlive())
            self->field_158.Get()->vf0(copy);
        self->Unk_6c3460(Unk_23a3db8_Optional<Unk_165e060>());
    }
    if (Unk_23a3db8_Optional<u32> value = Unk_6c2bb0_Value(self)) {
        u32 copy = *value;
        if (self->field_158.IsAlive())
            self->field_158.Get()->vf1(copy);
        Unk_23a3db8_Lock lock(self->field_188);
        self->field_17c.Reset();
    }
}

// 0x71006c2e30
bool Unk_6c2e30(void* p) {
    Unk_23a3db8* self = static_cast<Unk_23a3db8*>(p);
    if (!self->field_50)
        return false;
    return !self->field_50->field_2fa;
}

// 0x71006c2cf0
void Unk_23a3db8::Unk_6c2cf0() {
    if (Unk_6c2e30(this))
        return;
    field_50 = Unk_23a3db8_ThreadRef(Unk_New().Create<Unk_23a3e08>(field_8, field_f8));
    field_50->Unk_6c3a00(field_148);
    field_50->Unk_6c3a70(field_150);
    Unk_5d0f90(field_50.m_ptr, &field_f8.field_8, -1, 0x10);
}

// 0x71006c3070
u32 Unk_23a3db8::Unk_6c3070() {
    Unk_23a3db8_Lock lock(field_88);
    return field_80;
}

// 0x71006c30b0
void Unk_23a3db8::Unk_6c30b0(const u32& state) {
    Unk_23a3db8_Lock lock(field_88);
    if (state != 1 || field_80 == 0)
        field_80 = state;
}

// 0x71006c2e60
bool Unk_6c2e60(void* p) {
    return static_cast<Unk_23a3db8*>(p)->Unk_6c3070() == 1;
}

// 0x71006c2ea0
// NON_MATCHING: the value is 32-bit (`mov w21, w1`): the name gives it as
// u64. And the original stores the request as one word made after the lock
// (`mov w8, #1; bfi x8, x21, #32, #32`), where this stores the flag and the
// value separately; a setter taking the request by value stores one word, but
// makes it before the lock.
bool Unk_6c2ea0(void* p, u64 value) {
    Unk_23a3db8* self = static_cast<Unk_23a3db8*>(p);
    Unk_23a3db8_Lock lock(self->field_88);
    if (self->Unk_6c3070() != 1 && self->Unk_6c3070() != 0)
        return false;
    if (!self->field_50) {
        self->Unk_6c30b0(3);
        return true;
    }
    self->Unk_6c30b0(2);
    {
        Unk_23a3db8_Lock lock2(self->field_d8);
        self->field_d0 = Unk_23a3db8_Request{true, static_cast<u32>(value)};
    }
    {
        Unk_23a3db8_Lock lock2(self->field_b0);
        self->field_a8 = Unk_23a3db8_Request();
    }
    return true;
}

// 0x71006c2fa0
// NON_MATCHING: the value is 32-bit (`mov w21, w1`): the name gives it as
// u64. And the original stores the request as one word made after the lock
// (`mov w8, #1; bfi x8, x21, #32, #32`), where this stores the flag and the
// value separately; a setter taking the request by value stores one word, but
// makes it before the lock.
bool Unk_6c2fa0(void* p, u64 value) {
    Unk_23a3db8* self = static_cast<Unk_23a3db8*>(p);
    Unk_23a3db8_Lock lock(self->field_88);
    if (self->Unk_6c3070() != 3)
        return false;
    if (!self->field_50)
        return true;
    self->Unk_6c30b0(0);
    {
        Unk_23a3db8_Lock lock2(self->field_b0);
        self->field_a8 = Unk_23a3db8_Request{true, static_cast<u32>(value)};
    }
    {
        Unk_23a3db8_Lock lock2(self->field_d8);
        self->field_d0 = Unk_23a3db8_Request();
    }
    return true;
}

// 0x71006c3140
bool Unk_6c3140(void* p) {
    return static_cast<Unk_23a3db8*>(p)->Unk_6c3070() == 3;
}

// 0x71006c3180
void Unk_23a3db8::Unk_6c3180(const void* arg1, const void* arg2) {
    if (field_50)
        field_50->Unk_6c3950(Unk_6c2450(arg1, arg2));
}

// 0x71006c31e0
void Unk_23a3db8::Unk_6c31e0(const Unk_239a418_Ref<Unk_239a418>& ref) {
    Unk_23a3db8_Assign(field_148, ref);
    if (field_50)
        field_50->Unk_6c3a00(ref);
}
