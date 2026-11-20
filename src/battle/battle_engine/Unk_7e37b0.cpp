// Scope: common
// A battle sequence player (0x71007e37b0 to 0x71007e7b40): each step function
// plays an effect on up to five handles, waits for all of them, stops them and
// names the next step. Placeholder names: rename once the class is known.
#include <types.h>

// A handle of a playing effect.
struct Unk_8a7ab0_Handle;

struct Unk_7fc430_Party;

// A handle and the party it plays for.
struct Unk_7e37b0_Slot {
    Unk_8a7ab0_Handle* field_0;
    Unk_7fc430_Party* field_8;
    u8 _10[0x18 - 0x10];
};
PKMN_SIZE_ASSERT(Unk_7e37b0_Slot, 0x18);

struct Unk_8925b0;
struct Unk_7e88d0;

struct Unk_7c2d80_Main;
struct Unk_7fe1d0;

struct Unk_7e37b0_Self {
    u8 _0[0x54];
    u8 field_54;
    u8 _55[0x58 - 0x55];
    u32 field_58;
    u8 _5c[0x60 - 0x5c];
    const Unk_7c2d80_Main* field_60;
    const Unk_7fe1d0* field_68;
    u8 _70[0x78 - 0x70];
    u16 field_78;
    u8 _7a[0x80 - 0x7a];
    Unk_7e37b0_Slot field_80[5];
    u8 _f8[0x4e8 - 0xf8];
    u16 field_4e8;
    u16 field_4ea;
    u32 field_4ec;
    u8 _4f0[0x5e0 - 0x4f0];
    u32 field_5e0;
    u8 field_5e4;
    u8 _5e5[0x5e8 - 0x5e5];
    const Unk_8925b0* field_5e8;
    u8 _5f0[0x608 - 0x5f0];
    const Unk_7e88d0* field_608;
};
PKMN_OFFSET_ASSERT(Unk_7e37b0_Self, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_7e37b0_Self, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_7e37b0_Self, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_7e37b0_Self, field_4e8, 0x4e8);
PKMN_OFFSET_ASSERT(Unk_7e37b0_Self, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_7e37b0_Self, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_7e37b0_Self, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_7e37b0_Self, field_608, 0x608);

bool Unk_8a7ab0(Unk_8a7ab0_Handle* self);
void Unk_8a79f0(Unk_8a7ab0_Handle* self);
bool Unk_8a7a20(Unk_8a7ab0_Handle* self);
struct Unk_7ecc90_Con;
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
Unk_7fc430_Party* Unk_7ed1a0(Unk_7ecc90_Con* self, u32 client);
void Unk_7e8880(const Unk_7e88d0* self);
void Unk_803a70(void* self, u32 index, u16 value);
bool Unk_7cc410(const Unk_7c2d80_Main* self);
bool Unk_7cc460(const Unk_7c2d80_Main* self);
u16 Unk_7cbb70(const Unk_7c2d80_Main* self);
void Unk_8a7be0(Unk_8a7ab0_Handle* self);
void Unk_7e75c0(Unk_7e37b0_Self* self, u32 id, u8 count);
void Unk_7e69b0(Unk_7e37b0_Self* self);
void Unk_7e72b0(Unk_7e37b0_Self* self);
// Declared as src/unsorted/leaf/Unk_892310.cpp names them.
void Unk_896170_set();
bool Unk_8925b0_getField83(const Unk_8925b0* self);
struct Unk_8139d0;
Unk_8139d0* Unk_7e88d0_getField10(const Unk_7e88d0* self);
void Unk_8139d0_clearField0(Unk_8139d0* self);
struct Unk_7fe2b0;
void* Unk_7fe2b0_getField168(const Unk_7fe2b0* self);
struct Unk_7cb850;
u8 Unk_7cb850_getField174(const Unk_7cb850* self);
struct Unk_7cbc20;
u32 Unk_7cbc20_getField170(const Unk_7cbc20* self);
struct Unk_8a7bd0;
const u8* Unk_8a7bd0_get(const Unk_8a7bd0* self);
struct Unk_8924c0;
u8* Unk_8924c0_getField10Ptr(Unk_8924c0* self);

// Stops what every handle plays.
static inline void Unk_7e37b0_StopAll(Unk_7e37b0_Self* self) {
    for (s32 i = 0; i < 5; i++) {
        if (self->field_80[i].field_0 != nullptr)
            Unk_8a7be0(self->field_80[i].field_0);
    }
}

// 0x71007e3b50
void Unk_7e3b50(Unk_7e37b0_Self* self, u32 client, Unk_8a7ab0_Handle* handle) {
    Unk_7fc430_Party* party = Unk_7ed1a0(Unk_7fe1d0_getField8(self->field_68), client);
    self->field_80[client].field_0 = handle;
    self->field_80[client].field_8 = party;
}

