// Scope: common
// PPFX's glare definitions (lib/yebis/YEBIS_draft/src/GPU/GPUGlareDef.h).
#include <math.h>
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/GPUGlareDef.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>

// The definitions the glare draws with (GPUGlareDef.cpp's): the stars, the
// glares and 0x71024e5950's items
extern PPFX::Unk_4a0540* Unk_24e58c0;
extern PPFX::Unk_4a0b00* Unk_24e5948;
extern PPFX::Unk_24e5950_Item* Unk_24e5950;

namespace PPFX {

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

// 0x71004a0bb0
Unk_4a0540& Unk_4a0540::operator=(const Unk_4a0540& other) {
    if (&other == this)
        return *this;
    Unk_4a0680();
    memmove(static_cast<Unk_4a0540_Base*>(this), &other, sizeof(Unk_4a0540_Base));
    if (other.field_20 != nullptr) {
#line 245
        field_20 = UNK_NEW_ARRAY(Unk_4a0540_Line, field_8);
        for (s32 i = 0; i < field_8; i++)
            field_20[i] = other.field_20[i];
    }
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
// NON_MATCHING: clang inlines the star's assignment (0x71004a0bb0), which the
// original calls; the stores before it are the original's.
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
    field_28 = fabsf(arg8) * 0.8f;
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

// a glare definition of the table (0x38 bytes; GPUGlareDef.cpp's static
// initialiser fills the table)
struct Unk_4a1010_Desc {
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
// 0x71024e7070: the table
extern Unk_4a1010_Desc Unk_24e7070[14] __attribute__((visibility("hidden")));

// 0x71004a06e0: makes the stars (not written yet)
s32 Unk_4a06e0();

// 0x71004a1010: makes the glare definitions
// NON_MATCHING: the 14 inlined constructors' zero stores are scheduled in
// another order (the original starts the next element's star earlier).
s32 Unk_4a1010() {
    if (Unk_24e5948 != nullptr)
        return 0;
    Unk_4a06e0();
#line 654
    Unk_24e5948 = UNK_NEW_ARRAY(PPFX::Unk_4a0b00, 14);
    for (s32 i = 0; i < 14; i++) {
        const Unk_4a1010_Desc& desc = Unk_24e7070[i];
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

// 0x71004a2b80
s32 Unk_4a2b80() {
    UNK_DELETE_ARRAY(Unk_24e5950);
    return 0;
}

namespace PPFX {

// what 0x71004a2be0 sets up and 0x71004a3cc0 reads: a xorshift128 generator
// and colours with their cumulative weights (placeholder)
struct Unk_4a2be0_Target {
    u8 _0[0x1b00];
    s32 field_1b00;
};
struct Unk_4a3cc0_Self {
    u32 field_0[4];  // the generator's state
    s32 field_10;
    s32 field_14;
    Unk_4a2be0_Target* field_18;
    Unk_Float4* field_20;  // the colours
    s32 field_28;          // how many (up to 4)
    Unk_Float4 field_2c;   // their cumulative weights
    s32 field_3c;
    f32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4a3cc0_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_4a3cc0_Self, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_4a3cc0_Self, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_4a3cc0_Self, field_40, 0x40);
// what 0x71004a2be0 hands 0x71004a2e20, 0x74 bytes each (placeholder)
struct Unk_4a2e20_Item {
    u8 _0[0x74];
};
PKMN_SIZE_ASSERT(Unk_4a2e20_Item, 0x74);

// 0x71004a2e20 (not written yet)
void Unk_4a2e20(Unk_4a3cc0_Self* self, const Unk_4a2e20_Item* item);

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

// 0x71004a2be0: seeds the generator, sets the colours' weights (FLT_MAX:
// the colour's fourth element), hands it the items and as many empty ones as
// make `total`
// NON_MATCHING: scheduling only: the original stores arg7, field_10 and
// field_18 before the first seed's stores, here they come after them
void Unk_4a2be0(Unk_4a3cc0_Self* self, u32 seed, Unk_4a2be0_Target* target, const Unk_4a2e20_Item* items, s32 count,
                const Unk_Float4* weights, s32 total, s32 arg7, f32 arg8) {
    self->field_3c = arg7;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_18 = target;
    Unk_Seed(self, seed);
    self->field_40 = arg8;
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
