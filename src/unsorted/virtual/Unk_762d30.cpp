// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_771250(u64);

class Unk_23a7938 {
public:
    virtual ~Unk_23a7938();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x90];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_23a7938, field_98, 0x98);

// 0x7100762d30
void Unk_23a7938::vf5() {
    Unk_771250(field_98);
}