// 0x71007e3ba0
void Unk_7e3ba0(Unk_7e37b0_Self* self) {
    self->field_54 = 0;
    self->field_58 = 0;
    for (s32 i = 0; i < 5; i++) {
        if (self->field_80[i].field_0 != nullptr)
            Unk_8a79f0(self->field_80[i].field_0);
    }
    Unk_7e8880(self->field_608);
}

// 0x71007e3c10
void Unk_7e3c10(Unk_7e37b0_Self* self) {
    self->field_58 = 0;
    self->field_54 = 0x2f;
    Unk_7e37b0_StopAll(self);
}

// 0x71007e3c80
bool Unk_7e3c80(Unk_7e37b0_Self* self) {
    for (s32 i = 0; i < 5; i++) {
        if (self->field_80[i].field_0 != nullptr && Unk_8a7a20(self->field_80[i].field_0))
            return true;
    }
    return false;
}

// 0x71007e3dc0
void Unk_7e3dc0(Unk_7e37b0_Self* self, const u16* values) {
    for (s32 i = 0; i < 5; i++)
        Unk_803a70(Unk_7fe2b0_getField168(reinterpret_cast<const Unk_7fe2b0*>(self->field_68)), i,
                   values[i]);
}

// 0x71007e4980
void Unk_7e4980(Unk_7e37b0_Self* self, u32*, u8* next) {
    if (Unk_7cc410(self->field_60)) {
        *next = 0x1d;
        return;
    }
    *next = Unk_7cc460(self->field_60) ? 0x24 : 0xc;
}

// 0x71007e4e60
void Unk_7e4e60(Unk_7e37b0_Self* self, u32*, u8* next) {
    u8 client = Unk_7cb850_getField174(reinterpret_cast<const Unk_7cb850*>(self->field_60));
    const u8* object =
        Unk_8a7bd0_get(reinterpret_cast<const Unk_8a7bd0*>(self->field_80[client].field_0));
    *next = *Unk_8924c0_getField10Ptr(reinterpret_cast<Unk_8924c0*>(const_cast<u8*>(object))) == 0
                ? 0x12
                : 0x11;
}

// 0x71007e5120
void Unk_7e5120(Unk_7e37b0_Self* self, u32*, u8* next) {
    if (Unk_7cc460(self->field_60))
        *next = 0x24;
    *next = 0x15;
}

// 0x71007e55b0
void Unk_7e55b0(Unk_7e37b0_Self* self, u32*, u8* next) {
    if (Unk_7cc460(self->field_60))
        *next = 0x24;
    *next = 0x1a;
}

// 0x71007e5f40
void Unk_7e5f40(Unk_7e37b0_Self* self, u32*, u8* next) {
    self->field_4ea = Unk_7cbb70(self->field_60);
    self->field_4ec = Unk_7cbc20_getField170(reinterpret_cast<const Unk_7cbc20*>(self->field_60));
    self->field_4e8 = Unk_7cb850_getField174(reinterpret_cast<const Unk_7cb850*>(self->field_60));
    *next = 0x25;
}

// 0x71007e6900
bool Unk_7e6900(Unk_7e37b0_Self* self) {
    bool done = true;
    for (s32 i = 0; i < 5; i++) {
        if (self->field_80[i].field_0 != nullptr)
            done &= Unk_8a7ab0(self->field_80[i].field_0);
    }
    if (!done)
        return false;
    Unk_896170_set();
    return true;
}

// 0x71007e5990
void Unk_7e5990(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x13, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x1e;
            }
            break;
    }
}

// 0x71007e6050
void Unk_7e6050(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x1a, 5);
            break;
        case 1:
            if (!Unk_7e6900(self))
                return;
            Unk_7e37b0_StopAll(self);
            break;
        case 2:
            *next = 0x2d;
            return;
        default:
            return;
    }
    (*seq)++;
}

// 0x71007e66c0
void Unk_7e66c0(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            self->field_78 = 0;
            Unk_7e75c0(self, 0x1e, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x30;
            }
            break;
    }
}

// 0x71007e4190
void Unk_7e4190(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x1, 5);
            (*seq)++;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x1;
            }
            break;
    }
}

// 0x71007e4280
void Unk_7e4280(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0xd, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x3;
            }
            break;
    }
}

// 0x71007e4340
void Unk_7e4340(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x7, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x4;
            }
            break;
    }
}

// 0x71007e4400
void Unk_7e4400(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0xe, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x5;
            }
            break;
    }
}

// 0x71007e4500
void Unk_7e4500(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x5, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e69b0(self);
                Unk_7e37b0_StopAll(self);
                *next = 0x7;
            }
            break;
    }
}

// 0x71007e4da0
void Unk_7e4da0(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x3, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x10;
            }
            break;
    }
}

