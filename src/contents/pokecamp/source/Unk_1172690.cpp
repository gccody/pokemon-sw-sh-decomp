// Scope: common
// Unk_241c218's functions on its target (src/contents/pokecamp/source/
// Unk_1172690.h): the weak references to it, its callable, and what it asks of
// the target. Placeholder names.
#include "contents/pokecamp/source/Unk_1172690.h"

#include "gflib3/Unk_Lock.h"

bool Unk_1174640(Unk_241c3c0* self);
void Unk_1174350(u64 self, u32 arg);
Unk_241c3c0* Unk_1173a10(void* self);
bool Unk_11747e0(Unk_241c3c0* self, Unk_239a418_Ref<Unk_27771c8> owner, bool arg);
void Unk_1174a00(Unk_241c3c0* self, Unk_241c218_Callable callable);
float32x4_t Unk_1174b30(Unk_241c3c0* self);

// The owner, locked as an Unk_27771c8.
static Unk_239a418_Ref<Unk_27771c8> Unk_241c218_Owner(const Unk_241c218_Self* self) {
    Unk_239a418_Handle* handle = self->field_68.m_ptr;
    return handle != nullptr ? Unk_Lock<Unk_27771c8>(handle) : Unk_239a418_Ref<Unk_27771c8>();
}

// The +0x98 reference while its object is alive, else the +0x90 one.
static const Unk_239a418_Ref<Unk_239a418_Handle>& Unk_241c218_Current(
    const Unk_241c218_Self* self) {
    return Unk_241c218_IsAlive(self->field_98) ? self->field_98 : self->field_90;
}

// Whether there's a target and it's busy.
static bool Unk_241c218_IsBusy(Unk_239a418_Ref<Unk_241c3c0> target) {
    return target.m_ptr != nullptr && Unk_1174640(target.m_ptr);
}

// 0x7101172690
Unk_239a418_Ref<Unk_239a418_Handle> Unk_1172690(const Unk_241c218_Self* self) {
    return self->field_88;
}

// 0x71011726c0
void Unk_11726c0(Unk_241c218_Self* self, Unk_241c218_Callable callable) {
    self->field_110 = std::move(callable);
}

// 0x7101172730
bool Unk_1172730(const Unk_241c218_Self* self) {
    return Unk_241c218_IsAlive(self->field_90) || Unk_241c218_IsAlive(self->field_98);
}

// 0x7101172950
bool Unk_1172950(u64 self) {
    return Unk_241c218_IsBusy(Unk_11719d0(reinterpret_cast<Unk_241c218_Self*>(self)->field_88));
}

// NON_MATCHING: the busy test after the target is dropped is one block in the
// original, shared by the path that drops it and the one that finds it gone;
// here clang duplicates it into the second (an extra tbnz). The target is a
// by-value argument so that the drop's null store stays, as in the original.
// 0x7101172770
bool Unk_1172770(Unk_241c218_Self* self) {
    if (Unk_241c218_IsBusy(Unk_11719d0(self->field_88)))
        return false;
    Unk_241c3c0* target = Unk_1173a10(self->field_80.m_ptr);
    if (target == nullptr)
        return false;
    Unk_11747e0(target, Unk_241c218_Owner(self), true);
    self->field_88 = target->vf2();
    return true;
}

// 0x71011729e0
bool Unk_11729e0(Unk_241c218_Self* self, bool arg) {
    Unk_239a418_Ref<Unk_239a418_Handle> handle(Unk_241c218_Current(self));
    if (Unk_241c218_IsAlive(self->field_88))
        return false;
    Unk_239a418_Ref<Unk_241c3c0> target = Unk_11719d0(handle);
    if (target.m_ptr == nullptr)
        return false;
    if (!Unk_11747e0(target.m_ptr, Unk_241c218_Owner(self), arg))
        return false;
    Unk_241c218_Assign(self->field_88, handle);
    return true;
}

// 0x7101172c40
bool Unk_1172c40(Unk_241c218_Self* self, Unk_241c218_Callable callable) {
    if (!Unk_11729e0(self, false))
        return false;
    Unk_1174a00(Unk_11719d0(self->field_88).m_ptr, std::move(callable));
    self->field_88.Reset();
    return true;
}

// 0x7101172d30
Unk_239a418_Ref<Unk_239a418_Handle> Unk_1172d30(const Unk_241c218_Self* self) {
    return Unk_241c218_Current(self);
}

// 0x7101172d80
float32x4_t Unk_1172d80(const Unk_241c218_Self* self) {
    Unk_239a418_Ref<Unk_239a418_Handle> handle(Unk_241c218_Current(self));
    Unk_239a418_Ref<Unk_241c3c0> target = Unk_11719d0(handle);
    if (target.m_ptr == nullptr)
        return float32x4_t{0.0f, 0.0f, 0.0f, 0.0f};
    return Unk_1174b30(target.m_ptr);
}

// 0x7101172e40
void Unk_1172e40(Unk_241c218_Self* self) {
    {
        Unk_239a418_Ref<Unk_241c3c0> target = Unk_11719d0(self->field_88);
        if (target.m_ptr != nullptr)
            Unk_1174350(reinterpret_cast<u64>(target.m_ptr), 0);
    }
    self->field_88.Reset();
}
