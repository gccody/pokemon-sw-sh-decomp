// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_241f360 {
public:
    virtual ~Unk_241f360();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71011b51a0
void Unk_241f360::vf4() {}

class Unk_241f3a8 {
public:
    virtual ~Unk_241f3a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71011b52a0
void Unk_241f3a8::vf4() {}
