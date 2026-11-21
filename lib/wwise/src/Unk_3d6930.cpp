// Scope: common
// What changes a source's speed (vtable 0x7102384858): the state at 0x10
// and two buffers. Written from the executable. Placeholder names.
#include "Unk_2384858.h"

#include <math.h>

// 0x71003d6930
void Unk_3d6930(Unk_2384858_T* self) {
    if (self->field_a8.field_0 != nullptr) {
        Unk_390500_call(reinterpret_cast<Unk_390500*>(&self->field_a8));
        // ClearAll() with the state's count reset before its last two stores.
        self->field_a8.field_c = 0x2b;
        self->field_a8.field_10 = 0;
        self->field_a8.field_12 = 0;
        self->field_a8.field_18 = 0;
        self->field_a8.field_20 = 0xffffffff;
        self->field_a8.field_24 = 1.0f;
        self->field_a8.field_0 = nullptr;
        self->field_a8.field_14 = 0;
        self->field_10.field_2c = 0;
        self->field_a8.field_28 = 0xffffffff;
        self->field_a8.field_2c = 1;
    }
}

// 0x71003d6bd0
u32 Unk_3d6bd0(Unk_2384858_T* self, u32 arg1, bool arg2) {
    if (arg1 == 1)
        self->field_70.field_12 = 0;
    if (self->field_f0)
        return 1;
    return self->field_8->vf6(arg1, arg2);
}

// 0x71003d6c00
u32 Unk_3d6c00(Unk_2384858_T* self) {
    self->field_8->vf3();
    Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_70));
    self->field_70.Clear();
    Unk_3d7680_set(reinterpret_cast<Unk_3d7680*>(&self->field_10));
    if (self->field_f0)
        return 1;
    return self->field_8->vf7();
}

// 0x71003d6ca0
void Unk_3d6ca0(Unk_2384858_T* self) {
    if (self->field_a8.field_0 != nullptr) {
        Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_a8));
        Unk_390500_call(reinterpret_cast<Unk_390500*>(&self->field_a8));
    }
    Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_70));
    self->field_e8 = nullptr;
    Unk_3d7690_call(reinterpret_cast<const Unk_3d7690*>(&self->field_10));
}

// 0x71003d6d10: the destructor
void Unk_3d6d10(Unk_2384858_T* self) {
    self->field_0 = Unk_2384858 + 2;
    Unk_3d6da0_update(reinterpret_cast<u64>(&self->field_10));
}

// 0x71003d6d30: the deleting destructor
void Unk_3d6d30(Unk_2384858_T* self) {
    self->field_0 = Unk_2384858 + 2;
    Unk_3d6da0_update(reinterpret_cast<u64>(&self->field_10));
    operator delete(self);
}

// 0x71003d6db0
f32 Unk_3d6db0(Unk_2384858_State* self) {
    return self->field_34 * (1.0f / 65536.0f) / self->field_54;
}

// 0x71003d6320: samples are asked for
void Unk_3d6320(Unk_2384858_T* self, Unk_3dd7b0_Buffer* buffer) {
    u32 count = buffer->field_10;
    Unk_2384858_Prev* prev = self->field_8;
    self->field_f1 = false;
    self->field_10.field_44 = count;
    f32 pitch = prev->vf8();
    Unk_3d71c0(&self->field_10, self->field_e8->field_26b_30 == 0, pitch);
    if (self->field_70.field_12 != 0) {
        Unk_3d63c0(self, buffer);
        return;
    }
    if (self->field_f0)
        buffer->field_30 = 0x11;
}

// 0x71003d6b20
void Unk_3d6b20(Unk_2384858_T* self, u32 arg1) {
    if (arg1 != 2) {
        if (self->field_70.field_0 != nullptr)
            self->field_8->vf3();
        Unk_390440_set(reinterpret_cast<Unk_390440*>(&self->field_70));
        self->field_70.Clear();
        Unk_3d7680_set(reinterpret_cast<Unk_3d7680*>(&self->field_10));
        if (arg1 == 0)
            self->field_f0 = false;
    }
    if (!self->field_f0)
        self->field_8->vf5(arg1);
}

