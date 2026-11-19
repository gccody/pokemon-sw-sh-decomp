// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_404540_18 {
    u8 _0[0x80];
    f32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_404540_18, field_80, 0x80);

struct Unk_404540 {
    u8 _0[0x18];
    Unk_404540_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_404540, field_18, 0x18);

class Unk_2384dd0 {
public:
    void vf3();
    void vf5();
    u32 vf6();
    f32 vf8();
    void vf9();
    u64 vf15();
    u64 vf16();
    u32 vf17();
    u32 vf18();
    void vf20();
    u32 vf21();
    u32 vf22();
    u32 vf23();
    u32 vf27();
};

// 0x71003cc2d0
void Unk_2384dd0::vf3() {
}

// 0x71003cc2e0
void Unk_2384dd0::vf5() {
}

// 0x71003cc2f0
u32 Unk_2384dd0::vf6() {
    return 1;
}

// 0x71003cc300
u32 Unk_2384dd0::vf21() {
    return 0;
}

// 0x71003cc310
u32 Unk_2384dd0::vf22() {
    return 0;
}

// 0x71003ddc50
void Unk_2384dd0::vf9() {
}

// 0x71003ddd40
void Unk_2384dd0::vf20() {
}

// 0x7100404540
f32 Unk_2384dd0::vf8() {
    const Unk_404540* self = reinterpret_cast<const Unk_404540*>(this);
    return self->field_18->field_80;
}

// 0x7100404550
u64 Unk_2384dd0::vf15() {
    return 0;
}

// 0x7100404560
u64 Unk_2384dd0::vf16() {
    return 0;
}

// 0x7100404570
u32 Unk_2384dd0::vf17() {
    return 0;
}

// 0x7100404580
u32 Unk_2384dd0::vf18() {
    return 0;
}

// 0x71004045b0
u32 Unk_2384dd0::vf23() {
    return 0;
}

// 0x71004045d0
u32 Unk_2384dd0::vf27() {
    return 0;
}
