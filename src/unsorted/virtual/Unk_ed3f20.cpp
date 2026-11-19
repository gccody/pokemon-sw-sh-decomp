// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_ed3f30(u64);

class Unk_23f78b8 {
public:
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
    u8 _8[0x140];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_23f78b8, field_148, 0x148);

// 0x7100ed3f20
void Unk_23f78b8::vf15() {
    Unk_ed3f30(field_148);
}

class Unk_23f7a60 : public Unk_239a4c0 {
public:
    ~Unk_23f7a60() override;
    u8 _54[0x284];
    u64 _2d8;
    u64 _2e0;
    u64 _2e8;
    u64 _2f0;
    u64 _2f8;
    u64 _300;
    u64 _308;
    u64 _310;
    u64 _318;
    Unk_239a418_Ref<Unk_239a418> field_320;
};
PKMN_OFFSET_ASSERT(Unk_23f7a60, field_320, 0x320);

// 0x7100ed8cd0: its key function
Unk_23f7a60::~Unk_23f7a60() {}

class Unk_23f7e30 {
public:
    virtual ~Unk_23f7e30();
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
};

// 0x7100ee14a0
void Unk_23f7e30::vf12() {}

// 0x7100ee14c0
void Unk_23f7e30::vf13() {}

class Unk_23f7eb0 {
public:
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
};

// 0x7100ee14b0
void Unk_23f7eb0::vf10() {}

// 0x7100ee14d0
void Unk_23f7eb0::vf11() {}
