// Scope: common
//
// A class on Unk_23f5318 (vtable 0x71024442f0): a reference of its own. Its
// destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the classes are known.
#include "gflib3/Unk_239a418.h"

// Its base (vtable 0x71023f5318), as far as this needs it: 19 slots and a
// destructor out of line (0x7100ea05b0).
class Unk_23f5318 : public Unk_239a418 {
public:
    ~Unk_23f5318() override;
    const Unk_239a418_Type* vf_type() override;
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

    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u64 field_a0;
    u64 field_a8;
    u64 field_b0;
    u64 field_b8;
    u64 field_c0;
    u64 field_c8;
    u64 field_d0;
    u64 field_d8;
    u64 field_e0;
    u64 field_e8;
    u64 field_f0;
    u64 field_f8;
    u64 field_100;
    u64 field_108;
    u64 field_110;
    u64 field_118;
    u64 field_120;
    u64 field_128;
    u64 field_130;
    u64 field_138;
    u64 field_140;
    u64 field_148;
    u64 field_150;
    u64 field_158;
    u64 field_160;
    u64 field_168;
    u64 field_170;
    u64 field_178;
    u64 field_180;
    u64 field_188;
    u64 field_190;
    u64 field_198;
    u64 field_1a0;
    u64 field_1a8;
    u64 field_1b0;
    u64 field_1b8;
    u64 field_1c0;
    u64 field_1c8;
    u64 field_1d0;
    u64 field_1d8;
    u64 field_1e0;
    u64 field_1e8;
    u64 field_1f0;
    u64 field_1f8;
    u64 field_200;
    u64 field_208;
    u64 field_210;
    u64 field_218;
    u64 field_220;
    u64 field_228;
    u64 field_230;
    u64 field_238;
    u64 field_240;
};

class Unk_24442f0 : public Unk_23f5318 {
public:
    ~Unk_24442f0() override;
    const Unk_239a418_Type* vf_type() override;

    Unk_239a418_Ref<Unk_239a418> field_248;
};
static_assert(sizeof(Unk_24442f0) == 0x250, "Unk_24442f0");
static_assert(__builtin_offsetof(Unk_24442f0, field_248) == 0x248, "Unk_24442f0::field_248");

// 0x71014de2c0, its D0 and thunks for +0x48 and +0x50
Unk_24442f0::~Unk_24442f0() {}
