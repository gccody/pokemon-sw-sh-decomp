// Scope: common
// PPFX's glare definitions (lib/yebis/YEBIS_draft/src/GPU/GPUGlareDef.h).
#include <float.h>
#include <math.h>
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/GPUGlareDef.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

// The definitions the glare draws with (GPUGlareDef.cpp's): the stars, the
// glares and 0x71024e5950's items, and two sets of four channel masks
extern PPFX::Unk_4a0540* Unk_24e58c0;
extern PPFX::Unk_Float4 Unk_24e58c8[4];
extern PPFX::Unk_Float4 Unk_24e5908[4];
extern PPFX::Unk_4a0b00* Unk_24e5948;
extern PPFX::Unk_4a2be0_Target* Unk_24e5950;

namespace PPFX {

// 0x71004a0530
Unk_4a0540::Unk_4a0540() {
    Unk_Clear();
}

// 0x71004a0540
s32 Unk_4a0540::Unk_4a0540_Copy(const Unk_4a0540& other) {
    if (&other == this)
        return 0;
    Unk_4a0680();
    memmove(static_cast<Unk_4a0540_Base*>(this), &other, sizeof(Unk_4a0540_Base));
    if (other.field_20 != nullptr) {
#line 245
        field_20 = UNK_NEW_ARRAY(Unk_4a0540_Line, field_8);
        for (s32 i = 0; i < field_8; i++)
            field_20[i] = other.field_20[i];
    }
    return 0;
}

// 0x71004a0680
void Unk_4a0540::Unk_4a0680() {
    UNK_DELETE_ARRAY(field_20);
    Unk_Clear();
}

// 0x71004a0bb0: a call of 0x71004a0540, which is inlined here (the same code).
// With the copy written out in this body instead, its inline cost (235) is
// under the threshold (250) and Unk_4a0cf0 inlines it, where the original
// calls it; through the call it costs 260.
Unk_4a0540& Unk_4a0540::operator=(const Unk_4a0540& other) {
    Unk_4a0540_Copy(other);
    return *this;
}

// 0x71004a0b00
Unk_4a0b00::Unk_4a0b00() {
    field_0 = nullptr;
    for (s32 i = 0; i < 8; i++)
        field_8[i] = 0.0f;
    for (s32 i = 0; i < 4; i++)
        field_30[i] = 0.0f;
    field_40 = 0.0f;
    for (s32 i = 0; i < 4; i++)
        field_4c[i] = 0.0f;
    field_5c = 0.0f;
    field_60 = 0.0f;
    field_68 = 0.0f;
    for (s32 i = 0; i < 4; i++)
        field_6c[i] = 0.0f;
}

// 0x71004a0b40
Unk_4a0b00::~Unk_4a0b00() {}

// 0x71004a0cf0
s32 Unk_4a0b00::Unk_4a0cf0(const char* name, u32 star, Unk_Float4 arg2, Unk_Float4 arg3, Unk_Float4 arg4,
                           f32 arg5, Unk_Float4 arg6, f32 arg7, f32 arg8, f32 arg9, Unk_Float4 arg10, f32 arg11) {
    field_80.Unk_4a0680();
    field_0 = name;
    field_8[0] = arg2.field_0[0].field_0;
    field_8[1] = arg2.field_0[1].field_0;
    field_8[2] = arg2.field_0[2].field_0;
    field_8[3] = arg2.field_0[3].field_0;
    field_8[4] = arg3.field_0[0].field_0;
    field_8[5] = arg3.field_0[1].field_0;
    field_8[6] = arg3.field_0[2].field_0;
    field_8[7] = arg3.field_0[3].field_0;
    field_2c = 4;
    field_30[0] = arg4.field_0[0].field_0;
    field_30[1] = arg4.field_0[1].field_0;
    field_30[2] = arg4.field_0[2].field_0;
    field_30[3] = arg4.field_0[3].field_0;
    field_40 = 1.0f;
    field_44 = arg5;
    field_48 = arg5 >= 0.05f;
    field_4c[0] = arg6.field_0[0].field_0;
    field_4c[1] = arg6.field_0[1].field_0;
    field_4c[2] = arg6.field_0[2].field_0;
    field_4c[3] = arg6.field_0[3].field_0;
    field_5c = arg7;
    field_60 = arg8;
    field_64 = fabsf(arg8) >= 1.0f;
    field_28 = fabsf(arg8) * 0.8f;
    if (fabsf(arg8) >= 1.0f)
        arg8 *= 0.36f;
    else if (arg8 < 0.0f && arg8 > -1.0f)
        field_28 = 0.4f;
    field_60 = arg8;
    field_68 = arg9;
    field_6c[0] = arg10.field_0[0].field_0;
    field_6c[1] = arg10.field_0[1].field_0;
    field_6c[2] = arg10.field_0[2].field_0;
    field_6c[3] = arg10.field_0[3].field_0;
    field_7c = arg11;
    if (star != 0xffffffff)
        field_80 = Unk_24e58c0[star];
    return 0;
}

// 0x71004a0f10
s32 Unk_4a0b00::Unk_4a0f10(const char* name, Unk_Float4 arg6, Unk_Float4 arg7, f32 arg8, Unk_Float4 arg9,
                           f32 arg10, f32 arg11, Unk_Float4 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16,
                           f32 arg17, f32 arg18, Unk_Float4 arg19, f32 arg20, s32 arg1, bool arg2, s32 lines,
                           bool arg4, bool arg5) {
    Unk_4a0cf0(name, 0xffffffff, arg6, arg7, arg9, arg11, arg12, arg16, arg17, arg18, arg19, arg20);
    field_48 = arg2;
    field_28 = arg8;
    field_2c = arg1;
    field_40 = arg10;
    field_64 = arg5;
    field_60 = arg17;
    field_80.Unk_Set("UserDef", lines, arg13, arg14, arg15, arg4);
    return 0;
}

}  // namespace PPFX

// 0x71004a0a30
s32 Unk_4a0a30() {
    UNK_DELETE_ARRAY(Unk_24e58c0);
    return 0;
}

// a star of the table (its constructor isn't constexpr: the TU's static
// initialiser stores the table)
struct Unk_4a06e0_Desc : PPFX::Unk_4a0540_Base {
    Unk_4a06e0_Desc(const char* name, s32 lines, f32 arg2, f32 arg3, f32 arg4, bool arg5) {
        field_0 = name;
        field_8 = lines;
        field_c = arg2;
        field_10 = arg3;
        field_14 = arg4;
        field_18 = arg5;
    }
};
PKMN_SIZE_ASSERT(Unk_4a06e0_Desc, 0x20);

