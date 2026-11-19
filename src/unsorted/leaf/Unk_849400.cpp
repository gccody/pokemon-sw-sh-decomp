// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_84a350(void*, void*, u64, u64, u32);

// 0x7100849400
void Unk_849400_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a350(self, value, arg2, arg3, 2);
}

void Unk_84a350(void*, void*, u64, u64, u32);

// 0x7100849410
void Unk_849410_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a350(self, value, arg2, arg3, 5);
}

void Unk_84a350(void*, void*, u64, u64, u32);

// 0x7100849420
void Unk_849420_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a350(self, value, arg2, arg3, 4);
}

void Unk_84a350(void*, void*, u64, u64, u32);

// 0x7100849430
void Unk_849430_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a350(self, value, arg2, arg3, 3);
}

void Unk_84a350(void*, void*, u64, u64, u32);

// 0x7100849440
void Unk_849440_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a350(self, value, arg2, arg3, 1);
}

void Unk_84a350(void*, void*, u64, u64, u32);

// 0x7100849450
void Unk_849450_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a350(self, value, arg2, arg3, 6);
}

void Unk_84a350(void*, void*, u64, u64, u32);

// 0x7100849460
void Unk_849460_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a350(self, value, arg2, arg3, 7);
}

void Unk_84a420(void*, void*, u64, u64, u32);

// 0x7100849660
void Unk_849660_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a420(self, value, arg2, arg3, 1);
}

void Unk_84a420(void*, void*, u64, u64, u32);

// 0x7100849670
void Unk_849670_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a420(self, value, arg2, arg3, 2);
}

void Unk_84a420(void*, void*, u64, u64, u32);

// 0x7100849680
void Unk_849680_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a420(self, value, arg2, arg3, 3);
}

void Unk_84a420(void*, void*, u64, u64, u32);

// 0x7100849690
void Unk_849690_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a420(self, value, arg2, arg3, 4);
}

void Unk_84a420(void*, void*, u64, u64, u32);

// 0x71008496a0
void Unk_8496a0_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a420(self, value, arg2, arg3, 5);
}

void Unk_84a420(void*, void*, u64, u64, u32);

// 0x71008496b0
void Unk_8496b0_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_84a420(self, value, arg2, arg3, 6);
}

struct Unk_27d0244_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d0244_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d0244_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d0244_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d0244_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d0244_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d0244_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d0244_Data, field_18, 0x18);

extern Unk_27d0244_Data Unk_27d0244 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710084a6f0
void Unk_84a6f0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d0244.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d0244.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d0244.field_18 = 0xffff;
    Unk_27d0244.field_10 = 0;
    Unk_27d0244.field_8 = r2;
    Unk_27d0244.field_c = 0;
    Unk_27d0244.field_14 = 0xffffffff;
}