// Samples and what they are (0x14 bytes), and what a buffer has after them.
struct Unk_3d7350_Base {
    Unk_3d7350_Base() {}

    void* field_0;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u16 field_12;
};
struct Unk_3d7350_Buffer : Unk_3d7350_Base {
    u16 field_14;
    u8 _16[2];
    u64 field_18;
    u32 field_20;
    f32 field_24;
    u32 field_28;
    u32 field_2c;
};
PKMN_SIZE_ASSERT(Unk_3d7350_Buffer, 0x30);

u32 Unk_390480(void* buffer, u16 count, u32 config);
void Unk_3da1d0(Unk_3d7350_Buffer* self, Unk_3d7350_Buffer* to);

// 0x71003d7350: the samples of a buffer go to memory of its own
u32 Unk_3d7350(void* /*self*/, Unk_3d7350_Buffer* buffer) {
    Unk_3d7350_Buffer copy = *buffer;
    u32 result = Unk_390480(&copy, buffer->field_10, buffer->field_8);
    if (result != 1)
        return result;
    copy.field_12 = buffer->field_12;
    Unk_3da1d0(buffer, &copy);
    Unk_390500_call(reinterpret_cast<Unk_390500*>(buffer));
    static_cast<Unk_3d7350_Base&>(*buffer) = copy;
    return 1;
}

// 0x71003d75b0: makes samples until there are enough or none are left
u32 Unk_3d75b0(Unk_2384858_State* self, Unk_3dd7b0_Buffer* in, Unk_3dd7b0_Buffer* out) {
    if (in->field_12 == 0)
        return 0x11;
    u32 result;
    do {
        result = Unk_23848b8[self->field_50][self->field_5c](in, out, self->field_44, self);
        if (self->field_50 == 2 && self->field_3c >= 0x400) {
            self->field_34 = self->field_38;
            self->field_50 = 1;
        }
    } while (in->field_12 != 0 && out->field_12 < self->field_44);
    return result;
}

// The step for a pitch in cents: 0x10000 when a sample is played for a sample.
static inline u32 Unk_3d76c0_Step(f32 rate, f32 pitch) {
    u32 step = static_cast<u32>(rate * 65536.0f * powf(2.0f, pitch / 1200.0f) + 0.5);
    if (step == 0)
        step = pitch > 0.0f ? 0xffffffff : 1;
    return step;
}

// 0x71003d76c0: the pitch (in cents) the samples are played with
void Unk_3d76c0(Unk_2384858_State* self, f32 pitch) {
    if (self->field_5f || self->field_58 != pitch) {
        u32 step = Unk_3d76c0_Step(self->field_54, pitch);
        self->field_34 = step;
        self->field_38 = step;
        self->field_3c = 0x400;
        self->field_58 = pitch;
        self->field_5f = false;
    }
}

// 0x71003d71c0: the pitch it goes to, in 0x400 samples
void Unk_3d71c0(Unk_2384858_State* self, bool arg1, f32 pitch) {
    if (self->field_5f)
        Unk_3d76c0(self, pitch);
    if (self->field_58 != pitch) {
        if (self->field_50 == 2) {
            u32 step = self->field_34 +
                       static_cast<s32>((self->field_38 - self->field_34) * self->field_3c) / 1024;
            if (step == 0)
                step = 1;
            self->field_34 = step;
        }
        f32 rate = self->field_54;
        self->field_3c = 0;
        self->field_38 = Unk_3d76c0_Step(rate, pitch);
        self->field_58 = pitch;
        if (!arg1)
            self->field_34 = self->field_38;
    }
    if (self->field_34 != self->field_38)
        self->field_50 = 2;
    else if (self->field_38 == 0x10000)
        self->field_50 = 0;
    else
        self->field_50 = 1;
}

// 0x71003d7190
bool Unk_3d7190(Unk_2384858_State* self) {
    if (self->field_50 == 0) {
        if (self->field_5d >= 3) {
            if (self->field_5c >= 4 && self->field_5c <= 7)
                return false;
            return true;
        }
    }
    return false;
}
