// Scope: common
//
// Functions of Unk_2403c30 (vtable 0x7102403c40, on Unk_24034f8: its type's
// parent is Unk_24034f8's) in the link battle app's area. Its class is declared
// by tools/typegen.py (src/unsorted/types/Unk_fd3160.cpp) without its real base,
// so its slots are written here as free functions over the base, and its
// destructors (0x7100fd2fe0, 0x7100fd30a0 and their thunks) aren't written yet.
// Placeholder names: rename once the classes are known.
#include <functional>

#include <types.h>

#include "unsorted/Unk_24034f8.h"

class Unk_2403c30;

// Untyped callees: placeholders.
u32 Unk_eb6530(void*);
void Unk_fcd090(void* self);
void Unk_67d450(Unk_239a418* target, u64* hash, Unk_239a418* object);
void Unk_fcd0e0(Unk_24034f8* self,
                s32 index,
                std::function<void(Unk_239a418_Ref<Unk_239a418>)> callback);
void Unk_fcd190(Unk_24034f8* self);
void Unk_fd28e0(Unk_2403c30* self, const u64& flag);

// 0x7100fd2ea0
// Sets the callbacks of slots 1 and 0 (mode 0) or slot 1 (mode 1), each
// handing what it's given to Unk_67d450 with the object at +0x5d0 and a hash;
// the std::functions' D0s are 0x7100fd3750, 0x7100fd3840 and 0x7100fd3930,
// their calls 0x7100fd37e0, 0x7100fd38d0 and 0x7100fd39c0.
void Unk_fd2ea0(Unk_24034f8* self, s32 mode) {
    switch (mode) {
        case 0:
            Unk_fcd0e0(self, 1, [self](Unk_239a418_Ref<Unk_239a418> object) {
                u64 hash = 0x4cd3ae07141d9bb7;
                Unk_67d450(self->field_5d0.m_ptr, &hash, object.m_ptr);
            });
            Unk_fcd0e0(self, 0, [self](Unk_239a418_Ref<Unk_239a418> object) {
                u64 hash = 0x4cd3b007141d9f1d;
                Unk_67d450(self->field_5d0.m_ptr, &hash, object.m_ptr);
            });
            break;
        case 1:
            Unk_fcd0e0(self, 1, [self](Unk_239a418_Ref<Unk_239a418> object) {
                u64 hash = 0x4cd3ae07141d9bb7;
                Unk_67d450(self->field_5d0.m_ptr, &hash, object.m_ptr);
            });
            break;
        default:
            return;
    }
    Unk_fcd190(self);
}

// 0x7100fd2fa0
// Slot 18.
u32 Unk_fd2fa0(Unk_24034f8* self) {
    return ~Unk_eb6530(self) & 1;
}

// 0x7100fd2fc0
// Slot 19.
void Unk_fd2fc0(Unk_24034f8* self) {
    if (self->field_5f0->field_58 & 1) {
        Unk_fcd090(self);
    }
}

// The flags they hand it.
static const u64 Unk_fd3650_flag = 0x80000000;
static const u64 Unk_fd3690_flag = 0x20000000;
static const u64 Unk_fd36d0_flag = 0x400000000;
static const u64 Unk_fd3710_flag = 0x1000000000000;

// The callables that hand Unk_fd28e0 one flag each.
struct Unk_fd3650 {
    Unk_2403c30* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3650, field_0, 0x0);

// 0x7100fd3650
void Unk_fd3650_call(const Unk_fd3650* self) {
    Unk_fd28e0(self->field_0, Unk_fd3650_flag);
}

// 0x7100fd3690
void Unk_fd3690_call(const Unk_fd3650* self) {
    Unk_fd28e0(self->field_0, Unk_fd3690_flag);
}

// 0x7100fd36d0
void Unk_fd36d0_call(const Unk_fd3650* self) {
    Unk_fd28e0(self->field_0, Unk_fd36d0_flag);
}

// 0x7100fd3710
void Unk_fd3710_call(const Unk_fd3650* self) {
    Unk_fd28e0(self->field_0, Unk_fd3710_flag);
}
