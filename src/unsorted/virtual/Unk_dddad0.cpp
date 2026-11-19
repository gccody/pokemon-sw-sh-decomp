// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f5d00.h"

class Unk_23f0920 {
public:
    virtual ~Unk_23f0920();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100dddad0
void Unk_23f0920::vf7() {}

class Unk_23f0d10 : public Unk_23f5d00 {
public:
    ~Unk_23f0d10() override;
    u8* vf5() override;
    Unk_23f5d00_Member<void> field_180;
};
PKMN_OFFSET_ASSERT(Unk_23f0d10, field_180, 0x180);

// 0x7100de4cc0: its key function
Unk_23f0d10::~Unk_23f0d10() {}
