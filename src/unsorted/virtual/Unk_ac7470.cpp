// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

struct Unk_23c9028_630 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23c9028_630, field_58, 0x58);

class Unk_23c9028 {
public:
    virtual ~Unk_23c9028();
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
    u8 _8[0x5f8];
    u64 field_600;
    u32 field_608;
    u8 _60c[0x24];
    Unk_23c9028_630* field_630;
};
PKMN_OFFSET_ASSERT(Unk_23c9028, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_23c9028, field_608, 0x608);
PKMN_OFFSET_ASSERT(Unk_23c9028, field_630, 0x630);

// 0x7100ac7470
void Unk_23c9028::vf21() {
    field_630->field_58 = field_630->field_58 & 0xfe;
}
