// PPFX's glare definitions (C:/workspace/YEBIS_draft/src/GPU/GPUGlareDef.cpp,
// the __FILE__ of its allocations). Nothing names the classes: placeholders,
// after their first functions.
#pragma once

#include <string.h>

#include <types.h>
#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>

namespace PPFX {

// A star's line (12 bytes, with a destructor that does nothing)
struct Unk_4a0540_Line {
    ~Unk_4a0540_Line() {}

    f32 field_0;
    f32 field_4;
    f32 field_8;
};
PKMN_SIZE_ASSERT(Unk_4a0540_Line, 0xc);

// What a star definition is made from (the static table's records)
struct Unk_4a0540_Base {
    const char* field_0;  // name
    s32 field_8;          // the number of lines
    f32 field_c;
    f32 field_10;
    f32 field_14;
    bool field_18;
};
PKMN_SIZE_ASSERT(Unk_4a0540_Base, 0x20);

// A star definition: its parameters and its lines
class Unk_4a0540 : public Unk_4a0540_Base {
public:
    Unk_4a0540();  // 0x71004a0530
    ~Unk_4a0540() { Unk_4a0680(); }

    s32 Unk_4a0540_Copy(const Unk_4a0540& other);  // 0x71004a0540
    void Unk_4a0680();                             // 0x71004a0680: frees the lines
    Unk_4a0540& operator=(const Unk_4a0540& other);  // 0x71004a0bb0
    Unk_4a0540& operator=(const Unk_4a0540_Base& other) {
        Unk_4a0680();
        *static_cast<Unk_4a0540_Base*>(this) = other;
        return *this;
    }

    void Unk_Clear() {
        memset(this, 0, sizeof(*this));
    }
    void Unk_Set(const char* name, s32 lines, f32 arg2, f32 arg3, f32 arg4, bool arg5) {
        field_0 = name;
        field_8 = lines;
        field_c = arg2;
        field_10 = arg3;
        field_14 = arg4;
        field_18 = arg5;
    }

    Unk_4a0540_Line* field_20;
};
PKMN_SIZE_ASSERT(Unk_4a0540, 0x28);

// A glare definition (0xa8 bytes): its name, parameters and the star it
// draws. The constructor and the destructor are out of line (a function-local
// static of GPUPostEffect.cpp has them).
struct Unk_4a0b00 {
    Unk_4a0b00();   // 0x71004a0b00
    ~Unk_4a0b00();  // 0x71004a0b40

    // 0x71004a0cf0: sets everything (`star` -1: no star)
    s32 Unk_4a0cf0(const char* name, u32 star, Unk_Float4 arg2, Unk_Float4 arg3, Unk_Float4 arg4, f32 arg5,
                   Unk_Float4 arg6, f32 arg7, f32 arg8, f32 arg9, Unk_Float4 arg10, f32 arg11);
    // 0x71004a0f10: the same without a star, then the user's values and star ("UserDef")
    s32 Unk_4a0f10(const char* name, Unk_Float4 arg6, Unk_Float4 arg7, f32 arg8, Unk_Float4 arg9, f32 arg10,
                   f32 arg11, Unk_Float4 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16, f32 arg17, f32 arg18,
                   Unk_Float4 arg19, f32 arg20, s32 arg1, bool arg2, s32 lines, bool arg4, bool arg5);

    const char* field_0;
    f32 field_8[8];
    f32 field_28;
    s32 field_2c;
    f32 field_30[4];
    f32 field_40;
    f32 field_44;
    bool field_48;
    f32 field_4c[4];
    f32 field_5c;
    f32 field_60;
    bool field_64;
    f32 field_68;
    f32 field_6c[4];
    f32 field_7c;
    Unk_4a0540 field_80;
};
PKMN_OFFSET_ASSERT(Unk_4a0b00, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_4a0b00, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_4a0b00, field_80, 0x80);
PKMN_SIZE_ASSERT(Unk_4a0b00, 0xa8);

// a line of Unk_4a2be0_Target (0x6c bytes; placeholder)
struct Unk_4a2be0_Line {
    Unk_4a2be0_Line()
        : field_4(0.0f), field_8(1.0f), field_c(0.1f), field_10(0.0f), field_14(1.0f), field_18(1.0f, 1.0f, 1.0f, 1.0f),
          field_28(1.0f, 1.0f, 1.0f, 1.0f), field_38(1.0f, 1.0f, 1.0f, 1.0f), field_48(0.5f), field_4c(0.8f),
          field_50(0.2f), field_54(1.0f), field_58(0.4f), field_5c(0.0f, 0.0f), field_64(1.0f, 1.0f) {}

    s32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
    Unk_Float4 field_18;  // the colour
    Unk_Float4 field_28;
    Unk_Float4 field_38;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    f32 field_54;
    f32 field_58;
    Unk_Float2 field_5c;
    Unk_Float2 field_64;
};
PKMN_OFFSET_ASSERT(Unk_4a2be0_Line, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_4a2be0_Line, field_48, 0x48);
PKMN_SIZE_ASSERT(Unk_4a2be0_Line, 0x6c);

// what 0x71024e5950 holds, 20 of them (0x1b04 bytes each): a set of lines
// (placeholder)
struct Unk_4a2be0_Target {
    Unk_4a2be0_Line field_0[64];
    s32 field_1b00;  // how many
};
PKMN_SIZE_ASSERT(Unk_4a2be0_Target, 0x1b04);

}  // namespace PPFX
