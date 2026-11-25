// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710065b680
u32 Unk_65b680_get() {
    return 0xffffffff;
}

struct Unk_65b690 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_65b690, field_0, 0x0);

void Unk_ad0(u64, void*, u64);

// 0x710065b690
void Unk_65b690_call(const Unk_65b690* self, void* value, u64 /*unused*/, u64 arg3) {
    Unk_ad0(self->field_0, value, arg3);
}

void Unk_65c5b0(void*);

// 0x710065c580
void Unk_65c580_call(void* self) {
    Unk_65c5b0(self);
}

struct Unk_65cd10_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65cd10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65cd10_arg1, field_8, 0x8);

struct Unk_65cd10_arg2 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65cd10_arg2, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65cd10_arg2, field_8, 0x8);

struct Unk_65cd10_arg3 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65cd10_arg3, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65cd10_arg3, field_8, 0x8);

struct Unk_65cd10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_65cd10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65cd10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_65cd10, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_65cd10, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_65cd10, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_65cd10, field_28, 0x28);

// 0x710065cd10
void Unk_65cd10_set(Unk_65cd10* self,
                    const Unk_65cd10_arg1* value,
                    const Unk_65cd10_arg2* arg2,
                    const Unk_65cd10_arg3* arg3) {
    self->field_8 = value->field_8;
    self->field_0 = value->field_0;
    self->field_18 = arg2->field_8;
    self->field_10 = arg2->field_0;
    self->field_28 = arg3->field_8;
    self->field_20 = arg3->field_0;
}

struct Unk_65cd50_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65cd50_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65cd50_arg1, field_8, 0x8);

struct Unk_65cd50 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65cd50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65cd50, field_8, 0x8);

// 0x710065cd50
void Unk_65cd50_set(Unk_65cd50* self, const Unk_65cd50_arg1* value) {
    self->field_8 = value->field_8;
    self->field_0 = value->field_0;
}

struct Unk_65cd70_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65cd70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65cd70_arg1, field_8, 0x8);

struct Unk_65cd70 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_65cd70, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_65cd70, field_18, 0x18);

// 0x710065cd70
void Unk_65cd70_set(Unk_65cd70* self, const Unk_65cd70_arg1* value) {
    self->field_18 = value->field_8;
    self->field_10 = value->field_0;
}

struct Unk_65cd90_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65cd90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65cd90_arg1, field_8, 0x8);

struct Unk_65cd90 {
    u8 _0[0x20];
    u64 field_20;
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_65cd90, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_65cd90, field_28, 0x28);

// 0x710065cd90
void Unk_65cd90_set(Unk_65cd90* self, const Unk_65cd90_arg1* value) {
    self->field_28 = value->field_8;
    self->field_20 = value->field_0;
}

struct Unk_65dc80 {
    u64 field_0;
    u8 _8[0x5];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_65dc80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_65dc80, field_d, 0xd);

// 0x710065dc80
u64 Unk_65dc80_get(const Unk_65dc80* self) {
    return self->field_0 - self->field_d;
}

struct Unk_65dcc0 {
    u8 _0[0xe];
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_65dcc0, field_e, 0xe);

u32 Unk_660230(u64);

// 0x710065dcc0
void Unk_65dcc0_call(Unk_65dcc0* self, u64 value) {
    u32 r0 = Unk_660230(value);
    self->field_e = r0;
}

struct Unk_65dd50 {
    u8 _0[0xd];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_65dd50, field_d, 0xd);

// 0x710065dd50
void Unk_65dd50_clearFieldd(Unk_65dd50* self) {
    self->field_d = 0;
}

struct Unk_65e010 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_65e010, field_c, 0xc);

// 0x710065e010
u32 Unk_65e010_get(const Unk_65e010* self) {
    return (self->field_c >> 3) & 1;
}

struct Unk_65e0c0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65e0c0, field_8, 0x8);

// 0x710065e0c0
u32 Unk_65e0c0_getField8(const Unk_65e0c0* self) {
    return self->field_8;
}

