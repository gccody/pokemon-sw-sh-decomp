// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2417970 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010f42c0
void Unk_2417970::vf0() {}

// 0x71010f42d0
void Unk_2417970::vf1() {}

// 0x71010f42e0
void Unk_2417970::vf2() {}
