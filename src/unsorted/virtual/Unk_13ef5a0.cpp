// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2436868 {
public:
    virtual ~Unk_2436868();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71013ef5a0, 0x71013ef5b0
Unk_2436868::~Unk_2436868() {}

// 0x71013ef600
void Unk_2436868::vf4() {}
