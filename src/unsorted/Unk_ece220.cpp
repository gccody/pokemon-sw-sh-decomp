// Scope: common
// Forwarders to the object behind Unk_24ba618, the palma (Poké Ball Plus)
// sound and LED file paths of a Pokémon, and a record unpacker.
// Placeholder types: rename them once the owning classes are known.
#include <stdio.h>

#include "types.h"

extern void* Unk_24ba618;

struct Unk_eaa630;
struct Unk_eaa650;
struct Unk_eaa6a0;
struct Unk_eaa6b0;
struct Unk_eaa6c0;

void Unk_eaa630_call(const Unk_eaa630* self, u32 value, void* arg2, void* arg3);
void Unk_eaa650_call(const Unk_eaa650* self, u32 value);
void Unk_eaa6a0_call(const Unk_eaa6a0* self, bool value);
void Unk_eaa6b0_call(const Unk_eaa6b0* self);
void Unk_eaa6c0_call(const Unk_eaa6c0* self, u32 value);

// What Unk_76d0d0 builds from a path (at least 0x30 bytes, returned by value).
struct Unk_76d0d0_Result {
    u8 _0[0x30];
};

Unk_76d0d0_Result Unk_76d0d0(const char* path);

// 0x7100ece220
void Unk_ece220(u32 value, u32 arg, void* arg2) {
    Unk_eaa630_call(static_cast<const Unk_eaa630*>(Unk_24ba618), value, &arg, arg2);
}

// 0x7100ece260
void Unk_ece260() {
    Unk_eaa6b0_call(static_cast<const Unk_eaa6b0*>(Unk_24ba618));
}

// 0x7100ece270
void Unk_ece270(u32 value) {
    Unk_eaa6c0_call(static_cast<const Unk_eaa6c0*>(Unk_24ba618), value);
}

// 0x7100ece290
void Unk_ece290(u32 value) {
    Unk_eaa650_call(static_cast<const Unk_eaa650*>(Unk_24ba618), value);
}

// 0x7100ece2b0
void Unk_ece2b0(bool value) {
    Unk_eaa6a0_call(static_cast<const Unk_eaa6a0*>(Unk_24ba618), value);
}

// 0x7100ece2d0
Unk_76d0d0_Result Unk_ece2d0(u16 species, u16 form, u32 happy) {
    switch (species) {
        case 646:
        case 800:
        case 849:
        case 876:
            break;
        case 710:
            if (form == 3) {
                break;
            }
            goto other;
        case 711:
            if (form == 3) {
                break;
            }
            goto other;
        default:
        other:
            form = 0;
            break;
    }
    char path[0x100];
    snprintf(path, sizeof(path), "bin/misc/palma/bin/wave/pv%04d_%03d_%s.wav", species, form,
             happy == 0 ? "Common" : "Happy");
    return Unk_76d0d0(path);
}

// NON_MATCHING: instruction scheduling and register allocation of the string
// selects (the "_F" address is materialised later than in the original).
// 0x7100ece390
Unk_76d0d0_Result Unk_ece390(u16 species, u16 form, bool rare, u32 female) {
    // Frillish and Jellicent have per-gender files.
    char path[0x100];
    snprintf(path, sizeof(path), "bin/misc/palma/bin/rgbled/poke_f_%04d_%03d_%s%s.bin", species,
             form, rare ? "R" : "N",
             species == 592 || species == 593 ? (female != 0 ? "_F" : "_M") : "");
    return Unk_76d0d0(path);
}

struct Unk_ece430_Source {
    u8 _0[0x8];
    u16 field_8;
    u8 _a[0x2];
    u8 field_c;
    u8 _d[0x23];
    union {
        u16 u16s[12];
        u32 u32s[12];
    } field_30;
};
PKMN_OFFSET_ASSERT(Unk_ece430_Source, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ece430_Source, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_ece430_Source, field_30, 0x30);
PKMN_SIZE_ASSERT(Unk_ece430_Source, 0x60);

struct Unk_ece430_Pair {
    u64 field_0;
    u64 field_8;
};

struct Unk_ece430_Record {
    u64 field_0;
    u64 field_8[2];
    u64 field_18[12];
    Unk_ece430_Pair field_78[6];
    u64 field_d8;
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_ece430_Record, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ece430_Record, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_ece430_Record, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_ece430_Record, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_ece430_Record, field_e0, 0xe0);
PKMN_SIZE_ASSERT(Unk_ece430_Record, 0xe8);

// 0x7100ece430
void Unk_ece430(Unk_ece430_Record* out, const Unk_ece430_Source* in) {
    *out = {};
    out->field_0 = in->field_8;
    if (in->field_c == 1) {
        for (int i = 0; i < 2; i++) {
            out->field_8[i] = in->field_30.u16s[i];
        }
    }
    if (in->field_c == 2) {
        for (int i = 0; i < 12; i++) {
            out->field_18[i] = in->field_30.u16s[i];
        }
    }
    if (in->field_c == 3) {
        out->field_d8 = in->field_30.u32s[0];
    }
    for (int i = 0; i < 6; i++) {
        out->field_78[i].field_8 = static_cast<u64>(-1);
    }
    if (in->field_c == 4) {
        for (int i = 0; i < 6; i++) {
            out->field_78[i].field_0 = in->field_30.u32s[i * 2];
            if (in->field_30.u32s[i * 2 + 1] != 0xffffffff) {
                out->field_78[i].field_8 = in->field_30.u32s[i * 2 + 1];
            }
        }
    }
    if (in->field_c == 5) {
        out->field_e0 = in->field_30.u32s[0];
    }
}
