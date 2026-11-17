// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_ec88c0(u64);

struct Unk_2403178_740 {
    u8 _0[0x708];
    u64 field_708;
};
PKMN_OFFSET_ASSERT(Unk_2403178_740, field_708, 0x708);

class Unk_2403178 {
public:
    virtual ~Unk_2403178();
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
    virtual void vf24();
    virtual void vf25();
    u8 _8[0x738];
    Unk_2403178_740* field_740;
};
PKMN_OFFSET_ASSERT(Unk_2403178, field_740, 0x740);

// 0x7100fc6580
void Unk_2403178::vf20() {
    Unk_ec88c0(field_740->field_708);
}
