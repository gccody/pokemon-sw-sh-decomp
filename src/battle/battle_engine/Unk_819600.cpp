// Scope: common
// What the battle's event handlers are given (0x7100819600 to 0x710081c430):
// the main module (+0, +8), the Pokemon (+0x10), the battle's state (+0x20),
// the event system (+0x30) and the handler (+0x40). Each function asks one of
// them. Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_7e8a20.h"
#include "battle/battle_engine/Unk_7ee6b0.h"

struct Unk_7fe1d0;
struct Unk_7fe1e0;
struct Unk_7fe250;
struct Unk_7fe350;
struct Unk_7ecc90_Con;
struct Unk_7c2d80_Main;

struct Unk_819600_Self {
    const Unk_7c2d80_Main* field_0;
    const Unk_7fe1d0* field_8;
    const void* field_10;
    const void* field_18;
    const void* field_20;
    u8 _28[0x30 - 0x28];
    Unk_7e8a20* field_30;
    u8 _38[0x40 - 0x38];
    void* field_40;
};
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_40, 0x40);

// The main module's getters of single fields: leaf functions with their own
// placeholder types (src/unsorted/leaf).
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
Unk_7ee6b0_Field* Unk_7fe1e0_getField28(const Unk_7fe1e0* self);
void* Unk_7fe250_getFielda8(const Unk_7fe250* self);
void* Unk_7fe350_getField2a8(const Unk_7fe350* self);
Unk_7ee6b0* Unk_7ecc90(Unk_7ecc90_Con* self, u8 pokeId);
Unk_7ee6b0* Unk_7ed1e0(Unk_7ecc90_Con* self, u8 pokeId);
struct Unk_7ffaf0;
u8 Unk_7ffaf0_getField10(const Unk_7ffaf0* self);
struct Unk_8003c0;
u8 Unk_8003c0_getField11(const Unk_8003c0* self);
struct Unk_7ffaa0;
u8 Unk_7ffaa0_getField0(const Unk_7ffaa0* self);
struct Unk_7e9a70;
void Unk_7e9a70_setField28(Unk_7e9a70* self, u64 value);
struct Unk_7e9a80;
void Unk_7e9a80_clearField28(Unk_7e9a80* self);
struct Unk_7ca1c0;
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);
struct Unk_7c58b0;
u32 Unk_7c58b0_get(const Unk_7c58b0* self);
struct Unk_7eef40;
u16 Unk_7eef40_getField70(const Unk_7eef40* self);
struct Unk_7f09c0;
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);

// The battle state's getters (src/unsorted/leaf/Unk_828420.cpp and others).
struct Unk_828cf0;
void* Unk_828cf0_getField11e0(const Unk_828cf0* self);
struct Unk_828d00;
void* Unk_828d00_getField1200(const Unk_828d00* self);
struct Unk_8289a0;
void* Unk_8289a0_getFieldb20(const Unk_8289a0* self);
struct Unk_828420;
void* Unk_828420_getField20(const Unk_828420* self);
struct Unk_828cb0;
void* Unk_828cb0_getField1160(const Unk_828cb0* self);
struct Unk_828a60;
void* Unk_828a60_getFieldcc0(const Unk_828a60* self);
struct Unk_828930;
void* Unk_828930_getFielda20(const Unk_828930* self);
struct Unk_8289d0;
void* Unk_8289d0_getFieldb80(const Unk_8289d0* self);
struct Unk_828a70;
void* Unk_828a70_getFieldce0(const Unk_828a70* self);

u32 Unk_803790(void* self, u8 pokeId);
u32 Unk_803760(void* self, u8 pokeId);
u32 Unk_803560(void* self, u8 pokeId);
u32 Unk_7ed660(Unk_7ecc90_Con* self, u8 pokeId);
void Unk_7cb420(const Unk_7c2d80_Main* self, Unk_7ecc90_Con* con, u8 pokeId);
u32 Unk_7ff460(void* self, u8 arg);
bool Unk_7f05a0(const Unk_7ee6b0* self, u32 flag);
u8 Unk_7cb490(u8 value);
bool Unk_7eb4f0(u16 item);
bool Unk_7eb510(u16 item);
bool Unk_7eb530(u16 item);
bool Unk_786ec0(u16 item);

// What the queries of a byte pass.
struct Unk_819600_Byte {
    u8 field_0;
    u8 _1[7];
};

// What Unk_819c80 gets back.
struct Unk_819c80_Out {
    u8 field_0;
    u8 _1[0xf];
};

// What Unk_81a250 passes.
struct Unk_81a250_Arg {
    u8 field_0;
    u8 field_1;
    u64 field_8;
};

// What Unk_81ab90 passes.
struct Unk_81ab90_Arg {
    u8 field_0;
    u32 field_4;
};