struct Unk_65ea00 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65ea00, field_8, 0x8);

// 0x710065ea00
u64 Unk_65ea00_getField8(const Unk_65ea00* self) {
    return self->field_8;
}

struct Unk_65edd0 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_65edd0, field_38, 0x38);

// 0x710065edd0
u64 Unk_65edd0_getField38(const Unk_65edd0* self) {
    return self->field_38;
}

struct Unk_65ede0 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_65ede0, field_40, 0x40);

// 0x710065ede0
u64 Unk_65ede0_getField40(const Unk_65ede0* self) {
    return self->field_40;
}

struct Unk_65edf0 {
    u8 _0[0x38];
    u64 field_38;
    u64 field_40;
    u8 _48[0x10];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_65edf0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_65edf0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_65edf0, field_58, 0x58);

// 0x710065edf0
u64 Unk_65edf0_get(const Unk_65edf0* self) {
    return (self->field_38 - self->field_40) - self->field_58;
}

struct Unk_65ee30 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_65ee30, field_30, 0x30);

// 0x710065ee30
u64 Unk_65ee30_getField30(const Unk_65ee30* self) {
    return self->field_30;
}

struct Unk_65ee70 {
    u8 _0[0x50];
    u64 field_50;
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_65ee70, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_65ee70, field_58, 0x58);

void Unk_65eae0(void*, u64, u64);

// 0x710065ee70
void Unk_65ee70_call(Unk_65ee70* self) {
    Unk_65eae0(self, self->field_50, self->field_58);
}

struct Unk_65f1a0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_65f1a0, field_10, 0x10);

// 0x710065f1a0
u64 Unk_65f1a0_getField10(const Unk_65f1a0* self) {
    return self->field_10;
}

struct Unk_65f1b0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_65f1b0, field_10, 0x10);

// 0x710065f1b0
void Unk_65f1b0_setField10(Unk_65f1b0* self, u64 value) {
    self->field_10 = value;
}

// 0x710065fb00
void Unk_65fb00() {}

struct Unk_6608d0 {
    u8 _0[0x60];
    void* field_60;
    u8 _68[0x60];
    u8 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_6608d0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_6608d0, field_c8, 0xc8);

void Unk_6628d0(void*);

// 0x71006608d0
u32 Unk_6608d0_call(Unk_6608d0* self) {
    Unk_6628d0(self->field_60);
    self->field_c8 = 1;
    return 1;
}

struct Unk_663620 {
    u8 _0[0x120];
    void* field_120;
};
PKMN_OFFSET_ASSERT(Unk_663620, field_120, 0x120);

void Unk_6676c0(void*, void*, u32);

// 0x7100663620
void Unk_663620_call(const Unk_663620* self, void* value, u32 arg2) {
    Unk_6676c0(self->field_120, value, arg2);
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_666600 {
    u8 _0[0x2f8];
    u8 field_2f8;
    u8 _2f9[0x27];
    void* field_320;
    u8 _328[0x18];
    u8 field_340;
};
PKMN_OFFSET_ASSERT(Unk_666600, field_2f8, 0x2f8);
PKMN_OFFSET_ASSERT(Unk_666600, field_320, 0x320);
PKMN_OFFSET_ASSERT(Unk_666600, field_340, 0x340);

namespace nn {
namespace os {
u64 LockMutex(MutexType*);
}
}  // namespace nn
namespace nn {
namespace os {
u64 UnlockMutex(MutexType*);
}
}  // namespace nn
void Unk_663c20(void*);

// 0x7100666600
void Unk_666600_call(Unk_666600* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_2f8));
    self->field_340 = 1;
    Unk_663c20(self->field_320);
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_2f8));
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_666640 {
    u8 _0[0x2f8];
    u8 field_2f8;
    u8 _2f9[0x2f];
    u64 field_328;
    u64 field_330;
    u64 field_338;
    u8 field_340;
};
PKMN_OFFSET_ASSERT(Unk_666640, field_2f8, 0x2f8);
PKMN_OFFSET_ASSERT(Unk_666640, field_328, 0x328);
PKMN_OFFSET_ASSERT(Unk_666640, field_330, 0x330);
PKMN_OFFSET_ASSERT(Unk_666640, field_338, 0x338);
PKMN_OFFSET_ASSERT(Unk_666640, field_340, 0x340);

