// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_937090(u64);
void Unk_9370d0(u64);

class Unk_23bfd60 {
public:
    virtual ~Unk_23bfd60();
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
    u8 _8[0x6b0];
    u64 field_6b8;
};
PKMN_OFFSET_ASSERT(Unk_23bfd60, field_6b8, 0x6b8);

// 0x7100935960
void Unk_23bfd60::vf17() {
    Unk_937090(field_6b8);
}

// 0x7100935970
void Unk_23bfd60::vf18() {
    Unk_9370d0(field_6b8);
}
