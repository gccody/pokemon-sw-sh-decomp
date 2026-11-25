// Scope: common
// The battle scene's scene (unsorted/Unk_98a420.h): functions on what its
// +0x38 and +0x58 objects lead to, and how they get there. Placeholder names
// and types: rename and move once the classes are known.
#include <nn/os.h>
#include <types.h>

#include "unsorted/Unk_98a420.h"

void Unk_8ea5d0(u64 self, u64 arg1);
void Unk_8ea650(u64 self, u64 arg1);

// 0x710098a820
void Unk_23c4ef0_Scene::Unk_98a820(u32 arg1) {
    Unk_8ea5d0(reinterpret_cast<u64>(Unk_98ab90(reinterpret_cast<u64>(field_38)) + 0x2f8), arg1);
}

// 0x710098a850
void Unk_23c4ef0_Scene::Unk_98a850(u32 arg1) {
    Unk_8ea650(reinterpret_cast<u64>(Unk_98ab90(reinterpret_cast<u64>(field_38)) + 0x2f8), arg1);
}

void Unk_93a290(void* self);

// 0x710098a8b0
void Unk_23c4ef0_Scene::Unk_98a8b0() {
    Unk_93a290(Unk_98adb0(reinterpret_cast<u64>(field_58)) + 0x30);
}

struct Unk_93a2a0;
void Unk_93a2a0_call(const Unk_93a2a0* self);

// 0x710098a8d0
void Unk_98a8d0(void* scene) {
    const Unk_23c4ef0_Scene* self = static_cast<const Unk_23c4ef0_Scene*>(scene);
    Unk_93a2a0_call(reinterpret_cast<const Unk_93a2a0*>(
        Unk_98adb0(reinterpret_cast<u64>(self->field_58)) + 0x30));
}

// The frame of one of the scene's objects, none without the object.
inline Unk_239a418_Ref<Unk_23f41d0> Unk_98a780_Frame(const Unk_98a950_Self* object) {
    if (object == nullptr)
        return Unk_239a418_Ref<Unk_23f41d0>();
    return Unk_98a950(object);
}

// 0x710098a8f0
void Unk_23c4ef0_Scene::Unk_98a8f0(bool arg1) {
    Unk_239a418_Ref<Unk_23f41d0> frame = Unk_98a780_Frame(field_38);
    if (frame.m_ptr != nullptr)
        frame.m_ptr->field_98 = arg1 ? 2 : 1;
}

Unk_239a418_Ref<Unk_239a418> Unk_672980(u64 object);

// 0x710098a950
Unk_239a418_Ref<Unk_23f41d0> Unk_98a950(const Unk_98a950_Self* self) {
    Unk_239a418_Ref<Unk_239a418> last = Unk_672980(self->field_10);
    Unk_239a498& object = *last.m_ptr;
    if (!Unk_IsKind<Unk_23f41d0>(object.vf_type()))
        return Unk_239a418_Ref<Unk_23f41d0>();
    return Unk_239a418_Ref<Unk_23f41d0>(static_cast<Unk_23f41d0*>(&object));
}

// 0x710098aa50
void Unk_23c4ef0_Scene::Unk_98aa50(u64 flags) {
    Unk_239a418_Ref<Unk_23f41d0> frame = Unk_98a780_Frame(field_38);
    if (frame.m_ptr != nullptr)
        frame.m_ptr->field_220 = flags;
}

// 0x710098aaa0
bool Unk_98aaa0(void* scene, u32 index) {
    return static_cast<const Unk_23c4ef0_Scene*>(scene)->field_20.test(index);
}

// 0x710098aae0
void Unk_23c4ef0_Scene::Unk_98aae0(bool arg1) {
    Unk_239a418_Ref<Unk_23f41d0> frame1 = Unk_98a780_Frame(field_38);
    Unk_239a418_Ref<Unk_23f41d0> frame2 = Unk_98a780_Frame(field_58);
    if (frame1.m_ptr != nullptr)
        frame1.m_ptr->field_e0 = arg1;
    if (frame2.m_ptr != nullptr)
        frame2.m_ptr->field_98 = arg1;
}

Unk_239a418_Ref<Unk_23bdbb0> Unk_14dd2a0(u64 object);

// The object a handle refers to, through its +0x50 interface: null once
// it's gone.
inline Unk_239a498* Unk_98a780_HandleObject(const Unk_239a418_Ref<Unk_239a418_Handle>& handle) {
    Unk_239a418_Handle* p = handle.m_ptr;
    if (p == nullptr)
        return nullptr;
    return reinterpret_cast<Unk_239a498*>(p->field_60);
}

// The object as a T, or null when it isn't one: through its +0x50 interface.
template <class T>
inline T* Unk_98a780_Cast(Unk_239a498* object) {
    if (object == nullptr)
        return nullptr;
    if (!Unk_IsKind<T>(object->vf_type()))
        return nullptr;
    return static_cast<T*>(object);
}

// 0x710098ab90
u8* Unk_98ab90(u64 object) {
    Unk_239a418_Ref<Unk_23bdbb0> owner = Unk_14dd2a0(object);
    Unk_23bdd98* target =
        Unk_98a780_Cast<Unk_23bdd98>(Unk_98a780_HandleObject(owner.m_ptr->field_2c8->vf2()));
    if (target == nullptr)
        nn::diag::detail::AbortImpl("", "", "", 0);
    return &target->field_638;
}
