// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10faa50 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_10faa50, field_50, 0x50);

u32 Unk_6a0d40();
void Unk_10faaa0(void*);

// 0x71010faa50
void Unk_10faa50_call(Unk_10faa50* self) {
    if (self->field_50 == 2) {
        u32 r0 = Unk_6a0d40();
        if ((r0 & 0xff) != 2)
            return;
        Unk_10faaa0(self);
        self->field_50 = 0;
    }
}

struct Unk_10fad30 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_10fad30, field_50, 0x50);

// 0x71010fad30
bool Unk_10fad30_check(const Unk_10fad30* self) {
    return self->field_50 == 0;
}

struct Unk_10fad40 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_10fad40, field_50, 0x50);

// 0x71010fad40
bool Unk_10fad40_check(const Unk_10fad40* self) {
    return self->field_50 == 2;
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_10fae10 {
    u8 _0[0xfc];
    u32 field_fc;
    u8 _100[0x220];
    u8 field_320;
};
PKMN_OFFSET_ASSERT(Unk_10fae10, field_fc, 0xfc);
PKMN_OFFSET_ASSERT(Unk_10fae10, field_320, 0x320);

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

// 0x71010fae10
void Unk_10fae10_call(Unk_10fae10* self, u32 value) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_320));
    self->field_fc = value;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_320));
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_10fd8d0 {
    u8 _0[0xf8];
    u8 field_f8;
    u8 _f9[0x227];
    u8 field_320;
};
PKMN_OFFSET_ASSERT(Unk_10fd8d0, field_f8, 0xf8);
PKMN_OFFSET_ASSERT(Unk_10fd8d0, field_320, 0x320);

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

// 0x71010fd8d0
void Unk_10fd8d0_call(Unk_10fd8d0* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_320));
    self->field_f8 = 0;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_320));
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_10fd900 {
    u8 _0[0xf9];
    u8 field_f9;
    u8 _fa[0x226];
    u8 field_320;
};
PKMN_OFFSET_ASSERT(Unk_10fd900, field_f9, 0xf9);
PKMN_OFFSET_ASSERT(Unk_10fd900, field_320, 0x320);

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

// 0x71010fd900
void Unk_10fd900_call(Unk_10fd900* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_320));
    self->field_f9 = 1;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_320));
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_10fd9a0 {
    u8 _0[0x340];
    u8 field_340;
    u8 _341[0x17];
    u8 field_358;
};
PKMN_OFFSET_ASSERT(Unk_10fd9a0, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_10fd9a0, field_358, 0x358);

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

// 0x71010fd9a0
void Unk_10fd9a0_call(Unk_10fd9a0* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_358));
    self->field_340 = 0;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_358));
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_10fda30 {
    u8 _0[0x378];
    u8 field_378;
    u8 _379[0x17];
    u8 field_390;
};
PKMN_OFFSET_ASSERT(Unk_10fda30, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_10fda30, field_390, 0x390);

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

// 0x71010fda30
void Unk_10fda30_call(Unk_10fda30* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_390));
    self->field_378 = 0;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_390));
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_10fdac0 {
    u8 _0[0x3b0];
    u8 field_3b0;
    u8 _3b1[0x17];
    u8 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_10fdac0, field_3b0, 0x3b0);
PKMN_OFFSET_ASSERT(Unk_10fdac0, field_3c8, 0x3c8);

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

// 0x71010fdac0
void Unk_10fdac0_call(Unk_10fdac0* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_3c8));
    self->field_3b0 = 0;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_3c8));
}

// 0x71010fe180
void Unk_10fe180_update() {}

struct Unk_10fe190 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10fe190, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe190, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe190, field_10, 0x10);

// 0x71010fe190
void Unk_10fe190_set(const Unk_10fe190* self, Unk_10fe190* value) {
    *value = *self;
}

struct Unk_10fe1b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10fe1b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe1b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe1b0, field_10, 0x10);

