// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5dd6f0_0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_5dd6f0_0 {
    virtual void vf0();
    Unk_5dd6f0_0_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_5dd6f0_0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5dd6f0_0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_5dd6f0_0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5dd6f0_0, field_20, 0x20);

struct Unk_5dd6f0 {
    Unk_5dd6f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_5dd6f0, field_0, 0x0);

// 0x71005dd6f0
void Unk_5dd6f0_call(Unk_5dd6f0* self) {
    Unk_5dd6f0_0* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        Unk_5dd6f0_0_8* v1 = v0->field_8;
        u64 v2 = v0->field_10;
        u64 v3 = v0->field_18;
        u64 v4 = v0->field_20;
        v0->vf0();
        v1->vf3(v2, v3, v4);
    }
}

struct Unk_5df190 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u8 field_30;
    u8 _31[0x3];
    u32 field_34;
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_5df190, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5df190, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5df190, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_5df190, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5df190, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_5df190, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_5df190, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_5df190, field_34, 0x34);
PKMN_OFFSET_ASSERT(Unk_5df190, field_38, 0x38);

namespace nn {
namespace os {
u64 GetHostArgc();
}
}  // namespace nn
namespace nn {
namespace os {
u64 GetHostArgv();
}
}  // namespace nn

// 0x71005df190
void Unk_5df190_call(Unk_5df190* self, u64 value) {
    self->field_0 = value;
    self->field_8 = 0xfde80;
    self->field_10 = 0x6000000;
    self->field_18 = 0;
    self->field_20 = 0x400000;
    self->field_28 = 0x100000;
    self->field_30 = 1;
    u32 r0 = nn::os::GetHostArgc();
    self->field_34 = r0;
    u64 r1 = nn::os::GetHostArgv();
    self->field_38 = r1;
}

struct Unk_5e1f40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f40, field_0, 0x0);

void Unk_5e1dc0(u64);

// 0x71005e1f40
void Unk_5e1f40_call(const Unk_5e1f40* self) {
    Unk_5e1dc0(self->field_0);
}

// 0x71005e1f50
void Unk_5e1f50_update() {}

struct Unk_5e1f60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f60_arg1, field_0, 0x0);

struct Unk_5e1f60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f60, field_0, 0x0);

// 0x71005e1f60
void Unk_5e1f60_set(const Unk_5e1f60* self, Unk_5e1f60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_5e1f70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f70_arg1, field_0, 0x0);

struct Unk_5e1f70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e1f70, field_0, 0x0);

// 0x71005e1f70
void Unk_5e1f70_set(const Unk_5e1f70* self, Unk_5e1f70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_5e3a50_0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5e3a50_0, field_10, 0x10);

struct Unk_5e3a50 {
    Unk_5e3a50_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e3a50, field_0, 0x0);

// 0x71005e3a50
u32 Unk_5e3a50_get(const Unk_5e3a50* self) {
    if (self->field_0 == nullptr) {
        return 0;
    }
    return self->field_0->field_10;
}
