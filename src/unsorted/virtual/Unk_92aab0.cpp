// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bf468 {
public:
    virtual ~Unk_23bf468();
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
    u8 _8[0x74];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_23bf468, field_7c, 0x7c);

// 0x710092aac0
void Unk_23bf468::vf14() {}

// 0x710092aab0
void Unk_23bf468::vf15() {
    field_7c = 3;
}
