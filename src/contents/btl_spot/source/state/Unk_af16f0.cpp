// Scope: common
//
// A battle spot state (Unk_23cc7a0, src/unsorted/virtual/Unk_af1c10.cpp, on
// Unk_23c9470): its slots 18 and 19, the callable it hands on, and how it
// sets its slots up for a mode (0-3): a std::function each, from a lambda
// that captures the state. Each lambda takes the reference it's called with
// and passes it on, with a hash per slot, to the object at the state's
// +0x5e0. The slots' callables take that reference (std::function<void(Ref)>,
// not the void() Unk_23c9470_Slot declares).
//
// The lambdas' classes are also the std::function model classes of
// src/unsorted/clone/Unk_ad7090.cpp (vtables 0x71023cc8f0 to 0x71023ccd28, in
// the order they're made here), and their calls (slot 6) are written below as
// free functions over the callable, the names functions.csv gives them. The
// lambdas' own copies compile to the same code but aren't checked.
// Placeholder names: rename once the classes are known.
#include <functional>
#include <utility>

#include "gflib3/Unk_239a418.h"

void Unk_67d450(Unk_239a418* object, u64* arg1, Unk_239a418* arg2);
void Unk_14ab0c0(u64 self, u64 key);
u32 Unk_eb6530(void*);

struct Unk_ace0e0;
void Unk_ace0e0_call(Unk_ace0e0* self);

// Unk_23c9470's: set a slot's callable, then two more steps.
void Unk_ace570(void* self, u32 slot, std::function<void(Unk_239a418_Ref<Unk_239a418>)> callback);
void Unk_ace620(void* self);
void Unk_ace880(void* self);

// What Unk_23c9470 keeps at +0x630.
struct Unk_af16f0_630 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_af16f0_630, field_58, 0x58);

// The state, as far as these functions read it.
struct Unk_af16f0_State {
    u8 _0[0x5e0];
    Unk_239a418_Ref<Unk_239a418> field_5e0;
    u8 _5e8[0x10];
    Unk_239a418_Ref<Unk_239a418> field_5f8;
    u8 _600[0x4];
    u32 field_604;
    u8 _608[0x28];
    Unk_af16f0_630* field_630;
};
PKMN_OFFSET_ASSERT(Unk_af16f0_State, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_af16f0_State, field_5f8, 0x5f8);
PKMN_OFFSET_ASSERT(Unk_af16f0_State, field_604, 0x604);
PKMN_OFFSET_ASSERT(Unk_af16f0_State, field_630, 0x630);

// A lambda's callable: its vtable and the state it captured.
struct Unk_af16f0_Lambda {
    void* vtable;
    Unk_af16f0_State* field_8;
};
PKMN_OFFSET_ASSERT(Unk_af16f0_Lambda, field_8, 0x8);

// What the callable that 0x7100af1db0 calls keeps: the state.
struct Unk_af1db0_Closure {
    Unk_af16f0_State* field_0;
};
PKMN_OFFSET_ASSERT(Unk_af1db0_Closure, field_0, 0x0);

// 0x7100af1bd0 (Unk_23cc7a0's slot 18)
u32 Unk_af1bd0(void* self) {
    return ~Unk_eb6530(self) & 1;
}

// 0x7100af1bf0 (Unk_23cc7a0's slot 19)
void Unk_af1bf0(Unk_af16f0_State* self) {
    if (self->field_630->field_58 & 1)
        Unk_ace0e0_call(reinterpret_cast<Unk_ace0e0*>(self));
}

// 0x7100af1db0
void Unk_af1db0(Unk_af1db0_Closure* closure) {
    Unk_af16f0_State* self = closure->field_0;
    u64 target = reinterpret_cast<u64>(self->field_5f8.m_ptr);
    u64 key = 0xc4075b79c0e79906;
    Unk_14ab0c0(target, reinterpret_cast<u64>(&key));
    self->field_604 = 1;
}

