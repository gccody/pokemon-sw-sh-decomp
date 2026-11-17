// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2435f38 {
public:
    virtual ~Unk_2435f38();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9();
    virtual u32 vf10();
    u8 _8[0x68];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_2435f38, field_70, 0x70);

// 0x71013e41e0
void Unk_2435f38::vf9() {}
