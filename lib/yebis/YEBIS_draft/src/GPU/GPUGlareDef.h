// PPFX's glare definitions (C:/workspace/YEBIS_draft/src/GPU/GPUGlareDef.cpp,
// the __FILE__ of its allocations). Nothing names the classes: placeholders,
// after their first functions.
#pragma once

#include <string.h>

#include <types.h>

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
    Unk_4a0540() { Unk_Clear(); }
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

    Unk_4a0540_Line* field_20;
};
PKMN_SIZE_ASSERT(Unk_4a0540, 0x28);

}  // namespace PPFX
