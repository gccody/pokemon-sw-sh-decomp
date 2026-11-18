// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"

class Unk_2399470 : public Unk_239a4c0 {
public:
    void vf2() override;
};

// 0x71005cfb80
void Unk_2399470::vf2() {}
