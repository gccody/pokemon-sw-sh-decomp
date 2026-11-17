// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2405488 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100fe28b0
void Unk_2405488::vf1() {}
