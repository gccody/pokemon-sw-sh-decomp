// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f5d00.h"

class Unk_23e36f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100ce00b0
void Unk_23e36f8::vf1() {}

class Unk_23e3730 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100ce00c0
void Unk_23e3730::vf0() {}

// 0x7100ce00d0
void Unk_23e3730::vf1() {}

class Unk_23e3760 : public Unk_23f5d00 {
public:
    ~Unk_23e3760() override;
    u8* vf5() override;
    Unk_23f5d00_Member<void> field_180;
};
PKMN_OFFSET_ASSERT(Unk_23e3760, field_180, 0x180);

// 0x7100ce0250: its key function
Unk_23e3760::~Unk_23e3760() {}
