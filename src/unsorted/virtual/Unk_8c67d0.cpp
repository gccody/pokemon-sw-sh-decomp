// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bb228 {
public:
    virtual ~Unk_23bb228();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5() = 0;
    virtual void vf6() = 0;
};

// 0x71008c67d0, 0x71008c67f0
Unk_23bb228::~Unk_23bb228() {}