void Unk_864070(void* self, u64* out, const Unk_819600_Byte* in);
void Unk_8641a0(void* self, u64* out, const Unk_819600_Byte* in);
void Unk_82c6b0(void* self, Unk_819c80_Out* out, const void* in);
void Unk_836da0(void* self, u64* out, const void* in);
void Unk_8530d0(void* self, u64* out, const Unk_81a250_Arg* in);
// Declared as src/unsorted/unk_82e410/Handler.h declares it (it's matched there).
struct Unk_23ad258;
struct Unk_8341a0_Result;
struct Unk_8341a0_Arg;
void Unk_8341a0(Unk_23ad258* self, Unk_8341a0_Result& result, const Unk_8341a0_Arg& arg);
void Unk_855f20(void* self, u64* out, const void* in);
void Unk_864650(void* self, u64* out, const Unk_81ab90_Arg* in);
void Unk_855080(void* self, u64* out, const void* in);

// 0x7100819610
u8 Unk_819610(const Unk_819600_Self* self) {
    return Unk_7e9830(self->field_30, 0x25);
}

// 0x71008196d0
Unk_7ee6b0* Unk_8196d0(const Unk_819600_Self* self, u8 pokeId) {
    return Unk_7ecc90(Unk_7fe1d0_getField8(self->field_8), pokeId);
}

// 0x7100819700
u32 Unk_819700(const Unk_819600_Self* self, u8 pokeId) {
    return Unk_803790(Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_8)),
                      pokeId);
}

// 0x7100819770
u8 Unk_819770(const Unk_819600_Self* self) {
    return Unk_7ffaf0_getField10(reinterpret_cast<const Unk_7ffaf0*>(
        Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_8))));
}

// 0x7100819810
u8 Unk_819810(const Unk_819600_Self* self) {
    return Unk_8003c0_getField11(reinterpret_cast<const Unk_8003c0*>(
        Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_8))));
}

// 0x7100819840
void Unk_819840(const Unk_819600_Self* self, u64 value) {
    Unk_7e9a70_setField28(static_cast<Unk_7e9a70*>(self->field_40), value);
}

// 0x7100819850
void Unk_819850(const Unk_819600_Self* self) {
    Unk_7e9a80_clearField28(static_cast<Unk_7e9a80*>(self->field_40));
}

// 0x7100819860
u32 Unk_819860(const Unk_819600_Self* self, u8 pokeId) {
    return Unk_803760(Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_8)),
                      pokeId);
}

// 0x7100819890
u32 Unk_819890(const Unk_819600_Self* self, u8 pokeId) {
    return Unk_7ed660(Unk_7fe1d0_getField8(self->field_8), pokeId);
}

// 0x71008198c0
void Unk_8198c0(const Unk_819600_Self* self, u8 pokeId) {
    Unk_7cb420(self->field_0, Unk_7fe1d0_getField8(self->field_8), pokeId);
}

// 0x71008198f0
u8 Unk_8198f0(const Unk_819600_Self* self) {
    return Unk_7ff460(Unk_7fe350_getField2a8(reinterpret_cast<const Unk_7fe350*>(self->field_8)),
                      0);
}

// 0x7100819970
bool Unk_819970(const Unk_819600_Self* self, u32 effect) {
    return Unk_7ffe20(Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_8)),
                      effect);
}

// 0x7100819a30
u32 Unk_819a30(const Unk_819600_Self* self, u8 pokeId) {
    return Unk_803560(Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_8)),
                      pokeId);
}

// 0x7100819a80
u8 Unk_819a80(const Unk_819600_Self* self, u8 arg) {
    Unk_819600_Byte in;
    in.field_0 = arg;
    u64 result;
    Unk_864070(Unk_828cf0_getField11e0(static_cast<const Unk_828cf0*>(self->field_20)), &result,
               &in);
    return result;
}

// 0x7100819ac0
u8 Unk_819ac0(const Unk_819600_Self* self, u8 arg) {
    Unk_819600_Byte in;
    in.field_0 = arg;
    u64 result;
    Unk_8641a0(Unk_828d00_getField1200(static_cast<const Unk_828d00*>(self->field_20)), &result,
               &in);
    return result;
}

// 0x7100819c80
u8 Unk_819c80(const Unk_819600_Self* self, const void* arg) {
    Unk_819c80_Out result;
    Unk_82c6b0(Unk_8289a0_getFieldb20(static_cast<const Unk_8289a0*>(self->field_20)), &result,
               arg);
    return result.field_0;
}

// 0x7100819cc0
// NON_MATCHING: the comparison is done on 32 bits in the original
bool Unk_819cc0(const Unk_819600_Self* self, const void* arg) {
    u64 result;
    Unk_836da0(Unk_828420_getField20(static_cast<const Unk_828420*>(self->field_20)), &result, arg);
    return static_cast<u8>(result) == 0;
}

// 0x710081a250
u8 Unk_81a250(const Unk_819600_Self* self, u8 arg1, u8 arg2, u64 arg3) {
    Unk_81a250_Arg arg;
    arg.field_0 = arg1;
    arg.field_1 = arg2;
    arg.field_8 = arg3;
    u64 result;
    Unk_8530d0(Unk_828cb0_getField1160(static_cast<const Unk_828cb0*>(self->field_20)), &result,
               &arg);
    return result;
}

