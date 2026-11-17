// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23aca98 {
public:
    virtual ~Unk_23aca98();
};

// 0x7100818770, 0x7100818780
Unk_23aca98::~Unk_23aca98() {}
