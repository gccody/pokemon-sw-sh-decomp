// Scope: common
// Loading and releasing the holders of Unk_277a1a0, and Unk_23a7b38's
// constructor, its setter and its first accessors (src/unsorted/unk_761f70/
// Unk_7814e0.h).
#include "unsorted/unk_761f70/Unk_7814e0.h"

#include "unsorted/Unk_23f4660.h"

// The name of the data of holder `index` (0x710076cc90, not decompiled).
Unk_23f4660_Name Unk_76cc90(s32 index);
// Loads the data `name` names (0x71005dd790, not decompiled).
Unk_239a418_Ref<Unk_7814e0_Data> Unk_5dd790(void* loader,
                                            u32 arg1,
                                            const Unk_23f4660_Name& name,
                                            u32 arg3,
                                            void* heap,
                                            void* arg5);
// Registers a holder of the object with it (0x71005e2930, not decompiled).
void Unk_5e2930(Unk_239a418* object, void* holder, bool arg);
void Unk_5e26a0(void* object);

// What loads the data (0x71024ba738).
extern void* Unk_24ba738;

namespace {

void Unk_Assign(Unk_239a418_Ref<Unk_7814e0_Data>& to, Unk_239a418_Ref<Unk_7814e0_Data>&& from) {
    if (to.m_ptr) {
        static_cast<Unk_239a458*>(to.m_ptr)->vf5();
        to.m_ptr = nullptr;
    }
    to.m_ptr = from.Release();
}

}  // namespace

// Loads the data `name` names and registers with it: as a holder of it when
// either callable is set.
inline void Unk_277a1a0_Entry::Unk_Load(const Unk_23f4660_Name& name, void* heap) {
    Unk_Assign(field_8, Unk_5dd790(Unk_24ba738, 0, name, 0, heap, nullptr));
    Unk_239a418_Ref<Unk_7814e0_Data> data(field_8);
    if (data.m_ptr) {
        if (field_10.field_0 || field_90.field_0)
            Unk_5e2930(data.m_ptr, this, true);
        Unk_5e26a0(data.m_ptr);
    }
}

// 0x71007814e0
// NON_MATCHING: register allocation. The original keeps the object's +0x48
// interface pointer in x22 and the object in x23 (and drops the copy through
// the interface pointer); this swaps them and drops it through [object, #0x48].
void Unk_7814e0(void* heap) {
    for (s32 i = 0; i < 0x31d; ++i)
        Unk_277a1a0[i].Unk_Load(Unk_76cc90(i), heap);
}

// 0x7100781640
void Unk_781640() {
    for (s32 i = 0; i < 0x31d; ++i)
        Unk_277a1a0[i].Unk_Release();
}

// 0x71007816b0
Unk_23a7b38::Unk_23a7b38() : field_8(0) {}

// 0x71007816f0
void Unk_23a7b38::Unk_7816f0(s32 index) {
    field_8 = index > 0x31c ? 0 : index;
}

// 0x7100781700
bool Unk_23a7b38::Unk_781700() const {
    return Unk_Root()->Get<u8>(8, 0) != 0;
}

// 0x7100781760
u8 Unk_23a7b38::Unk_781760() const {
    return Unk_Root()->Get<u8>(10, 0);
}

// 0x71007817c0
u8 Unk_23a7b38::Unk_7817c0() const {
    return Unk_Root()->Get<u8>(12, 0);
}

// 0x7100781820
u8 Unk_23a7b38::Unk_781820() const {
    return Unk_Root()->Get<u8>(14, 0);
}

// 0x7100781880
u8 Unk_23a7b38::Unk_781880() const {
    return Unk_Root()->Get<u8>(16, 0);
}

// 0x71007818e0
u8 Unk_23a7b38::Unk_7818e0() const {
    u8 value = Unk_Root()->Get<u8>(18, 0);
    return value == 101 ? 100 : value;
}

// 0x7100781940
bool Unk_23a7b38::Unk_781940() const {
    return Unk_Root()->Get<u8>(18, 0) == 101;
}

// 0x71007819a0
u8 Unk_23a7b38::Unk_7819a0() const {
    return Unk_Root()->Get<u8>(20, 0);
}

// 0x7100781a00
s32 Unk_23a7b38::Unk_781a00() const {
    return Unk_Root()->Get<s8>(22, 0);
}

// 0x7100781a60
u8 Unk_23a7b38::Unk_781a60() const {
    return Unk_Root()->Get<u8>(38, 0);
}
