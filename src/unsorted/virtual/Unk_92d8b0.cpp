// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_91b5a0(void*, u64);
void Unk_91b5c0(void*, u64, u64, u32);

class Unk_23bf6a8 {
public:
    virtual ~Unk_23bf6a8();
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
    u8 _8[0x5d0];
    u64 field_5d8;
    u8 _5e0[0x50];
    u8 field_630;
    u8 _631[0xc7];
    u64 field_6f8;
};
PKMN_OFFSET_ASSERT(Unk_23bf6a8, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_23bf6a8, field_630, 0x630);
PKMN_OFFSET_ASSERT(Unk_23bf6a8, field_6f8, 0x6f8);

// 0x710092d8b0
void Unk_23bf6a8::vf17() {
    if (field_630 != 0) {
        Unk_91b5c0(this, field_5d8, field_6f8, 1);
    }
}

// 0x710092d8d0
void Unk_23bf6a8::vf18() {
    if (field_630 != 0) {
        Unk_91b5a0(this, field_5d8);
    }
}
