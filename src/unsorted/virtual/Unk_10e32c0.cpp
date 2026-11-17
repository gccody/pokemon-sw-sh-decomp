// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15b6e10(void* self);

class Unk_2415f18 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71010e32c0
void Unk_2415f18::vf1() {
    Unk_15b6e10(this);
}
