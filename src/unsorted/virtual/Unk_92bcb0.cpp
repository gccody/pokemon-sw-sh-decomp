// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bf560 {
public:
    virtual ~Unk_23bf560();
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
};

// 0x710092bcb0
void Unk_23bf560::vf14() {}

struct Unk_23bf658_8 {
    u8 _0[0x33d];
    u8 field_33d;
};
PKMN_OFFSET_ASSERT(Unk_23bf658_8, field_33d, 0x33d);

class Unk_23bf658 {
public:
    virtual void vf0();
    virtual u8 vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    Unk_23bf658_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_23bf658, field_8, 0x8);

// 0x710092c5d0
u8 Unk_23bf658::vf1() {
    return field_8->field_33d;
}

// 0x710092c5a0
void Unk_23bf658::vf6() {}

// 0x710092c640
void Unk_23bf658::vf7() {
    ::operator delete(this);
}
