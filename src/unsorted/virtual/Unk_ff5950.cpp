// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2406410 {
public:
    virtual ~Unk_2406410();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100ff5950
void Unk_2406410::vf7() {}

class Unk_24064c8 {
public:
    virtual void vf0();
};

// 0x7100ff5960
void Unk_24064c8::vf0() {}
