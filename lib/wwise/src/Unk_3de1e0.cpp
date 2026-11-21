// Scope: common
// Sources on the stream source (0x7102384080) and on the class of
// 0x7102383f80: small functions. Written from the executable. Placeholder
// names.
#include "Unk_2384080.h"

extern int Unk_2381488;
extern void* _ZTV11Unk_23850d8[];
extern void* _ZTV11Unk_23851d8[];

u32 Unk_3047c0(int poolId, void* ptr);
void Unk_3cbca0(Unk_2383f80* self);
void Unk_3cbcd0(void* self);
void Unk_3ccad0(Unk_2384080* self);
u32 Unk_3cccd0(Unk_2384080* self, u32 arg1);
u32 Unk_3cd0c0(Unk_2384080* self);
u32 Unk_304740(int poolId, void* ptr);
u32 Unk_3cc0e0(Unk_2383f80* self);
void Unk_3cc3a0(void* self);

// The stream sources with more of their own: bytes they keep and what is
// still to skip.
class Unk_3de1e0_T : public Unk_2384080 {
public:
    u32 field_84;
    void* field_88;
    u32 field_90;
    u32 field_94;
    u16 field_98;

    void FreeKept() {
        if (field_88 != nullptr) {
            Unk_3047c0(Unk_2381488, field_88);
            field_88 = nullptr;
            field_90 = 0;
        }
    }
};
PKMN_OFFSET_ASSERT(Unk_3de1e0_T, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_3de1e0_T, field_98, 0x98);

// The class with the vtable 0x71023850d8: its samples are in the sound's
// data.
class Unk_23850d8_T : public Unk_2383f80 {
public:
    u8* field_58;
    u16 field_60;
};
PKMN_OFFSET_ASSERT(Unk_23850d8_T, field_60, 0x60);

static inline Unk_3dd7b0_T* Unk_3de1e0_Virtual(void* self) {
    return static_cast<Unk_3dd7b0_T*>(self);
}

// 0x71003de1e0
void Unk_3de1e0(Unk_3de1e0_T* self) {
    self->FreeKept();
    Unk_3ccad0(self);
}

// 0x71003de500: skips what was to skip
void Unk_3de500(Unk_3de1e0_T* self) {
    u32 skip = self->field_94;
    self->field_68 -= skip;
    self->field_60 += skip;
    self->field_94 = 0;
    if (self->field_68 == 0) {
        if (self->field_82_1)
            self->field_82_1 = 0;
        else
            self->field_58->vf17();
    }
}

// 0x71003de550
u32 Unk_3de550(Unk_3de1e0_T* self, u32 arg1) {
    if (arg1 <= 1)
        self->FreeKept();
    return Unk_3cccd0(self, arg1);
}

// 0x71003de770
u32 Unk_3de770(Unk_3de1e0_T* self, u32 arg1, u32* result1, u32* result2) {
    *result1 = arg1;
    *result2 = self->field_30 + Unk_3de1e0_Virtual(self)->vf32() * arg1;
    return 1;
}

// 0x71003de7d0
u32 Unk_3de7d0(Unk_3de1e0_T* self) {
    self->field_94 = 0;
    self->FreeKept();
    return Unk_3cd0c0(self);
}

// 0x71003de870: the destructor of the class with the vtable 0x71023850d8
void Unk_3de870(Unk_23850d8_T* self) {
    self->field_0 = _ZTV11Unk_23850d8 + 2;
    Unk_3cbca0(self);
}

// 0x71003de890: its deleting destructor
void Unk_3de890(Unk_23850d8_T* self) {
    self->field_0 = _ZTV11Unk_23850d8 + 2;
    Unk_3cbca0(self);
    operator delete(self);
}

// 0x71003dea90
u32 Unk_3dea90(Unk_23850d8_T* self, u64 arg1, u64 arg2) {
    self->field_58 = self->field_58 + arg1 - arg2;
    return 1;
}

// 0x71003deab0
void Unk_3deab0(Unk_23850d8_T* self) {
    Unk_3de1e0_Virtual(self)->vf3();
    Unk_3cbcd0(self);
}

// 0x71003dec70: back to where it starts; one loop less
u32 Unk_3dec70(Unk_23850d8_T* self, bool last) {
    u32 frame = self->field_28 >> 6;
    self->field_58 = self->field_18->field_290 + self->field_30 + frame * self->field_60;
    if (self->field_54 > 1)
        self->field_54--;
    return last ? 0x11 : 0x2d;
}

// 0x71003df550
void Unk_3df550(Unk_3de1e0_T* self) {
    Unk_3de1e0_Virtual(self)->vf3();
    Unk_3ccad0(self);
}

// 0x71003df5c0
u32 Unk_3df5c0(Unk_3de1e0_T* self, u32 arg1) {
    u32 result = Unk_3cccd0(self, arg1);
    if (arg1 <= 1)
        self->field_98 = 0;
    return result;
}

// 0x71003df820
u32 Unk_3df820(Unk_3de1e0_T* self, u32 arg1, u32* result1, u32* result2) {
    u32 blocks = arg1 >> 6;
    *result1 = blocks << 6;
    *result2 = self->field_30 + self->field_84 * blocks;
    return 1;
}

// 0x71003df850
u32 Unk_3df850(Unk_3de1e0_T* self) {
    self->field_98 = 0;
    return Unk_3cd0c0(self);
}

// 0x71003dedd0: where the playing context says it is, in whole blocks of 64
u32 Unk_3dedd0(Unk_23850d8_T* self) {
    if (self->field_18->field_26b_22) {
        u32 position = Unk_3cc0e0(self);
        self->field_28 = position & ~0x3fu;
        self->field_18->SetSeek(position - self->field_28);
        if (self->field_28 >= self->field_24)
            return 2;
        u32 frame = self->field_28 >> 6;
        self->field_58 = self->field_18->field_290 + self->field_30 + frame * self->field_60;
    }
    return 1;
}

// The stream source with the vtable 0x71023851d8: two blocks of memory.
class Unk_23851d8_T : public Unk_2384080 {
public:
    u32 field_84;
    void* field_88;
    void* field_90;
};
PKMN_OFFSET_ASSERT(Unk_23851d8_T, field_90, 0x90);

static inline void Unk_3df070_Dtor(Unk_23851d8_T* self) {
    self->field_0 = _ZTV11Unk_23851d8 + 2;
    if (self->field_88 != nullptr) {
        Unk_304740(Unk_2381488, self->field_88);
        self->field_88 = nullptr;
    }
    if (self->field_90 != nullptr)
        Unk_3047c0(Unk_2381488, self->field_90);
    Unk_3cc3a0(self);
}

// 0x71003df070: its destructor
void Unk_3df070(Unk_23851d8_T* self) {
    Unk_3df070_Dtor(self);
}

// 0x71003df0e0: and its deleting destructor
void Unk_3df0e0(Unk_23851d8_T* self) {
    Unk_3df070_Dtor(self);
    operator delete(self);
}
