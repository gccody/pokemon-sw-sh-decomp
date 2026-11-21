// Scope: common
// Wwise's audio manager (Unk_3358b0.h). Placeholder names.
#include "Unk_3358b0.h"

#include <string.h>

// 0x71003358b0
void Unk_3358b0(Unk_3358b0_T* self) {
    self->field_0.field_10 = nullptr;
    self->field_28.field_0 = nullptr;
    self->field_28.field_8 = nullptr;
    self->field_28.field_10 = nullptr;
    self->field_28.field_18 = nullptr;
    self->field_28.field_20 = 0;
    self->field_28.field_24 = 0;
    self->field_50.field_0 = nullptr;
    self->field_50.field_8 = nullptr;
    self->field_50.field_10 = nullptr;
    self->field_50.field_18 = nullptr;
    self->field_50.field_20 = 0;
    self->field_50.field_24 = 0;
    self->field_78 = 0;
    self->field_7c = 0;
    Unk_334a10(&self->field_80);
    self->field_88 = 0;
    self->field_90 = 0;
    self->field_94 = 0;
    self->field_98 = 0;
    self->field_a0.field_0 = nullptr;
    self->field_a0.field_8 = 0;
    self->field_a0.field_c = 0;
}

// 0x7100335940
u32 Unk_335940(Unk_3358b0_T* self) {
    u32 result = self->field_0.Init(Unk_237e820, Unk_24bbc30.field_14);
    if (result == 1) {
        result = self->field_28.Init(0x20);
        if (result == 1)
            result = self->field_50.Init(0x20);
    }
    self->field_88 = nn::os::GetSystemTick().field_0;
    return result;
}

// 0x7100335a60
void Unk_335a60(Unk_3358b0_T* self) {
    Unk_335c40(self);
    Unk_335df0(self);
    Unk_335f00(self);
    self->field_0.Term(Unk_237e820);
    self->field_28.Term();
    self->field_50.Term();
}

void Unk_38fcb0(void* self, u32 id);
extern void* Unk_24bbc08;

// Drops the actions of a list.
template <class L>
__attribute__((always_inline)) static inline void Unk_335df0_Flush(L& list) {
    auto it = list.BeginEx();
    while (it.item != nullptr) {
        Unk_3358b0_Action* action = it.item->item.field_8;
        Unk_3358b0_Params params;
        params.field_0 = 0;
        Unk_3358b0_Obj* obj = action->field_8;
        if (obj->field_34 == 0x503) {
            Unk_341ca0_get(reinterpret_cast<const Unk_341ca0*>(obj));
            action->field_8->vf11(&params);
        } else if (obj->field_34 == 0x403) {
            obj->vf11(&params);
        }
        Unk_38fcb0(Unk_24bbc08, action->field_30);
        it = list.Erase(it);
        action->field_8->vf3();
        int pool = Unk_237e820;
        action->vf1();
        Unk_3047c0(pool, action);
    }
}

// NON_MATCHING: the original tests the type 0x503 before 0x403, in two branches and a jump
// 0x7100335df0
void Unk_335df0(Unk_3358b0_T* self) {
    Unk_335df0_Flush(self->field_50);
}

// NON_MATCHING: as Unk_335df0
// 0x7100335f00
void Unk_335f00(Unk_3358b0_T* self) {
    Unk_335df0_Flush(self->field_28);
}

// 0x7100336010
u32 Unk_336010(Unk_3358b0_T* self, bool a1) {
    u8* read = self->field_0.field_0;
    u8* write = self->field_0.field_8;
    if (read != write) {
        Unk_336100(self, 0, 4);
        __sync_fetch_and_sub(&self->field_94, 1);
        for (u32 i = 0; self->field_94 > 0; i++) {
            nn::TimeSpan time;
            time.field_0 = static_cast<s64>(i >> 7) * 1000000;
            nn::os::SleepThread(time);
        }
        __sync_synchronize();
        __sync_fetch_and_add(&self->field_7c, 1);
    }
    if (!Unk_24bbc30.field_45 && a1)
        Unk_336510(reinterpret_cast<Unk_336510_T*>(self));
    else if (read != write)
        self->field_80.Unk_334a30();
    return 1;
}
