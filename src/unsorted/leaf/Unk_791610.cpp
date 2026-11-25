// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_791610_0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_791610_0 {
    virtual void vf0();
    Unk_791610_0_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_791610_0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_791610_0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_791610_0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_791610_0, field_20, 0x20);

struct Unk_791610 {
    Unk_791610_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_791610, field_0, 0x0);

// 0x7100791610
void Unk_791610_call(Unk_791610* self) {
    Unk_791610_0* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        Unk_791610_0_8* v1 = v0->field_8;
        u64 v2 = v0->field_10;
        u64 v3 = v0->field_18;
        u64 v4 = v0->field_20;
        v0->vf0();
        v1->vf3(v2, v3, v4);
    }
}

extern void* Unk_27ce848;
void Unk_793880(void*);

// 0x7100791da0
void Unk_791da0_call(u64 /*unused*/) {
    Unk_793880(Unk_27ce848);
}

extern void* Unk_27ce848;
void Unk_793a60(void*, u32);

// 0x7100791db0
void Unk_791db0_call(void* /*unused*/, u32 value) {
    Unk_793a60(Unk_27ce848, value);
}

struct Unk_7935d0 {
    u8 _0[0x70];
    void* field_70;
};
PKMN_OFFSET_ASSERT(Unk_7935d0, field_70, 0x70);

void Unk_6744e0(void*);

// 0x71007935d0
void Unk_7935d0_call(const Unk_7935d0* self) {
    Unk_6744e0(self->field_70);
}

struct Unk_7935e0 {
    u8 _0[0x70];
    void* field_70;
};
PKMN_OFFSET_ASSERT(Unk_7935e0, field_70, 0x70);

void Unk_674620(void*);

// 0x71007935e0
void Unk_7935e0_call(const Unk_7935e0* self) {
    Unk_674620(self->field_70);
}

struct Unk_7935f0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_7935f0, field_70, 0x70);

void Unk_674680(u64);

// 0x71007935f0
void Unk_7935f0_call(const Unk_7935f0* self) {
    Unk_674680(self->field_70);
}

struct Unk_793600 {
    u8 _0[0x70];
    void* field_70;
};
PKMN_OFFSET_ASSERT(Unk_793600, field_70, 0x70);

void Unk_674690(void*, void*, void*);

// 0x7100793600
void Unk_793600_call(const Unk_793600* self, void* value, void* arg2) {
    Unk_674690(self->field_70, value, arg2);
}

struct Unk_793610 {
    u8 _0[0x70];
    void* field_70;
};
PKMN_OFFSET_ASSERT(Unk_793610, field_70, 0x70);

void Unk_6746f0(void*);

// 0x7100793610
void Unk_793610_call(const Unk_793610* self, u32 /*unused*/) {
    Unk_6746f0(self->field_70);
}

struct Unk_793620 {
    u8 _0[0x70];
    void* field_70;
};
PKMN_OFFSET_ASSERT(Unk_793620, field_70, 0x70);

void Unk_674720(void*, void*, u32, u64, u64);

// 0x7100793620
void Unk_793620_call(const Unk_793620* self, void* value, bool arg2, u64 arg3, u64 arg4) {
    Unk_674720(self->field_70, value, arg2, arg3, arg4);
}

struct Unk_793630 {
    u8 _0[0x70];
    void* field_70;
};
PKMN_OFFSET_ASSERT(Unk_793630, field_70, 0x70);

void Unk_674b60(void*, void*, u32, u64, u64);

// 0x7100793630
void Unk_793630_call(const Unk_793630* self, void* value, bool arg2, u64 arg3, u64 arg4) {
    Unk_674b60(self->field_70, value, arg2, arg3, arg4);
}

// 0x7100793920
void Unk_793920_update() {}

extern void* Unk_27ce848;
void Unk_793c10(void*, void*, void*);

// 0x7100794490
void Unk_794490_call(void* /*unused*/, void* value, void* arg2) {
    Unk_793c10(Unk_27ce848, value, arg2);
}

struct Unk_27ce9dc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27ce9dc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ce9dc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ce9dc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ce9dc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ce9dc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ce9dc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ce9dc_Data, field_18, 0x18);

extern Unk_27ce9dc_Data Unk_27ce9dc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710079d190
void Unk_79d190_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ce9dc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ce9dc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ce9dc.field_18 = 0xffff;
    Unk_27ce9dc.field_10 = 0;
    Unk_27ce9dc.field_8 = r2;
    Unk_27ce9dc.field_c = 0;
    Unk_27ce9dc.field_14 = 0xffffffff;
}
