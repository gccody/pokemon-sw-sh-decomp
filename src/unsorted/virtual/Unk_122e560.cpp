// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_2419350.h"

class Unk_2424588 : public Unk_2419350 {
public:
    void vf8() override;
    void vf5() override;
    u32 vf6() override;
    u32 vf10() override;
};

// 0x710122e560
void Unk_2424588::vf8() {}