namespace nn {
namespace os {
u64 LockMutex(MutexType*);
}
}  // namespace nn
namespace nn {
namespace os {
u64 UnlockMutex(MutexType*);
}
}  // namespace nn

// 0x7100666640
void Unk_666640_call(Unk_666640* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_2f8));
    self->field_330 = 0xffffffffffffffff;
    self->field_328 = 0xffffffffffffffff;
    self->field_338 = 0;
    self->field_340 = 0;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_2f8));
}

struct Unk_666680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_666680_arg1, field_0, 0x0);

struct Unk_666680 {
    u8 _0[0x358];
    u64 field_358;
};
PKMN_OFFSET_ASSERT(Unk_666680, field_358, 0x358);

// 0x7100666680
u32 Unk_666680_update(const Unk_666680* self, Unk_666680_arg1* value) {
    if (value == nullptr) {
        return 0x100b;
    }
    value->field_0 = self->field_358;
    return 0;
}

// 0x7100666a30
void Unk_666a30() {}

struct Unk_666a40 {
    u32 field_0;
    u8 _4[0x8];
    u32 field_c;
    u8 _10[0x8];
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_666a40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_666a40, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_666a40, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_666a40, field_20, 0x20);

// 0x7100666a40
u32 Unk_666a40_update(Unk_666a40* self) {
    self->field_0 = 0;
    self->field_c = 2;
    self->field_18 = 0;
    self->field_20 = 0x10;
    return 0;
}

namespace nn {
namespace audio {
struct AudioOut;
}
}  // namespace nn
struct Unk_6671e0 {
    u8 _0[0x10];
    u8 field_10;
    u8 field_11;
    u8 _12[0xbe];
    u8 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_6671e0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_6671e0, field_11, 0x11);
PKMN_OFFSET_ASSERT(Unk_6671e0, field_d0, 0xd0);
namespace nn {
namespace audio {
u64 StopAudioOut(AudioOut*);
}
}  // namespace nn

// 0x71006671e0
u32 Unk_6671e0_call(Unk_6671e0* self) {
    if (self->field_11 != 0) {
        if (self->field_10 != 0) {
            nn::audio::StopAudioOut(reinterpret_cast<nn::audio::AudioOut*>(&self->field_d0));
            self->field_10 = 0;
            return 0;
        }
        return 0;
    }
    return 0;
}

struct Unk_667600 {
    u8 _0[0x8];
    u64 field_8;
    void* field_10;
    u8 _18[0x48];
    u32 field_60;
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_667600, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_667600, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_667600, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_667600, field_64, 0x64);

void Unk_668bc0(void*, u32, u32);

// 0x7100667600
u32 Unk_667600_call(Unk_667600* self, u64 value, u32 arg2, u32 arg3) {
    self->field_8 = value;
    self->field_60 = arg2;
    self->field_64 = arg3;
    Unk_668bc0(self->field_10, arg2, arg3);
    return 0;
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_667c40 {
    u8 _0[0x38];
    u8 field_38;
    u8 _39[0x37];
    void* field_70;
    u8 _78[0x20];
    u8 field_98;
};
PKMN_OFFSET_ASSERT(Unk_667c40, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_667c40, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_667c40, field_98, 0x98);

namespace nn {
namespace os {
u64 LockMutex(MutexType*);
}
}  // namespace nn
namespace nn {
namespace os {
u64 UnlockMutex(MutexType*);
}
}  // namespace nn
void Unk_663c20(void*);

// 0x7100667c40
void Unk_667c40_call(Unk_667c40* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_38));
    self->field_98 = 1;
    Unk_663c20(self->field_70);
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_38));
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_667c80 {
    u8 _0[0x38];
    u8 field_38;
    u8 _39[0x53];
    u8 field_8c;
    u8 _8d[0xb];
    u8 field_98;
};
PKMN_OFFSET_ASSERT(Unk_667c80, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_667c80, field_8c, 0x8c);
PKMN_OFFSET_ASSERT(Unk_667c80, field_98, 0x98);