// the stars (0x71024e6f90, in the TU's merged statics)
static const Unk_4a06e0_Desc Unk_Stars[] = {
    Unk_4a06e0_Desc("Disable", 0, 0.0f, 0.0f, 0.0f, false),
    Unk_4a06e0_Desc("Cross", 4, 1.0f, 1.25f, 0.0f, true),
    Unk_4a06e0_Desc("CrossFilter", 4, 1.0f, 2.4f, 0.0f, false),
    Unk_4a06e0_Desc("SnowCross", 6, 1.0f, 2.4f, 0.0f, false),
    Unk_4a06e0_Desc("SunnyCross", 8, 1.0f, 2.4f, 1.3f, false),
    Unk_4a06e0_Desc("Vertical", 2, 1.0f, 4.0f, 0.0f, false),
    Unk_4a06e0_Desc("Anamorphic", 2, 1.0f, 3.0f, 0.0f, false),
};

// a glare definition of the table (0x38 bytes; its constructor isn't
// constexpr either)
struct Unk_4a1010_Desc {
    Unk_4a1010_Desc(const char* name, f32 arg8, f32 argc, f32 arg10, f32 arg14, f32 arg18, u32 star, f32 arg20,
                    f32 arg24, f32 arg28, f32 arg2c, f32 arg30) {
        field_0 = name;
        field_8 = arg8;
        field_c = argc;
        field_10 = arg10;
        field_14 = arg14;
        field_18 = arg18;
        field_1c = star;
        field_20 = arg20;
        field_24 = arg24;
        field_28 = arg28;
        field_2c = arg2c;
        field_30 = arg30;
    }

    const char* field_0;  // the name
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    u32 field_1c;  // the star
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    f32 field_30;
};
PKMN_SIZE_ASSERT(Unk_4a1010_Desc, 0x38);

