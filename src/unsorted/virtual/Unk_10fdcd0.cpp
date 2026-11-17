// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2417dc8 {
public:
    virtual ~Unk_2417dc8();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010fdcd0
void Unk_2417dc8::vf2() {}

class Unk_2417df8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71010fdd50
void Unk_2417df8::vf0() {}
