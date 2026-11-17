// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_92e170(u64);

class Unk_23bf8d8 {
public:
    virtual ~Unk_23bf8d8();
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
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23bf8d8, field_80, 0x80);

// 0x7100930ba0
void Unk_23bf8d8::vf14() {
    Unk_92e170(field_80);
}
