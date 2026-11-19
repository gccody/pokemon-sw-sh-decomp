// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_171b640();

// 0x710171b630
void Unk_171b630_call() {
    Unk_171b640();
}

void Unk_171bb70();

// 0x710171bb60
void Unk_171bb60_call() {
    Unk_171bb70();
}

void Unk_171c100();

// 0x710171c0f0
void Unk_171c0f0_call() {
    Unk_171c100();
}

void Unk_171c610();

// 0x710171c600
void Unk_171c600_call() {
    Unk_171c610();
}

void Unk_171cb80();

// 0x710171cb70
void Unk_171cb70_call() {
    Unk_171cb80();
}

void Unk_171d0b0();

// 0x710171d0a0
void Unk_171d0a0_call() {
    Unk_171d0b0();
}

void Unk_171d610();

// 0x710171d600
void Unk_171d600_call() {
    Unk_171d610();
}

void Unk_171db40();

// 0x710171db30
void Unk_171db30_call() {
    Unk_171db40();
}

// 0x710171e250
void Unk_171e250_update() {
}

struct Unk_171e260_8 {
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
    virtual void vf24(u64, u64);
};

struct Unk_171e260 {
    u8 _0[0x8];
    Unk_171e260_8* field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_171e260, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_171e260, field_10, 0x10);

// 0x710171e260
void Unk_171e260_call(const Unk_171e260* self, u64 value) {
    self->field_8->vf24(self->field_10, value);
}
