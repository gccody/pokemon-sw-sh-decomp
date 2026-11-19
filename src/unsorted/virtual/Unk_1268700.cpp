// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2428328 {
public:
    virtual ~Unk_2428328();
    virtual void vf2();
    virtual void vf3();
    u8 _8[0x3ba];
    u8 field_3c2;
};
PKMN_OFFSET_ASSERT(Unk_2428328, field_3c2, 0x3c2);

// 0x7101268700
void Unk_2428328::vf3() {
    field_3c2 = 1;
}

class Unk_24283e8 {
public:
    virtual ~Unk_24283e8();
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

// 0x7101269800
void Unk_24283e8::vf9() {}
