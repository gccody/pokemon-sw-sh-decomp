// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24df330;

// 0x71003f7fb0
u64 Unk_3f7fb0_get() {
    return Unk_24df330;
}

void Unk_3f7fe0(void*, void*, u64);

// 0x71003f7fd0
void Unk_3f7fd0_call(void* self, u64 value) {
    Unk_3f7fe0(self, self, value);
}

extern const u8 Unk_24df358[] __attribute__((visibility("hidden")));

// 0x71003f83b0
const u8* Unk_3f83b0_get() {
    return Unk_24df358;
}

struct Unk_3fcd40 {
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
    virtual void vf22();
    virtual void vf23();
    u64 field_8;
    u8 _10[0x40];
    u64 field_50;
    u8 _58[0x63];
    u8 field_bb;
};
PKMN_OFFSET_ASSERT(Unk_3fcd40, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3fcd40, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_3fcd40, field_bb, 0xbb);
void Unk_3fcb30(void*);
void Unk_3ffea0(u64, void*);

// 0x71003fcd40
void Unk_3fcd40_call(Unk_3fcd40* self, u32 value) {
    if (value == 2) {
        self->field_bb = 1;
        self->vf23();
        Unk_3fcb30(self);
        if (self->field_8 != 0) {
            Unk_3ffea0(self->field_50, self);
            return;
        }
        return;
    }
    Unk_3fcb30(self);
    if (self->field_8 != 0) {
        Unk_3ffea0(self->field_50, self);
        return;
    }
}

struct Unk_3ff910 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3ff910, field_8, 0x8);

namespace nn { namespace os { u64 GetCurrentThread(); } }

// 0x71003ff910
void Unk_3ff910_call(Unk_3ff910* self) {
    u64 r0 = nn::os::GetCurrentThread();
    self->field_8 = r0;
}

namespace nn { namespace os { struct ConditionVariableType; } }
namespace nn { namespace os { struct MutexType; } }
namespace nn { namespace os { struct ThreadType; } }
struct Unk_3ffbe0 {
    u8 _0[0x10];
    u8 field_10;
    u8 _11[0x3f];
    u8 field_50;
    u8 _51[0x17f];
    u64 field_1d0;
    u8 _1d8[0x8];
    u8 field_1e0;
    u8 _1e1[0x1f];
    u8 field_200;
    u8 _201[0x5f];
    u8 field_260;
};
PKMN_OFFSET_ASSERT(Unk_3ffbe0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3ffbe0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_3ffbe0, field_1d0, 0x1d0);
PKMN_OFFSET_ASSERT(Unk_3ffbe0, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_3ffbe0, field_200, 0x200);
PKMN_OFFSET_ASSERT(Unk_3ffbe0, field_260, 0x260);

namespace nn { namespace os { u64 DestroyThread(ThreadType*); } }
namespace nn { namespace os { u64 LockMutex(MutexType*); } }
namespace nn { namespace os { u64 SignalConditionVariable(ConditionVariableType*); } }
namespace nn { namespace os { u64 UnlockMutex(MutexType*); } }
namespace nn { namespace os { u64 WaitThread(ThreadType*); } }
void Unk_6733a0(u64);

// 0x71003ffbe0
void Unk_3ffbe0_call(Unk_3ffbe0* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
    self->field_260 = 0;
    nn::os::SignalConditionVariable(reinterpret_cast<nn::os::ConditionVariableType*>(&self->field_200));
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
    if (self->field_50 != 0) {
        nn::os::WaitThread(reinterpret_cast<nn::os::ThreadType*>(&self->field_10));
        nn::os::DestroyThread(reinterpret_cast<nn::os::ThreadType*>(&self->field_10));
        Unk_6733a0(self->field_1d0);
        self->field_1d0 = 0;
    }
}

namespace nn { namespace os { struct MutexType; } }
struct Unk_3ffcb0 {
    u8 _0[0x1e0];
    u8 field_1e0;
    u8 _1e1[0x27];
    u32 field_208;
};
PKMN_OFFSET_ASSERT(Unk_3ffcb0, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_3ffcb0, field_208, 0x208);

namespace nn { namespace os { u64 LockMutex(MutexType*); } }
namespace nn { namespace os { u64 UnlockMutex(MutexType*); } }

// 0x71003ffcb0
void Unk_3ffcb0_call(Unk_3ffcb0* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
    self->field_208 = self->field_208 - 1;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
}

namespace nn { namespace os { struct MutexType; } }
struct Unk_3ffd50 {
    u8 _0[0x1e0];
    u8 field_1e0;
    u8 _1e1[0x2b];
    u32 field_20c;
};
PKMN_OFFSET_ASSERT(Unk_3ffd50, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_3ffd50, field_20c, 0x20c);

namespace nn { namespace os { u64 LockMutex(MutexType*); } }
namespace nn { namespace os { u64 UnlockMutex(MutexType*); } }

// 0x71003ffd50
void Unk_3ffd50_call(Unk_3ffd50* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
    self->field_20c = self->field_20c - 1;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
}

struct Unk_3ffdb0 {
    u8 _0[0x210];
    u8 field_210;
};
PKMN_OFFSET_ASSERT(Unk_3ffdb0, field_210, 0x210);

// 0x71003ffdb0
void Unk_3ffdb0_set(Unk_3ffdb0* self) {
    self->field_210 = 1;
}

namespace nn { namespace os { struct MutexType; } }
struct Unk_3ffdc0 {
    u8 _0[0x1e0];
    u8 field_1e0;
    u8 _1e1[0x33];
    u32 field_214;
};
PKMN_OFFSET_ASSERT(Unk_3ffdc0, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_3ffdc0, field_214, 0x214);

namespace nn { namespace os { u64 LockMutex(MutexType*); } }
namespace nn { namespace os { u64 UnlockMutex(MutexType*); } }

// 0x71003ffdc0
void Unk_3ffdc0_call(Unk_3ffdc0* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
    self->field_214 = self->field_214 + 1;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
}

namespace nn { namespace os { struct ConditionVariableType; } }
namespace nn { namespace os { struct MutexType; } }
struct Unk_3ffe00 {
    u8 _0[0x1e0];
    u8 field_1e0;
    u8 _1e1[0x1f];
    u8 field_200;
    u8 _201[0x13];
    u32 field_214;
};
PKMN_OFFSET_ASSERT(Unk_3ffe00, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_3ffe00, field_200, 0x200);
PKMN_OFFSET_ASSERT(Unk_3ffe00, field_214, 0x214);

namespace nn { namespace os { u64 LockMutex(MutexType*); } }
namespace nn { namespace os { u64 SignalConditionVariable(ConditionVariableType*); } }
namespace nn { namespace os { u64 UnlockMutex(MutexType*); } }

// 0x71003ffe00
void Unk_3ffe00_call(Unk_3ffe00* self) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
    self->field_214 = self->field_214 - 1;
    nn::os::SignalConditionVariable(reinterpret_cast<nn::os::ConditionVariableType*>(&self->field_200));
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_1e0));
}