// the glare definitions (0x71024e7070, in the TU's merged statics)
static const Unk_4a1010_Desc Unk_Glares[] = {
    Unk_4a1010_Desc("Disable", 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    Unk_4a1010_Desc("Bloom", 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f),
    Unk_4a1010_Desc("Lens Flare", 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0, 0.0f, 0.0f, 0.5f, 0.5f, 1.0f),
    Unk_4a1010_Desc("Standard", 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 1, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f),
    Unk_4a1010_Desc("Cheap Lens Camera", 1.2f, 1.2f, 1.0f, 0.07f, 1.0f, 1, 0.0f, 0.99f, 2.0f, 1.0f, 2.0f),
    Unk_4a1010_Desc("Afterimage", 1.0f, 1.0f, 1.0f, 0.02f, 0.5f, 1, 0.0f, 0.5f, 6.0f, 1.0f, 1.0f),
    Unk_4a1010_Desc("Cross Screen Filter", 1.0f, 1.5f, 1.0f, 0.02f, 1.0f, 2, PPFX::Unk_Radians(37.5f), -0.99f,
                    1.0f, 1.0f, 3.0f),
    Unk_4a1010_Desc("Spectral Cross Filter", 1.0f, 1.5f, 1.0f, 0.02f, 1.0f, 2, -PPFX::Unk_Radians(37.5f), -1.0f,
                    1.0f, 1.0f, 3.0f),
    Unk_4a1010_Desc("Snow Cross Filter", 1.0f, 1.5f, 1.0f, 0.02f, 1.0f, 3, PPFX::Unk_Radians(5.0f), -0.99f, 1.0f,
                    1.0f, 3.0f),
    Unk_4a1010_Desc("Spectral Snow Cross", 1.0f, 1.5f, 1.0f, 0.02f, 1.0f, 3, -PPFX::Unk_Radians(5.0f), -1.0f,
                    1.0f, 1.0f, 3.0f),
    Unk_4a1010_Desc("Sunny Cross Filter", 1.0f, 1.5f, 1.0f, 0.02f, 1.0f, 4, 0.0f, -0.99f, 1.0f, 1.0f, 3.0f),
    Unk_4a1010_Desc("Spectral Sunny Cross", 1.0f, 1.5f, 1.0f, 0.02f, 1.0f, 4, PPFX::Unk_Radians(45.0f), -1.0f,
                    1.0f, 1.0f, 3.0f),
    Unk_4a1010_Desc("Horizontal Streak", 1.0f, 1.5f, 1.0f, 0.0f, 0.5f, 5, PPFX::Unk_Radians(90.0f), 0.5f, 0.0f,
                    0.0f, 1.5f),
    Unk_4a1010_Desc("Vertical Streak", 1.0f, 1.5f, 1.0f, 0.0f, 0.5f, 5, 0.0f, 0.5f, 0.0f, 0.0f, 1.5f),
};

// colours (0x71024e6e78 and 0x71024e6eb8, in the TU's merged statics)
static const PPFX::Unk_Float4 Unk_Colors0[] = {
    PPFX::Unk_Float4(1.0f, 0.64f, 0.74f, 2.0f),
    PPFX::Unk_Float4(0.66f, 1.0f, 0.73f, 1.0f),
    PPFX::Unk_Float4(0.46f, 0.5f, 1.0f, 2.0f),
    PPFX::Unk_Float4(0.79f, 0.51f, 1.0f, 2.0f),
};
static const PPFX::Unk_Float4 Unk_Colors1[] = {
    PPFX::Unk_Float4(0.3f, 0.9f, 0.4f, 0.0f), PPFX::Unk_Float4(0.7f, 0.1f, 0.6f, 0.0f),
    PPFX::Unk_Float4(0.6f, 0.3f, 0.2f, 0.0f), PPFX::Unk_Float4(0.2f, 0.3f, 1.0f, 0.0f),
    PPFX::Unk_Float4(0.1f, 0.7f, 0.7f, 0.0f), PPFX::Unk_Float4(0.9f, 0.3f, 0.3f, 0.0f),
};

// 0x71004a06e0: makes the stars and the channel masks
// (The masks are default-constructed, then assigned: the constructor loop
// keeps SROA off the array, so it stays on the stack and is copied whole,
// and only the first row of Unk_24e5908 is read back from the stack. Their
// colours are set first, white last, and every alpha after: the merged
// stack stores follow that order.)
s32 Unk_4a06e0() {
    if (Unk_24e58c0 != nullptr)
        return 0;
#line 330
    Unk_24e58c0 = UNK_NEW_ARRAY(PPFX::Unk_4a0540, 8);
    for (s32 i = 0; i < 7; i++)
        Unk_24e58c0[i] = Unk_Stars[i];
    PPFX::Unk_Float4 masks[4];
    masks[1] = PPFX::Unk_Float4(0.0f, 0.0f, 1.0f, 0.0f);
    masks[2] = PPFX::Unk_Float4(0.0f, 1.0f, 0.0f, 0.0f);
    masks[3] = PPFX::Unk_Float4(1.0f, 0.0f, 0.0f, 0.0f);
    masks[0] = PPFX::Unk_Float4(1.0f, 1.0f, 1.0f, 0.0f);
    for (s32 i = 0; i < 4; i++)
        masks[i].field_0[3] = 1.0f;
    memcpy(Unk_24e58c8, masks, sizeof(masks));
    Unk_24e5908[0] = Unk_24e58c8[0];
    Unk_24e5908[1] = Unk_24e58c8[3];
    Unk_24e5908[2] = Unk_24e58c8[2];
    Unk_24e5908[3] = Unk_24e58c8[1];
    return 0;
}

// 0x71004a1010: makes the glare definitions
s32 Unk_4a1010() {
    if (Unk_24e5948 != nullptr)
        return 0;
    Unk_4a06e0();
#line 654
    Unk_24e5948 = UNK_NEW_ARRAY(PPFX::Unk_4a0b00, 14);
    for (s32 i = 0; i < 14; i++) {
        const Unk_4a1010_Desc& desc = Unk_Glares[i];
        Unk_24e5948[i].Unk_4a0cf0(
            desc.field_0, desc.field_1c, PPFX::Unk_Float4(desc.field_8, desc.field_8, desc.field_8, desc.field_8),
            PPFX::Unk_Float4(desc.field_c, desc.field_c, desc.field_c, desc.field_c),
            PPFX::Unk_Float4(desc.field_10, desc.field_10, desc.field_10, desc.field_10), desc.field_14,
            PPFX::Unk_Float4(desc.field_18, desc.field_18, desc.field_18, desc.field_18), desc.field_20, desc.field_24,
            desc.field_28, PPFX::Unk_Float4(desc.field_2c, desc.field_2c, desc.field_2c, desc.field_2c), desc.field_30);
    }
    return 0;
}

// 0x71004a15b0
s32 Unk_4a15b0() {
    UNK_DELETE_ARRAY(Unk_24e5948);
    return 0;
}

namespace PPFX {


// what 0x71004a2be0 sets up and 0x71004a3cc0 reads: a xorshift128 generator
// and colours with their cumulative weights (placeholder)
struct Unk_4a3cc0_Self {
    Unk_4a3cc0_Self() {}
    Unk_4a3cc0_Self(const Unk_Float4* colors, s32 count);

    u32 field_0[4];  // the generator's state
    s32 field_10;
    s32 field_14;
    Unk_4a2be0_Target* field_18;
    const Unk_Float4* field_20;  // the colours
    s32 field_28;          // how many (up to 4)
    Unk_Float4 field_2c;   // their cumulative weights
    s32 field_3c;
    f32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4a3cc0_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_4a3cc0_Self, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_4a3cc0_Self, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_4a3cc0_Self, field_40, 0x40);
// what 0x71004a2be0 hands 0x71004a2e20, 0x74 bytes each (placeholder; FLT_MAX:
// 0x71004a2e20 chooses the value)
struct Unk_4a2e20_Item {
    Unk_4a2e20_Item()
        : field_0(-1), field_4(FLT_MAX), field_8(FLT_MAX), field_c(FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX),
          field_1c(FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX), field_2c(FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX),
          field_3c(FLT_MAX), field_40(FLT_MAX), field_44(FLT_MAX), field_48(FLT_MAX), field_4c(FLT_MAX),
          field_50(FLT_MAX), field_54(FLT_MAX), field_58(FLT_MAX), field_5c(FLT_MAX, FLT_MAX),
          field_64(FLT_MAX, FLT_MAX), field_6c(true), field_70(FLT_MAX) {}

    s32 field_0;
    f32 field_4;
    f32 field_8;
    Unk_Float4 field_c;  // a colour
    Unk_Float4 field_1c;
    Unk_Float4 field_2c;
    f32 field_3c;
    f32 field_40;
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    f32 field_54;
    f32 field_58;
    Unk_Float2 field_5c;
    Unk_Float2 field_64;
    bool field_6c;
    f32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_4a2e20_Item, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_4a2e20_Item, field_6c, 0x6c);
PKMN_SIZE_ASSERT(Unk_4a2e20_Item, 0x74);

namespace {

// what 0x71004a1690 makes the glare's sets of lines from, five of them
// (placeholder; local to the file: its implicit constructor is inlined into
// 0x71004a1690, the only place that constructs one)
struct Unk_4a1690_Style {
    s32 field_0;                    // the first of its four Unk_24e5950 items
    Unk_4a2e20_Item field_4[8];     // the items
    s32 field_3a4;                  // how many
    const Unk_Float4* field_3a8;    // the colours
    Unk_Float4 field_3b0;           // their weights
    s32 field_3c0;                  // how many colours
    s32 field_3c4;                  // the seed
    f32 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_4a1690_Style, field_3a4, 0x3a4);
PKMN_OFFSET_ASSERT(Unk_4a1690_Style, field_3c8, 0x3c8);
PKMN_SIZE_ASSERT(Unk_4a1690_Style, 0x3d0);

}  // namespace

// 0x71004a2e20 (below)
inline void Unk_4a2e20(Unk_4a3cc0_Self* self, Unk_4a2e20_Item* item);
// 0x71004a3cc0 (below)
Unk_Float4 Unk_4a3cc0(Unk_4a3cc0_Self* self);

// the generator's state from a seed (inline)
static inline void Unk_Seed(Unk_4a3cc0_Self* self, u32 seed) {
    for (s32 i = 0; i < 4; i++) {
        seed = 1812433253 * (seed ^ (seed >> 30)) + i + 1;
        self->field_0[i] = seed;
    }
}

// the generator's next number (inline)
static inline u32 Unk_Next(Unk_4a3cc0_Self* self) {
    s32 t = self->field_0[0] ^ (self->field_0[0] << 11);
    self->field_0[0] = self->field_0[1];
    self->field_0[1] = self->field_0[2];
    self->field_0[2] = self->field_0[3];
    self->field_0[3] = self->field_0[3] ^ (self->field_0[3] >> 19) ^ (t ^ (t >> 8));
    return self->field_0[3];
}

// a number from 0 to 1 (inline)
static inline f32 Unk_Random(Unk_4a3cc0_Self* self) {
    return static_cast<f32>(Unk_Next(self) & 0x7fffffff) * 4.65661287e-10f;
}

// a colour's index, chosen by its weight (inline)
static inline s32 Unk_Pick(Unk_4a3cc0_Self* self) {
    f32 r = Unk_Random(self);
    s32 last = self->field_28 - 1;
    for (s32 i = 0; i < last; i++) {
        if (r <= self->field_2c.field_0[i].field_0) {
            return i;
        }
    }
    return last;
}

// a generator seeded with 1 and the colours (inline)
inline Unk_4a3cc0_Self::Unk_4a3cc0_Self(const Unk_Float4* colors, s32 count) {
    Unk_Seed(this, 1);
    field_20 = colors;
    field_28 = count;
}

// a colour's elements multiplied by another's (inline)
static inline Unk_Float4 Unk_Mul(const Unk_Float4& a, const Unk_Float4& b) {
    return Unk_Float4(a.field_0[0].field_0 * b.field_0[0].field_0, a.field_0[1].field_0 * b.field_0[1].field_0,
                      a.field_0[2].field_0 * b.field_0[2].field_0, a.field_0[3].field_0 * b.field_0[3].field_0);
}

// a colour's elements multiplied by a value (inline)
static inline Unk_Float4 Unk_Scale(const Unk_Float4& a, f32 s) {
    return Unk_Float4(a.field_0[0].field_0 * s, a.field_0[1].field_0 * s, a.field_0[2].field_0 * s,
                      a.field_0[3].field_0 * s);
}

// one minus a colour times (1 - k * k), not below zero (inline)
static inline Unk_Float4 Unk_Filter(const Unk_Float4& a, f32 k) {
    f32 s = 1.0f - k * k;
    return Unk_Float4(fmaxf(1.0f - s * a.field_0[0].field_0, 0.0f), fmaxf(1.0f - s * a.field_0[1].field_0, 0.0f),
                      fmaxf(1.0f - s * a.field_0[2].field_0, 0.0f), fmaxf(1.0f - s * a.field_0[3].field_0, 0.0f));
}


// 0x71004a2be0 (below)
void Unk_4a2be0(Unk_4a3cc0_Self* self, u32 seed, Unk_4a2be0_Target* target, Unk_4a2e20_Item* items, s32 count,
                const Unk_Float4* weights, s32 total, s32 arg7, f32 arg8);

}  // namespace PPFX

// 0x71004a1690: makes Unk_24e5950's items: five sets of lines, each in four
// sizes (`seeds`: what the sets' seeds add, or nullptr)
// The colour loops' indices are `s64` and `u32` (closer than `s32`).
// NON_MATCHING: written from the original's stores (what it sets is the
// original's); the stores' order and register allocation differ.
s32 Unk_4a1690(const s32* seeds) {
    using namespace PPFX;
#line 1209
    Unk_24e5950 = UNK_NEW_ARRAY(Unk_4a2be0_Target, 20);
    static Unk_4a1690_Style styles[5];
    // style 0
    {
        Unk_4a1690_Style& style = styles[0];
        style.field_0 = 0;
        style.field_3c4 = (seeds != nullptr ? seeds[0] : 0) + 3;
        style.field_3a4 = 2;
        style.field_3a8 = Unk_Colors0;
        style.field_3b0 = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        style.field_3c0 = 4;
        style.field_3c8 = 0.2f;
        {
            Unk_4a2e20_Item item;
            item.field_4 = -1.1f;
            item.field_8 = 0.25f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[1], Unk_Colors0[3]), 4.0f);
            item.field_1c = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            item.field_2c = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            item.field_3c = 0.2f;
            item.field_40 = 0.3f;
            item.field_44 = 0.85f;
            item.field_48 = 0.05f;
            item.field_4c = 0.4f;
            item.field_50 = -0.3f;
            item.field_54 = 0.1f;
            item.field_58 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_64.field_0[0].field_0 = 1.25f;
            item.field_64.field_0[1].field_0 = 0.75f;
            item.field_6c = false;
            item.field_70 = 0.05f;
            style.field_4[0] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -1.4f;
            item.field_8 = 0.45f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[2], Unk_Colors0[2]), 0.3f);
            item.field_1c = Unk_Float4(1.75f, 1.75f, 1.75f, 1.75f);
            item.field_2c = Unk_Float4(0.25f, 0.25f, 0.25f, 0.25f);
            item.field_3c = 0.2f;
            item.field_40 = 0.5f;
            item.field_44 = 0.65f;
            item.field_48 = -0.02f;
            item.field_4c = 0.85f;
            item.field_50 = 0.6f;
            item.field_54 = 0.5f;
            item.field_58 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.1f;
            item.field_5c.field_0[1].field_0 = 0.9f;
            item.field_64.field_0[0].field_0 = 1.0f;
            item.field_64.field_0[1].field_0 = 0.5f;
            item.field_6c = false;
            item.field_70 = 0.0f;
            style.field_4[1] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = 1.5f;
            item.field_8 = -2.0f;
            item.field_c = Unk_Mul(Unk_Colors0[3], Unk_Colors0[3]);
            item.field_1c = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            item.field_2c = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            item.field_3c = 1.0f;
            item.field_44 = 0.0f;
            item.field_4c = 2.0f;
            item.field_50 = 0.1f;
            item.field_54 = 0.0f;
            item.field_58 = 0.5f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_64.field_0[0].field_0 = 0.0f;
            item.field_64.field_0[1].field_0 = 0.0f;
            item.field_6c = false;
            item.field_70 = 0.0f;
            style.field_4[2] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -1.2f;
            item.field_8 = 0.25f;
            item.field_c = Unk_Mul(Unk_Colors0[3], Unk_Colors0[2]);
            item.field_1c = Unk_Float4(0.7f, 0.7f, 0.7f, 0.7f);
            item.field_2c = Unk_Float4(1.3f, 1.3f, 1.3f, 1.3f);
            item.field_3c = 0.4f;
            item.field_40 = 0.1f;
            style.field_4[3] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -2.3f;
            item.field_8 = 0.28f;
            item.field_c = Unk_Mul(Unk_Colors0[1], Unk_Colors0[3]);
            item.field_1c = Unk_Filter(Unk_Colors1[1], 0.6f);
            item.field_2c = Unk_Colors1[1];
            item.field_3c = 0.4f;
            item.field_40 = 0.4f;
            item.field_44 = 1.0f;
            item.field_48 = 0.5f;
            item.field_4c = 1.5f;
            item.field_50 = 0.5f;
            item.field_54 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_64.field_0[0].field_0 = 0.0f;
            item.field_64.field_0[1].field_0 = 0.0f;
            item.field_6c = false;
            item.field_70 = 0.08f;
            style.field_4[4] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -3.2f;
            item.field_8 = 0.5f;
            item.field_c = Unk_Mul(Unk_Colors0[3], Unk_Colors0[0]);
            item.field_1c = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            item.field_2c = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
            item.field_3c = 1.0f;
            item.field_40 = 0.5f;
            item.field_44 = 0.0f;
            item.field_48 = 0.3f;
            item.field_4c = 2.0f;
            item.field_50 = 0.6f;
            item.field_54 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_64.field_0[0].field_0 = 0.0f;
            item.field_64.field_0[1].field_0 = 0.0f;
            item.field_6c = false;
            item.field_70 = 0.0f;
            style.field_4[5] = item;
        }
    }
    // style 1
    {
        Unk_4a1690_Style& style = styles[1];
        style.field_0 = 4;
        style.field_3c4 = (seeds != nullptr ? seeds[1] : 0) + 4;
        style.field_3a4 = 6;
        style.field_3a8 = Unk_Colors0;
        style.field_3b0 = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        style.field_3c0 = 4;
        style.field_3c8 = 0.2f;
        {
            Unk_4a2e20_Item item;
            item.field_4 = -0.9f;
            item.field_8 = 0.22f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[1], Unk_Mul(Unk_Colors0[2], Unk_Colors0[2])), 4.0f);
            item.field_2c = Unk_Colors1[0];
            item.field_3c = 0.1f;
            item.field_40 = 0.25f;
            item.field_44 = 1.0f;
            item.field_48 = 0.05f;
            item.field_4c = 0.3f;
            item.field_50 = -0.25f;
            item.field_54 = 0.25f;
            item.field_58 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 0.8f;
            item.field_64.field_0[0].field_0 = 0.5f;
            item.field_64.field_0[1].field_0 = 0.35f;
            item.field_6c = false;
            item.field_70 = -0.05f;
            style.field_4[0] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = 1.5f;
            item.field_8 = 0.5f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[1], Unk_Colors0[3]), 2.0f);
            item.field_2c = Unk_Colors1[1];
            item.field_3c = 0.1f;
            item.field_40 = 1.0f;
            item.field_44 = 1.0f;
            item.field_48 = 0.05f;
            item.field_4c = 10.0f;
            item.field_50 = -0.3f;
            item.field_54 = 0.05f;
            item.field_58 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_64.field_0[0].field_0 = 0.5f;
            item.field_64.field_0[1].field_0 = 0.35f;
            item.field_6c = false;
            item.field_70 = 0.05f;
            style.field_4[1] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = 1.5f;
            item.field_8 = 0.75f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Mul(Unk_Colors0[1], Unk_Colors0[1]), Unk_Colors0[2]), 1.1f);
            item.field_2c = Unk_Colors1[0];
            item.field_3c = 0.1f;
            item.field_40 = 1.0f;
            item.field_44 = 0.75f;
            item.field_48 = 0.03f;
            item.field_4c = 1.0f;
            item.field_50 = 0.6f;
            item.field_54 = 0.3f;
            item.field_58 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_64.field_0[0].field_0 = 1.2f;
            item.field_64.field_0[1].field_0 = 0.75f;
            item.field_6c = false;
            item.field_70 = 0.0f;
            style.field_4[2] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -2.0f;
            item.field_8 = 1.1f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[2], Unk_Colors0[2]), 0.5f);
            item.field_2c = Unk_Scale(Unk_Colors1[3], 0.25f);
            item.field_3c = 0.1f;
            item.field_40 = 1.0f;
            item.field_44 = 0.5f;
            item.field_48 = -0.025f;
            item.field_4c = 1.0f;
            item.field_50 = 0.9f;
            item.field_54 = 0.5f;
            item.field_58 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 0.75f;
            item.field_64.field_0[0].field_0 = 1.2f;
            item.field_64.field_0[1].field_0 = 0.75f;
            item.field_6c = false;
            item.field_70 = 0.0f;
            style.field_4[3] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -1.21f;
            item.field_8 = 0.45f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[1], Unk_Mul(Unk_Colors0[1], Unk_Colors0[1])), 2.0f);
            item.field_1c = Unk_Filter(Unk_Colors1[0], 0.9f);
            item.field_2c = Unk_Colors1[0];
            item.field_3c = 0.1f;
            item.field_40 = 0.3f;
            item.field_44 = 0.5f;
            item.field_48 = 0.06f;
            item.field_4c = 0.5f;
            item.field_50 = -0.4f;
            item.field_54 = 0.1f;
            item.field_58 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 0.9f;
            item.field_64.field_0[0].field_0 = 1.25f;
            item.field_64.field_0[1].field_0 = 0.7f;
            item.field_6c = false;
            item.field_70 = 0.0f;
            style.field_4[4] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -1.1495f;
            item.field_8 = 0.42749998f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[2], Unk_Mul(Unk_Colors0[2], Unk_Colors0[2])), 2.0f);
            item.field_1c = Unk_Filter(Unk_Colors1[0], 0.9f);
            item.field_2c = Unk_Colors1[0];
            item.field_3c = 0.1f;
            item.field_40 = 0.3f;
            item.field_44 = 0.5f;
            item.field_48 = 0.06f;
            item.field_4c = 0.5f;
            item.field_50 = -0.38f;
            item.field_54 = 0.05f;
            item.field_58 = 1.0f;
            item.field_5c.field_0[0].field_0 = 1.0f;
            item.field_5c.field_0[1].field_0 = 0.9f;
            item.field_64.field_0[0].field_0 = 1.25f;
            item.field_64.field_0[1].field_0 = 0.7f;
            item.field_6c = false;
            item.field_70 = 0.0f;
            style.field_4[5] = item;
        }
    }
    // style 2
    {
        Unk_4a1690_Style& style = styles[2];
        style.field_0 = 8;
        style.field_3c4 = (seeds != nullptr ? seeds[2] : 0) + 8;
        style.field_3a4 = 0;
        style.field_3a8 = Unk_Colors0;
        style.field_3b0 = Unk_Float4(0.0f, 1.0f, 0.05f, 0.0f);
        style.field_3c0 = 4;
        style.field_3c8 = 0.05f;
    }
    // style 3
    {
        Unk_4a1690_Style& style = styles[3];
        style.field_0 = 12;
        style.field_3c4 = (seeds != nullptr ? seeds[3] : 0) + 12;
        style.field_3a4 = 0;
        style.field_3a8 = Unk_Colors0;
        style.field_3b0 = Unk_Float4(0.0f, 0.05f, 1.0f, 0.0f);
        style.field_3c0 = 4;
        style.field_3c8 = 0.5f;
    }
    // style 4
    {
        Unk_4a1690_Style& style = styles[4];
        style.field_0 = 16;
        style.field_3c4 = (seeds != nullptr ? seeds[4] : 0) + 16;
        style.field_3a4 = 6;
        style.field_3a8 = Unk_Colors0;
        style.field_3b0 = Unk_Float4(1.0f, 0.5f, 1.0f, 1.0f);
        style.field_3c0 = 4;
        style.field_3c8 = 0.5f;
        {
            Unk_4a2e20_Item item;
            item.field_4 = 1.7f;
            item.field_8 = 0.16f;
            item.field_c = Unk_Mul(Unk_Colors0[3], Unk_Colors0[2]);
            item.field_1c = Unk_Filter(Unk_Colors1[5], 0.1f);
            item.field_2c = Unk_Colors1[5];
            item.field_3c = 0.9f;
            item.field_40 = 0.6f;
            item.field_44 = 1.0f;
            item.field_48 = -0.05f;
            item.field_4c = 1.6f;
            item.field_50 = 1.2f;
            item.field_54 = 1.0f;
            item.field_5c.field_0[0].field_0 = 0.25f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_6c = false;
            item.field_70 = 0.05f;
            style.field_4[0] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = 0.3f;
            item.field_8 = -0.07f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[1], Unk_Colors0[3]), 2.0f);
            item.field_1c = Unk_Float4(0.7f, 0.7f, 0.7f, 0.7f);
            item.field_2c = Unk_Float4(1.3f, 1.3f, 1.3f, 1.3f);
            item.field_3c = 0.4f;
            item.field_40 = 0.5f;
            item.field_44 = 1.0f;
            item.field_48 = 0.1f;
            item.field_4c = 1.3f;
            item.field_50 = -0.4f;
            item.field_54 = 1.0f;
            item.field_5c.field_0[0].field_0 = 0.25f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_6c = false;
            item.field_70 = -0.05f;
            style.field_4[1] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -0.4f;
            item.field_8 = 0.11f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[3], Unk_Colors0[0]), 3.0f);
            item.field_1c = Unk_Filter(Unk_Colors1[1], 0.6f);
            item.field_2c = Unk_Colors1[1];
            item.field_3c = 0.4f;
            item.field_40 = 1.0f;
            item.field_44 = 1.0f;
            item.field_48 = -0.1f;
            item.field_4c = 2.0f;
            item.field_54 = 1.0f;
            item.field_5c.field_0[0].field_0 = 0.25f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_6c = false;
            item.field_70 = 0.05f;
            style.field_4[2] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -0.7f;
            item.field_8 = -0.13f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[1], Unk_Colors0[2]), 2.0f);
            item.field_1c = Unk_Filter(Unk_Colors1[4], 0.3f);
            item.field_2c = Unk_Colors1[4];
            item.field_3c = 0.7f;
            item.field_40 = 0.4f;
            item.field_44 = 1.0f;
            item.field_48 = 0.6f;
            item.field_4c = 1.7f;
            item.field_50 = -0.5f;
            item.field_54 = 1.0f;
            item.field_5c.field_0[0].field_0 = 0.25f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_6c = false;
            item.field_70 = -0.05f;
            style.field_4[3] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -1.1f;
            item.field_8 = -0.21f;
            item.field_c = Unk_Mul(Unk_Colors0[3], Unk_Colors0[0]);
            item.field_1c = Unk_Filter(Unk_Colors1[0], 0.7f);
            item.field_2c = Unk_Colors1[0];
            item.field_3c = 0.3f;
            item.field_40 = 0.75f;
            item.field_44 = 1.0f;
            item.field_48 = -0.05f;
            item.field_4c = 1.4f;
            item.field_50 = 0.3f;
            item.field_54 = 1.0f;
            item.field_5c.field_0[0].field_0 = 0.25f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_6c = false;
            item.field_70 = 0.05f;
            style.field_4[4] = item;
        }
        {
            Unk_4a2e20_Item item;
            item.field_4 = -2.2f;
            item.field_8 = 0.35f;
            item.field_c = Unk_Scale(Unk_Mul(Unk_Colors0[1], Unk_Colors0[3]), 0.5f);
            item.field_1c = Unk_Float4(0.5f, 0.5f, 0.5f, 0.5f);
            item.field_2c = Unk_Float4(1.5f, 1.5f, 1.5f, 1.5f);
            item.field_3c = 0.5f;
            item.field_40 = 0.7f;
            item.field_44 = 1.0f;
            item.field_48 = 0.2f;
            item.field_4c = 1.9f;
            item.field_50 = -2.2f;
            item.field_54 = 1.0f;
            item.field_5c.field_0[0].field_0 = 0.25f;
            item.field_5c.field_0[1].field_0 = 1.0f;
            item.field_6c = false;
            item.field_70 = -0.05f;
            style.field_4[5] = item;
        }
    }
    static const s32 totals[4] = {8, 16, 32, 64};
    static const s32 arg7s[4] = {1, 3, 3, 5};
    for (s64 i = 0; i < 5; i++) {
        Unk_4a1690_Style& style = styles[i];
        for (u32 j = 0; j < 4; j++) {
            Unk_4a3cc0_Self self(style.field_3a8, style.field_3c0);
            Unk_4a2be0(&self, style.field_3c4, &Unk_24e5950[style.field_0 + j], style.field_4, style.field_3a4,
                       &style.field_3b0, totals[j], arg7s[j], style.field_3c8);
        }
    }
    return 0;
}

