// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2418090 {
public:
    virtual ~Unk_2418090();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4() = 0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2418090, field_8, 0x8);

// 0x71010ff4a0
void Unk_2418090::vf3() {
    field_8 = 0;
}