// 0x71010fe1b0
void Unk_10fe1b0_set(const Unk_10fe1b0* self, Unk_10fe1b0* value) {
    *value = *self;
}

// 0x71010fe260
void Unk_10fe260_update() {}

struct Unk_10fe270 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10fe270, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe270, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe270, field_10, 0x10);

// 0x71010fe270
void Unk_10fe270_set(const Unk_10fe270* self, Unk_10fe270* value) {
    *value = *self;
}

struct Unk_10fe290 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10fe290, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe290, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe290, field_10, 0x10);

// 0x71010fe290
void Unk_10fe290_set(const Unk_10fe290* self, Unk_10fe290* value) {
    *value = *self;
}

// 0x71010fe2f0
void Unk_10fe2f0_update() {}

struct Unk_10fe300 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10fe300, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe300, field_8, 0x8);

// 0x71010fe300
void Unk_10fe300_set(const Unk_10fe300* self, Unk_10fe300* value) {
    *value = *self;
}

struct Unk_10fe310 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10fe310, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe310, field_8, 0x8);

// 0x71010fe310
void Unk_10fe310_set(const Unk_10fe310* self, Unk_10fe310* value) {
    *value = *self;
}

// 0x71010fe3d0
void Unk_10fe3d0_update() {}

struct Unk_10fe3e0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10fe3e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe3e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe3e0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_10fe3e0, field_18, 0x18);

// 0x71010fe3e0
void Unk_10fe3e0_set(const Unk_10fe3e0* self, Unk_10fe3e0* value) {
    *value = *self;
}

struct Unk_10fe400 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10fe400, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe400, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe400, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_10fe400, field_18, 0x18);

// 0x71010fe400
void Unk_10fe400_set(const Unk_10fe400* self, Unk_10fe400* value) {
    *value = *self;
}

// 0x71010fe470
void Unk_10fe470_update() {}

struct Unk_10fe480 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10fe480, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe480, field_8, 0x8);

// 0x71010fe480
void Unk_10fe480_set(const Unk_10fe480* self, Unk_10fe480* value) {
    *value = *self;
}

struct Unk_10fe490 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10fe490, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe490, field_8, 0x8);

// 0x71010fe490
void Unk_10fe490_set(const Unk_10fe490* self, Unk_10fe490* value) {
    *value = *self;
}

// 0x71010fe530
void Unk_10fe530_update() {}

struct Unk_10fe540 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10fe540, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe540, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe540, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_10fe540, field_18, 0x18);

// 0x71010fe540
void Unk_10fe540_set(const Unk_10fe540* self, Unk_10fe540* value) {
    *value = *self;
}

struct Unk_10fe560 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10fe560, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe560, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe560, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_10fe560, field_18, 0x18);

// 0x71010fe560
void Unk_10fe560_set(const Unk_10fe560* self, Unk_10fe560* value) {
    *value = *self;
}

// 0x71010fe610
void Unk_10fe610_update() {}

struct Unk_10fe620 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10fe620, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe620, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe620, field_10, 0x10);

// 0x71010fe620
void Unk_10fe620_set(const Unk_10fe620* self, Unk_10fe620* value) {
    *value = *self;
}

struct Unk_10fe640 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10fe640, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10fe640, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10fe640, field_10, 0x10);

// 0x71010fe640
void Unk_10fe640_set(const Unk_10fe640* self, Unk_10fe640* value) {
    *value = *self;
}

struct Unk_27e501c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e501c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e501c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e501c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e501c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e501c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e501c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e501c_Data, field_18, 0x18);

extern Unk_27e501c_Data Unk_27e501c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71010fe890
void Unk_10fe890_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e501c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e501c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e501c.field_10 = 0xffff;
    Unk_27e501c.field_8 = r2;
    Unk_27e501c.field_c = 0xffffffff;
    Unk_27e501c.field_18 = 0;
    Unk_27e501c.field_14 = 0;
}