// 0x71004a2b80
s32 Unk_4a2b80() {
    UNK_DELETE_ARRAY(Unk_24e5950);
    return 0;
}

namespace PPFX {

// 0x71004a2be0: seeds the generator, sets the colours' weights (FLT_MAX:
// the colour's fourth element), hands it the items and as many empty ones as
// make `total`
void Unk_4a2be0(Unk_4a3cc0_Self* self, u32 seed, Unk_4a2be0_Target* target, Unk_4a2e20_Item* items, s32 count,
                const Unk_Float4* weights, s32 total, s32 arg7, f32 arg8) {
    Unk_Seed(self, seed);
    self->field_14 = 0;
    self->field_18 = target;
    self->field_3c = arg7;
    self->field_40 = arg8;
    self->field_10 = 0;
    f32 sum = 0.0f;
    for (s32 i = 0; i < self->field_28; i++) {
        f32 weight = weights->v(i).field_0;
        if (weight != 3.40282347e+38f) {
            sum += weight;
        } else {
            sum += self->field_20[i].field_0[3].field_0;
        }
        self->field_2c.v(i).field_0 = sum;
    }
    for (s32 i = 0; i < self->field_28; i++) {
        self->field_2c.field_0[i].field_0 /= sum;
    }
    for (s32 i = 0; i < count; i++) {
        Unk_4a2e20(self, &items[i]);
    }
    Unk_Seed(self, seed * 31 + 1);
    s32 rest = total - count;
    rest = rest < 0 ? 0 : (rest > total ? total : rest);
    for (s32 i = 0; i < rest; i++) {
        Unk_4a2e20(self, nullptr);
    }
    target->field_1b00 = self->field_10;
}

// a value's size, the value itself when it's positive (inline)
static inline f32 Unk_Abs(f32 x) {
    return x > 0.0f ? x : -x;
}

// a value clamped to 0 to 1 (inline)
static inline f32 Unk_Saturate(f32 x) {
    return x < 0.0f ? 0.0f : (x > 1.0f ? 1.0f : x);
}

// a value whose part above `knee` is squeezed into what's left up to 1
// (inline)
static inline f32 Unk_Soft(f32 x, f32 knee) {
    f32 t = (x - knee) / (1.0f - knee);
    if (t > 0.0f)
        x = t / (t + 1.0f) * (1.0f - knee) + knee;
    return x;
}

// 1 or -1, at random (inline)
static inline f32 Unk_Sign(Unk_4a3cc0_Self* self) {
    return (Unk_Next(self) & 1) != 0 ? -1.0f : 1.0f;
}

// a number from `lo` to `hi` (inline; the random number isn't a named local:
// its DBG_VALUE would keep the A57 FP load balancing pass from renaming the
// product, which the original's registers show it did)
static inline f32 Unk_Range(Unk_4a3cc0_Self* self, f32 lo, f32 hi) {
    return lo + Unk_Random(self) * (hi - lo);
}

// whether a line's shape is under a quarter (inline)
static inline bool Unk_Small(f32 shape) {
    return shape < 0.25f;
}

// 0x71004a2e20: fills in the item's values that are FLT_MAX at random (an
// empty item without `item`), then adds its lines to the target. It's
// inline: its static (0x71024e6c70, guard 0x71024e6d60) is reached through
// the GOT, like those of the other inline functions.
// The shape's test is an inline function: its call, still there at the first
// InstCombine, keeps field_4c's doubling a second store (no select).
// NON_MATCHING: 12 bytes longer; the original doesn't fold `spread` into the
// test of field_50 (separate cbz; here `spread` comes out inverted and or-ed
// with the compare; `spread &&` first doesn't help), and keeps 1.0f in s8
// across the colour call (here it's rematerialised); two products have their
// operands the other way round (`width = size * |field_4|` in the second
// branch, field_50's `pow * e`: Reassociate's ranks put the earlier value
// first, and storing e into field_50 first adds a reload after powf; width
// computed once after the branches is much worse); the rest is the
// registers that follow.
inline void Unk_4a2e20(Unk_4a3cc0_Self* self, Unk_4a2e20_Item* item) {
    Unk_4a2e20_Item empty;
    if (item == nullptr)
        item = &empty;
    if (item->field_0 < 0)
        item->field_0 = self->field_14;
    bool given = true;
    if (item->field_4 == FLT_MAX) {
        item->field_4 = powf(20.0f, -Unk_Random(self)) * 2.5f * Unk_Sign(self);
        if (item->field_4 >= 0.7f && item->field_4 < 1.3f)
            item->field_4 = item->field_4 * 1.5f + 0.25f;
        given = false;
    }
    f32 size;
    f32 width;
    if (item->field_8 == FLT_MAX) {
        size = powf(10.0f, -Unk_Random(self));
        width = size * Unk_Abs(item->field_4);
        item->field_8 = width * 0.2f + 0.001f;
    } else {
        size = Unk_Soft(Unk_Abs(item->field_8) / 0.2f / Unk_Abs(item->field_4), 0.8f);
        width = size * Unk_Abs(item->field_4);
    }
    if (item->field_6c)
        item->field_8 *= Unk_Sign(self);
    f32 shape = item->field_5c.field_0[0].field_0;
    if (shape == FLT_MAX) {
        shape = Unk_Range(self, size * size + 0.1f, 1.1f);
        item->field_5c.field_0[0].field_0 = shape;
    }
    if (Unk_Small(shape) && !given)
        item->field_4 = -Unk_Saturate(Unk_Abs(item->field_4) * 2.0f);
    if (item->field_5c.field_0[1].field_0 == FLT_MAX)
        item->field_5c.field_0[1].field_0 = Unk_Small(shape) ? Unk_Range(self, 0.75f, 1.0f) : Unk_Range(self, 0.25f, 1.25f);
    if (item->field_64.field_0[0].field_0 == FLT_MAX) {
        if (Unk_Small(shape))
            item->field_64.field_0[0].field_0 = Unk_Range(self, 0.5f, 1.0f) * Unk_Abs(item->field_4);
        else
            item->field_64.field_0[0].field_0 = Unk_Range(self, 1.0f, 2.0f) * Unk_Abs(item->field_4);
    }
    if (item->field_64.field_0[1].field_0 == FLT_MAX)
        item->field_64.field_0[1].field_0 = item->field_64.field_0[0].field_0 * Unk_Range(self, 0.5f, 0.75f);
    if (item->field_40 == FLT_MAX)
        item->field_40 = Unk_Small(shape) ? Unk_Range(self, 0.25f, 2.0f) : Unk_Range(self, 0.1f, 1.5f);
    if (item->field_44 == FLT_MAX)
        item->field_44 = 1.0f - powf(Unk_Range(self, 0.0f, 0.8f), 5.0f);
    if (item->field_48 == FLT_MAX)
        item->field_48 = powf(10.0f, -0.25f * size) * Unk_Range(self, -1.0f, 1.0f);
    bool spread = false;
    if (item->field_4c == FLT_MAX) {
        f32 r = Unk_Range(self, 0.5f, 1.0f) * powf(Unk_Abs(item->field_4), 0.5f);
        item->field_4c = powf(size, 0.5f) * r;
        if (Unk_Small(shape))
            item->field_4c *= 2.0f;
        spread = true;
    }
    if (item->field_50 == FLT_MAX) {
        f32 e = exp2f(-Unk_Random(self));
        item->field_50 = powf(Unk_Saturate(Unk_Abs(item->field_8)), 0.75f) * e;
        item->field_50 *= Unk_Sign(self);
        if (item->field_50 < 0.0f && spread && item->field_4 > 0.0f)
            item->field_4c *= 2.0f;
        if (item->field_50 < 0.0f)
            item->field_50 = -(item->field_4c * Unk_Soft(-item->field_50 / item->field_4c, 0.8f));
        if (Unk_Small(shape))
            item->field_50 = Unk_Abs(item->field_50);
    }
    bool faded = false;
    if (item->field_54 == FLT_MAX) {
        item->field_54 = 1.0f;
        if (Unk_Abs(item->field_4) > 0.75f)
            item->field_54 = Unk_Range(self, 1.0f - width, 1.0f);
        faded = true;
    }
    if (item->field_58 == FLT_MAX)
        item->field_58 = Unk_Range(self, 0.25f, 0.75f);
    f32 fade = item->field_3c;
    if (fade == FLT_MAX) {
        fade = Unk_Range(self, 0.0f, 0.25f);
        item->field_3c = fade;
    }
    if (item->field_2c.field_0[0].field_0 == FLT_MAX) {
        s32 index = static_cast<s32>(Unk_Next(self) & 0x7fffffff) % 6;
        f32 s = powf(4.0f, Unk_Random(self) * item->field_3c * -4.0f) * 2.0f;
        const Unk_Float4& color = Unk_Colors1[index];
        item->field_2c = Unk_Float4(s * color.field_0[0].field_0, s * color.field_0[1].field_0,
                                    s * color.field_0[2].field_0, s * color.field_0[3].field_0);
    }
    if (item->field_1c.field_0[0].field_0 == FLT_MAX)
        item->field_1c = Unk_Filter(item->field_2c, 1.0f - fade);
    if (item->field_c.field_0[0].field_0 == FLT_MAX) {
        f32 k = 1.0f / width;
        Unk_Float4 color = Unk_Scale(Unk_4a3cc0(self), 2.0f);
        item->field_c = Unk_Float4(k * color.field_0[0].field_0, k * color.field_0[1].field_0,
                                   k * color.field_0[2].field_0, k * color.field_0[3].field_0);
        if (faded) {
            k = 1.0f / (item->field_54 * 0.5f + 0.5f);
            item->field_c = Unk_Float4(k * item->field_c.field_0[0].field_0, k * item->field_c.field_0[1].field_0,
                                       k * item->field_c.field_0[2].field_0, k * item->field_c.field_0[3].field_0);
        }
    }
    if (item->field_70 == FLT_MAX) {
        item->field_70 = 0.0f;
        if (Unk_Random(self) <= self->field_40) {
            f32 d = 0.025f / (Unk_Abs(item->field_4) * 0.5f + 0.5f);
            f32 v = Unk_Range(self, 0.5f, 1.0f) * d;
            item->field_70 = Unk_Sign(self) * v;
        }
        if (faded && item->field_54 <= 0.1f)
            item->field_70 = 0.05f;
    }
    s32 count;
    s32 last;
    s32 set;
    if (item->field_70 == 0.0f) {
        count = 1;
        last = 0;
        set = 0;
    } else {
        count = self->field_3c;
        last = count - 1;
        set = last / 2;
        if (set < 0)
            set = 0;
        else
            set = set > 2 ? 2 : set;
    }
    // each count's lines' colour weights (one, three or five lines)
    static const Unk_Float4 weights[3][5] = {
        {Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f)},
        {Unk_Float4(1.0f, 0.0f, 0.0f, 0.0f), Unk_Float4(0.0f, 1.0f, 0.0f, 0.0f), Unk_Float4(0.0f, 0.0f, 1.0f, 0.0f)},
        {Unk_Float4(0.5f, 0.0f, 0.0f, 0.0f), Unk_Float4(0.5f, 0.25f, 0.0f, 0.0f), Unk_Float4(0.0f, 0.5f, 0.0f, 0.0f),
         Unk_Float4(0.0f, 0.25f, 0.5f, 0.0f), Unk_Float4(0.0f, 0.0f, 0.5f, 0.0f)},
    };
    for (s32 i = 0; i < count; i++) {
        if (self->field_10 > 63)
            break;
        f32 offset = 0.0f;
        if (count != 1) {
            f32 a = item->field_70 * -0.5f;
            f32 b = item->field_70 * 0.5f;
            offset = a + static_cast<f32>(i) / static_cast<f32>(last) * (b - a);
        }
        Unk_4a2be0_Line& line = self->field_18->field_0[self->field_10];
        line.field_4 = offset + item->field_4;
        f32 ratio = item->field_4 / line.field_4;
        line.field_c = item->field_8 * ratio;
        line.field_18 = Unk_Mul(item->field_c, weights[set][i]);
        line.field_28 = item->field_1c;
        line.field_38 = item->field_2c;
        line.field_48 = item->field_3c;
        line.field_8 = item->field_40;
        line.field_14 = item->field_44;
        line.field_10 = item->field_48 + offset * -0.1f;
        line.field_4c = ratio * item->field_4c;
        line.field_50 = item->field_50 / ratio;
        line.field_54 = item->field_54;
        line.field_58 = item->field_58;
        line.field_5c = item->field_5c;
        line.field_64 = item->field_64;
        line.field_0 = item->field_0;
        self->field_10++;
    }
    self->field_14++;
}

