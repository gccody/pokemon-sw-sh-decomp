// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn4ui2d9AlignmentE
#include <types.h>

struct Unk_17ab1f0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(u32, u64);
    u8 _8[0x51];
    u8 field_59;
};
PKMN_OFFSET_ASSERT(Unk_17ab1f0, field_59, 0x59);

struct Unk_17ac700 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

struct Unk_17ab2f0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u64, u32);
};

struct Unk_17ab3e0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(u64, u32);
};

struct Unk_17ac590_arg1 {
    u8 _0[0x80];
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u64 field_a0;
    u64 field_a8;
    u8 _b0[0xdb];
    u8 field_18b;
};
PKMN_OFFSET_ASSERT(Unk_17ac590_arg1, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_17ac590_arg1, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_17ac590_arg1, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_17ac590_arg1, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_17ac590_arg1, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_17ac590_arg1, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_17ac590_arg1, field_18b, 0x18b);

struct Unk_17ac590 {
    u8 _0[0x70];
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_17ac590, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_17ac590, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_17ac590, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_17ac590, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_17ac590, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_17ac590, field_98, 0x98);

struct Unk_17ac8d0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24(u64);
};

struct Unk_17ac9c0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26(u64);
};

namespace nn {
namespace ui2d {
class Alignment {
public:
    u32 vf4();
    void vf5();
    void vf7(u32 value, u64 arg2);
    u32 vf8();
    void vf9();
    u32 vf10();
    u64 vf11();
    void vf13(u64 value, bool arg2);
    void vf15(u64 value, bool arg2);
    void vf21();
    void vf22();
    void vf23(Unk_17ac590_arg1* value);
    void vf25(u64 value);
    void vf27(u64 value);
};
}  // namespace ui2d
}  // namespace nn

// 0x7101793360
void nn::ui2d::Alignment::vf22() {
}

// 0x71017ab1b0
u32 nn::ui2d::Alignment::vf4() {
    return 0xffffffff;
}

// 0x71017ab1c0
void nn::ui2d::Alignment::vf5() {
}

// 0x71017ab1f0
void nn::ui2d::Alignment::vf7(u32 value, u64 arg2) {
    Unk_17ab1f0* self = reinterpret_cast<Unk_17ab1f0*>(this);
    if (value == 0x10) {
        self->field_59 = arg2;
        return;
    }
    self->vf9(value, arg2);
}

// 0x71017ab210
u32 nn::ui2d::Alignment::vf8() {
    return 0xff;
}

// 0x71017ab220
void nn::ui2d::Alignment::vf9() {
}

// 0x71017ab2f0
void nn::ui2d::Alignment::vf13(u64 value, bool arg2) {
    Unk_17ab2f0* self = reinterpret_cast<Unk_17ab2f0*>(this);
    self->vf12(value, arg2);
}

// 0x71017ab3e0
void nn::ui2d::Alignment::vf15(u64 value, bool arg2) {
    Unk_17ab3e0* self = reinterpret_cast<Unk_17ab3e0*>(this);
    self->vf14(value, arg2);
}

// 0x71017ac430
void nn::ui2d::Alignment::vf21() {
}

// 0x71017ac590
void nn::ui2d::Alignment::vf23(Unk_17ac590_arg1* value) {
    const Unk_17ac590* self = reinterpret_cast<const Unk_17ac590*>(this);
    value->field_88 = self->field_78;
    u64 v0 = self->field_88;
    value->field_a8 = self->field_98;
    value->field_98 = v0;
    value->field_80 = self->field_70;
    u64 v1 = self->field_80;
    value->field_a0 = self->field_90;
    value->field_90 = v1;
    value->field_18b = 0;
}

// 0x71017ac6f0
u32 nn::ui2d::Alignment::vf10() {
    return 0;
}

// 0x71017ac700
u64 nn::ui2d::Alignment::vf11() {
    Unk_17ac700* self = reinterpret_cast<Unk_17ac700*>(this);
    self->vf10();
    return 0;
}

// 0x71017ac8d0
void nn::ui2d::Alignment::vf25(u64 value) {
    Unk_17ac8d0* self = reinterpret_cast<Unk_17ac8d0*>(this);
    self->vf24(value);
}

// 0x71017ac9c0
void nn::ui2d::Alignment::vf27(u64 value) {
    Unk_17ac9c0* self = reinterpret_cast<Unk_17ac9c0*>(this);
    self->vf26(value);
}
