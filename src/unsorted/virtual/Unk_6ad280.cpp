// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a2c10 {
public:
    virtual ~Unk_23a2c10();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
};

// 0x71006ad2b0, 0x71006ad260
Unk_23a2c10::~Unk_23a2c10() {}

// 0x71006ad280
u32 Unk_23a2c10::vf3() {
    return 1;
}