namespace nn {
namespace os {
u64 LockMutex(MutexType*);
}
}  // namespace nn
namespace nn {
namespace os {
u64 UnlockMutex(MutexType*);
}
}  // namespace nn

// 0x7100667c80
void Unk_667c80_call(Unk_667c80* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_38));
    self->field_8c = 1;
    self->field_98 = 0;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_38));
}

// 0x7100667cc0
void Unk_667cc0() {}

struct Unk_667e40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_667e40_arg1, field_0, 0x0);

struct Unk_667e40 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_667e40, field_a0, 0xa0);

// 0x7100667e40
u32 Unk_667e40_update(const Unk_667e40* self, Unk_667e40_arg1* value) {
    if (value == nullptr) {
        return 0x100b;
    }
    value->field_0 = self->field_a0;
    return 0;
}

struct Unk_667e60 {
    u8 _0[0xa8];
    s64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_667e60, field_a8, 0xa8);

// 0x7100667e60
bool Unk_667e60_check(const Unk_667e60* self) {
    return self->field_a8 > 1;
}

void Unk_6682e0(void*);
void Unk_6686d0(void*);

// 0x71006682b0
void Unk_6682b0_call(void* self) {
    Unk_6682e0(self);
    Unk_6686d0(self);
}

struct Unk_669f50_arg2 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(u64, u64);
};

// 0x7100669f50
void Unk_669f50_call(u64 self, u64 value, Unk_669f50_arg2* arg2) {
    arg2->vf2(self, value);
}

struct Unk_669f70_arg1 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

// 0x7100669f70
void Unk_669f70_call(u64 self, Unk_669f70_arg1* value) {
    value->vf3(self, 0, 0);
}

// 0x710066abc0
void Unk_66abc0_update() {}

struct Unk_66abd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_66abd0_arg1, field_0, 0x0);

struct Unk_66abd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_66abd0, field_0, 0x0);

// 0x710066abd0
void Unk_66abd0_set(const Unk_66abd0* self, Unk_66abd0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_66abe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_66abe0_arg1, field_0, 0x0);

struct Unk_66abe0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_66abe0, field_0, 0x0);

