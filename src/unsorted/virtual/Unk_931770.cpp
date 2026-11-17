// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_e80810(u64);

class Unk_23bf9d0 {
public:
    virtual ~Unk_23bf9d0();
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
    u8 _8[0x80];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_23bf9d0, field_88, 0x88);

// 0x7100931770
void Unk_23bf9d0::vf15() {
    Unk_e80810(field_88);
}