// 0x710081a350
u8 Unk_81a350(const Unk_819600_Self* self, u8 arg) {
    u64 result;
    Unk_819600_Byte in;
    in.field_0 = arg;
    Unk_8341a0(static_cast<Unk_23ad258*>(
                   Unk_828a60_getFieldcc0(static_cast<const Unk_828a60*>(self->field_20))),
               *reinterpret_cast<Unk_8341a0_Result*>(&result),
               *reinterpret_cast<const Unk_8341a0_Arg*>(&in));
    return result;
}

// 0x710081a390
u8 Unk_81a390(const Unk_819600_Self* self) {
    return Unk_7ffaa0_getField0(reinterpret_cast<const Unk_7ffaa0*>(
        Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_8))));
}

// 0x710081ab50
u16 Unk_81ab50(const Unk_819600_Self* self, const void* arg) {
    u64 result;
    Unk_855f20(Unk_828930_getFielda20(static_cast<const Unk_828930*>(self->field_20)), &result,
               arg);
    return result;
}

// 0x710081ab90
u8 Unk_81ab90(const Unk_819600_Self* self, u8 arg1, u32 arg2) {
    u64 result;
    Unk_81ab90_Arg arg;
    arg.field_0 = arg1;
    arg.field_4 = arg2;
    Unk_864650(Unk_8289d0_getFieldb80(static_cast<const Unk_8289d0*>(self->field_20)), &result,
               &arg);
    return result;
}

// 0x710081ac10
u32 Unk_81ac10(const Unk_819600_Self* self, const void* arg) {
    u64 result;
    Unk_855080(Unk_828a70_getFieldce0(static_cast<const Unk_828a70*>(self->field_20)), &result,
               arg);
    return result;
}

// The event's targets: a count in variable 5, the Pokemon from variable 6.
static inline u8 Unk_819600_Target(const Unk_819600_Self* self, u8 index) {
    Unk_7e8a20* event = self->field_30;
    if (index < Unk_7e9830(event, 5))
        return Unk_7e9830(event, 6 + index);
    return 0x1f;
}

// 0x710081acc0
bool Unk_81acc0(const Unk_819600_Self* self, u8 pokeId) {
    u32 count = Unk_7e9830(self->field_30, 5);
    for (u32 i = 0; i < count; i++) {
        if (Unk_819600_Target(self, i) == pokeId)
            return true;
    }
    return false;
}

// 0x710081aed0
bool Unk_81aed0(const Unk_819600_Self* self, u8 pokeId) {
    return Unk_7f05a0(Unk_7ed1e0(Unk_7fe1d0_getField8(self->field_8), pokeId), 0);
}

// 0x710081af00
// NON_MATCHING: the original compares the ranges in another order
bool Unk_81af00(u16 species, u16 item) {
    switch (species) {
        case 0x17e:
        case 0x17f:
        case 0x1e7:
            if (item == 0)
                return true;
            break;
        case 0x1ed:
            if (Unk_7eb4f0(item))
                return true;
            break;
        case 0x289:
            if (Unk_7eb530(item))
                return true;
            break;
        case 0x305:
            if (Unk_7eb510(item))
                return true;
            break;
        case 0x378:
            if (item == 0x44f)
                return true;
            break;
        case 0x379:
            if (item == 0x450)
                return true;
            break;
        default:
            if (Unk_786ec0(item))
                return true;
            break;
    }
    return false;
}

// 0x710081b040
bool Unk_81b040(const Unk_819600_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_7ed1e0(Unk_7fe1d0_getField8(self->field_8), pokeId);
    u16 species = Unk_7eef40_getField70(reinterpret_cast<const Unk_7eef40*>(poke));
    return Unk_81af00(species, Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(poke)));
}

// 0x710081b090
bool Unk_81b090(const Unk_819600_Self* self, u8 position) {
    if (Unk_7ca1c0_getField150(reinterpret_cast<const Unk_7ca1c0*>(self->field_0)) != 2 &&
        Unk_7c58b0_get(reinterpret_cast<const Unk_7c58b0*>(self->field_0)) == 0) {
        u8 side = Unk_7cb490(position);
        if (side == 1 || side == 3)
            return true;
    }
    return false;
}

struct Unk_7f0b70;
bool Unk_7f0b70_check(const Unk_7f0b70* self);

// 0x710081b200
bool Unk_81b200(const Unk_819600_Self* self, u8 pokeId) {
    return Unk_7f0b70_check(reinterpret_cast<const Unk_7f0b70*>(
        Unk_7ed1e0(Unk_7fe1d0_getField8(self->field_8), pokeId)));
}

// 0x710081b500
bool Unk_81b500(const Unk_819600_Self* self, u32 ratio) {
    u32 value = Unk_7e9830(self->field_30, 0x33) * ratio;
    return Unk_7e97b0(self->field_30, 0x33, value);
}
