// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2417bd8 {
public:
    virtual ~Unk_2417bd8();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010f7e60
void Unk_2417bd8::vf2() {}

class Unk_2417c08 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71010f7ee0
void Unk_2417c08::vf0() {}