// 0x7100af1ec0 (Unk_23cc8e0's slot 6: mode 0, slot 0)
void Unk_af1ec0(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d86f0c1ba6328;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af1fb0 (Unk_23cc928's slot 6: mode 0, slot 2)
void Unk_af1fb0(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79a18f0c1b77267;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af20a0 (Unk_23cc970's slot 6: mode 0, slot 7)
void Unk_af20a0(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d84f0c1ba5fc2;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2190 (Unk_23cc9b8's slot 6: mode 0, slot 3)
void Unk_af2190(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79a19f0c1b7741a;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2280 (Unk_23cca00's slot 6: mode 0, slot 1)
void Unk_af2280(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d80f0c1ba58f6;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2370 (Unk_23cca48's slot 6: mode 1, slot 0)
void Unk_af2370(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d86f0c1ba6328;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2460 (Unk_23cca90's slot 6: mode 1, slot 2)
void Unk_af2460(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79a18f0c1b77267;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2550 (Unk_23ccad8's slot 6: mode 1, slot 7)
void Unk_af2550(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d84f0c1ba5fc2;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2640 (Unk_23ccb20's slot 6: mode 1, slot 1)
void Unk_af2640(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d80f0c1ba58f6;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2730 (Unk_23ccb68's slot 6: mode 2, slot 2)
void Unk_af2730(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79a18f0c1b77267;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2820 (Unk_23ccbb0's slot 6: mode 2, slot 7)
void Unk_af2820(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d84f0c1ba5fc2;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2910 (Unk_23ccbf8's slot 6: mode 2, slot 3)
void Unk_af2910(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79a19f0c1b7741a;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2a00 (Unk_23ccc40's slot 6: mode 2, slot 1)
void Unk_af2a00(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d80f0c1ba58f6;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2af0 (Unk_23ccc88's slot 6: mode 3, slot 2)
void Unk_af2af0(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79a18f0c1b77267;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2be0 (Unk_23cccd0's slot 6: mode 3, slot 7)
void Unk_af2be0(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d84f0c1ba5fc2;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af2cd0 (Unk_23ccd18's slot 6: mode 3, slot 1)
void Unk_af2cd0(Unk_af16f0_Lambda* self, Unk_239a418_Ref<Unk_239a418>&& arg) {
    Unk_239a418_Ref<Unk_239a418> object(std::move(arg));
    Unk_239a418* target = self->field_8->field_5e0.m_ptr;
    u64 key = 0xd79d80f0c1ba58f6;
    Unk_67d450(target, &key, object.m_ptr);
}

// 0x7100af16f0
void Unk_af16f0(Unk_af16f0_State* self, u32 mode) {
    switch (mode) {
        case 0:
            Unk_ace570(self, 0, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d86f0c1ba6328;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 2, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79a18f0c1b77267;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 7, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d84f0c1ba5fc2;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 3, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79a19f0c1b7741a;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 1, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d80f0c1ba58f6;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace620(self);
            Unk_ace880(self);
            break;
        case 1:
            Unk_ace570(self, 0, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d86f0c1ba6328;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 2, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79a18f0c1b77267;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 7, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d84f0c1ba5fc2;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 1, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d80f0c1ba58f6;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace620(self);
            Unk_ace880(self);
            break;
        case 2:
            Unk_ace570(self, 2, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79a18f0c1b77267;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 7, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d84f0c1ba5fc2;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 3, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79a19f0c1b7741a;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 1, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d80f0c1ba58f6;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace620(self);
            Unk_ace880(self);
            break;
        case 3:
            Unk_ace570(self, 2, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79a18f0c1b77267;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 7, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d84f0c1ba5fc2;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace570(self, 1, [self](Unk_239a418_Ref<Unk_239a418> object) {
                Unk_239a418* target = self->field_5e0.m_ptr;
                u64 key = 0xd79d80f0c1ba58f6;
                Unk_67d450(target, &key, object.m_ptr);
            });
            Unk_ace620(self);
            Unk_ace880(self);
            break;
    }
}
