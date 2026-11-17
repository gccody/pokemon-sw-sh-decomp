// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2433840 {
public:
    virtual ~Unk_2433840();
    virtual void vf2();
    virtual void vf3();
};

// 0x710139ff50, 0x710139ff40
Unk_2433840::~Unk_2433840() {}