// 0x71007e4ec0
void Unk_7e4ec0(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0xc, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                if (Unk_8925b0_getField83(self->field_5e8))
                    *next = 0x2d;
                else
                    *next = 0x12;
            }
            break;
    }
}

// 0x71007e4f90
void Unk_7e4f90(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x4, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                *next = 0x13;
            }
            break;
    }
}

// 0x71007e54f0
void Unk_7e54f0(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x5, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e69b0(self);
                Unk_7e37b0_StopAll(self);
                *next = 0x19;
            }
            break;
    }
}

// 0x71007e5c40
void Unk_7e5c40(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x22, 5);
            break;
        case 1:
            if (!Unk_7e6900(self))
                return;
            Unk_7e72b0(self);
            Unk_7e37b0_StopAll(self);
            break;
        case 2:
            *next = 0x21;
            return;
        default:
            return;
    }
    (*seq)++;
}

// 0x71007e5dc0
void Unk_7e5dc0(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x24, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x2d;
            }
            break;
    }
}

// 0x71007e5e80
void Unk_7e5e80(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x25, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x2d;
            }
            break;
    }
}

// 0x71007e6110
void Unk_7e6110(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x1b, 5);
            break;
        case 1:
            if (!Unk_7e6900(self))
                return;
            Unk_7e37b0_StopAll(self);
            break;
        case 2:
            *next = 0x2d;
            return;
        default:
            return;
    }
    (*seq)++;
}

// 0x71007e61d0
void Unk_7e61d0(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x19, 5);
            break;
        case 1:
            if (!Unk_7e6900(self))
                return;
            Unk_7e37b0_StopAll(self);
            break;
        case 2:
            *next = 0x2d;
            return;
        default:
            return;
    }
    (*seq)++;
}

// 0x71007e6290
void Unk_7e6290(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x15, 5);
            break;
        case 1:
            if (!Unk_7e6900(self))
                return;
            Unk_7e37b0_StopAll(self);
            break;
        case 2:
            *next = 0x2d;
            return;
        default:
            return;
    }
    (*seq)++;
}

// 0x71007e6350
void Unk_7e6350(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x16, 5);
            break;
        case 1:
            if (!Unk_7e6900(self))
                return;
            Unk_7e37b0_StopAll(self);
            break;
        case 2:
            *next = 0x2d;
            return;
        default:
            return;
    }
    (*seq)++;
}

// 0x71007e6410
void Unk_7e6410(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x18, 5);
            break;
        case 1:
            if (!Unk_7e6900(self))
                return;
            Unk_7e37b0_StopAll(self);
            break;
        case 2:
            *next = 0x2d;
            return;
        default:
            return;
    }
    (*seq)++;
}

// 0x71007e64d0
void Unk_7e64d0(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x17, 5);
            break;
        case 1:
            if (!Unk_7e6900(self))
                return;
            Unk_7e37b0_StopAll(self);
            break;
        case 2:
            *next = 0x2d;
            return;
        default:
            return;
    }
    (*seq)++;
}

// 0x71007e6590
void Unk_7e6590(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x1c, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x2e;
            }
            break;
    }
}

// 0x71007e6650
void Unk_7e6650(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e75c0(self, 0x1d, 5);
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                *next = 0x31;
            }
            break;
    }
}

// 0x71007e4740
void Unk_7e4740(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_8139d0_clearField0(Unk_7e88d0_getField10(self->field_608));
            Unk_7e37b0_StopAll(self);
            Unk_7e75c0(self, 8, 5);
            self->field_5e4 = 0;
            self->field_5e0 = 0;
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 9;
            }
            break;
    }
}

// 0x71007e4b60
void Unk_7e4b60(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e37b0_StopAll(self);
            Unk_7e75c0(self, 9, 5);
            self->field_5e4 = 0;
            self->field_5e0 = 0;
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0xe;
            }
            break;
    }
}

// 0x71007e52e0
void Unk_7e52e0(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_7e37b0_StopAll(self);
            Unk_7e75c0(self, 0xa, 5);
            self->field_5e4 = 0;
            self->field_5e0 = 0;
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x17;
            }
            break;
    }
}

// 0x71007e5770
void Unk_7e5770(Unk_7e37b0_Self* self, u32* seq, u8* next) {
    switch (*seq) {
        case 0:
            Unk_8139d0_clearField0(Unk_7e88d0_getField10(self->field_608));
            Unk_7e37b0_StopAll(self);
            Unk_7e75c0(self, 0xb, 5);
            self->field_5e4 = 0;
            self->field_5e0 = 0;
            (*seq)++;
            break;
        case 1:
            if (Unk_7e6900(self)) {
                Unk_7e37b0_StopAll(self);
                *next = 0x1c;
            }
            break;
    }
}
