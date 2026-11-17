// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2416118 {
public:
    virtual ~Unk_2416118();
    virtual void vf2();
    virtual u32 vf3();
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
    u8 _8[0xc];
    u32 field_14;
    u8 _18[0x2a];
    u8 field_42;
};
PKMN_OFFSET_ASSERT(Unk_2416118, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2416118, field_42, 0x42);

// 0x71010e4410
u32 Unk_2416118::vf3() {
    return 1;
}

// 0x71010e4420
void Unk_2416118::vf12() {
    field_42 = 1;
    field_14 = 2;
}