// 0x710066abe0
void Unk_66abe0_set(const Unk_66abe0* self, Unk_66abe0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710066c130
u32 Unk_66c130() {
    return 0;
}

struct Unk_66efd0 {
    u8 _0[0xa4];
    u32 field_a4;
};
PKMN_OFFSET_ASSERT(Unk_66efd0, field_a4, 0xa4);

// 0x710066efd0
u32 Unk_66efd0_update(Unk_66efd0* self, u32 value) {
    self->field_a4 = value;
    return 0;
}

// 0x710066fc10
u32 Unk_66fc10_get() {
    return 0;
}

// 0x710066fc20
u32 Unk_66fc20_get() {
    return 0;
}

struct Unk_670430 {
    u8 _0[0x40];
    u64 field_40;
    u8 _48[0x8];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_670430, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_670430, field_50, 0x50);

// 0x7100670430
u64 Unk_670430_get(const Unk_670430* self) {
    return self->field_50 - self->field_40;
}

struct Unk_6707e0 {
    u8 _0[0x1d8];
    u32 field_1d8;
};
PKMN_OFFSET_ASSERT(Unk_6707e0, field_1d8, 0x1d8);

// 0x71006707e0
u32 Unk_6707e0_getField1d8(const Unk_6707e0* self) {
    return self->field_1d8;
}

struct Unk_670800 {
    u8 _0[0x1f0];
    u8 field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_670800, field_1f0, 0x1f0);

// 0x7100670800
u8 Unk_670800_getField1f0(const Unk_670800* self) {
    return self->field_1f0;
}

struct Unk_670810 {
    u8 _0[0x1f4];
    u32 field_1f4;
};
PKMN_OFFSET_ASSERT(Unk_670810, field_1f4, 0x1f4);

// 0x7100670810
u32 Unk_670810_getField1f4(const Unk_670810* self) {
    return self->field_1f4;
}

struct Unk_670820 {
    u8 _0[0x1f8];
    u32 field_1f8;
};
PKMN_OFFSET_ASSERT(Unk_670820, field_1f8, 0x1f8);

// 0x7100670820
u32 Unk_670820_getField1f8(const Unk_670820* self) {
    return self->field_1f8;
}

struct Unk_671ce0 {
    u8 _0[0x1f8];
    u32 field_1f8;
};
PKMN_OFFSET_ASSERT(Unk_671ce0, field_1f8, 0x1f8);

// 0x7100671ce0
void Unk_671ce0_setField1f8(Unk_671ce0* self, u32 value) {
    self->field_1f8 = value;
}

struct Unk_671cf0 {
    u8 _0[0x194];
    u32 field_194;
};
PKMN_OFFSET_ASSERT(Unk_671cf0, field_194, 0x194);

// 0x7100671cf0
void Unk_671cf0_setField194(Unk_671cf0* self, u32 value) {
    self->field_194 = value;
}

struct Unk_6745f0_c0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6(u64);
};

struct Unk_6745f0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6745f0_arg1, field_8, 0x8);

struct Unk_6745f0 {
    u8 _0[0xc0];
    Unk_6745f0_c0* field_c0;
};
PKMN_OFFSET_ASSERT(Unk_6745f0, field_c0, 0xc0);

// 0x71006745f0
bool Unk_6745f0_call(const Unk_6745f0* self, const Unk_6745f0_arg1* value) {
    u32 r0 = self->field_c0->vf6(value->field_8);
    return r0 == 1;
}

void Unk_675ea0(void*, u32, u64, u32);

// 0x7100674800
void Unk_674800_call(u32 self, u64 value, u32 arg2, u64 /*unused*/, void* arg4) {
    if (arg4 != nullptr) {
        Unk_675ea0(arg4, self, value, arg2);
    }
}

void Unk_676c60(void*, u32, u64, u32);

// 0x7100674c30
void Unk_674c30_call(u32 self, u64 value, u32 arg2, u64 /*unused*/, void* arg4) {
    if (arg4 != nullptr) {
        Unk_676c60(arg4, self, value, arg2);
    }
}

struct Unk_675040_a0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

struct Unk_675040_80 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual u32 vf11(u64);
};

struct Unk_675040 {
    u8 _0[0x20];
    void* field_20;
    u8 _28[0x58];
    Unk_675040_80* field_80;
    u8 _88[0x18];
    Unk_675040_a0* field_a0;
};
PKMN_OFFSET_ASSERT(Unk_675040, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_675040, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_675040, field_a0, 0xa0);

void Unk_6750b0(void*, u64);

// 0x7100675040
u32 Unk_675040_call(const Unk_675040* self, u64 value) {
    self->field_a0->vf4();
    u32 r1 = self->field_80->vf11(value);
    if (r1 != 1) {
        return 0;
    }
    Unk_6750b0(self->field_20, value);
    return 1;
}

struct Unk_675720 {
    u8 _0[0x20];
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_675720, field_20, 0x20);

u32 Unk_675600(void*, u64);

// 0x7100675720
bool Unk_675720_call(const Unk_675720* self, u64 value) {
    if (self->field_20 == nullptr) {
        return false;
    }
    u32 r0 = Unk_675600(self->field_20, value);
    return r0 != 0;
}

struct Unk_675750_80 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual u32 vf20(u64, s64);
};