// 0x71004a3cc0: a random colour, the product of two picked by their weights,
// each squared one time in four
Unk_Float4 Unk_4a3cc0(Unk_4a3cc0_Self* self) {
    s32 index = Unk_Pick(self);
    const Unk_Float4* a = &self->field_20[index];
    f32 r = a->field_0[0].field_0;
    f32 g = a->field_0[1].field_0;
    f32 b = a->field_0[2].field_0;
    f32 w = a->field_0[3].field_0;
    if (Unk_Random(self) < 0.25f) {
        r *= a->field_0[0].field_0;
        g *= a->field_0[1].field_0;
        b *= a->field_0[2].field_0;
        w *= a->field_0[3].field_0;
    }
    index = Unk_Pick(self);
    const Unk_Float4* c = &self->field_20[index];
    r *= c->field_0[0].field_0;
    g *= c->field_0[1].field_0;
    b *= c->field_0[2].field_0;
    w *= c->field_0[3].field_0;
    if (Unk_Random(self) < 0.25f) {
        r *= c->field_0[0].field_0;
        g *= c->field_0[1].field_0;
        b *= c->field_0[2].field_0;
        w *= c->field_0[3].field_0;
    }
    Unk_Float4 color;
    color.field_0[0].field_0 = r;
    color.field_0[1].field_0 = g;
    color.field_0[2].field_0 = b;
    color.field_0[3].field_0 = w;
    return color;
}

}  // namespace PPFX
