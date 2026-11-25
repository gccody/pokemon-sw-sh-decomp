// Scope: common
// More of Unk_241c218's functions (src/contents/pokecamp/source/
// Unk_1172690.h): what it forwards to its target, the weak reference it
// prefers, and the request it keeps (+0xb0..+0xd0) with its transform
// (+0xe0..+0x110). Placeholder names.
#include "contents/pokecamp/source/Unk_1172690.h"

struct Unk_1174cb0;

bool Unk_1174640(Unk_241c3c0* self);
void Unk_1174910(Unk_241c3c0* self, const Unk_241c218_Pair& arg);
void Unk_11744a0(Unk_241c3c0* self, u32 value);
u32 Unk_1174cb0_getField350(const Unk_1174cb0* self);
void Unk_112e920(Unk_239a418* self, const Unk_241c218_Pair& arg);
void Unk_1160e20(Unk_239a418* self, const Unk_241c218_Pair& id, u32 arg);

// 0x7101172eb0
void Unk_1172eb0(Unk_241c218_Self* self, const Unk_241c218_Pair& arg) {
    {
        Unk_239a418_Ref<Unk_241c3c0> target = Unk_11719d0(self->field_88);
        if (target.m_ptr != nullptr && Unk_1174640(target.m_ptr)) {
            if (self->field_198) {
                self->field_198 = false;
                Unk_112e920(target.m_ptr, self->field_1a0);
            }
            Unk_1174910(target.m_ptr, arg);
        }
    }
    self->field_88.Reset();
}

// 0x7101172f50
void Unk_1172f50(Unk_241c218_Self* self, const Unk_239a418_Ref<Unk_239a418_Handle>& handle) {
    Unk_241c218_Assign(self->field_98, handle);
}

// 0x7101172fb0
void Unk_1172fb0(const Unk_241c218_Self* self) {
    Unk_239a418_Ref<Unk_241c3c0> target = Unk_11719d0(self->field_88);
    if (target.m_ptr != nullptr) {
        Unk_241c218_Pair id;
        id.field_0 = 0x275dbcecced052c0;
        id.field_8 = 0;
        Unk_1160e20(target.m_ptr, id, 0);
    }
}

// 0x7101173020
u32 Unk_1173020(const Unk_241c218_Self* self) {
    Unk_239a418_Ref<Unk_241c3c0> target = Unk_11719d0(self->field_88);
    if (target.m_ptr == nullptr)
        return 7;
    return Unk_1174cb0_getField350(reinterpret_cast<const Unk_1174cb0*>(target.m_ptr));
}

// 0x7101173090
void Unk_1173090(const Unk_241c218_Self* self, u32 value) {
    Unk_239a418_Ref<Unk_241c3c0> target = Unk_11719d0(self->field_88);
    if (target.m_ptr != nullptr)
        Unk_11744a0(target.m_ptr, value);
}

// 0x71011730e0
void Unk_11730e0(Unk_241c218_Self* self) {
    self->field_e0 = {};
    self->field_f0 = Unk_1f07bd0;
    self->field_100 = Unk_1f07af0;
}

// 0x7101173110
void Unk_1173110(Unk_241c218_Self* self, void* arg, const Unk_241c218_Pair& pair, u32 value) {
    self->field_b8 = pair.field_8;
    self->field_b0 = pair.field_0;
    self->field_c0 = value;
    self->field_c8 = arg;
    self->field_d0.Reset();
    Unk_11730e0(self);
}

// 0x71011731a0
void Unk_11731a0(Unk_241c218_Self* self,
                 const Unk_241c218_Ref& ref,
                 const Unk_241c218_Pair& pair,
                 u32 value) {
    self->field_b8 = pair.field_8;
    self->field_b0 = pair.field_0;
    self->field_c0 = value;
    self->field_c8 = nullptr;
    self->field_d0 = ref;
    Unk_11730e0(self);
}

// 0x7101173280
void Unk_1173280(Unk_241c218_Self* self) {
    self->field_b8 = 0;
    self->field_b0 = 0;
    self->field_c0 = 2;
    self->field_c8 = nullptr;
    self->field_d0.Reset();
    Unk_11730e0(self);
}