struct Unk_675750_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_675750_arg1, field_8, 0x8);

struct Unk_675750 {
    u8 _0[0x80];
    Unk_675750_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_675750, field_80, 0x80);

// 0x7100675750
bool Unk_675750_call(const Unk_675750* self, const Unk_675750_arg1* value, s64 index) {
    u32 r0 = self->field_80->vf20(value->field_8, index);
    return r0 == 1;
}

struct Unk_6757c0_80 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u32 vf18(u64, u64, s64);
};

struct Unk_6757c0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6757c0_arg1, field_8, 0x8);

struct Unk_6757c0_arg2 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6757c0_arg2, field_8, 0x8);

struct Unk_6757c0 {
    u8 _0[0x80];
    Unk_6757c0_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_6757c0, field_80, 0x80);

// 0x71006757c0
bool Unk_6757c0_call(const Unk_6757c0* self,
                     const Unk_6757c0_arg1* value,
                     const Unk_6757c0_arg2* arg2,
                     s64 index) {
    u32 r0 = self->field_80->vf18(value->field_8, arg2->field_8, index);
    return r0 == 1;
}

struct Unk_6757f0_80 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual u32 vf22(u64, u64);
};

struct Unk_6757f0_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6757f0_arg1, field_8, 0x8);

struct Unk_6757f0_arg2 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6757f0_arg2, field_8, 0x8);

struct Unk_6757f0 {
    u8 _0[0x80];
    Unk_6757f0_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_6757f0, field_80, 0x80);

// 0x71006757f0
bool Unk_6757f0_call(const Unk_6757f0* self,
                     const Unk_6757f0_arg1* value,
                     const Unk_6757f0_arg2* arg2) {
    u32 r0 = self->field_80->vf22(value->field_8, arg2->field_8);
    return r0 == 1;
}

struct Unk_679bb0_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(u64, u64);
};

struct Unk_679bb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679bb0_arg1, field_0, 0x0);

struct Unk_679bb0_arg2 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679bb0_arg2, field_0, 0x0);

struct Unk_679bb0 {
    Unk_679bb0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_679bb0, field_0, 0x0);

// 0x7100679bb0
void Unk_679bb0_call(const Unk_679bb0* self,
                     const Unk_679bb0_arg1* value,
                     const Unk_679bb0_arg2* arg2) {
    self->field_0->vf2(value->field_0, arg2->field_0);
}

// 0x7100679bd0
void Unk_679bd0_update() {}

struct Unk_679be0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679be0_arg1, field_0, 0x0);

struct Unk_679be0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679be0, field_0, 0x0);

// 0x7100679be0
void Unk_679be0_set(const Unk_679be0* self, Unk_679be0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_679bf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679bf0_arg1, field_0, 0x0);

struct Unk_679bf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679bf0, field_0, 0x0);

// 0x7100679bf0
void Unk_679bf0_set(const Unk_679bf0* self, Unk_679bf0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100679c20
void Unk_679c20_update() {}

struct Unk_679c30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679c30_arg1, field_0, 0x0);

struct Unk_679c30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679c30, field_0, 0x0);

// 0x7100679c30
void Unk_679c30_set(const Unk_679c30* self, Unk_679c30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_679c40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679c40_arg1, field_0, 0x0);

struct Unk_679c40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679c40, field_0, 0x0);

// 0x7100679c40
void Unk_679c40_set(const Unk_679c40* self, Unk_679c40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100679c60
void Unk_679c60_update() {}

struct Unk_679c70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679c70_arg1, field_0, 0x0);

struct Unk_679c70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679c70, field_0, 0x0);

// 0x7100679c70
void Unk_679c70_set(const Unk_679c70* self, Unk_679c70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_679c80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679c80_arg1, field_0, 0x0);

struct Unk_679c80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_679c80, field_0, 0x0);

// 0x7100679c80
void Unk_679c80_set(const Unk_679c80* self, Unk_679c80_arg1* value) {
    value->field_0 = self->field_0;
}
