// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_2417870 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2417870, field_78, 0x78);

// 0x71010f3a10
void Unk_2417870::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_2417970 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010f42c0
void Unk_2417970::vf0() {}

// 0x71010f42d0
void Unk_2417970::vf1() {}

// 0x71010f42e0
void Unk_2417970::vf2() {}
